#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vysyx_25050147_top.h" // Verilator生成的头文件
#include "verilated.h"          // Verilator核心头文件
#include "verilated_vcd_c.h"
#include "Vysyx_25050147_top__Dpi.h"
#include "svdpi.h"
static Vysyx_25050147_top *ysyx_25050147_top;
vluint64_t sim_time = 0; // 用于计数时钟边沿
int inst[20] = {
    0x00500093, // addi x1, x0, 5   (机器码: 0x00500093)
    0x00700113, // addi x2, x0, 7   (机器码: 0x00700113)
    0x00508113, // addi  x2, x1,5  (机器码: 0x002081b3)
    0x00100073};
bool exit1 = 0;
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
int pmem_read(int n)
{
  return inst[(n - 0x80000000) / 4];
}
void notify_ebreak()
{
  // 打印调试信息（可选）
  // vpi_printf("EBREAK triggered: Simulation finished by DPI-C call.\n");
  exit1 = 1;
  // 结束仿真（标准 VPI 方法）
}
int main()
{
  ysyx_25050147_top = new Vysyx_25050147_top; // 必须创建实例!
  Verilated::traceEverOn(true);
  VerilatedVcdC *m_trace = new VerilatedVcdC;
  ysyx_25050147_top->trace(m_trace, 5);
  m_trace->open("waveform.vcd");

  reset(10);

  while (!exit1)
  {
    ysyx_25050147_top->mem = pmem_read(ysyx_25050147_top->pc);
    single_cycle();
    m_trace->dump(sim_time);
    sim_time++; // 更新仿真时间
    printf("PC=0x%08x \n", ysyx_25050147_top->pc);
  }
  m_trace->close();
  delete ysyx_25050147_top;
  return 0;
}
// #include "Vour.h"
// #include "verilated.h"
// int main(int argc, char **argv)
// {
//   VerilatedContext *contextp = new VerilatedContext;
//   contextp->commandArgs(argc, argv);
//   Vour *top = new Vour{contextp};
//   while (!contextp->gotFinish())
//   {
//     top->eval();
//   }
//   delete top;
//   delete contextp;
//   return 0;
// }
