import "DPI-C" function void notify_ebreak();
import "DPI-C" function void get_register_value(input int index, output bit [31:0] value);
module ysyx_25050147_top (
    input      [31:0] mem,
    input             rst,
    input             clk,
    output reg [31:0] pc
);

    wire [31:0] wdata;
    wire [ 4:0] waddr;
    wire        wen;
    wire [31:0] rdata;
    wire [ 4:0] raddr;

    wire [31:0] snpc;
       wire [31:0] dnpc;
    wire      [4:0]  op_type;
    wire [31:0] src1;
    wire [31:0] src2;
    wire [31:0] result;
    wire [4:0] rd;

    assign waddr = rd;

    assign wdata = op_type==1?pc+4:result;

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
        rdata,
        raddr,
        wen
    );
    assign wen=(|waddr)?1:0;
   assign snpc = pc + 4;
   assign dnpc= op_type==1?result:snpc;
    ysyx_25050147_EXU exu (
        src1,
        src2,
        result
    );
    ysyx_25050147_IDU idu (
        mem,
        rdata,
        pc,
        raddr,
        op_type,
        src1,
        src2,
        rd
    );
    wire is_ebreak;
    
assign is_ebreak=op_type==0?1:0;
 always @(posedge clk) begin
        if (is_ebreak) begin
            notify_ebreak(); // 调用 DPI-C 函数
        end
    end
endmodule
