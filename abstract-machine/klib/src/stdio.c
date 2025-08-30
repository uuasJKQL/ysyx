#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
void int_to_str(int num, char *str)
{

  int i = 0;
  int is_negative = 0;

  // 处理负数
  if (num < 0)
  {
    is_negative = 1;
    num = -num;
  }

  // 处理0的特殊情况
  if (num == 0)
  {
    str[i++] = '0';
  }
  else
  {
    // 将数字转换为字符串（反向）
    while (num != 0)
    {
      str[i++] = '0' + (num % 10);
      num /= 10;
    }

    // 添加负号（如果需要）
    if (is_negative)
    {
      str[i++] = '-';
    }

    // 反转字符串
    for (int j = 0; j < i / 2; j++)
    {
      char temp = str[j];
      str[j] = str[i - 1 - j];
      str[i - 1 - j] = temp;
    }
  }

  // 添加字符串结束符
  str[i] = '\0';
}
int printf(const char *fmt, ...)
{
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  char *s;
  char *st = out;
  int d;
  char *s1 = "0";
  while (*fmt) // 遍历格式字符串
  {
    switch (*fmt)
    {
    case '%': // 处理字符串参数

      switch (*(++fmt))
      {
      case 's':
        s = va_arg(ap, char *); // 获取char*类型的参数
        strcpy(st, s);
        st += strlen(s);
        break;
      case 'd':
        d = va_arg(ap, int);
        itoa(d, s1, 10);
        strcpy(st, s1);
        st += strlen(s1);
        break;
      case '%':
        *st = *fmt;
        st++;
        break;
      default:
        break;
      }
      break;
    default:

      *st = *fmt;
      st++;
      break;
    }
    fmt++;
  }
  *st = '\0';
  va_end(ap); // 清理工作
  return 1;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
  panic("Not implemented");
}

#endif
