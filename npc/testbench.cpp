#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <dlfcn.h>
#include <map>
#include <cstring>

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
bool hit_good_trap = false;
int exit_code = -1;

// 内存跟踪开关
bool enable_mem_trace = true;

// 寄存器名称映射
const char *reg_names[32] = {
    "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

// 阴影寄存器存储 - 用于跟踪NPC中所有寄存器的值
uint32_t shadow_registers[32] = {0};

// DiffTest相关定义和变量
#ifdef DIFFTEST

// 寄存器上下文结构体 - 必须与NEMU中的定义一致
struct diff_context_t
{
    uint32_t gpr[32]; // 32个通用寄存器
    uint32_t pc;      // 程序计数器
    // 可以根据需要添加其他寄存器（如CSR等）
};

// DiffTest API函数指针
typedef void (*difftest_memcpy_t)(uint32_t addr, void *buf, size_t n, bool direction);
typedef void (*difftest_regcpy_t)(void *dut, bool direction);
typedef void (*difftest_exec_t)(uint64_t n);
typedef void (*difftest_raise_intr_t)(uint32_t NO);

// 全局DiffTest变量
static void *difftest_so = NULL;
static difftest_memcpy_t difftest_memcpy = NULL;
static difftest_regcpy_t difftest_regcpy = NULL;
static difftest_exec_t difftest_exec = NULL;
static difftest_raise_intr_t difftest_raise_intr = NULL;

static struct diff_context_t ref_regs; // REF(NEMU)寄存器状态
static struct diff_context_t dut_regs; // DUT(NPC)寄存器状态

#endif // DIFFTEST

// 默认程序（当没有指定文件时使用）
const std::vector<uint32_t> DEFAULT_PROGRAM = {
    0x00500093, // addi x1, x0, 5
    0x00700113, // addi x2, x0, 7
    0x00508113, // addi x2, x1, 5
    0x002081b3, // add x3, x1, x2
    0x00100073  // ebreak
};

// 全局内存模拟
#define MEM_SIZE (64 * 1024 * 1024) // 64MB 内存
#define MEM_BASE 0x80000000         // 内存基地址
static uint8_t *memory = nullptr;

// 地址转换函数：将虚拟地址转换为物理地址
uint32_t virtual_to_physical(uint32_t vaddr)
{
    // 对于简单的系统，我们可以直接将0x80000000映射到物理内存的0地址
    // 或者保持地址不变，但分配足够大的内存
    if (vaddr >= MEM_BASE && vaddr < MEM_BASE + MEM_SIZE)
    {
        return vaddr - MEM_BASE;
    }
    // 如果地址不在我们管理的内存范围内，返回一个错误值
    return 0xFFFFFFFF;
}

// 打印内存访问详情
void print_memory_access(const char *type, uint32_t vaddr, uint32_t paddr,
                         uint32_t value, uint8_t mask, size_t size, bool is_write)
{
    if (!enable_mem_trace)
        return;

    printf("[MEM %s] vaddr=0x%08x, paddr=0x%08x, ",
           is_write ? "WRITE" : "READ", vaddr, paddr);

    if (is_write)
    {
        printf("value=0x%08x, mask=0x%02x, bytes=[", value, mask);
        for (int i = 0; i < 4; i++)
        {
            if (mask & (1 << i))
            {
                uint8_t byte_val = (value >> (i * 8)) & 0xFF;
                printf("0x%02x", byte_val);
            }
            else
            {
                printf("----");
            }
            if (i < 3)
                printf(" ");
        }
        printf("]");
    }
    else
    {
        printf("value=0x%08x, bytes=[", value);
        for (int i = 0; i < 4; i++)
        {
            uint8_t byte_val = (value >> (i * 8)) & 0xFF;
            printf("0x%02x", byte_val);
            if (i < 3)
                printf(" ");
        }
        printf("]");
    }

    printf("\n");
}

// DPI-C 函数实现
extern "C" int pmem_read(int raddr)
{
    // 总是读取地址为 `raddr & ~0x3u` 的4字节返回
    uint32_t aligned_addr = raddr & ~0x3u;

    // 检查内存是否初始化
    if (!memory)
    {
        printf("错误: 内存未初始化!\n");
        return 0;
    }

    // 地址转换
    uint32_t phys_addr = virtual_to_physical(aligned_addr);

    // 检查地址是否在有效范围内
    if (phys_addr == 0xFFFFFFFF || phys_addr >= MEM_SIZE - 3)
    {
        // 对于不在我们管理范围内的地址，返回0
        return 0;
    }

    // 读取4字节
    uint32_t value = 0;
    value |= (uint32_t)memory[phys_addr + 0] << 0;
    value |= (uint32_t)memory[phys_addr + 1] << 8;
    value |= (uint32_t)memory[phys_addr + 2] << 16;
    value |= (uint32_t)memory[phys_addr + 3] << 24;

    // 打印内存读取详情
    print_memory_access("READ", aligned_addr, phys_addr, value, 0xF, 4, false);

    return value;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask)
{
    // 总是往地址为 `waddr & ~0x3u` 的4字节按写掩码 `wmask` 写入 `wdata`
    uint32_t aligned_addr = waddr & ~0x3u;

    // 检查内存是否初始化
    if (!memory)
    {
        printf("错误: 内存未初始化!\n");
        return;
    }

    // 地址转换
    uint32_t phys_addr = virtual_to_physical(aligned_addr);

    // 检查地址是否在有效范围内
    if (phys_addr == 0xFFFFFFFF || phys_addr >= MEM_SIZE - 3)
    {
        // 对于不在我们管理范围内的地址，忽略写入
        return;
    }

    // 打印内存写入详情（在写入前打印，显示旧值）
    uint32_t old_value = 0;
    old_value |= (uint32_t)memory[phys_addr + 0] << 0;
    old_value |= (uint32_t)memory[phys_addr + 1] << 8;
    old_value |= (uint32_t)memory[phys_addr + 2] << 16;
    old_value |= (uint32_t)memory[phys_addr + 3] << 24;

    printf("[MEM WRITE] vaddr=0x%08x, paddr=0x%08x, old_value=0x%08x, new_value=0x%08x, mask=0x%02x\n",
           aligned_addr, phys_addr, old_value, wdata, wmask);

    printf("           Bytes: [");
    for (int i = 0; i < 4; i++)
    {
        uint32_t byte_addr = phys_addr + i;
        uint8_t old_byte = memory[byte_addr];
        uint8_t new_byte = old_byte;

        if (wmask & (1 << i))
        {
            new_byte = (wdata >> (i * 8)) & 0xFF;
        }

        if (wmask & (1 << i))
        {
            printf("0x%08x: 0x%02x->0x%02x", aligned_addr + i, old_byte, new_byte);
        }
        else
        {
            printf("0x%08x: 0x%02x", aligned_addr + i, old_byte);
        }

        if (i < 3)
            printf(", ");
    }
    printf("]\n");

    // 根据写掩码写入相应的字节
    if (wmask & 0x1)
        memory[phys_addr + 0] = (wdata >> 0) & 0xFF;
    if (wmask & 0x2)
        memory[phys_addr + 1] = (wdata >> 8) & 0xFF;
    if (wmask & 0x4)
        memory[phys_addr + 2] = (wdata >> 16) & 0xFF;
    if (wmask & 0x8)
        memory[phys_addr + 3] = (wdata >> 24) & 0xFF;
}

// 初始化内存
void initialize_memory()
{
    if (!memory)
    {
        memory = (uint8_t *)malloc(MEM_SIZE);
        if (!memory)
        {
            printf("错误: 无法分配内存!\n");
            exit(1);
        }
        memset(memory, 0, MEM_SIZE);
        printf("内存初始化成功: %d MB, 基地址: 0x%08x\n", MEM_SIZE / (1024 * 1024), MEM_BASE);
    }
}

// 清理内存
void cleanup_memory()
{
    if (memory)
    {
        free(memory);
        memory = nullptr;
        printf("内存已释放\n");
    }
}

// 使用DPI-C函数读取内存的包装函数
int pmem_read_wrapper(uint32_t addr)
{
    return pmem_read(addr);
}

// 初始化内存：将程序加载到模拟内存中
void initialize_memory_with_program()
{
    initialize_memory();

    printf("开始加载程序到内存...\n");

    // 将程序写入内存的0x80000000位置
    for (size_t i = 0; i < instruction_memory.size(); i++)
    {
        uint32_t addr = MEM_BASE + i * 4;
        uint32_t instruction = instruction_memory[i];

        // 使用DPI-C函数写入内存，写入4个字节（wmask = 0xF）
        pmem_write(addr, instruction, 0xF);

        if (i < 10)
        { // 只打印前10条指令的加载信息
            uint32_t phys_addr = virtual_to_physical(addr);
            printf("加载指令到内存: vaddr=0x%08x, paddr=0x%08x, inst=0x%08x\n",
                   addr, phys_addr, instruction);
        }
    }
    printf("总共加载了 %zu 条指令到内存\n", instruction_memory.size());
}

// DPI-C函数：更新阴影寄存器
void update_shadow_register(int index, const svBitVecVal *value)
{
    if (index >= 0 && index < 32)
    {
        shadow_registers[index] = value[0];
        // printf("更新寄存器 x%d(%s) = 0x%08x\n", index, reg_names[index], value[0]);
    }
}

#ifdef DIFFTEST

// 初始化DiffTest
bool difftest_init(const char *so_path)
{
    printf("初始化DiffTest，加载动态库: %s\n", so_path);

    // 加载动态库
    difftest_so = dlopen(so_path, RTLD_LAZY);
    if (!difftest_so)
    {
        printf("错误: 无法加载动态库 %s: %s\n", so_path, dlerror());
        return false;
    }

    // 获取API函数指针
    difftest_memcpy = (difftest_memcpy_t)dlsym(difftest_so, "difftest_memcpy");
    difftest_regcpy = (difftest_regcpy_t)dlsym(difftest_so, "difftest_regcpy");
    difftest_exec = (difftest_exec_t)dlsym(difftest_so, "difftest_exec");
    difftest_raise_intr = (difftest_raise_intr_t)dlsym(difftest_so, "difftest_raise_intr");

    if (!difftest_memcpy || !difftest_regcpy || !difftest_exec)
    {
        printf("错误: 无法找到DiffTest API函数\n");
        dlclose(difftest_so);
        return false;
    }

    printf("DiffTest初始化成功\n");
    return true;
}

// 同步初始状态到REF(NEMU)
void difftest_sync_initial_state()
{
    printf("同步初始状态到REF...\n");

    // 同步内存：将测试程序复制到NEMU
    if (!instruction_memory.empty())
    {
        difftest_memcpy(MEM_BASE, instruction_memory.data(),
                        instruction_memory.size() * 4, true);
    }

    // 初始化DUT寄存器状态（复位状态）
    memset(&dut_regs, 0, sizeof(dut_regs));
    for (int i = 0; i < 32; i++)
    {
        dut_regs.gpr[i] = 0;
    }
    dut_regs.pc = MEM_BASE;       // 初始PC
    dut_regs.gpr[0] = 0;          // x0 (zero) 必须为0
    dut_regs.gpr[2] = 0x80009000; // 设置初始栈指针，这是RISC-V程序的常见设置

    // 同步寄存器状态到REF
    difftest_regcpy(&dut_regs, true);

    printf("初始状态同步完成\n");
}

// 从NPC获取当前寄存器状态
void difftest_get_dut_state()
{
    // 更新PC
    dut_regs.pc = ysyx_25050147_top->pc;

    // 从阴影寄存器获取所有寄存器值
    for (int i = 0; i < 32; i++)
    {
        dut_regs.gpr[i] = shadow_registers[i];
    }

    // 确保x0寄存器始终为0
    dut_regs.gpr[0] = 0;
}

// 打印寄存器状态
void print_register_state(const char *title, struct diff_context_t *regs)
{
    printf("%s:\n", title);
    printf("  PC: 0x%08x\n", regs->pc);

    for (int i = 0; i < 32; i += 4)
    {
        printf("  ");
        for (int j = 0; j < 4 && (i + j) < 32; j++)
        {
            int idx = i + j;
            printf("x%2d(%s)=0x%08x ", idx, reg_names[idx], regs->gpr[idx]);
        }
        printf("\n");
    }
    printf("\n");
}

// 比对DUT和REF的状态
bool difftest_check_state()
{
    bool match = true;

    // 比对PC
    if (dut_regs.pc != ref_regs.pc)
    {
        printf("DiffTest错误: PC不匹配!\n");
        printf("  DUT PC: 0x%08x\n", dut_regs.pc);
        printf("  REF PC: 0x%08x\n", ref_regs.pc);
        match = false;
    }

    // 比对所有通用寄存器
    for (int i = 0; i < 32; i++)
    {
        if (dut_regs.gpr[i] != ref_regs.gpr[i])
        {
            printf("DiffTest错误: 寄存器x%d(%s)不匹配!\n", i, reg_names[i]);
            printf("  DUT x%d: 0x%08x\n", i, dut_regs.gpr[i]);
            printf("  REF x%d: 0x%08x\n", i, ref_regs.gpr[i]);
            match = false;
        }
    }

    if (!match)
    {
        printf("\n寄存器状态对比:\n");
        print_register_state("DUT (NPC) 寄存器状态", &dut_regs);
        print_register_state("REF (NEMU) 寄存器状态", &ref_regs);
    }

    return match;
}

// 执行DiffTest：让REF执行指令并比对状态
bool difftest_step()
{
    // 让REF执行一条指令
    difftest_exec(1);

    // 获取REF的当前状态
    difftest_regcpy(&ref_regs, false);

    // 获取DUT的当前状态
    difftest_get_dut_state();

    // 比对状态
    return difftest_check_state();
}

// 清理DiffTest资源
void difftest_cleanup()
{
    if (difftest_so)
    {
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
bool load_binary_file(const std::string &filename, uint32_t base_addr = 0x80000000)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        std::cerr << "错误: 无法打开文件: " << filename << std::endl;
        return false;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (size == 0)
    {
        std::cerr << "错误: 文件为空: " << filename << std::endl;
        return false;
    }

    size_t word_count = (size + 3) / 4;
    instruction_memory.resize(word_count, 0);

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size))
    {
        std::cerr << "错误: 读取文件失败: " << filename << std::endl;
        return false;
    }

    for (size_t i = 0; i < size; i += 4)
    {
        uint32_t word = 0;
        for (int j = 0; j < 4 && (i + j) < size; j++)
        {
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
    std::cout << "EBREAK指令触发，检查程序状态..." << std::endl;

    // 检查a0寄存器(x10)的值，这是RISC-V中常用的返回值寄存器
    uint32_t return_value = shadow_registers[10]; // a0寄存器

    if (return_value == 0)
    {
        std::cout << "✓ HIT GOOD TRAP: 程序正常结束 (a0 = 0)" << std::endl;
        hit_good_trap = true;
        exit_code = 0;
    }
    else
    {
        std::cout << "✗ BAD TRAP: 程序异常结束 (a0 = " << return_value << ")" << std::endl;
        hit_good_trap = false;
        exit_code = return_value;
    }

    exit1 = true;
}

void print_usage(const char *program_name)
{
    std::cout << "用法: " << program_name << " [选项] [程序文件]" << std::endl;
    std::cout << "选项:" << std::endl;
    std::cout << "  -h, --help     显示此帮助信息" << std::endl;
    std::cout << "  -t, --timeout N 设置仿真超时周期数（默认: 1000）" << std::endl;
    std::cout << "  -v, --verbose   显示详细仿真信息" << std::endl;
    std::cout << "  --no-mem-trace  禁用内存访问跟踪" << std::endl;
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

// 打印当前寄存器状态
void print_current_registers()
{
    printf("当前NPC寄存器状态:\n");
    printf("  PC: 0x%08x\n", ysyx_25050147_top->pc);

    for (int i = 0; i < 32; i += 4)
    {
        printf("  ");
        for (int j = 0; j < 4 && (i + j) < 32; j++)
        {
            int idx = i + j;
            printf("x%2d(%s)=0x%08x ", idx, reg_names[idx], shadow_registers[idx]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    // 默认参数
    std::string program_file = "";
    uint32_t timeout_cycles = 1000000;
    uint32_t no_use = 0;
    bool verbose = false;
#ifdef DIFFTEST
    std::string diff_so_path = "";
    bool enable_difftest = false;
#endif

    // 解析命令行参数
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help")
        {
            print_usage(argv[0]);
            return 0;
        }
        else if (arg == "-t" || arg == "--timeout")
        {
            if (i + 1 < argc)
            {
                no_use = std::stoi(argv[++i]);
            }
            else
            {
                std::cerr << "错误: --timeout 参数需要指定周期数" << std::endl;
                return 1;
            }
        }
        else if (arg == "-v" || arg == "--verbose")
        {
            verbose = true;
        }
        else if (arg == "--no-mem-trace")
        {
            enable_mem_trace = false;
        }
#ifdef DIFFTEST
        else if (arg == "--diff")
        {
            if (i + 1 < argc)
            {
                diff_so_path = argv[++i];
                enable_difftest = true;
            }
            else
            {
                std::cerr << "错误: --diff 参数需要指定动态库路径" << std::endl;
                return 1;
            }
        }
#endif
        else if (arg[0] == '-')
        {
            std::cerr << "错误: 未知选项 " << arg << std::endl;
            print_usage(argv[0]);
            return 1;
        }
        else
        {
            program_file = arg;
        }
    }

    // 初始化内存
    initialize_memory();

    // 初始化阴影寄存器
    memset(shadow_registers, 0, sizeof(shadow_registers));

    // 初始化Verilator
    ysyx_25050147_top = new Vysyx_25050147_top;
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    ysyx_25050147_top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

#ifdef DIFFTEST
    // 初始化DiffTest
    if (enable_difftest)
    {
        if (!difftest_init(diff_so_path.c_str()))
        {
            std::cerr << "DiffTest初始化失败，继续执行但不进行比对" << std::endl;
            enable_difftest = false;
        }
        else
        {
            std::cout << "DiffTest已启用" << std::endl;
        }
    }
#endif

    // 加载程序
    if (!program_file.empty())
    {
        if (!load_binary_file(program_file))
        {
            std::cerr << "警告: 使用默认程序" << std::endl;
            instruction_memory = DEFAULT_PROGRAM;
        }
    }
    else
    {
        std::cout << "未指定程序文件，使用默认程序" << std::endl;
        instruction_memory = DEFAULT_PROGRAM;
    }

    // 使用DPI-C函数将程序加载到内存中
    initialize_memory_with_program();

#ifdef DIFFTEST
    // 同步初始状态到REF
    if (enable_difftest)
    {
        difftest_sync_initial_state();
    }
#endif

    std::cout << "程序大小: " << instruction_memory.size() << " 条指令" << std::endl;
    std::cout << "仿真超时: " << timeout_cycles << " 个周期" << std::endl;
    std::cout << "内存跟踪: " << (enable_mem_trace ? "启用" : "禁用") << std::endl;
    std::cout << "开始仿真..." << std::endl;

    // 复位
    reset(10);

    // 初始化阴影寄存器状态（复位后所有寄存器为0）
    for (int i = 0; i < 32; i++)
    {
        shadow_registers[i] = 0;
    }
    shadow_registers[0] = 0;          // x0 必须为0
    shadow_registers[2] = 0x80009000; // 设置初始栈指针

    // 主仿真循环
    while (!exit1 && sim_time < timeout_cycles)
    {
        ysyx_25050147_top->clk = 0;
        ysyx_25050147_top->eval();
        m_trace->dump(sim_time);
        ysyx_25050147_top->clk = 1;
        ysyx_25050147_top->eval();

        // 检查是否执行到ebreak指令
        // 现在通过读取当前PC地址的指令来检查
        uint32_t current_pc = ysyx_25050147_top->pc;
        uint32_t current_inst = pmem_read_wrapper(current_pc);

        if (current_inst == 0x00100073)
        { // ebreak的指令编码
            if (verbose)
            {
                printf("周期=%lu: 检测到EBREAK指令\n", sim_time);
            }
            notify_ebreak();
        }

        if (verbose)
        {
            printf("周期=%lu, PC=0x%08x, Inst=0x%08x\n",
                   sim_time, current_pc, current_inst);
        }

#ifdef DIFFTEST
        // 执行DiffTest比对
        if (enable_difftest)
        {
            if (!difftest_step())
            {
                printf("DiffTest在周期 %lu 发现错误，停止仿真\n", sim_time);
                break;
            }
        }
#endif

        sim_time++;

        if (sim_time % 1000 == 0)
        {
            printf("仿真进度: %lu/%u 周期\n", sim_time, timeout_cycles);
        }
    }

    ysyx_25050147_top->clk = 0;
    ysyx_25050147_top->eval();
    m_trace->dump(sim_time);
    sim_time++;
    m_trace->dump(sim_time);

    // 仿真结束处理
    if (hit_good_trap)
    {
        std::cout << "🎉 仿真成功: HIT GOOD TRAP!" << std::endl;
        std::cout << "程序正常结束，返回码: " << exit_code << std::endl;
    }
    else if (exit1)
    {
        std::cout << "❌ 仿真失败: BAD TRAP或异常退出" << std::endl;
        std::cout << "退出码: " << exit_code << std::endl;
    }
    else if (sim_time >= timeout_cycles)
    {
        std::cout << "⏰ 仿真超时结束" << std::endl;
    }
    else
    {
        std::cout << "🔍 仿真因DiffTest错误结束" << std::endl;
    }

    std::cout << "总仿真周期: " << sim_time << std::endl;
    std::cout << "最终PC: 0x" << std::hex << ysyx_25050147_top->pc << std::dec << std::endl;

    // 打印最终寄存器状态
    print_current_registers();

#ifdef DIFFTEST
    // 清理DiffTest资源
    if (enable_difftest)
    {
        difftest_cleanup();
    }
#endif

    // 清理资源
    m_trace->close();
    delete ysyx_25050147_top;
    delete m_trace;

    // 清理内存
    cleanup_memory();

    // 根据是否命中GOOD TRAP返回相应的退出码
    return (hit_good_trap && sim_time > 10) ? 0 : 1;
}