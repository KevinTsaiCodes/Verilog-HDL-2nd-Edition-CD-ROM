module edge_dff(q, d, clk);

output q;
reg q;
input d, clk;


always @(posedge clk)
	q <= d;
endmodule

module stimulus;

wire Q;
reg D, CLK ;

always #5 CLK = ~CLK;

initial
begin
	$monitor($time, " Q=%b, D= %b, CLK=%b ",
			Q, D, CLK );
	 
	CLK = 1'B0;
	 

	D = 1'b0;
	#110 D = 1'b0;
        #150 D = 1'b1;	
	#100 $stop;
end
 
//instantiate the d-flipflop
edge_dff DFF(Q,  D, CLK );
 
endmodule

	
