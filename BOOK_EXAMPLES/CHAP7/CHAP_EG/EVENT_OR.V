module stimulus;
wire Q;
reg D, CLK, RESET;

initial
begin
	CLK = 0;
	RESET = 1;

	#50 RESET = 0;
	#100 RESET = 1;
	#100 RESET = 0;
	#1000 $finish;
end

initial
begin
	D = 0;
	#3 forever #5 D = ~D;
end

always #5 CLK = ~CLK;

latch l1(Q, D, CLK, RESET);

endmodule


module latch(Q, d, clock, reset);

output Q;
input d, clock, reset;

reg q;

assign Q = q;

//A level sensitive latch with asynchronous reset 
always @( reset or clock or d) 
//Wait for reset or clock or d to change
begin 
        if (reset) 							 //if reset signal is high, set q to 0. 
                q = 1'b0; 
        else    if(clock)       //if clock is high, latch input  
                q = d; 
end 

endmodule
 

