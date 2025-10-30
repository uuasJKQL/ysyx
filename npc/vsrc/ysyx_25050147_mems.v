module ysyx_25050147_mems (
    input      [ 2:0] op,
    input      [ 1:0] addr,
    input      [31:0] data,
    output reg [31:0] mem_result,
    output reg [ 7:0] wmask

);
    reg  [ 7:0] wmask1;
    reg  [31:0] result;
    always @(*) begin
        case (addr)
            2'b00: begin


                wmask = wmask1;
                mem_result = result;
            end
            2'b01: begin
                wmask = {wmask1[6:0], 1'b0};
                mem_result = result << 8;
            end
            2'b10: begin
                wmask = {wmask1[5:0], 2'b00};
                mem_result = result << 16;
            end
            2'b11: begin
                wmask = {wmask1[4:0], 3'b000};
                mem_result = result << 24;
            end
            default: begin
                wmask = 8'b00001111;
                mem_result = result;
            end
        endcase
    end
    always @(*) begin
        case (op[2:0])
            3'b100: begin
                result = {{24'b0}, data[7:0]};
                wmask1 = 8'b00000001;
            end
            3'b101: begin
                result = {{16'b0}, data[15:0]};
                wmask1 = 8'b00000011;
            end
            3'b110: begin
                result = data;
                wmask1 = 8'b000001111;
            end
            3'b000: begin
                result = {{24{data[7]}}, data[7:0]};
                wmask1 = 8'b00000001;
            end
            3'b001: begin
                result = {{16{data[15]}}, data[15:0]};
                wmask1 = 8'b00000011;
            end
            3'b010: begin
                result = data;
                wmask1 = 8'b000001111;
            end
            default: begin
                result = 32'b0;
                wmask1 = 8'b00001111;
            end
        endcase
    end
endmodule
