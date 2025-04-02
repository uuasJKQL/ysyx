module top (
    input [3:0]A,
    input [3:0]B,
    input [2:0]sel,
    output reg [3:0]result,
    output Carry,
    output Overflow,
    output zero
);
wire [3:0] Result;
wire [3:0]t_no_Cin;
wire Cin;
assign Cin=sel[0]||(sel=='b110);
assign t_no_Cin = {4{ Cin }}^B;
assign {Carry,Result} ={1'b0,A} + {1'b0,t_no_Cin} + {4'b0000,Cin};
assign Overflow = (A[3] == t_no_Cin[3]) && (Result [3] != A[3]);
assign zero = ~(| Result);
always @(*) begin
    
 case (sel)
    'b000: result=Result;
    'b001: result=Result ;
    'b010: result=~A;
    'b011:result=A&B;
    'b100:result=A|B;
    'b101:result=A^B;
    'b110:result={3'b000,Result[3]^Overflow};
    'b111:result={3'b000,zero};
    
    
    default: ;
 endcase  
end 
endmodule