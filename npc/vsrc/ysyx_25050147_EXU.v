
module ysyx_25050147_EXU (
    input  [ 3:0] alu_op,
    input         is_beq,
    input  [31:0] src1,
    input  [31:0] src2,
    output [31:0] result

);

    ysyx_25050147_ALU myalu (
        .alu_op(alu_op),
        .src1  (src1),
        .src2  (src2),
        .is_beq(is_beq),
        .fresult(result)
    );


endmodule


