//this module executes in time 0. No stimulus
//is applied. This module demonstrates how
//wand and wor declarations work.
module wand_wor;

//Declare wand and wor nets.
wand out1;
wor out2;

//output is an and of the inputs.
buf (out1, 1'b0);
buf (out1, 1'b1);

//output is an or of the inputs.
buf (out2, 1'b0);
buf (out2, 1'b1);

initial
	$monitor ($time," out1 = %b, out2 = %b", out1, out2);

endmodule
