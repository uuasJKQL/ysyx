#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
// 主时钟周期：10 个单位时间（高电平 5，低电平 5）
const int MAIN_CLK_HALF_PERIOD = 5;

// PS/2 时钟周期：20 个单位时间（高电平 10，低电平 10）
const int PS2_CLK_HALF_PERIOD = 10;
int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vtop *dut = new Vtop;

    // 波形初始化
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    // 基础信号初始化
    vluint64_t time = 0;
    dut->clk = 0;
    dut->clrn = 0;
    dut->ps2_clk = 1;
    dut->ps2_data = 1;
    //  dut->nextdata = 1;

    // 复位序列 (10个时钟周期)
    for (int i = 0; i < 10; ++i)
    {
        dut->clk = !dut->clk;
        dut->eval();
        tfp->dump(time);
        time += 10;
    }
    dut->clrn = 1;

    // 模拟发送Q键扫描码
    const uint8_t make_code = 0x15;
    const uint8_t break_prefix = 0xF0;

    // 发送按键按下
    // 发送BREAK前缀
    // PS/2 时钟手动控制示例
    dut->ps2_clk = 0; // PS/2 起始位低电平
    dut->eval();
    tfp->dump(time);
    time += PS2_CLK_HALF_PERIOD; // 保持低电平 10 单位

    dut->ps2_clk = 1; // PS/2 高电平
    dut->eval();
    tfp->dump(time);
    time += PS2_CLK_HALF_PERIOD; // 保持高电平 10 单位

    // 主时钟自动周期（10 单位周期）
    dut->clk = !dut->clk; // 每次翻转主时钟
    dut->eval();
    tfp->dump(time);
    time += MAIN_CLK_HALF_PERIOD; // 主时钟半周期 5 单位
    // 数据位（BREAK_PREFIX 0xF0）
    uint8_t data = break_prefix;
    for (int i = 0; i < 8; ++i)
    {

        // dut->ps2_data = (data >> i) & 1;
        dut->ps2_clk = 0; // PS/2 起始位低电平
        dut->eval();
        tfp->dump(time);
        time += PS2_CLK_HALF_PERIOD; // 保持低电平 10 单位

        dut->ps2_clk = 1; // PS/2 高电平
        dut->eval();
        tfp->dump(time);
        time += PS2_CLK_HALF_PERIOD; // 保持高电平 10 单位

        // 主时钟自动周期（10 单位周期）
        dut->clk = !dut->clk; // 每次翻转主时钟
        dut->eval();
        tfp->dump(time);
        time += MAIN_CLK_HALF_PERIOD; // 主时钟半周期 5 单位
    }

    // ... 类似地完成完整的数据传输 ...

    // 清理
    tfp->close();
    delete dut;
    return 0;
}
