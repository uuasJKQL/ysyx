module top (
input [1:0]y,
input [1:0]x0,
input [1:0]x1,
input [1:0]x2,
input [1:0]x3,
output reg[1:0] F
);
always @(*) begin
    case (y)
        'b00:F=x0;
         'b01:F=x1;
         'b10:F=x2;
        default: F=x3;
    endcase
end

endmodule