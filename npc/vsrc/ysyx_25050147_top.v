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
    wire      [4:0]  op_type;
    wire [31:0] src1;
    wire [31:0] src2;
    wire [31:0] result;
    wire [4:0] rd;
    assign waddr = rd;

    assign wdata = result;
    Reg #(32, 32'h80000000) PC (
        clk,
        rst,
        snpc,
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
    ysyx_25050147_EXU exu (
        op_type,
        src1,
        src2,
        result
    );
    ysyx_25050147_IDU idu (
        mem,
        rdata,
        raddr,
        op_type,
        src1,
        src2,
        rd

    );

   
// export "DPI-C" task read_ebreak;
// task read_ebreak;
//  //assign if_noebreak=op_type==2?0:1;
//    output bit if_noebreak;  
// endtask
endmodule
