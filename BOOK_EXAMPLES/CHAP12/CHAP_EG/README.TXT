File Name       Description                      Reference in Book
---------       -----------                      -----------------

udp_and.v	User's own definition of	 Section 12.2.1
		an AND primitive, udp_and.
		This file must be included
		in a project with file fulladd.v	
		for simulation in the project
		"fulladd.spj" . It cannot be 
		simulated by itself.

udp_or.v	User's own definition of	 Section 12.2.3
		an OR primitive, udp_or.
		The don't care symbol ? is used.
		This file must be included
		in a project with file fulladd.v	
		for simulation. in the project
		"fulladd.spj" . It cannot be 
		simulated by itself.


fulladd.v	A 1-bit full adder designed	 Section 12.2.4
		using the primitives udp_and
		and udp_or. A project file
		fuladd.spj has been created
		for you. To simulate this
		file, simply open project file
		"fulladd.spj" in the SILOS simulator
		and start simulation.

mux4_1.v	A 4-to-1 multiplexer using	 Section 12.2.5
		UDPs with stimulus.

latch.v		Level sensitive latch using	 Section 12.3.1
		UDP.

dff.v		Edge sensitive D-flipflop using	 Section 12.3.2
		UDP. A ripple counter is 
		designed using the D-ff's.

tff_cntr.v	Edge sensitive T-flipflop using	 Section 12.3.3
		UDP. A ripple counter is 
		designed using the T-ff's.

dffshort.v	Edge sensitive D-flipflop using	 Section 12.4
		UDP shorthand notation. A ripple 
		counter is designed using 
		the D-ff's.

