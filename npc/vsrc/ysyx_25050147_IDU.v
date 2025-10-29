module ysyx_25050147_IDU (
    input      [31:0] mem,
    input      [31:0] rs1,
    input      [31:0] pc,
    output     [ 4:0] raddr1,
    input      [31:0] rs2,
    output     [ 4:0] raddr2,
    output reg [ 4:0] op_type,
    output reg [31:0] op_src1,
    output reg [31:0] op_src2,
    output     [ 4:0] rd,
    output     [31:0] branch_target,
    output reg [ 3:0] alu_op,
    output     is_beq
);
    wire [31:0] op_src1_I;
    wire [31:0] op_src2_I;
    wire [31:0] op_src1_U;
    wire [31:0] op_src1_J;
    wire [31:0] op_src1_R;
    wire [31:0] op_src2_R;
    wire [31:0] op_src1_S;
    wire [31:0] op_src2_S;
    parameter EBREAK = 0, JUMP = 1, ELSE = 2, STORE = 4, LOAD = 8, BRANCH = 16;
    assign is_beq = op_type[4];
    always @(*) begin
        case (mem[6:0])
            7'b1101111: begin  //jal   J

                op_src1 = op_src1_J;
                op_src2 = pc;
                op_type = JUMP;
                alu_op  = 'b0000;
            end
            7'b1100111: begin  //jalr I
                op_type = JUMP;
                op_src1 = op_src1_I;
                op_src2 = op_src2_I;
                alu_op  = 'b0000;
            end
            7'b0010011: begin  //addi  I
                op_type = ELSE;
                op_src1 = op_src1_I;
                op_src2 = op_src2_I;
                alu_op  = {1'b0, mem[14:12]};
            end
            7'b0010111: begin  //auipc  U
                op_type = ELSE;
                op_src1 = op_src1_U;
                op_src2 = pc;
                alu_op  = 'b0000;
            end
            7'b0110111: begin  //lui U
                op_type = ELSE;
                op_src1 = op_src1_U;
                op_src2 = 0;
                alu_op  = 'b0000;
            end
            7'b0110011: begin  //add  R
                op_type = ELSE;
                op_src1 = op_src1_R;
                op_src2 = op_src2_R;
                alu_op  = {mem[30], mem[14:12]};
            end
            7'b0100011: begin  //sw 14:12 010
                op_type = STORE;
                op_src1 = op_src1_S;
                op_src2 = op_src2_S;
                alu_op  = 'b0000;
            end
            7'b0000011: begin  //lw  I 14:12 010
                op_type = LOAD;
                op_src1 = op_src1_I;
                op_src2 = op_src2_I;
                alu_op  = 'b0000;
            end
            7'b1100011: begin  //beq  B
                op_type = BRANCH;
                op_src1 = rs1;
                op_src2 = rs2;
                alu_op  = {1'b0,mem[14:12]};
            end
            7'b1110011: begin
                op_type = EBREAK;  //e
                op_src1 = 0;
                op_src2 = 0;
                alu_op  = 'b0000;
            end
            default: begin
                op_type = ELSE;  //e
                op_src1 = 0;
                op_src2 = 0;
                alu_op  = 'b0000;
            end
        endcase

    end

    assign raddr2 = mem[24:20];
    assign raddr1 = mem[19:15];
    assign op_src1_I = rs1;
    assign op_src2_I = {{20{mem[31]}}, mem[31:20]};
    assign op_src1_U = {mem[31:12], 12'b0};
    assign op_src1_J = {{12{mem[31]}}, mem[19:12], mem[20], mem[30:21], 1'b0};
    assign op_src2_R = rs2;
    assign op_src1_R = rs1;
    assign rd = mem[11:7];
    assign op_src1_S = rs1;

    assign op_src2_S = {{20{mem[31]}}, mem[31:25], mem[11:7]};
    assign branch_target = {{20{mem[31]}}, mem[7], mem[30:25], mem[11:8], 1'b0};
endmodule
