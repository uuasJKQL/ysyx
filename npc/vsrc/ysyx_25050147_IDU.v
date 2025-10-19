module ysyx_25050147_IDU (
    input      [31:0] mem,
    input      [31:0] rs1,
    input      [31:0] pc,
    output     [ 4:0] raddr,
    output reg [ 4:0] op_type,
    output reg [31:0] op_src1,
    output reg [31:0] op_src2,
    output     [ 4:0] rd

);
    wire [31:0] op_src1_I;
        wire [31:0] op_src2_I;
    wire [31:0] op_src1_U;
    wire [31:0] op_src1_J;
    parameter EBREAK = 0, JUMP = 1, ELSE = 2;
    always @(*) begin
        case (mem[6:0])
            7'b1101111: begin  //jal

                op_src1 = op_src1_J;
                op_src2 = pc;
                op_type = JUMP;
            end
            7'b1100111: begin  //jalr
                op_type = JUMP;
                op_src1 = op_src1_I;
                op_src2 = op_src2_I;
            end
            7'b0010011: begin  //addi
                op_type = ELSE;
                op_src1 = op_src1_I;
                op_src2 = op_src2_I;
            end
            7'b0010111: begin  //auipc
                op_type = ELSE;
                op_src1 = op_src1_U;
                op_src2 = pc;
            end
             7'b0110111: begin  //lui
                op_type = ELSE;
                op_src1 = op_src1_U;
                op_src2 =0;
            end
            7'b0000000: begin  //lui
                op_type =4;
                op_src1 = 0;
                op_src2 =0;
            end
            default: 
            begin
            op_type = EBREAK;  //eb
            op_src1=0;
            op_src2=0;
            end
        endcase

    end
    assign raddr = mem[19:15];

    assign op_src1_I = {{20{mem[31]}}, mem[31:20]};
    assign op_src2_I = rs1;
    assign op_src1_U = {mem[31:12], 12'b0};
    assign op_src1_J = {{12{mem[31]}}, mem[19:12], mem[20], mem[30:21], 1'b0};
    assign rd = mem[11:7];
endmodule
