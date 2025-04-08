#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

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
    dut->clk = 0;

    dut->eval();
    dut->ps2_clk = 0; // 起始位

    tfp->dump(time);
    time += 5;
    dut->ps2_data = 0;
    dut->eval();
    tfp->dump(time);
    time += 5;
    dut->clk = 1;
    time += 1;
    dut->ps2_clk = 1;
    dut->eval();
    tfp->dump(time);
    time += 5;

    // 数据位（BREAK_PREFIX 0xF0）
    uint8_t data = break_prefix;
    for (int i = 0; i < 400; ++i)
    {
        if (count == 50)
        {
            dut->ps2_clk = !dut->ps2_clk;
        }
        int count = 0;
        count++ dut->clk = !dut->clk;
        time += 5;
        count += 1;
        //   dut->ps2_data = (data >> i) & 1;
    }

    // ... 类似地完成完整的数据传输 ...

    // 清理
    tfp->close();
    delete dut;
    return 0;
}
