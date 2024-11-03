`timescale 1ns / 100 ps
module fault_strobe;

// declare delays as parameters for ease of modification.
parameter offset=50, wait_strobe=2;

// setup the stobe for the test nodes.
initial 
	// Specify a startup time of "offset" before strobing test nodes.  
	#offset 

	// After a negative clock edge occurs, 
	// strobe the test nodes after a wait time of "wait_strobe".
	forever @(negedge stimulate.clock) 
		#wait_strobe   $fs_strobe( stimulate.vendcoke,
				stimulate.vendpepsi, stimulate.vendsoft_drink );


endmodule
