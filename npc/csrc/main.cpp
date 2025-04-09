#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"      // Verilator生成的头文件
#include "verilated.h" // Verilator核心头文件
#include "verilated_vcd_c.h"
#include <nvboard.h>
#include <nvboard.h>
#include <Vtop.h>

static TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME* top);
static void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}
static void reset(int n) {
  top.clrn =0;
  while (n -- > 0) single_cycle();
  top.clrn = 1;
}




int main() {
  nvboard_bind_all_pins(&top);
  nvboard_init();

    reset(10);


  while(1) {
    nvboard_update();
    single_cycle();
  }
}
