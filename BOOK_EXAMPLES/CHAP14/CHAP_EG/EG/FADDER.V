module fadder (c_out, sum, a, b, c_in);

output c_out, sum;
input a, b, c_in;

assign {c_out, sum} = a + b + c_in;

endmodule

// Define the stimulus (top level module)
module stimulus;

// Set up variables
reg   A, B;
reg C_IN;
wire  SUM;
wire C_OUT;

// Instantiate the 1-bit full adder. call it FA1
fadder FA1(  C_OUT, SUM,  A, B, C_IN);


// Setup the monitoring for the signal values
initial
begin
	$monitor($time," A= %b, B=%b, C_IN= %b,, C_OUT= %b, SUM= %b\n",
													A, B, C_IN, C_OUT, SUM);
end

// Stimulate inputs
initial
begin
	A = 1; B = 1; C_IN = 1;
	#50 A = 1; B = 1; C_IN = 0;
	#50 A = 1; B = 0; C_IN = 1;
	#50 A = 1; B = 0; C_IN = 0;
	#50 A = 0; B = 1; C_IN = 1;
	#50 A = 0; B = 1; C_IN = 0;
	#50 A = 0; B = 0; C_IN = 1;
	#50 A = 0; B = 0; C_IN = 0;

	 
end	

endmodule