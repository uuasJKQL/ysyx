#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c)
{
  if (user_handler)
  {
    Event ev = {0};
    switch (c->mcause)
    {
    case 0x0000000b:
      ev.event = EVENT_YIELD;
      break;
    default:
      ev.event = EVENT_ERROR;
      break;
    }

    // 调试输出：打印上下文内容
    // printf("===== Context Dump (mcause: 0x%x) =====\n", c->mcause);
    // printf("mepc:   0x%x\n", c->mepc);
    // printf("mcause: 0x%x\n", c->mcause);
    // printf("mstatus:0x%x\n", c->mstatus);

    // // 打印所有寄存器（可选，输出较多）

    // printf("All registers:\n");
    // for (int i = 0; i < NR_REGS; i++)
    // {
    //   if (i != 0)
    //     printf("  x%d: 0x%x\n", i, c->gpr[i]);
    // }

    // printf("===================================\n");

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *))
{
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
  // Context结构体在kstack.end处
  Context *ctx = (Context *)kstack.end - 1;
  // 指向Context的指针cp在kstack.start处

  Context **cp = (Context **)kstack.start;
  *cp = ctx;

  // 初始化通用寄存器为0
  for (int i = 0; i < NR_REGS; i++)
  {
    ctx->gpr[i] = 0;
  }

  // 设置参数寄存器（根据RISC-V调用约定，a0寄存器用于传递第一个参数）
  // 假设a0是gpr[10]，具体索引取决于NR_REGS的定义
  ctx->gpr[10] = (uintptr_t)arg;

  // 设置栈指针（假设sp是gpr[2]）
  // 栈指针指向kstack.start之后的位置，跳过cp指针
  ctx->gpr[2] = (uintptr_t)ctx;

  // 设置入口地址
  ctx->mepc = (uintptr_t)entry;
  // printf("kstack.start: %x, kstack.end: %x, ctx: %x,cp:%x,sp:%x\n", kstack.start, kstack.end, ctx, cp, ctx->gpr[2]);
  //  初始化其他状态寄存器
  ctx->mcause = 0;
  ctx->mstatus = 0x1800;
  ctx->pdir = NULL;

  return ctx;
}

void yield()
{
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled()
{
  return false;
}

void iset(bool enable)
{
}
