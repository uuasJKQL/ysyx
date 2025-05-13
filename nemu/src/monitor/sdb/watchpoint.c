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

#include "sdb.h"

#define NR_WP 32
static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
  int i;
  for (i = 0; i < NR_WP; i++)
  {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}
#include <assert.h>
WP *head_wp()
{
  return head;
}
WP *new_wp()
{
  if (free_ == NULL)
  {
    assert(0);
  }

  WP *new_node = free_;
  free_ = free_->next;

  new_node->next = head;
  head = new_node;

  return new_node;
}

void free_wp(int n)
{

  WP *current = head;
  WP *prev = NULL;

  while (current != NULL && current->NO != n)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    assert(0);
  }

  if (prev != NULL)
  {
    prev->next = current->next;
  }
  else
  {
    head = current->next;
  }

  current->next = free_;
  free_ = current;
}
/* TODO: Implement the functionality of watchpoint */