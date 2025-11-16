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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <ctype.h>
#include <memory/vaddr.h>
const char *reg_name[] =
    {
        "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
        "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
        "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
        "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6", "pc"};
enum
{
  TK_NOTYPE = 256,

  TK_number,
  TK_U,
  TK_EQ,
  TK_NEQ,
  TK_AND,
  TK_REG,
  TK_HEX,
  TK_DEREF

  /* TODO: Add more token types */

};

static struct rule
{
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces
    {"\\+", '+'},      // plus
    {"==", TK_EQ},     // equal //N
    {"!=", TK_NEQ},    // N
    {"&&", TK_AND},    // N
    {"0[Xx][0-9a-fA-F]+", TK_HEX},
    {"[0-9]+", TK_number},
    {"\\$[A-Za-z0-9]+", TK_REG},

    {"\\(", '('},
    {"\\)", ')'},
    {"-", '-'},
    {"\\*", '*'},
    {"/", '/'},
    {"u", TK_U}};
// 42,43,45,47,259-261
#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */

void init_regex()
{
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++)
  {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0)
    {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token
{
  int type;

  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;
void find_main_op(int a, int b, int p, int q, int *op_type, int *op_p, bool *op_f)
{
  for (int i = q; i >= p; i--)
  {
    bool op_true = 1;
    if (tokens[i].type == a || tokens[i].type == b)
    {
      int pare_sum = 0;
      for (int j = 1; j <= i - p; j++)
      {
        if (tokens[i - j].type == ')')
        {
          pare_sum--;
        }
        else if (tokens[i - j].type == '(')
        {
          pare_sum++;
        }
      }
      if (pare_sum > 0)
      {
        op_true = 0;
      }
      if (op_true)
      {
        *op_f = 1;
        *op_type = tokens[i].type;
        *op_p = i;
        break;
      }
    }
  }
}
bool check_parentheses(int p, int q)
{
  bool parentheses = 0;
  int p_sum = 0;
  if (tokens[p].type == '(' && tokens[q].type == ')')
  {
    parentheses = 1;
    for (int i = p; i < q; i++)
    {
      if (tokens[i].type == '(')
      {
        p_sum++;
      }
      else if (tokens[i].type == ')')
      {
        p_sum--;
      }
      if (p_sum == 0)
        parentheses = 0;
      else if (p_sum < 0)
      {
        printf("bad expresson");
        assert(0);
      }
    }
    if (p_sum > 1)
    {
      printf("bad expresson");
      assert(0);
    }

    return parentheses;
  }

  return false;
}

static bool make_token(char *e)
{
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0')
  {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++)
    {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
      {
        // char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //  i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type)
        {
        case TK_NOTYPE:
          nr_token--;
          break;
        case TK_U:
          nr_token--;
          break;
        case TK_EQ:
          tokens[nr_token].type = TK_EQ;
          strcpy(tokens[nr_token].str, "==");
          break;
        case TK_number:
          tokens[nr_token].type = TK_number;
          strncpy(tokens[nr_token].str, e + position - substr_len, substr_len);
          break;
        case TK_HEX:
          tokens[nr_token].type = TK_HEX;
          strncpy(tokens[nr_token].str, e + position - substr_len, substr_len);
          break;
        case TK_REG:
          tokens[nr_token].type = TK_REG;
          strncpy(tokens[nr_token].str, e + position - substr_len, substr_len);
          break;
        case '+':
          tokens[nr_token].type = '+';
          strcpy(tokens[nr_token].str, "+");
          break;
        case '(':
          tokens[nr_token].type = '(';
          strcpy(tokens[nr_token].str, "(");
          break;
        case ')':
          tokens[nr_token].type = ')';
          strcpy(tokens[nr_token].str, ")");
          break;
        case '-':
          tokens[nr_token].type = '-';
          strcpy(tokens[nr_token].str, "-");
          break;
        case '*':
          tokens[nr_token].type = '*';
          strcpy(tokens[nr_token].str, "*");
          break;
        case '/':
          tokens[nr_token].type = '/';
          strcpy(tokens[nr_token].str, "/");
          break;
        case TK_NEQ:
          tokens[nr_token].type = TK_NEQ;
          strcpy(tokens[nr_token].str, "!=");
          break;
        case TK_AND:
          tokens[nr_token].type = TK_AND;
          strcpy(tokens[nr_token].str, "&&");
          break;
        default:
          printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
        }
        nr_token++;
        break;
      }
    }

    if (i == NR_REGEX)
    {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      position++;
      //   return false;
    }
  }

  return true;
}
uint32_t eval(int p, int q)
{
  int op_type = 0;
  int op_p = 0;
  bool op_f = 0;

  if (p > q)
  {
    printf("error :p>q\n");
    printf("p%d\n", p);
    printf("q%d\n", q);
    return false;
  }
  else if (p == q)
  {
    switch (tokens[p].type)
    {
    case TK_HEX:
    {
      char *hex = tokens[p].str + 2;
      uint32_t val = 0;
      for (; *hex; ++hex)
      {
        uint8_t byte = (uint8_t)*hex;
        // 统一转换为大写处理
        if (isalpha(byte))
        {
          byte = toupper(byte);
        }
        // 字符转数值 (0-15)
        val = (val << 4) | ((byte & 0xF) + (byte > '9' ? 9 : 0));
      }
      return val;
    }
    case TK_number:
      return atoi(tokens[q].str);
    case TK_REG:
    {
      char *rn = tokens[p].str;
      rn++;
      for (int i = 0; i < 33; i++)
      {

        if (strcmp(reg_name[i], rn) == 0 || strcmp("0", rn) == 0)
        {
          if (strcmp("pc", rn) == 0)
            return cpu.pc;
          else
            return cpu.gpr[i];
        }
      }

      printf("reg not found");
      return 0;
    }
    }
    return atoi(tokens[q].str);
  }
  else if (check_parentheses(p, q) == true)
  {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }

  else
  {
    find_main_op(TK_AND, TK_AND, p, q, &op_type, &op_p, &op_f);
    if (!op_f)
      find_main_op(TK_EQ, TK_NEQ, p, q, &op_type, &op_p, &op_f);
    if (!op_f)
      find_main_op('+', '-', p, q, &op_type, &op_p, &op_f);
    if (!op_f)
      find_main_op('*', '/', p, q, &op_type, &op_p, &op_f);
    if (!op_f)
      find_main_op(TK_DEREF, TK_DEREF, p, q, &op_type, &op_p, &op_f);
    // printf("op position and optype:%d and %d\n", op_p, op_type);
    uint32_t val1 = 0;
    if (op_type != TK_DEREF)
    {
      val1 = eval(p, op_p - 1);
    }
    uint32_t val2 = eval(op_p + 1, q);

    switch (op_type)
    {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2; /* ... */
    case '*':
      return val1 * val2; /* ... */
    case '/':
      return val1 / val2; /* ... */
    case TK_AND:
      return val1 && val2;
    case TK_NEQ:
      return val1 != val2;
    case TK_EQ:
      return val1 == val2;
    case TK_DEREF:
      return vaddr_read(val2, 4);
    default:
      assert(0);
    }
  }
}

word_t expr(char *e, bool *success)
{
  // printf("%s\n", e);
  if (!make_token(e))
  {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  // printf("result:%d\n",eval(0,nr_token-1));
  for (int i = 0; i < nr_token; i++)
  {
    if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type <= 47 && tokens[i - 1].type >= 43) || (tokens[i - 1].type >= 259 && tokens[i - 1].type <= 261)))
    {
      tokens[i].type = TK_DEREF;
    }
  }

  return eval(0, nr_token - 1);
}
