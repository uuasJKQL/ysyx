module ysyx_25050147_meml (
    input      [ 2:0] op,
    input      [ 1:0] addr,
    input      [31:0] data,
    output reg [31:0] result
);
    reg [31:0] mem_data;
    always @(*) begin
        case (addr)
            2'b00:   mem_data = data;
            2'b01:   mem_data = data >> 8;
            2'b10:   mem_data = data >> 16;
            2'b11:   mem_data = data >> 24;
            default: mem_data = 0;
        endcase
    end
    always @(*) begin
        case (op[2:0])
            3'b100: begin
                result = {{24'b0}, mem_data[7:0]};

            end
            3'b101: begin
                result = {{16'b0}, mem_data[15:0]};

            end
            3'b110: begin
                result = mem_data;

            end
            3'b000: begin
                result = {{24{mem_data[7]}}, mem_data[7:0]};

            end
            3'b001: begin
                result = {{16{mem_data[15]}}, mem_data[15:0]};

            end
            3'b010: begin
                result = mem_data;

            end
            default: begin
                result = 32'b0;
            end
        endcase
    end
endmodule
