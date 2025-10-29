module ysyx_25050147_ALU (
    input      [ 3:0] alu_op,
    input      [31:0] src1,
    input      [31:0] src2,
    input             is_beq,
    output [31:0] fresult
);
    reg [31:0] result;
    wire zero;
    wire        Overflow;
    wire [31:0] Result;
    wire [31:0] t_no_Cin;
    wire        Carry;
    wire        Cin;
    assign Cin = alu_op[3] | (alu_op[1])|is_beq;
    assign t_no_Cin = {32{Cin}} ^ src2;
    assign {Carry, Result} = {1'b0, src1} + {1'b0, t_no_Cin} + {32'b0000, Cin};
    assign Overflow = (src1[31] == t_no_Cin[31]) && (Result[31] != src1[31]);
    assign zero = ~(|Result);
    reg is_branch;
    always @(*) begin

        case (alu_op)
            'b0000: result = Result;
            'b0001: result = src1 << src2[4:0];
            'b0010: result = {31'b000, Result[31] ^ Overflow};  //less than
            'b0011: result = {31'b000, ~Carry};  //unsigned less than
            'b0100: result = src1 ^ src2;
            'b0101: result = src1 >> src2[4:0];
            'b0110: result = src1 | src2;
            'b0111: result = src1 & src2;
            
            'b1000: result = Result;  //-
            'b1101: result = src1 >>> src2[4:0];
            
            
            // 'b1010: result = {31'b000, ~(Result[31] ^ Overflow)};  //-
            // 'b1011: result = {31'b000, Carry};  //-



            // 'b1100: result = {31'b000, ~zero};  //-







            default: result = 0;
        endcase
    end
    always @(*) begin
        case (alu_op[2:1])
            2'b00:   is_branch=zero;  
            2'b10:   is_branch=Result[31] ^ Overflow;
            2'b11:   is_branch=~Carry;
            default: ;
        endcase

    end
    assign fresult=is_beq?{31'b0,is_branch^alu_op[0]}:result;
endmodule
