//title Simple testbench for the Code Coverage example

`timescale 1ns / 1ns
`disable_codecoverage
module testbench;
	reg[1:0] A, B, C, D;
	wire[1:0] Z;
	select select_ABCD (A, B, C, D, Z);
	initial
		begin
		#10 A=0; B=0; C=0; D=0;
		#10 C = 2'b10;
		#10 D = 2'b11;
		#100 $finish;
		end
endmodule
`enable_codecoverage

