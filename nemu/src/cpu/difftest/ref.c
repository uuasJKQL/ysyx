/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

// 内存同步函数：在NPC和NEMU之间同步内存数据
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
  if (direction == DIFFTEST_TO_REF)
  {
    // 从DUT(NPC)复制到REF(NEMU) - 将NPC的内存数据写入NEMU
    uint8_t *data = (uint8_t *)buf;
    for (size_t i = 0; i < n; i++)
    {
      paddr_write(addr + i, 1, data[i]); // 逐字节写入NEMU内存
    }
  }
  else
  {
    // 从REF(NEMU)复制到DUT(NPC) - 从NEMU内存读取数据到NPC
    uint8_t *data = (uint8_t *)buf;
    for (size_t i = 0; i < n; i++)
    {
      data[i] = paddr_read(addr + i, 1); // 逐字节从NEMU内存读取
    }
  }
}

// 寄存器同步函数：在NPC和NEMU之间同步寄存器状态
__EXPORT void difftest_regcpy(CPU_state *dut, bool direction)
{
  CPU_state *ctx = dut;

  if (direction == DIFFTEST_TO_REF)
  {
    // 从NPC设置NEMU寄存器
    for (int i = 0; i < 32; i++)
    {
      cpu.gpr[i] = ctx->gpr[i];
    }
    // cpu.csr[0] = ctx->csr[0];
    cpu.pc = ctx->pc;
  }
  else
  {
    // 从NEMU读取寄存器到NPC
    for (int i = 0; i < 32; i++)
    {
      ctx->gpr[i] = cpu.gpr[i];
    }

    ctx->pc = cpu.pc;
  }
}
// 执行函数：让NEMU执行指定数量的指令
__EXPORT void difftest_exec(uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    // 执行一条指令
    cpu_exec(1);
  }
}

// 中断处理函数：处理中断（目前简单实现，后续可扩展）
__EXPORT void difftest_raise_intr(word_t NO)
{
  // 目前简单实现，实际使用时需要根据中断号NO进行相应处理
  // 可以设置中断相关寄存器或触发中断处理逻辑
  // printf("Interrupt raised: %d\n", NO);
}

__EXPORT void difftest_init(int port)
{
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
