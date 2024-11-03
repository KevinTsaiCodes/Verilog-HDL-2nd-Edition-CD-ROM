/**************************************************************************
Adapted from Example 14-8 Stimulus for Newspaper Vending Machine FSM
"Verilog HDL  A Guide to Digital Design and Synthesis"
By Samir Palnitkar, Prentice Hall, ISBN 0-13-451675-3 
**************************************************************************/

`define nickel 2'b01
`define dime 2'b10

`timescale 1ns / 1ns

module stimulus;
reg clock;
reg [1:0] coin;
reg reset;
reg newspaper;

`include "vending.v"

//Apply stimulus to the vending machine
initial
begin
	clock = 0;
	coin = 0;
	reset = 1;
	#50 reset = 0;
	#1400 $finish;
end

initial
	fork 
		//Put 3 nickels to get newspaper
		#100 coin = `nickel;
		#200 coin = `nickel;
		#300 coin = `nickel; 

		//Put one nickel and then one dime to get newspaper
		#500 coin = `nickel; 
		#600 coin = `dime; 

		//Put two dimes; machine does not return a nickel to get newspaper
		#800 coin = `dime; 
		#900 coin = `dime; 

		//Put one dime and then one nickel to get newspaper
		#1100 coin = `dime; 
		#1200 coin = `nickel;
		join


//setup clock; cycle time = 40 units
always
begin
	#30 clock = ~clock;
end

//reset coin to zero
always @(posedge clock) 
	if (coin !=0) #35 coin =0; 

//test for newspaper
always @(posedge S15)
begin
	newspaper = 1;	
	repeat (2) @(posedge clock) 
	newspaper = 0;
	@(negedge clock);
end

endmodule
