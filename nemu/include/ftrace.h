#include <stdint.h>
#ifndef ftrace_H
#define ftrace_H

// 定义结构体类型
struct ftrace_data
{
    uint32_t pc_value[1024];
    char *name[1024];
    uint32_t size[1024];
    uint32_t num;
};
// 声明全局变量为extern，表示它在其他地方定义
extern struct ftrace_data func_tab;

#endif