module top (
    input clk,

    input            clrn,
    input            ps2_clk,
    input            ps2_data,
    output reg       nextdata,
    output reg [6:0] HEX0,
    output reg [6:0] HEX1,
    output reg  en,
    output show2,
    output           Ready,
    output reg [6:0] HEX2,
    output reg [6:0] HEX3,
    output reg [6:0] HEX4,
    output reg [6:0] HEX5,
    output reg [6:0] HEX6,
    output reg [6:0] HEX7
);
    wire [7:0] Data;
    reg  [7:0] RData;
    wire [7:0] ascii;
    wire       Overflow;
    reg  [7:0] count;
wire [3:0]show;
wire show3;
assign show2=show3;
  initial begin
   //HEX4=7'b1111111;
    HEX5=7'b1111111;
  end

    ROM rom(
.data(Data[7:0]),
.ascii(ascii[7:0])
    );
  segment sega1(
        .data(show[3:0]),
        .seg (HEX4)
    );
    segment sega (
        .data(Data[3:0]),
        .seg (HEX0)
    );
    segment segb (
        .data(Data[7:4]),
        .seg (HEX1)
    );
    segment segc (
        .data(ascii[3:0]),
        .seg (HEX2)
    );
    segment segd (
        .data(ascii[7:4]),
        .seg (HEX3)
    );
    segment sege (
        .data(count[3:0]),
        .seg (HEX6)
    );
    segment segf (
        .data(count[7:4]),
        .seg (HEX7)
    );
    ps2_keyboard controller (
        .clk       (clk),
        .clrn      (clrn),
        .ps2_clk   (ps2_clk),
        .ps2_data  (ps2_data),
        .data      (Data),
        .ready     (Ready),
        .nextdata_n(nextdata),
        .overflow  (Overflow),
    .count(show),
    .sampling(show3)
    );

    always @(posedge clk) begin

if (!Ready) begin
    nextdata<=1;
end
else
begin
        nextdata <= 0;
        RData <= Data;
        if (Data == 8'hF0 && RData != 8'hF0) 
        begin
       en<=1;     
        count <= count + 1;
        end

end
    end
endmodule

