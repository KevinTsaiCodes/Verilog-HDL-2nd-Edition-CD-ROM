To simulate the files in this directory, open project
file "dram.spj" in the Silos simulator and run it.

File Name       Description                      Reference in Book
---------       -----------                      -----------------
dram.v		Behavioral description		 Appendix F
		of a 256K X 16 DRAM. Must
		be included with testdram.v in
		a project file dram.spj
		for simulation.
		If you try to simulate it alone
		it will report errors.

testdram.v	Test Bench for the DRAM.Included
		in the project file dram.spj. This
		file cannot be simulated by itself.
		

dram.tim	Timing parameters used in the    
		testdram.v file. This file is already
		included in the stimulus file testdram.v.
		

ini_file	Initialization file to 		 
		initialize DRAM used in dram.v 
		and testdram.v . This file is already
		defined using defparam
		in the stimulus file testdram.v.
	
