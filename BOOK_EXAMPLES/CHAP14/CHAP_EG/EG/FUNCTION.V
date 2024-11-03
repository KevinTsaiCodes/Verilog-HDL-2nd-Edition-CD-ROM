module test_bench;

wire c_out; 
wire [3:0] sum;
reg [3:0] a, b; 
reg c_in;

fadder adder(c_out, sum, a, b, c_in);

endmodule

module fadder (c_out, sum, a, b, c_in);

output c_out; 
output [3:0] sum;
input [3:0] a, b; 
input c_in;

assign {c_out, sum} = fulladd( a, b, c_in);

function [4:0] fulladd;
input [3:0] a, b;
input c_in;

begin
	fulladd = a + b + c_in;
end
endfunction

endmodule

