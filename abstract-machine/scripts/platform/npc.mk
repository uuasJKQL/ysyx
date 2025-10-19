AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

DIFFTEST ?= 0
DIFFTEST_SO_PATH ?= $(NEMU_HOME)/build/riscv32-nemu-interpreter-so

# 检查DiffTest环境
check-difftest:
	@echo "检查DiffTest环境..."
	@if [ -f "$(DIFFTEST_SO_PATH)" ]; then \
		echo "✓ DiffTest动态库存在: $(DIFFTEST_SO_PATH)"; \
	else \
		echo "✗ DiffTest动态库不存在: $(DIFFTEST_SO_PATH)"; \
		echo "请执行以下命令编译NEMU共享库:"; \
		echo "  cd $(NPC_HOME)/../nemu && make menuconfig"; \
		echo "  选择: Build target -> Shared object"; \
		echo "  make"; \
	fi

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

# 普通运行（不带DiffTest）
run: insert-arg
	$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin

# 带DiffTest的运行
run-diff: insert-arg check-difftest
	@if [ -f "$(DIFFTEST_SO_PATH)" ]; then \
		echo "使用DiffTest运行仿真..."; \
		$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin DIFFTEST=1; \
	else \
		echo "错误: DiffTest动态库不存在，无法运行DiffTest"; \
		echo "请先执行: make check-difftest 查看详情"; \
		exit 1; \
	fi

# 条件运行：根据DIFFTEST变量选择运行方式
run-conditional: insert-arg
	@if [ "$(DIFFTEST)" = "1" ]; then \
		echo "启用DiffTest运行..."; \
		if [ -f "$(DIFFTEST_SO_PATH)" ]; then \
			$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin DIFFTEST=1; \
		else \
			echo "错误: DiffTest动态库不存在"; \
			echo "请先编译NEMU共享库或执行: make check-difftest"; \
			exit 1; \
		fi \
	else \
		echo "普通运行（无DiffTest）..."; \
		$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin; \
	fi

.PHONY: insert-arg run run-diff run-conditional check-difftest
