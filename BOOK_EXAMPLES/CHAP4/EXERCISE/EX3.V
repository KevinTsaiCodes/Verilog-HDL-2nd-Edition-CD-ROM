//This module does nothing.
//It only demonstrates how to declare I/O ports.

module test_bench;

	wire [3:0] reg_out;
	reg [3:0] reg_in;
	reg clock;
	shift_reg reg1(reg_out, reg_in, clock);
	// initial block goes here

endmodule

module shift_reg(reg_out, reg_in, clock);

	output [3:0] reg_out;
	input [3:0] reg_in;
	input clock;

	//internals not shown

endmodule
