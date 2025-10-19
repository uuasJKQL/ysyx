
VERILATOR_FLAGS = -Wall --trace --cc --exe --build
VERILATOR_SOURCES = $(shell find $(abspath ./vsrc) -name "*.v") # 替换为所有Verilog文件
TESTBENCH = testbench.cpp  # 测试台代码
SIM_EXE = obj_dir/Vysyx_25050147_top     # Verilator生成的可执行文件路径

VERILATOR = verilator
TOPNAME = ysyx_25050147_top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=
VERILATOR_CFLAGS += -MMD --build --trace -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)
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
all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "编译仿真程序..."
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOPNAME) \
		-CFLAGS "-DTOP_NAME=V$(TOPNAME)" \
		$(TESTBENCH) $(VSRCS)

	@echo "=============================================="
	@echo "仿真开始"
	@echo "程序文件: $(if $(IMG),$(IMG),默认程序)"
	@echo "超时周期: $(TIMEOUT)"
	@echo "详细模式: $(if $(filter 1,$(VERBOSE)),是,否)"
	@echo "=============================================="
	
	$(eval SIM_ARGS :=)
	$(if $(IMG), $(eval SIM_ARGS := $(SIM_ARGS) $(IMG)))
	$(if $(filter-out 1000,$(TIMEOUT)), $(eval SIM_ARGS := $(SIM_ARGS) -t $(TIMEOUT)))
	$(if $(filter 1,$(VERBOSE)), $(eval SIM_ARGS := $(SIM_ARGS) -v))
	
	./$(SIM_EXE) $(SIM_ARGS)


include ../Makefile
