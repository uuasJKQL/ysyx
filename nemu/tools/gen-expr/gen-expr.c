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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
// this should be enough
static char buf[1024*1024] = {};
static char code_buf[1024*1024+ 128] = {}; // a little larger than `buf`
uint32_t count=0;
bool is_full=0;
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
uint32_t choose (uint32_t n)
{

return rand()%n;
}
void gen_rand_op()
{if(count>=1024*1024-1)
{
  is_full=1;
}
else{

  switch (choose(4))
{
case 0:
  buf[count]= '+';
 break;
case 1:
buf[count]= '-';
break;
case 2:
buf[count]= '*';
break;
default:
buf[count]= '/';
break;
}

count++;
}
}

void gen_num()
{if(count>=1024*1024-2)
  {
    is_full=1;
  }
  else{

  buf [count]=('0'+choose(10));
buf[count+1]='u';
  count+=2;

  }}
void gen(char n)
{if(count>=1024*1024-1)
  {
    is_full=1;
  }
  else{
  buf[count]=n;
  count++;
}}
static bool gen_rand_expr(int depth) 
{depth++;
  if(depth>10)
  {return 0;}
if(!choose(9))
{  buf[count]=' ';
 count++ ;
}
  
  switch (choose(3)) {
  case 0: gen_num(); break;
  case 1: gen('('); gen_rand_expr(depth); gen(')'); break;
  default: gen_rand_expr(depth); gen_rand_op(); gen_rand_expr(depth);break;
  }
  return 1;
}

  


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 1; i < loop+1; i ++) {
    for (int i = 0; i < sizeof(buf)/sizeof(buf[0]); i++) {
      buf[i] = '\0';
  }
  is_full=0;
    count =0;
    if(!gen_rand_expr(0))
    { i--;
      continue;}

if(is_full)
{ i--;
  continue;}
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0)
    {i--;
       continue;
    }
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
