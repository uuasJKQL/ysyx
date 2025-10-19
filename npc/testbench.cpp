#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
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
        // 这样可以安全地停止仿真
        return 0x00100073;
    }
}

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
    
    // 计算需要多少32位字
    size_t word_count = (size + 3) / 4; // 向上取整
    
    instruction_memory.resize(word_count, 0);
    
    // 读取数据
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        std::cerr << "错误: 读取文件失败: " << filename << std::endl;
        return false;
    }
    
    // 将字节数据转换为32位字（小端序）
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

// 打印使用说明
void print_usage(const char* program_name)
{
    std::cout << "用法: " << program_name << " [选项] [程序文件]" << std::endl;
    std::cout << "选项:" << std::endl;
    std::cout << "  -h, --help     显示此帮助信息" << std::endl;
    std::cout << "  -t, --timeout N 设置仿真超时周期数（默认: 1000）" << std::endl;
    std::cout << "  -v, --verbose   显示详细仿真信息" << std::endl;
    std::cout << "示例:" << std::endl;
    std::cout << "  " << program_name << " add-riscv32e-npc.bin" << std::endl;
    std::cout << "  " << program_name << " -t 2000 program.bin" << std::endl;
}

int main(int argc, char** argv)
{
    // 默认参数
    std::string program_file = "";
    uint32_t timeout_cycles = 1000;
    bool verbose = false;
    
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
    Verilated::commandArgs(argc, argv); // 传递参数给Verilator
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    ysyx_25050147_top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

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
        
        sim_time++;
        ysyx_25050147_top->mem= pmem_read(ysyx_25050147_top->pc);
        // 每1000周期显示一次进度
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
    }
    
    std::cout << "总仿真周期: " << sim_time << std::endl;
    std::cout << "最终PC: 0x" << std::hex << ysyx_25050147_top->pc << std::dec << std::endl;
    
    // 清理资源
    m_trace->close();
    delete ysyx_25050147_top;
    delete m_trace;
    
    return 0;
}
