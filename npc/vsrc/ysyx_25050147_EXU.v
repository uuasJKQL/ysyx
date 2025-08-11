
module ysyx_25050147_EXU (
    input           [4:0]  op_type,
    input      [31:0] src1,
    input      [31:0] src2,
    output reg [31:0] result
);

    always @(*) begin
        case (op_type)

            5'b1: result = src1 + src2;
            default: ;
        endcase

    end


 
endmodule
