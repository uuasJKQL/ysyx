module top (
    input clk,

    input            clrn,
    input            ps2_clk,
    input            ps2_data,
    output reg       nextdata,
    output reg [6:0] HEX0,
    output reg [6:0] HEX1,
    output Ready,
     output reg [6:0] HEX2,
     output reg [6:0] HEX3,
     output reg [6:0] HEX4,
     output reg [6:0] HEX5
);
    wire [7:0] Data;
    reg [7:0]RData;
wire[2:0] write;
wire[2:0] read;
    wire       Overflow;
reg [7:0] count;
    segment sega (
        .data(RData[3:0]),
        .seg (HEX0)
    );
    segment segb (
        .data(RData[7:4]),
        .seg (HEX1)
    );
     segment segc (
        .data({1'b0,read}),
        .seg (HEX2)
    );
     segment segd (
        .data({1'b0,write}),
        .seg (HEX3)
    );
       segment sege (
        .data(count[3:0]),
        .seg (HEX4)
    );
       segment segf (
        .data(count[7:4]),
        .seg (HEX5)
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
        .w_ptr(write),
        .r_ptr(read)
    );
    always @(posedge ps2_clk) begin

if(!Ready)
begin
 nextdata<=0;
 RData<=Data;
 if(Data==8'hF0&&RData!=8'hF0)
 count<=count+1;
end

    end
endmodule

