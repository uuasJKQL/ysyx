module top (
    input clk,

    input            clrn,
    input            ps2_clk,
    input            ps2_data,
    output reg       nextdata,
    output reg [6:0] HEX0,
    output reg [6:0] HEX1,


output reg en,
    output           Ready,
    output reg [6:0] HEX2,
    output reg [6:0] HEX3,
    output reg [6:0] HEX4,
    output reg [6:0] HEX5,
    output reg [6:0] HEX6,
    output reg [6:0] HEX7
);

    reg [3:0] count2;
    wire [7:0] Data;
    reg  [7:0] RData;
    wire [7:0] ascii;
    wire       Overflow;
    reg  [7:0] count;
    reg  [2:0] show;
    reg  [5:0] show2;
   
    initial begin
        HEX4=7'b1111111;
        HEX5 = 7'b1111111;
    end

    ROM rom (
        .data (Data[7:0]),
        .ascii(ascii[7:0])
    );

    segment sega (
        .en(en),
        .data(Data[3:0]),
        .seg (HEX0)
    );
    segment segb (
        .en(en),
        .data(Data[7:4]),
        .seg (HEX1)
    );
    segment segc (
       .en(en),
        .data(ascii[3:0]),
        .seg (HEX2)
    );
    segment segd (
       .en(en),
        .data(ascii[7:4]),
        .seg (HEX3)
    );
    segment sege (
       .en(1),
        .data(count[3:0]),
        .seg (HEX6)
    );
    segment segf (
        .en(1),
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
        .overflow  (Overflow)

    );
//assign en=(is_work[1]^is_work[0]);

    always @(posedge ps2_clk) begin
count2<=count2+1;
if(count2==10)
begin
    en<=1;
end
    
            nextdata <= 0;
            RData <= Data;

            if (Data == 8'hF0 && RData != 8'hF0) begin
             en<=0;
             count2<=0;
                count <= count + 1;
            end
       



    end



endmodule
