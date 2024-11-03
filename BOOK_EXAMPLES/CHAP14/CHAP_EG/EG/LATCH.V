module test_bench;

wire q;
reg d, clk;

latch  latch1(q, d, clk);

//initial	//stimulus goes here

endmodule 

module latch(q, d, clk);

output q;
reg q;
input d, clk;

always @(clk or d)
 	if (clk)
		q <= d;
endmodule

	
