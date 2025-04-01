VERILATOR = verilator
VERILATOR_FLAGS = -Wall --trace --cc --exe --build
VERILATOR_SOURCES = vsrc/top.v  # 替换为所有Verilog文件
TESTBENCH = csrc/testbench.cpp  # 测试台代码
SIM_EXE = obj_dir/Vtop     # Verilator生成的可执行文件路径

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	$(VERILATOR) $(VERILATOR_FLAGS) $(TESTBENCH) $(VERILATOR_SOURCES)
	@echo "=============================================="
	@echo "Simulation started"
	@echo "=============================================="
	./$(SIM_EXE)
clean:
	rm -rf obj_dir waveform.vcd
include ../Makefile
