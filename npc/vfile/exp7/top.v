module top (
    input clk,

    input            clrn,
    input            ps2_clk,
    input            ps2_data,
    output reg       nextdata,
    output reg [6:0] HEX0,
    output reg [6:0] HEX1,


    output        en,
    output           Ready,
    output reg [6:0] HEX2,
    output reg [6:0] HEX3,
    output reg [6:0] HEX4,
    output reg [6:0] HEX5,
    output reg [6:0] HEX6,
    output reg [6:0] HEX7
);
parameter wait_data =0 ;
parameter show_data =1 ;
 wire change;
    wire [7:0] Data;
    reg  [7:0] RData;
    wire [7:0] ascii;
    wire       Overflow;
reg current_state;
reg next_state;
reg [7:0]count;
reg [3:0]count2;
    initial begin
        HEX4 = 7'b1111111;
        HEX5 = 7'b1111111;
       next_state=1;
    end

    ROM rom (
        .data (Data[7:0]),
        .ascii(ascii[7:0])
    );

    segment sega (
        .en  (en),
        .data(Data[3:0]),
        .seg (HEX0)
    );
    segment segb (
        .en  (en),
        .data(Data[7:4]),
        .seg (HEX1)
    );
    segment segc (
        .en  (en),
        .data(ascii[3:0]),
        .seg (HEX2)
    );
    segment segd (
        .en  (en),
        .data(ascii[7:4]),
        .seg (HEX3)
    );
    segment sege (
        .en  (1),
        .data(count[3:0]),
        .seg (HEX6)
    );
    segment segf (
        .en  (1),
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
.count(count2)
    );
    //assign en=(is_work[1]^is_work[0]);
always @(*) begin
    case (current_state)
       wait_data : if(Ready)next_state=show_data;
      show_data : if(Data == 8'hF0)next_state=wait_data  ;
      endcase
end
assign change=(current_state==show_data)&&(next_state==wait_data);
always @(posedge Ready) begin
      RData<=Data;
end
always @(posedge ps2_clk) begin
    
    current_state<=next_state;
    if(change)
    count<=count+1;
end

    assign en=current_state;




endmodule