#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  uint32_t keycode = inl(0xa0000060);

  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  }
  else
  {
    if (keycode & KEYDOWN_MASK)
    {
      // 按键释放，最高位为1
      kbd->keydown = 0;
      kbd->keycode = keycode & ~KEYDOWN_MASK; // 去掉最高位
    }
    else
    {
      // 按键按下，最高位为0
      kbd->keydown = 1;
      kbd->keycode = keycode;
    }
  }
}
