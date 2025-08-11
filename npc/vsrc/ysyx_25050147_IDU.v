module ysyx_25050147_IDU (
    input      [31:0] mem,
    input      [31:0] rdata,
    output     [ 4:0] raddr,
    output reg        [4:0]op_type,
    output     [31:0] op_src1,
    output     [31:0] op_src2,
    output     [ 4:0] rd

);
    always @(*) begin
        case ({
            mem[6:0], mem[14:12]
        })

            10'b0010011000: op_type = 1;
            10'b0000010001: begin
                case ({
                    mem[15], mem[11:7]
                })
                    6'b100000: op_type = 2;
                    default:   op_type = 0;
                endcase
            end
            default: op_type = 0;
        endcase

    end
    assign raddr = mem[19:15];
    assign op_src1 = {{20{mem[31]}}, mem[31:20]};
    assign op_src2 = rdata;
    assign rd = mem[11:7];
endmodule
