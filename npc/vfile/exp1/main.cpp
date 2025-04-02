#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"      // Verilator生成的头文件
#include "verilated.h" // Verilator核心头文件
#include "verilated_vcd_c.h"
#include <nvboard.h>
static TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME *top);


int main()
{
  nvboard_bind_all_pins(&top);
  nvboard_init();

  while (1)
  {
    top.eval();
    nvboard_update();
  }
  return 0;
}
