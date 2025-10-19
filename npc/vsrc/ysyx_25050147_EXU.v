
module ysyx_25050147_EXU (
    input      [31:0] src1,
    input      [31:0] src2,
    output reg [31:0] result
);

ysyx_25050147_ALU myalu(
.src1(src1),
.src2(src2),
.result(result)

);

 
endmodule


