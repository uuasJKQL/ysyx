module segment (
    input      [3:0] data,
    output reg [6:0] seg
);
    always @(*) begin
        case (data[3:0])
            4'h0: seg[6:0] = 7'b1000000;
            4'h1: seg[6:0] = 7'b1111001;
            4'h2: seg[6:0] = 7'b0100100;
            4'h3: seg[6:0] = 7'b0110000;
            4'h4: seg[6:0] = 7'b0011001;
            4'h5: seg[6:0] = 7'b0010010;
            4'h6: seg[6:0] = 7'b0000010;
            4'h7: seg[6:0] = 7'b1111000;
            4'h8: seg[6:0] = 7'b0000000;
            4'h9: seg[6:0] = 7'b0010000;
            4'ha: seg[6:0] = 7'b0001000;
            4'hb: seg[6:0] = 7'b0000011;
            4'hc: seg[6:0] = 7'b1000110;
            4'hd: seg[6:0] = 7'b0100001;
            4'he: seg[6:0] = 7'b0000110;
            4'hf: seg[6:0] = 7'b0001110;
        endcase
    end
endmodule
