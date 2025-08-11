module ROM (
    input  [7:0] data,
    output reg [7:0]  ascii
);
    always @(*) begin
        case (data)
            8'h45: ascii = 8'h48;  // 0 -> '0'
            8'h16: ascii = 8'h49;  // 1 -> '1'
            8'h1E: ascii = 8'h50;  // 2 -> '2'
            8'h26: ascii = 8'h51;  // 3 -> '3'
            8'h25: ascii = 8'h52;  // 4 -> '4'
            8'h2E: ascii = 8'h53;  // 5 -> '5'
            8'h36: ascii = 8'h54;  // 6 -> '6'
            8'h3D: ascii = 8'h55;  // 7 -> '7'
            8'h3E: ascii = 8'h56;  // 8 -> '8'
            8'h46: ascii = 8'h57;  // 9 -> '9'

            // 大写字母映射
            8'h1C: ascii = 8'h65;  // A
            8'h32: ascii = 8'h66;  // B
            8'h21: ascii = 8'h67;  // C
            8'h23: ascii = 8'h68;  // D
            8'h24: ascii = 8'h69;  // E
            8'h2B: ascii = 8'h70;  // F
            8'h34: ascii = 8'h71;  // G
            8'h33: ascii = 8'h72;  // H
            8'h43: ascii = 8'h73;  // I
            8'h3B: ascii = 8'h74;  // J
            8'h42: ascii = 8'h75;  // K
            8'h4B: ascii = 8'h76;  // L
            8'h3A: ascii = 8'h77;  // M
            8'h31: ascii = 8'h78;  // N
            8'h44: ascii = 8'h79;  // O
            8'h4D: ascii = 8'h80;  // P
            8'h15: ascii = 8'h81;  // Q
            8'h2D: ascii = 8'h82;  // R
            8'h1B: ascii = 8'h83;  // S
            8'h2C: ascii = 8'h84;  // T
            8'h3C: ascii = 8'h85;  // U
            8'h2A: ascii = 8'h86;  // V
            8'h1D: ascii = 8'h87;  // W
            8'h22: ascii = 8'h88;  // X
            8'h35: ascii = 8'h89;  // Y
            8'h1A: ascii = 8'h90;  // Z

            // 默认情况（未列出的按键返回0）
            default: ascii = 8'h0;





        endcase
    end
endmodule
