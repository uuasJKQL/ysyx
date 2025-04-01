#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"          // Verilator生成的头文件
#include "verilated.h"     // Verilator核心头文件
#include "verilated_vcd_c.h"
int main(int argc, char** argv) {
    // Verilator环境初始化
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};  // 实例化DUT
  // --- 新增：初始化波形跟踪 ---
    Verilated::traceEverOn(true);      // 启用跟踪功能
    VerilatedVcdC* tfp = new VerilatedVcdC; // 创建跟踪对象
    top->trace(tfp, 99);               // 跟踪模块所有信号（层级深度99）
    tfp->open("waveform.vcd");         // 指定输出波形文件名
    // ---------------------------

    // 初始化随机种子
    srand(time(nullptr));

    // 运行100次随机测试
    for (int i = 0; i < 100; ++i) {
        int a = rand() & 1;  // 生成0或1
        int b = rand() & 1;

        // 驱动输入信号
        top->a = a;
        top->b = b;

        // 评估电路
        top->eval();
        // --- 新增：记录波形 ---
        tfp->dump(contextp->time());   // 记录当前时间点的信号值
        contextp->timeInc(1);          // 时间步进（单位可选，如1ns）
        // ---------------------

        // 打印结果
        printf("[Test %2d] a = %d, b = %d, f = %d\n", i+1, a, b, top->f);

        // 验证异或逻辑
        assert(top->f == (a ^ b));
    }
    // --- 新增：关闭跟踪 ---
    tfp->close();
    delete tfp;
    // ---------------------
    // 清理资源
    delete top;
    delete contextp;

    printf("\nAll tests passed!\n");
    return 0;
}
