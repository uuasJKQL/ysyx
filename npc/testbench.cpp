#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

#define MAKE_Q 0x15
#define BREAK_PREFIX 0xF0

class PS2Sim {
private:
    vluint64_t timestep;
    Vtop* dut;
    VerilatedVcdC* tfp;
    bool ps2_clk;

    void clock_pulse() {
        // 时钟上升沿
        dut->ps2_clk = 1;
        dut->eval();
        tfp->dump(timestep);
        timestep += 5;
        
        // 时钟下降沿
        dut->ps2_clk = 0;
        dut->eval();
        tfp->dump(timestep);
        timestep += 5;
    }

public:
    PS2Sim(Vtop* _dut, VerilatedVcdC* _tfp) 
        : dut(_dut), tfp(_tfp), ps2_clk(1), timestep(0) {
        dut->ps2_clk = 1;
        dut->ps2_data = 1;
    }

    void send_byte(uint8_t data) {
        std::cout << "Sending byte: 0x" << std::hex << (int)data << std::endl;

        // 起始位
        dut->ps2_data = 0;
        clock_pulse();

        // 数据位 (LSB first)
        uint8_t parity = 1;
        for (int i = 0; i < 8; ++i) {
            bool bit = data & (1 << i);
            dut->ps2_data = bit;
            parity ^= bit;
            clock_pulse();
        }

        // 奇偶校验位
        dut->ps2_data = parity;
        clock_pulse();

        // 停止位
        dut->ps2_data = 1;
        clock_pulse();
    }

    void send_key(uint8_t make, bool is_press) {
        std::cout << (is_press ? "Key DOWN" : "Key UP") 
                  << " code: 0x" << std::hex << (int)make << std::endl;
        
        if (!is_press) {
            send_byte(BREAK_PREFIX);
        }
        send_byte(make);
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtop* dut = new Vtop;

    // 波形初始化
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    // 全局时间管理
    vluint64_t global_time = 0;

    // 初始化信号
    dut->clk = 0;
    dut->clrn = 0;
    dut->ps2_clk = 1;
    dut->ps2_data = 1;
    dut->nextdata = 0;

    // 复位序列（10个时钟周期）
    for (int i = 0; i < 10; ++i) {
        dut->clk = !dut->clk;
        dut->eval();
        tfp->dump(global_time);
        global_time += 10;
    }
    dut->clrn = 1;

    PS2Sim ps2(dut, tfp);

    // 主测试序列
    for (int rep = 0; rep < 3; ++rep) {  // 测试3次循环
        // 发送按键按下
        ps2.send_key(MAKE_Q, true);
        
        // 等待100时钟周期
        for (int i = 0; i < 100; ++i) {
            dut->clk = !dut->clk;
            dut->eval();
            tfp->dump(global_time);
            global_time += 10;
        }

        // 发送按键释放
        ps2.send_key(MAKE_Q, false);

        // 等待100时钟周期
        for (int i = 0; i < 100; ++i) {
            dut->clk = !dut->clk;
            dut->eval();
            tfp->dump(global_time);
            global_time += 10;
        }
    }

    // 清理
    tfp->close();
    delete dut;
    std::cout << "Simulation completed" << std::endl;
    return 0;
}
