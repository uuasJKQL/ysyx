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

enum {
  TK_NOTYPE = 256, TK_EQ,TK_number,TK_U,TK_NEQ,TK_AND,TK_REG,TK_HEX,TK_P

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
  {"!=",TK_NEQ},
  {"&&",TK_AND},
  {"[0-9]+",TK_number},
  {"\\$[A-Za-z]\\d+",TK_REG},
  {"0[xX][0-9a-fA-F]+",TK_HEX},
  {"\\(",'('},
  {"\\)",')'},
  {"-",'-'},
  {"\\*",'*'},
  {"/",'/'},
{"u",TK_U}
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */

void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;

  char str[32];
} Token;
//( 9*9-(7)-2-7)/(((1)) )
static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
bool check_parentheses(int p,int q)
{bool parentheses=0;
  int p_sum=0;
  if(tokens[p].type=='('&&tokens[q].type==')')
  {parentheses=1;
    for(int i=p;i<q;i++)
  {if(tokens[i].type=='(')
{p_sum++;

}
else if(tokens[i].type==')')
{p_sum--;}
if(p_sum==0)
parentheses=0;
else if(p_sum<0)
{
  printf("bad expresson");
  assert(0);
}
}
if(p_sum>1)
{
  printf("bad expresson");
  assert(0);
}

return parentheses;
 
}
  
  return false;
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE:
                  nr_token--;
                     break ;
          case TK_U:
          nr_token--;
          break;
            case TK_EQ:tokens[nr_token].type=TK_number;
               strcpy(tokens[nr_token].str,"==");
              break;
          case TK_number:tokens[nr_token].type=TK_number;
                   strncpy(tokens[nr_token].str,e+position-substr_len,substr_len);
                  break;
           case TK_HEX:   tokens[nr_token].type=TK_HEX;
           strncpy(tokens[nr_token].str,e+position-substr_len,substr_len);   
           case TK_REG:   tokens[nr_token].type=TK_REG;
           strncpy(tokens[nr_token].str,e+position-substr_len,substr_len);   
            
          case  '+': tokens[nr_token].type='+';
                   strcpy(tokens[nr_token].str,"+");
                     break;
          case  '(': tokens[nr_token].type='(';
                   strcpy(tokens[nr_token].str,"(");
                     break;
         case  ')': tokens[nr_token].type=')';
                   strcpy(tokens[nr_token].str,")");
                     break;
          case  '-': tokens[nr_token].type='-';
                     strcpy(tokens[nr_token].str,"-");
                      break;   
          case  '*': tokens[nr_token].type='*';
                      strcpy(tokens[nr_token].str,"*");
                         break;
          case  '/': tokens[nr_token].type='/';
                      strcpy(tokens[nr_token].str,"/");
                      break;            
          case  TK_NEQ: tokens[nr_token].type=TK_NEQ;
                      strcpy(tokens[nr_token].str,"!=");
                      break;                   
           case  TK_AND: tokens[nr_token].type=TK_AND;
                      strcpy(tokens[nr_token].str,"&&");
                      break;   
          default: printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
        }
nr_token++;
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      position++;
   //   return false;
    }
  }

  return true;
}
uint32_t eval(int p, int q) 
{
  int op_type=0;
  int op_p=0;
  bool op_f=0;
  
  if (p > q) {
   printf("error :p>q\n");
   printf("p%d\n",p);
   printf("q%d\n",q);
    return false;
  }
  else if (p == q) {
    return atoi(tokens[q].str);
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  
  else {
    for(int i=q;i>=p;i--)
    {bool op_true=1;
      if(tokens[i].type=='+'|| tokens[i].type=='-')
    {
      int pare_sum=0;
      for(int j=1;j<=i-p;j++)
    {
      if(tokens[i-j].type==')')
  {pare_sum--;
               }
       else if(tokens[i-j].type=='(')        
    {pare_sum++;
     }
    }
    if(pare_sum>0)
    {op_true=0;} 
    if(op_true)
    {
  op_f=1;
    op_type=tokens[i].type;
    op_p=i;
    break;}
    } 
  }

    if(!op_f)
    {for(int i=q;i>=p;i--)
      {bool op_true=1;
        if(tokens[i].type=='*'||tokens[i].type=='/' )
      {  int pare_sum=0;
        for(int j=1;j<=i-p;j++)
      {
        if(tokens[i-j].type==')')
    {pare_sum--;
                 }
         else if(tokens[i-j].type=='(')        
      {pare_sum++;
       }
      }
      if(pare_sum>0)
      {op_true=0;} 
    
    if (op_true)
    {  op_f=1;
      op_type=tokens[i].type;
      op_p=i;
      break;
     }
    
      
      } 
    }
    }
  
  
    
      printf("op position and optype:%d and %d\n",op_p,op_type);
   uint32_t val1 = eval(p, op_p - 1);
   uint32_t val2 = eval(op_p + 1, q);

    switch (op_type) {
      case '+': return val1 + val2;
      case '-': return val1-val2;/* ... */
      case '*': return val1*val2;/* ... */
      case '/': return val1/val2;/* ... */
      default: assert(0);
    }
  }
}


word_t expr(char *e, bool *success) {
//  printf("%s\n",e);
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
//printf("result:%d\n",eval(0,nr_token-1));

  return eval(0,nr_token-1);
}
