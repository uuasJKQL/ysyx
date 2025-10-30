import "DPI-C" function void notify_ebreak();
import "DPI-C" function void update_shadow_register(
    input int        index,
    input bit [31:0] value
);
module ysyx_25050147_top (
    input             rst,
    input             clk,
    output reg [31:0] pc
);
    wire [31:0] mem;
    wire [31:0] wdata;
    wire [ 4:0] waddr;
    wire [31:0] wdata_mem;
    wire [31:0] waddr_mem;
    wire [ 7:0] wmask;
    wire        wen;
    wire [31:0] rdata1;
    wire [ 4:0] raddr1;
    wire [31:0] rdata2;
    wire [ 4:0] raddr2;
    wire [31:0] snpc;
    wire [31:0] dnpc;
    wire [ 4:0] op_type;
    wire [31:0] src1;
    wire [31:0] src2;
    wire [31:0] result;
    wire [ 4:0] rd;
    wire        wen_mem;
    wire [31:0]inst;
    wire[31:0] branch_target;
    wire[3:0] alu_op;
    wire [31:0] branch_offset;

    wire [31:0] mem_out;
        wire [31:0] mem_in;
    wire is_branch;
    wire is_beq;
    assign waddr = rd;
    assign wdata = op_type[0] ? pc + 4 :( op_type[3]?mem_out:result);//1
assign inst = pmem_read(pc);
    Reg #(32, 32'h80000000) PC (
        clk,
        rst,
        dnpc,
        pc,
        1'b1
    );
    RegisterFile #(3'd5, 6'd32) rfile (
        clk,
        wdata,
        waddr,
        rdata1,
        raddr1,
        rdata2,
        raddr2,
        wen
    );
     
    assign wen = ((|waddr) && ~op_type[2]&&~op_type[4]) ? 1 : 0;
    assign snpc = pc + 4;
    assign dnpc = op_type == 1 ? result : (is_branch?branch_target:snpc);
  assign branch_target=pc+branch_offset;
    assign  is_branch = (op_type[4]&&result[0] )? 1 : 0;
    assign wen_mem = op_type[2] ? 1 : 0;
    assign waddr_mem = result;
    assign wdata_mem = mem_in;//store data
    ysyx_25050147_IFU ifu (
        result,
        1'b1,
        wen_mem,
        waddr_mem,
        wdata_mem,
        wmask,
        mem
    );

    ysyx_25050147_EXU exu (
       alu_op,
       is_beq,
        src1,
        src2,
        result
    );
    ysyx_25050147_IDU idu (
        inst,
        rdata1,
        pc,
        raddr1,
        rdata2,
        raddr2,
        op_type,
        src1,
        src2,
        rd,
        branch_offset,
        alu_op,
        is_beq
    );
 ysyx_25050147_meml memload_change(
inst[14:12],
result[1:0],
mem,
mem_out//store or load data

   );
    ysyx_25050147_mems memstore_change(
inst[14:12],
result[1:0],
rdata2,
mem_in,//store or load data
wmask

   );
    wire is_ebreak;

    assign is_ebreak = op_type == 0 ? 1 : 0;
    always @(posedge clk) begin
        if (is_ebreak) begin
            notify_ebreak();  // 调用 DPI-C 函数
        end
    end
    always @(posedge clk) begin
        if (wen && waddr != 0) begin
            update_shadow_register({{27'b0}, waddr}, wdata);
        end
    end
endmodule
