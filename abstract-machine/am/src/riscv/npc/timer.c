#include <am.h>
#define RTC_ADDR 0xa0000048
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }
static uint64_t boot_time = 0;
static uint64_t read_time()
{
  uint32_t hi, lo, hi2;

  do
  {
    hi =inl( RTC_ADDR + 4); 
    lo = inl(RTC_ADDR);     
    hi2 =inl(RTC_ADDR + 4);
  } while (hi != hi2); 

  return ((uint64_t)hi << 32) | lo;
}
void __am_timer_init() {
  boot_time = read_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_time() - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
