#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s)
{
  size_t i = 0;
  while (s[i])
  {
    i++;
  }
  return i;
}

char *strcpy(char *dst, const char *src)
{
  int i = 0;

  while (src[i])
  {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n)
{
  panic("Not implemented");
}

char *strcat(char *dst, const char *src)
{
  int i = 0;
  int p = strlen(dst);
  while (src[i])
  {
    dst[p + i] = src[i];
    i++;
  }
  dst[p + i] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2)
{
  int i = 0;
  while (1)
  {
    if ((s1[i] - s2[i]) != 0)
      return s1[i] - s2[i];
    else if (s1[i] == 0 && s2[i] == 0)
      return 0;
    i++;
  }

  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n)
{
  unsigned char *p = s;

  for (int i = 0; i < n; i++)
  {
    *(p + i) = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n)
{
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n)
{
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n)
{
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;

  for (int i = 0; i < n; i++)
  {
    if (*(p1 + i) < *(p2 + i))
    {
      return -1;
    }
    else if (*(p1 + i) > *(p2 + i))
    {
      return 1;
    }
  }
  return 0;
}

#endif
