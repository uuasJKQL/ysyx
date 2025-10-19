#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <dlfcn.h>  // 动态链接库支持

#include "Vysyx_25050147_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vysyx_25050147_top__Dpi.h"
#include "svdpi.h"

static Vysyx_25050147_top *ysyx_25050147_top;
vluint64_t sim_time = 0;

// 全局变量存储指令内存
std::vector<uint32_t> instruction_memory;
bool exit1 = 0;

// DiffTest相关定义和变量
#ifdef DIFFTEST

// 寄存器上下文结构体 - 必须与NEMU中的定义一致
struct diff_context_t {
    uint32_t gpr[32];    // 32个通用寄存器
    uint32_t pc;         // 程序计数器
    // 可以根据需要添加其他寄存器（如CSR等）
};

// DiffTest API函数指针
typedef void (*difftest_memcpy_t)(uint32_t addr, void *buf, size_t n, bool direction);
typedef void (*difftest_regcpy_t)(void *dut, bool direction);
typedef void (*difftest_exec_t)(uint64_t n);
typedef void (*difftest_raise_intr_t)(uint32_t NO);

// 全局DiffTest变量
static void* difftest_so = NULL;
static difftest_memcpy_t difftest_memcpy = NULL;
static difftest_regcpy_t difftest_regcpy = NULL;
static difftest_exec_t difftest_exec = NULL;
static difftest_raise_intr_t difftest_raise_intr = NULL;

static struct diff_context_t ref_regs;  // REF(NEMU)寄存器状态
static struct diff_context_t dut_regs;  // DUT(NPC)寄存器状态

#endif // DIFFTEST

// 默认程序（当没有指定文件时使用）
const std::vector<uint32_t> DEFAULT_PROGRAM = {
    0x00500093, // addi x1, x0, 5
    0x00700113, // addi x2, x0, 7  
    0x00508113, // addi x2, x1, 5
    0x00100073  // ebreak
};

int pmem_read(uint32_t addr)
{
    // 计算内存索引（假设指令从0x80000000开始）
    uint32_t index = (addr - 0x80000000) / 4;
    
    if (index < instruction_memory.size()) {
        return instruction_memory[index];
    } else {
        // 如果地址超出范围，返回ebreak指令（0x00100073）
        return 0x00100073;
    }
}

#ifdef DIFFTEST

// 初始化DiffTest
bool difftest_init(const char* so_path) {
    printf("初始化DiffTest，加载动态库: %s\n", so_path);
    
    // 加载动态库
    difftest_so = dlopen(so_path, RTLD_LAZY);
    if (!difftest_so) {
        printf("错误: 无法加载动态库 %s: %s\n", so_path, dlerror());
        return false;
    }
    
    // 获取API函数指针
    difftest_memcpy = (difftest_memcpy_t)dlsym(difftest_so, "difftest_memcpy");
    difftest_regcpy = (difftest_regcpy_t)dlsym(difftest_so, "difftest_regcpy");
    difftest_exec = (difftest_exec_t)dlsym(difftest_so, "difftest_exec");
    difftest_raise_intr = (difftest_raise_intr_t)dlsym(difftest_so, "difftest_raise_intr");
    
    if (!difftest_memcpy || !difftest_regcpy || !difftest_exec) {
        printf("错误: 无法找到DiffTest API函数\n");
        dlclose(difftest_so);
        return false;
    }
    
    printf("DiffTest初始化成功\n");
    return true;
}

// 同步初始状态到REF(NEMU)
void difftest_sync_initial_state() {
    printf("同步初始状态到REF...\n");
    
    // 同步内存：将测试程序复制到NEMU
    if (!instruction_memory.empty()) {
        difftest_memcpy(0x80000000, instruction_memory.data(), 
                       instruction_memory.size() * 4, true);
    }
    
    // 初始化DUT寄存器状态（复位状态）
    memset(&dut_regs, 0, sizeof(dut_regs));
    for (int i = 0; i < 32; i++) {
        dut_regs.gpr[i] = 0;
    }
    dut_regs.pc = 0x80000000;  // 初始PC
    
    // 同步寄存器状态到REF
    difftest_regcpy(&dut_regs, true);
    
    printf("初始状态同步完成\n");
}

// 从NPC获取当前寄存器状态
void difftest_get_dut_state() {
    // 这里需要根据你的NPC实际实现来获取寄存器值
    // 目前使用模拟数据，你需要替换为实际的寄存器读取逻辑
    
    // 假设我们通过DPI接口获取寄存器值
    // 例如：dut_regs.gpr[1] = get_register(1);
    
    // 暂时使用模拟更新：PC递增，寄存器值简单变化
    dut_regs.pc = ysyx_25050147_top->pc;
    
    // 注意：这里需要实际实现从NPC读取所有寄存器的逻辑
    // 你可能需要在Verilog中添加DPI-C接口来导出寄存器值
}

// 比对DUT和REF的状态
bool difftest_check_state() {
    // 获取REF的当前状态
    difftest_regcpy(&ref_regs, false);
    
    // 比对PC
    if (dut_regs.pc != ref_regs.pc) {
        printf("DiffTest错误: PC不匹配!\n");
        printf("  DUT PC: 0x%08x\n", dut_regs.pc);
        printf("  REF PC: 0x%08x\n", ref_regs.pc);
        return false;
    }
    
    // 这里可以添加更多寄存器的比对
    // for (int i = 0; i < 32; i++) {
    //     if (dut_regs.gpr[i] != ref_regs.gpr[i]) {
    //         printf("DiffTest错误: 寄存器x%d不匹配!\n", i);
    //         printf("  DUT x%d: 0x%08x\n", i, dut_regs.gpr[i]);
    //         printf("  REF x%d: 0x%08x\n", i, ref_regs.gpr[i]);
    //         return false;
    //     }
    // }
    
    return true;
}

// 执行DiffTest：让REF执行指令并比对状态
bool difftest_step() {
    // 让REF执行一条指令
    difftest_exec(1);
    
    // 获取DUT的当前状态
    difftest_get_dut_state();
    
    // 比对状态
    return difftest_check_state();
}

// 清理DiffTest资源
void difftest_cleanup() {
    if (difftest_so) {
        dlclose(difftest_so);
        difftest_so = NULL;
    }
    printf("DiffTest资源已清理\n");
}

#endif // DIFFTEST

void single_cycle()
{
    ysyx_25050147_top->clk = 0;
    ysyx_25050147_top->eval();
    ysyx_25050147_top->clk = 1;
    ysyx_25050147_top->eval();
}

void reset(int n)
{
    ysyx_25050147_top->rst = 1;
    while (n-- > 0)
        single_cycle();
    ysyx_25050147_top->rst = 0;
}

// 读取二进制文件到指令内存
bool load_binary_file(const std::string& filename, uint32_t base_addr = 0x80000000)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "错误: 无法打开文件: " << filename << std::endl;
        return false;
    }
    
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    if (size == 0) {
        std::cerr << "错误: 文件为空: " << filename << std::endl;
        return false;
    }
    
    size_t word_count = (size + 3) / 4;
    instruction_memory.resize(word_count, 0);
    
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        std::cerr << "错误: 读取文件失败: " << filename << std::endl;
        return false;
    }
    
    for (size_t i = 0; i < size; i += 4) {
        uint32_t word = 0;
        for (int j = 0; j < 4 && (i + j) < size; j++) {
            word |= (static_cast<uint32_t>(buffer[i + j]) & 0xFF) << (j * 8);
        }
        instruction_memory[i / 4] = word;
    }
    
    std::cout << "成功加载 " << size << " 字节 (" << word_count 
              << " 条指令) 从文件: " << filename << std::endl;
    return true;
}

void notify_ebreak()
{
    std::cout << "EBREAK指令触发，停止仿真" << std::endl;
    exit1 = true;
}

void print_usage(const char* program_name)
{
    std::cout << "用法: " << program_name << " [选项] [程序文件]" << std::endl;
    std::cout << "选项:" << std::endl;
    std::cout << "  -h, --help     显示此帮助信息" << std::endl;
    std::cout << "  -t, --timeout N 设置仿真超时周期数（默认: 1000）" << std::endl;
    std::cout << "  -v, --verbose   显示详细仿真信息" << std::endl;
#ifdef DIFFTEST
    std::cout << "  --diff SO_PATH  启用DiffTest，指定NEMU动态库路径" << std::endl;
#endif
    std::cout << "示例:" << std::endl;
    std::cout << "  " << program_name << " add-riscv32e-npc.bin" << std::endl;
    std::cout << "  " << program_name << " -t 2000 program.bin" << std::endl;
#ifdef DIFFTEST
    std::cout << "  " << program_name << " --diff ../nemu/build/riscv32-nemu-interpreter-so program.bin" << std::endl;
#endif
}

int main(int argc, char** argv)
{
    // 默认参数
    std::string program_file = "";
    uint32_t timeout_cycles = 1000;
    bool verbose = false;
#ifdef DIFFTEST
    std::string diff_so_path = "";
    bool enable_difftest = false;
#endif
    
    // 解析命令行参数
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            print_usage(argv[0]);
            return 0;
        }
        else if (arg == "-t" || arg == "--timeout") {
            if (i + 1 < argc) {
                timeout_cycles = std::stoi(argv[++i]);
            } else {
                std::cerr << "错误: --timeout 参数需要指定周期数" << std::endl;
                return 1;
            }
        }
        else if (arg == "-v" || arg == "--verbose") {
            verbose = true;
        }
#ifdef DIFFTEST
        else if (arg == "--diff") {
            if (i + 1 < argc) {
                diff_so_path = argv[++i];
                enable_difftest = true;
            } else {
                std::cerr << "错误: --diff 参数需要指定动态库路径" << std::endl;
                return 1;
            }
        }
#endif
        else if (arg[0] == '-') {
            std::cerr << "错误: 未知选项 " << arg << std::endl;
            print_usage(argv[0]);
            return 1;
        }
        else {
            program_file = arg;
        }
    }
    
    // 初始化Verilator
    ysyx_25050147_top = new Vysyx_25050147_top;
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    ysyx_25050147_top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

#ifdef DIFFTEST
    // 初始化DiffTest
    if (enable_difftest) {
        if (!difftest_init(diff_so_path.c_str())) {
            std::cerr << "DiffTest初始化失败，继续执行但不进行比对" << std::endl;
            enable_difftest = false;
        } else {
            std::cout << "DiffTest已启用" << std::endl;
        }
    }
#endif

    // 加载程序
    if (!program_file.empty()) {
        if (!load_binary_file(program_file)) {
            std::cerr << "警告: 使用默认程序" << std::endl;
            instruction_memory = DEFAULT_PROGRAM;
        }
    } else {
        std::cout << "未指定程序文件，使用默认程序" << std::endl;
        instruction_memory = DEFAULT_PROGRAM;
    }
    
#ifdef DIFFTEST
    // 同步初始状态到REF
    if (enable_difftest) {
        difftest_sync_initial_state();
    }
#endif

    std::cout << "程序大小: " << instruction_memory.size() << " 条指令" << std::endl;
    std::cout << "仿真超时: " << timeout_cycles << " 个周期" << std::endl;
    std::cout << "开始仿真..." << std::endl;

    // 复位
    reset(10);
 
    // 主仿真循环
    ysyx_25050147_top->mem = pmem_read(ysyx_25050147_top->pc);
    
    while (!exit1 && sim_time < timeout_cycles) {
        ysyx_25050147_top->clk = 0;
        ysyx_25050147_top->eval();
        m_trace->dump(sim_time);
        ysyx_25050147_top->clk = 1;
        ysyx_25050147_top->eval();
        
        if (verbose) {
            printf("周期=%lu, PC=0x%08x, Inst=0x%08x\n", 
                   sim_time, ysyx_25050147_top->pc, ysyx_25050147_top->mem);
        }
        
#ifdef DIFFTEST
        // 执行DiffTest比对
        if (enable_difftest) {
            if (!difftest_step()) {
                printf("DiffTest在周期 %lu 发现错误，停止仿真\n", sim_time);
                break;
            }
        }
#endif
        
        sim_time++;
        ysyx_25050147_top->mem = pmem_read(ysyx_25050147_top->pc);
        
        if (sim_time % 1000 == 0) {
            printf("仿真进度: %lu/%u 周期\n", sim_time, timeout_cycles);
        }
    }
         
    ysyx_25050147_top->clk = 0;
    ysyx_25050147_top->eval();
    m_trace->dump(sim_time);
    sim_time++;
    m_trace->dump(sim_time);  
    
    // 仿真结束处理
    if (exit1) {
        std::cout << "仿真正常结束（EBREAK触发）" << std::endl;
    } else if (sim_time >= timeout_cycles) {
        std::cout << "仿真超时结束" << std::endl;
    } else {
        std::cout << "仿真因DiffTest错误结束" << std::endl;
    }
    
    std::cout << "总仿真周期: " << sim_time << std::endl;
    std::cout << "最终PC: 0x" << std::hex << ysyx_25050147_top->pc << std::dec << std::endl;
    
#ifdef DIFFTEST
    // 清理DiffTest资源
    if (enable_difftest) {
        difftest_cleanup();
    }
#endif
    
    // 清理资源
    m_trace->close();
    delete ysyx_25050147_top;
    delete m_trace;
    
    return 0;
}
