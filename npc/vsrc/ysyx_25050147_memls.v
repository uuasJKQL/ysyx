module ysyx_25050147_memls (
    input         [2:0]    op,
    input[31:0]data,
    output reg[31:0]result

);

always @(*) begin
    case (op[1:0])
        2'b00: begin
            result = {{24{~op[2]}},data[7:0]};
        end
        2'b01: begin
           result = {{16{~op[2]}},data[15:0]};
        end
        2'b10: begin
           result = data;
        end
        default: begin
            result = 32'b0;
        end
    endcase
end
endmodule
