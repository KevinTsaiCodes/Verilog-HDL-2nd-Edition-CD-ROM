//title Simple Design to illustrate Code Coverage

module select (A, B, C, D, Z);
	input [1:0] A, B, C, D;
	output [1:0] Z;
	reg [1:0] Z;
	reg out, out1, out2;

	initial #1 out = 1;
	
	always @( A or B or C or D)
		begin
		if (A > B || C < D)
			Z = A;
		else if (C > D)
			Z = C;
		else
			Z = A + B;
		end

	always @out  
		begin
		#1 out1 = ~out;
		#1 out2 = ~out1;
		#1 out = ~out2 | out1;
		end
endmodule
