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
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <math.h>
#include <memory/vaddr.h>
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
  static char *line_read = NULL;

  if (line_read)
  {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu)");

  if (line_read && *line_read)
  {
    add_history(line_read);
  }

  return line_read;
}
static int cmd_p(char *args)
{
  bool success = 1;
  uint32_t value = expr(args, &success);
  if (success)
  {
    printf("expr value:0x%08x\n", value);
  }
  else
    assert(0);
  return 0;
}

static int cmd_c(char *args)
{
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args)
{
  nemu_state.state = NEMU_QUIT; // quit
  return -1;
}
static int cmd_si(char *args)
{
  if (args == NULL)
  {
    cpu_exec(1);
    return 0;
  }
  int n = atoi(args);
  cpu_exec(n);
  return 0;
}
static int cmd_info(char *args)
{
  if (!strcmp(args, "r"))
  {
    isa_reg_display();
  }
  if (!strcmp(args, "w"))
  {
    WP *current = head_wp();
    for (int i = 0; i < 31; i++)
    {

      printf("num:%d   address:%s\n", current->NO, current->expr);
      if (current->next == NULL)
      {
        break;
      }
      else
      {
        current = current->next;
      }
    }
  }

  return 0;
}

static int cmd_x(char *args)
{
  char *Nbyte = strtok(args, " ");
  char *point = Nbyte + strlen(Nbyte) + 3;
  int N = atoi(Nbyte);
  int k = strlen(point);
  int p = atoi(point);
  int sum = 0;
  for (int j = 0; j < k; j++)
  {
    sum += p % 10 * 16 * pow(16, j);
    p /= 10;
  }
  for (int i = 0; i < N; i++)
  {
    printf("0x%08x \n", vaddr_read(sum + 4 * i, 4));
  }
  return 0;
}
static int cmd_w(char *args)
{
  WP *wp = new_wp();
  assert(wp != NULL);
  strcpy(wp->expr, args);
  bool success = 1;
  wp->val = expr(wp->expr, &success);
  assert(success);
  printf("watchpoint %d:%s\n", wp->NO, wp->expr);

  return 0;
}
static int cmd_d(char *args)
{
  free_wp(atoi(args));
  printf(" delete watchpoint %d\n", atoi(args));
  return 0;
}
static int cmd_help(char *args);

static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "singal step", cmd_si},
    {"info", "show rgister or monitor", cmd_info},
    {"x", "Scan memory", cmd_x},
    {"w", "watchpoints", cmd_w},
    {"d", "delete watchpoints", cmd_d},
    {"p", "expr ", cmd_p}
    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL)
  {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++)
    {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else
  {
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(arg, cmd_table[i].name) == 0)
      {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode()
{
  is_batch_mode = true;
}

void sdb_mainloop()
{
  if (is_batch_mode)
  {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;)
  {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end)
    {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(cmd, cmd_table[i].name) == 0)
      {
        if (cmd_table[i].handler(args) < 0)
        {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD)
    {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb()
{
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
