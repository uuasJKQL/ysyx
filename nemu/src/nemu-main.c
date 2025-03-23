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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
word_t expr(char *e, bool *success);
int is_exit_status_bad();

char*temp;
bool a;
bool *s=&a;
uint32_t result ;
char line[1024*1025];
char expressions[1024*1024];
int error_counter=0;
int line_i=0;
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
FILE *fp;
 fp = fopen("tools/gen-expr/build/input", "r");
   if(fp == NULL) {
      perror("打开文件时发生错误");
      return(-1);
   }

while (fgets(line, sizeof(line), fp)) {
        // 去除换行符
        line[strcspn(line, "\n")] = '\0';

        // 找到第一个空格位置
        char *space_pos = strchr(line, ' ');
        if (!space_pos) {
            fprintf(stderr, "格式错误\n");
            continue;
        }

        // 分割左右部分
        *space_pos = '\0'; // 切割字符串
        result= atoi(line); // 转换左侧数字

        // 提取右侧表达式
        char *exprp = space_pos + 1;
        strcpy(expressions,exprp); // 复制字符串
      printf("%s\n",expressions);
        if(expr(expressions,s)!=result)
     error_counter++  ;
     else
     printf("pass:%d \n",line_i);;
line_i++;
      }
 fclose(fp);
printf("error num:%d",error_counter);
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
