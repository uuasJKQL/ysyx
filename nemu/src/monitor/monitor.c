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
#include <memory/paddr.h>
#include <elf.h>
#include <ftrace.h>
void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();

static void welcome()
{
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
                          "to record the trace. This may lead to a large log file. "
                          "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  // Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //  assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

struct ftrace_data func_tab;
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;
Elf32_Ehdr ehdr;
void parse_elf(const char *elf_file)
{
  FILE *fp = fopen(elf_file, "rb");
  if (!fp)
  {
    perror("Failed to open file");
    return;
  }

  // 1. 读取ELF头
  if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1)
  {
    perror("Failed to read ELF header");
    fclose(fp);
    return;
  }
  if (ehdr.e_ident[EI_MAG0] != 0x7F ||
      ehdr.e_ident[EI_MAG1] != 'E' ||
      ehdr.e_ident[EI_MAG2] != 'L' ||
      ehdr.e_ident[EI_MAG3] != 'F')
  {
    assert(0);
  }

  Elf32_Shdr *shdr_table = malloc(ehdr.e_shnum * ehdr.e_shentsize);
  if (!shdr_table)
  {
    perror("Failed to allocate memory for section headers");
    fclose(fp);
    return;
  }
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  if (fread(shdr_table, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum)
  {
    perror("Failed to read section header table");
    free(shdr_table);
    fclose(fp);
    return;
  }

  // 3. 获取节头字符串表（.shstrtab）
  Elf32_Shdr *shstrtab_shdr = &shdr_table[ehdr.e_shstrndx];
  char *shstrtab = malloc(shstrtab_shdr->sh_size);
  if (!shstrtab)
  {
    perror("Failed to allocate memory for section header string table");
    free(shdr_table);
    fclose(fp);
    return;
  }
  fseek(fp, shstrtab_shdr->sh_offset, SEEK_SET);
  if (fread(shstrtab, 1, shstrtab_shdr->sh_size, fp) != shstrtab_shdr->sh_size)
  {
    perror("Failed to read section header string table");
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }

  // 4. 查找符号表（.symtab）和其对应的字符串表（.strtab）
  Elf32_Shdr *symtab_shdr = NULL;
  Elf32_Shdr *strtab_shdr = NULL;

  for (int i = 0; i < ehdr.e_shnum; ++i)
  {
    Elf32_Shdr *shdr = &shdr_table[i];
    // 可以使用 shstrtab + shdr->sh_name 获取节名称
    // const char* section_name = shstrtab + shdr->sh_name;

    if (shdr->sh_type == SHT_SYMTAB)
    { // 找到符号表
      symtab_shdr = shdr;
      // 符号表节头的 sh_link 字段指向其使用的字符串表在节头表中的索引
      if (shdr->sh_link < ehdr.e_shnum)
      {
        strtab_shdr = &shdr_table[shdr->sh_link];
      }
      break; // 通常只有一个.symtab
    }
  }

  if (!symtab_shdr || !strtab_shdr)
  {
    fprintf(stderr, "Symbol table or associated string table not found.\n");
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }

  // 5. 读取字符串表（.strtab）
  char *strtab = malloc(strtab_shdr->sh_size);
  if (!strtab)
  {
    perror("Failed to allocate memory for string table");
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }
  fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
  if (fread(strtab, 1, strtab_shdr->sh_size, fp) != strtab_shdr->sh_size)
  {
    perror("Failed to read string table");
    free(strtab);
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }
  // 6. 读取符号表
  int num_symbols = symtab_shdr->sh_size / symtab_shdr->sh_entsize;
  Elf32_Sym *symtab = malloc(symtab_shdr->sh_size);
  if (!symtab)
  {
    perror("Failed to allocate memory for symbol table");
    free(strtab);
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }
  fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
  if (fread(symtab, symtab_shdr->sh_entsize, num_symbols, fp) != num_symbols)
  {
    perror("Failed to read symbol table");
    free(symtab);
    free(strtab);
    free(shstrtab);
    free(shdr_table);
    fclose(fp);
    return;
  }
  // 7. 遍历符号表并打印符号信息
  printf("Symbol table:\n");
  int k = 0;
  for (int i = 0; i < num_symbols; ++i)
  {
    Elf32_Sym *symbol = &symtab[i];
    const char *name = strtab + symbol->st_name; // 从字符串表获取符号名

    // 可以根据 symbol->st_info 过滤符号类型 (STT_FUNC, STT_OBJECT等)
    // 这里打印所有符号
    if (ELF32_ST_TYPE(symbol->st_info) == STT_FUNC)
    {
      k++;
      func_tab.name[k] = malloc(strlen(name) + 1); // +1 用于 null 终止符
      if (func_tab.name[k] == NULL)
      {
        // 处理内存分配失败
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
      }
      strcpy(func_tab.name[k], name);
      func_tab.pc_value[k] = symbol->st_value;
      func_tab.size[k] = symbol->st_size;
      func_tab.num += 1;
      printf("  Name: %s, Address: 0x%lx, Size: %lu\n",
             name, (unsigned long)symbol->st_value,
             (unsigned long)symbol->st_size);
    }
  }
  // 8. 清理资源
  free(symtab);
  free(strtab);
  free(shstrtab);
  free(shdr_table);
  fclose(fp);
}
static long load_img()
{
  if (img_file == NULL)
  {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}
static int parse_args(int argc, char *argv[])
{
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:f:", table, NULL)) != -1)
  {
    switch (o)
    {
    case 'b':
      sdb_set_batch_mode();
      break;
    case 'p':
      sscanf(optarg, "%d", &difftest_port);
      break;
    case 'l':
      log_file = optarg;
      break;
    case 'd':
      diff_so_file = optarg;
      break;
    case 'f':
      elf_file = optarg;
      break;
    case 1:
      img_file = optarg;
      return 0;
    default:
      printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
      printf("\t-b,--batch              run with batch mode\n");
      printf("\t-l,--log=FILE           output log to FILE\n");
      printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
      printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
      printf("\n");
      exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[])
{
  /* Perform some global initialization. */

  /* Parse arguments. */

  parse_args(argc, argv);
#ifdef CONFIG_FTRACE
  parse_elf(elf_file);
#endif
  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img()
{
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor()
{
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
