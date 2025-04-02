module top (
    input clk,

    input            clrn,
    input            ps2_clk,
    input            ps2_data,
    output reg       nextdata,
    output reg [6:0] HEX0,
    output reg [6:0] HEX1
    // output reg [6:0] HEX2,
    // output reg [6:0] HEX3,
    // output reg [6:0] HEX4,
    // output reg [6:0] HEX5
);
    wire [7:0] Data;
    wire       Ready;
    wire       Overflow;
    segment sega (
        .data(Data[3:0]),
        .seg (HEX0)
    );
    segment segb (
        .data(Data[7:4]),
        .seg (HEX1)
    );
    ps2_keyboard controller (
        .clk       (clk),
        .clrn      (clrn),
        .ps2_clk   (ps2_clk),
        .ps2_data  (ps2_data),
        .data      (Data),
        .ready     (Ready),
        .nextdata_n(nextdata),
        .overflow  (Overflow)

    );
    always @(posedge clk) begin

        if (Ready) nextdata <= 0;

    end
endmodule

