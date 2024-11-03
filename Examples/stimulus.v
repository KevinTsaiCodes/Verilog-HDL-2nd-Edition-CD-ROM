/**************************************************************************
1998 Copyright Actel Corporation
coke and pepsi are trademarks of their respective companies
**************************************************************************/


`timescale 1ns / 1ns
module stimulate;
reg clock;
reg resetn;
reg [1:0] coin;
reg coke;
reg pepsi;
reg soft_drink;
wire vendcoke;
wire vendpepsi;
wire vendsoft_drink;
reg [96:1] info;

//instantiate the drink machine

drink_machine dm(.clock(clock), .resetn(resetn),.coin(coin),.coke(coke),
	.pepsi(pepsi),.soft_drink(soft_drink),.vendcoke(vendcoke),
	.vendpepsi(vendpepsi),.vendsoft_drink(vendsoft_drink));

//instantiate SDF file
initial
	$sdf_annotate("design.sdf",stimulate.dm);
//display output
initial
begin
	$display("\t\t\t\tTime	Reset	 vendcoke	vendpepsi	vendsoft_drink\n");
	$monitor("%d	%d	%d	%d	%d", $time, resetn, vendcoke, vendpepsi, vendsoft_drink);
end

//Stimulate the state machine
initial
begin
	clock = 0;
	coin	= 0;
	resetn = 0;
	coke = 0;
	pepsi = 0;
	soft_drink = 0;
	#50	resetn = 1;

	@(negedge clock);

	//Choose a subset of each block of the test vectors for the 
	//first statistical fault simulation run.

	//Put in two dimes and a nickel and select a coke
	#80 coke = 1;			
//	#80 coin = 2;#40 coin = 0;  	
//	#80 coin = 2;#40 coin = 0;  
//	#80 coin = 1;#40 coin = 0;  
//	#80 coke = 0;			


	//Put in one dime and three nickels and select a soft_drink
	#80 soft_drink = 1;		//1
//	#80 coin = 2;#40 coin = 0;	
//	#80 coin = 1;#40 coin = 0;
//	#80 coin = 1;#40 coin = 0;
//	#80 coin = 1;#40 coin = 0;
//	#80 soft_drink=0;		

	//Put in one quarter and select a pepsi
	#80 pepsi = 1;			//1
//	#80 coin = 3;#40 coin = 0;	
//	#80 pepsi=0;			

	//Put in three dimes and select a coke
	#80 coke = 1;			//1
//	#80 coin = 2;#40 coin = 0;	
//	#80 coin = 2;#40 coin = 0; 
//	#80 coin = 2;#40 coin = 0;
//	#80 coke=0;			

	#80	$finish;
end

//clock setup
 always
begin
	#20 clock = ~clock;
end 

endmodule

	