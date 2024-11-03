/**************************************************************************
Adapted from Example 14-8 Stimulus for Newspaper Vending Machine FSM
"Verilog HDL  A Guide to Digital Design and Synthesis"
By Samir Palnitkar, Prentice Hall, ISBN 0-13-451675-3 
**************************************************************************/
`timescale 1ns / 1ns
module stimulus;
reg clock;
reg [1:0] coin;
reg [1:0] coin1;
reg reset;
wire newspaper;
reg [96:1] info;

//instantiate the vending state machine
vend vendY (coin, clock, reset, newspaper);

//Display the output
initial
begin
	$display("\t\t\t\tTime	Reset   Newspaper\n");
	$monitor("%d	%d		%d", $time, reset, newspaper);
end

//Apply stimulus to the vending machine
initial
begin
	clock = 0;
	coin = 0;
	coin1 = 0;
	reset = 1;
	#50 reset = 0;

	@(negedge clock);

	//Put 3 nickels to get newspaper
	#80 coin = 1; #40 coin = 0;
	#80 coin = 1; #40 coin = 0;
	#80 coin = 1; #40 coin = 0;

	//Put one nickel and then one dime to get newspaper
	#180 coin = 1; #40 coin = 0;
	#80 coin = 2; #40 coin = 0;

	//Put two dimes; machine does not return a nickel to get newspaper
	#180 coin = 2; #40 coin = 0;
	#80 coin = 2; #40 coin = 0;

	//Put one dime and then one nickel to get newspaper
	#180 coin = 2; #40 coin = 0;
	#80 coin = 1; #40 coin = 0;

	#80 $finish;
end

//setup clock; cycle time = 40 units
always
begin
	#20 clock = ~clock;
end

//ascii vector to explain stimulus
always @coin
begin
	coin1 = coin1 +1;
	case (coin1)
	0: info = "off";
	1: info = "adding coins";
	2: info = "adding coins";
	3: begin info = "newspaper"; coin1 = 0; end
	endcase
end

endmodule
