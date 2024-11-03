//This file is not intended for simulation.
//It demonstrates how a latch may be inferred due
//to incomplete specification.

//Latch is inferred because of incomplete specification

module top;

wire out;
reg control, a, b;

incomplete lat1(out, control, a);
complete lat2(out, control, a, b);

endmodule 

module incomplete (out, control, a);

output out;
reg out;
input control, a;

always @(control or a)
	if(control)
		out <= a;

endmodule

//Multiplexer is inferred because of complete specification
module complete (out, control, a, b);

output out;
reg out;
input control, a, b;

always @(control or a or b)
	if(control)
		out <= a;
	else
		out <= b;

endmodule
