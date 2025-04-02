#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

// PS/2 键盘扫描码定义
#define MAKE_Q 0x15       // Q 键按下码
#define BREAK_PREFIX 0xF0 // 释放键前缀

class PS2Sim
{
private:
    vluint64_t timestep;
    Vtop *dut;
    bool ps2_clk;
    bool ps2_data;

    void clock_pulse()
    {
        dut->ps2_clk = 1;
        dut->eval();
        timestep += 5;
        dut->ps2_clk = 0;
        dut->eval();
        timestep += 5;
    }

public:
    PS2Sim(Vtop *_dut) : dut(_dut), ps2_clk(1), ps2_data(1), timestep(0) {}

    // 发送单个字节（包含起始位、奇偶校验、停止位）
    void send_byte(uint8_t data)
    {
        // 起始位 (0)
        ps2_data = 0;
        clock_pulse();

        // 数据位 (LSB first)
        uint8_t parity = 1;
        for (int i = 0; i < 8; ++i)
        {
            bool bit = data & (1 << i);
            ps2_data = bit;
            parity ^= bit;
            clock_pulse();
        }

        // 奇偶校验位
        ps2_data = parity;
        clock_pulse();

        // 停止位 (1)
        ps2_data = 1;
        clock_pulse();
    }

    // 发送按键动作（按下/释放）
    void send_key(uint8_t make, bool is_press)
    {
        if (!is_press)
        {
            send_byte(BREAK_PREFIX);
        }
        send_byte(make);
    }
};

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vtop *dut = new Vtop;

    // 初始化波形追踪
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    // 初始化信号
    dut->clk = 0;
    dut->clrn = 0; // 先复位
    dut->ps2_clk = 1;
    dut->ps2_data = 1;
    dut->nextdata = 0;

    // 复位操作
    for (int i = 0; i < 10; ++i)
    {
        dut->clk = !dut->clk;
        dut->eval();
        tfp->dump(i * 10);
    }
    dut->clrn = 1; // 结束复位

    PS2Sim ps2(dut);

    // 模拟 10 次 Q 键按下松开
    for (int rep = 0; rep < 10; ++rep)
    {
        // 按下 Q
        ps2.send_key(MAKE_Q, true);
        // 松开 Q
        ps2.send_key(MAKE_Q, false);

        // 间隔 100 个时钟周期
        for (int i = 0; i < 100; ++i)
        {
            dut->clk = !dut->clk;
            dut->eval();
            tfp->dump(100 * rep + i * 10 + 1000);
        }
    }

    // 清理
    tfp->close();
    delete dut;
    return 0;
}