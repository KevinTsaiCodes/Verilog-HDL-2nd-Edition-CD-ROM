To run RTL simulation, open project file rtl.spj
To run Gate simulation, open project file gate.spj

File Name		Description		
---------		-----------		

clookahd.v		RTL description of a	
			4-bit carry lookahead 
			adder.

clookahd.gv		gate level description 	
			of a 4-bit carry lookahead 
			adder.

stimulus.v		Stimulus file to verify 
			the functionality of
			gate vs. RTL description.

abc_100.v		Simulation library for	
			abc_100 technology cells.

abc_100.db		Synthesis library for
			abc_100 technology cells.
			This is in a Synopsys
			format.


To run the RTL level simulation, files needed are

clookahd.v	 stimulus.v 


To run the gate level simulation, files needed are

clookahd.gv,  stimulus.v, and  abc_100.v(library file).

For gate level simulation, the statement to include 
library file is specified at the top of file "clookahd.gv".


