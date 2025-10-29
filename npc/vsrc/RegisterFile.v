module RegisterFile #(
    ADDR_WIDTH = 1,
    DATA_WIDTH = 1
) (
    input                   clk,
    input  [DATA_WIDTH-1:0] wdata,
    input  [ADDR_WIDTH-1:0] waddr,
    output [DATA_WIDTH-1:0] rdata1,
    input  [ADDR_WIDTH-1:0] raddr1,
    output [DATA_WIDTH-1:0] rdata2,
    input  [ADDR_WIDTH-1:0] raddr2,
    input                   wen

);
    reg [DATA_WIDTH-1:0] rf[2**ADDR_WIDTH-1:0];
    always @(posedge clk) begin
        if (wen) rf[waddr] <= wdata;
    end
    assign rdata1 = rf[raddr1];
    assign rdata2 = rf[raddr2];
endmodule
