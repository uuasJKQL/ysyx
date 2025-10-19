VERILATOR_FLAGS = -Wall --trace --cc --exe --build
VERILATOR_SOURCES = $(shell find $(abspath ./vsrc) -name "*.v")
TESTBENCH = testbench.cpp
SIM_EXE = obj_dir/Vysyx_25050147_top

VERILATOR = verilator
TOPNAME = ysyx_25050147_top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=
VERILATOR_CFLAGS += -MMD --build --trace -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# DiffTest配置
DIFFTEST ?= 0
DIFFTEST_SO_PATH ?= ../nemu/build/riscv32-nemu-interpreter-so

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

# 保留ASan用于内存检查
CXXFLAGS += -fsanitize=address
CFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address

# DiffTest编译选项
ifeq ($(DIFFTEST), 1)
    CXXFLAGS += -DDIFFTEST
    LDFLAGS += -ldl -Wl,-rpath,$(dir $(DIFFTEST_SO_PATH))
    # 检查动态库是否存在
    DIFFTEST_SO_EXISTS = $(wildcard $(DIFFTEST_SO_PATH))
    ifneq ($(DIFFTEST_SO_EXISTS),)
        $(info DiffTest已启用，使用动态库: $(DIFFTEST_SO_PATH))
    else
        $(warning DiffTest动态库不存在: $(DIFFTEST_SO_PATH))
        $(warning 请先编译NEMU为共享库: cd ../nemu && make menuconfig && make)
    endif
endif

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

# 仿真相关配置
# 仿真相关配置
IMG ?=  # 程序镜像文件
TIMEOUT ?= 1000  # 默认超时周期
VERBOSE ?= 0     # 详细输出

# 查找 ASan 库路径
ASAN_LIB := $(shell gcc -print-file-name=libasan.so)

# 仿真目标
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "编译仿真程序..."
	
	# 设置编译选项
	@if [ "$(DIFFTEST)" = "1" ]; then \
		echo "启用DiffTest编译..."; \
		if [ -f "$(DIFFTEST_SO_PATH)" ]; then \
			$(VERILATOR) $(VERILATOR_FLAGS) \
				--top-module $(TOPNAME) \
				-CFLAGS "-DTOP_NAME=V$(TOPNAME) -DDIFFTEST" \
				-LDFLAGS "-ldl -Wl,-rpath,$(dir $(DIFFTEST_SO_PATH))" \
				$(TESTBENCH) $(VSRCS); \
		else \
			echo "错误: DiffTest动态库不存在"; \
			exit 1; \
		fi \
	else \
		$(VERILATOR) $(VERILATOR_FLAGS) \
			--top-module $(TOPNAME) \
			-CFLAGS "-DTOP_NAME=V$(TOPNAME)" \
			$(TESTBENCH) $(VSRCS); \
	fi

	@echo "=============================================="
	@echo "仿真开始"
	@echo "程序文件: $(if $(IMG),$(IMG),默认程序)"
	@echo "超时周期: $(TIMEOUT)"
	@echo "详细模式: $(if $(VERBOSE),$(VERBOSE),否)"
	@echo "DiffTest: $(if $(DIFFTEST),$(DIFFTEST),禁用)"
	@echo "ASan库路径: $(ASAN_LIB)"
	@echo "=============================================="
	
	# 构建仿真参数
	@SIM_ARGS=""; \
	if [ -n "$(IMG)" ]; then SIM_ARGS="$$SIM_ARGS $(IMG)"; fi; \
	if [ "$(TIMEOUT)" != "1000" ]; then SIM_ARGS="$$SIM_ARGS -t $(TIMEOUT)"; fi; \
	if [ "$(VERBOSE)" = "1" ]; then SIM_ARGS="$$SIM_ARGS -v"; fi; \
	if [ "$(DIFFTEST)" = "1" ] && [ -f "$(DIFFTEST_SO_PATH)" ]; then SIM_ARGS="$$SIM_ARGS --diff $(DIFFTEST_SO_PATH)"; fi; \
	\
	# 检查是否需要使用 LD_PRELOAD \
	if [ -n "$(ASAN_LIB)" ] && [ -f "$(ASAN_LIB)" ]; then \
		echo "使用 LD_PRELOAD 加载 ASan 库: $(ASAN_LIB)"; \
		echo "运行命令: LD_PRELOAD=\"$(ASAN_LIB)\" ./$(SIM_EXE) $$SIM_ARGS"; \
		LD_PRELOAD="$(ASAN_LIB)" ./$(SIM_EXE) $$SIM_ARGS; \
	else \
		echo "运行命令: ./$(SIM_EXE) $$SIM_ARGS"; \
		./$(SIM_EXE) $$SIM_ARGS; \
	fi

# 或者更简单的版本：总是尝试使用 LD_PRELOAD
sim-simple:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "编译仿真程序..."
	
	@if [ "$(DIFFTEST)" = "1" ]; then \
		echo "启用DiffTest编译..."; \
		if [ -f "$(DIFFTEST_SO_PATH)" ]; then \
			$(VERILATOR) $(VERILATOR_FLAGS) \
				--top-module $(TOPNAME) \
				-CFLAGS "-DTOP_NAME=V$(TOPNAME) -DDIFFTEST" \
				-LDFLAGS "-ldl -Wl,-rpath,$(dir $(DIFFTEST_SO_PATH))" \
				$(TESTBENCH) $(VSRCS); \
		else \
			echo "错误: DiffTest动态库不存在"; \
			exit 1; \
		fi \
	else \
		$(VERILATOR) $(VERILATOR_FLAGS) \
			--top-module $(TOPNAME) \
			-CFLAGS "-DTOP_NAME=V$(TOPNAME)" \
			$(TESTBENCH) $(VSRCS); \
	fi

	@echo "运行仿真 (使用 LD_PRELOAD)..."
	@SIM_ARGS=""; \
	if [ -n "$(IMG)" ]; then SIM_ARGS="$$SIM_ARGS $(IMG)"; fi; \
	if [ "$(TIMEOUT)" != "1000" ]; then SIM_ARGS="$$SIM_ARGS -t $(TIMEOUT)"; fi; \
	if [ "$(VERBOSE)" = "1" ]; then SIM_ARGS="$$SIM_ARGS -v"; fi; \
	if [ "$(DIFFTEST)" = "1" ] && [ -f "$(DIFFTEST_SO_PATH)" ]; then SIM_ARGS="$$SIM_ARGS --diff $(DIFFTEST_SO_PATH)"; fi; \
	LD_PRELOAD="$(shell gcc -print-file-name=libasan.so)" ./$(SIM_EXE) $$SIM_ARGS

# 另一个备选方案：直接设置 LD_PRELOAD 环境变量
run-with-asan:
	@echo "使用 LD_PRELOAD 运行仿真..."
	@SIM_ARGS=""; \
	if [ -n "$(IMG)" ]; then SIM_ARGS="$$SIM_ARGS $(IMG)"; fi; \
	if [ "$(TIMEOUT)" != "1000" ]; then SIM_ARGS="$$SIM_ARGS -t $(TIMEOUT)"; fi; \
	if [ "$(VERBOSE)" = "1" ]; then SIM_ARGS="$$SIM_ARGS -v"; fi; \
	if [ "$(DIFFTEST)" = "1" ] && [ -f "$(DIFFTEST_SO_PATH)" ]; then SIM_ARGS="$$SIM_ARGS --diff $(DIFFTEST_SO_PATH)"; fi; \
	LD_PRELOAD="$(shell gcc -print-file-name=libasan.so)" ./$(SIM_EXE) $$SIM_ARGS

# DiffTest专用目标
sim-diff:
	@echo "使用DiffTest运行仿真..."
	$(MAKE) sim DIFFTEST=1 IMG=$(IMG) TIMEOUT=$(TIMEOUT) VERBOSE=$(VERBOSE)

# 帮助信息更新
help:
	@echo "可用目标:"
	@echo "  sim           - 编译并运行仿真 (自动处理ASan)"
	@echo "  sim-simple    - 简化版本，总是使用LD_PRELOAD"
	@echo "  run-with-asan - 仅运行已编译的仿真程序(使用LD_PRELOAD)"
	@echo "  sim-diff      - 启用DiffTest运行仿真"
	@echo "  check-difftest - 检查DiffTest环境"
	@echo "  all           - 构建默认目标"
	@echo "  clean         - 清理构建文件"
	@echo ""
	@echo "可用变量:"
	@echo "  IMG=program.bin    - 指定程序文件"
	@echo "  TIMEOUT=5000       - 设置仿真超时周期"
	@echo "  VERBOSE=1          - 启用详细输出"
	@echo "  DIFFTEST=1         - 启用DiffTest"
	@echo "  DIFFTEST_SO_PATH=path/to/so - 指定DiffTest动态库路径"
