module top (
    input      [7:0] code,
    input            enable,
    output reg [2:0] result,
    output           sign,
    output reg [6:0] HEX0


);
    integer i;
    assign sign = |code;
    always @(*) begin
        if (enable && |code) begin

            for (i = 0; i<8; i = i + 1) begin
                if (code[i]) begin
                    result = i[2:0];
                end
            end
            case (result)
                'b000: HEX0 = 'b1000000;
                'b001: HEX0 = 'b1111001;
                'b010: HEX0 = 'b0100100;
                'b011: HEX0 = 'b0110000;
                'b100: HEX0 = 'b0011001;
                'b101: HEX0 = 'b0010010;
                'b110: HEX0 = 'b0000010;
                'b111: HEX0 = 'b1111000;


                default: ;
          
            endcase
        end
        else
        begin
         HEX0='b0000000;
         result='b000;
        end
    end

    //输入可以使用拨动开关SW7-SW0。使能端可以用SW8。输出为LED2-0，输出指示可以是LED4，数码管输出为HEX0。   
endmodule
