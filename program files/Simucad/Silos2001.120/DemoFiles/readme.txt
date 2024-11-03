	   =====================================
	               Silos 2001 
             Verilog HDL 2001 Toolbox Demonstration
	   ========================================

*******************************************************************
	Importent Note:
	Silos is updated and improved several times each year. 
	If you wish you may download the latest demonstration
	version of Silos from Simucad's web site, www.simucad.com.
*******************************************************************

SPECIAL NOTICES:

1)	This Silos 2001 Demonstration Program is designed to be used for 
	demonstration purposes only.  
	The program has specific limitations to prevent usage for commercial
	purposes.  There are features and capabilities which are intentionally 
	reduced or disabled.

	The demonstration version is limited to 200 gates and 350 lines of 
	behavioral code.

2)  	The Silos 2001 User's Manual is now available in PDF format
	in the "doc" subdirectory of the Silos 2001 CD and the Simucad
	web site, www.simucad.com.  

*******************************************************************
*******************************************************************

Silos 2001 is a graphical framework that integrates tools for the Verilog HDL designer.
The tools featured in the framework are:

	- Code Coverage;
	- Finite State Machine Editor;
	- Chromacoded Editor;
	- Help System;
	- Silos Simulator;
	- Hierarchy Browser;
	- Waveform Viewer.

Use of the mouse left, right buttons and drag-and-drop in the framework creates an
environment that integrates these tools simply, efficiently, and pleasing to use.

1)  This demonstration version of Silos 2001 supports the following IEEE 1364-2001
    Verilog Hardware Description features:

	- Generate Blocks
	- Attribute Properties
	- ANSI C style port definitions
	- Explicit in-line parameter passing
	- Comma separated sensitivity lists
	- Combinational logic sensitivity wild card
	- ANSI C style task/function I/O definitions
	- New timing constraint checks
	- Negative timing constraints
	- Enhanced file I/O



    This demonstration version of Silos 2001 also supports the Programming 
    Language Interface (PLI), and the Standard Delay File (SDF) format.


SYSTEM REQUIREMENTS: 

1) 	At least 16 MB of available memory is recommended.  Memory usage 
	varies depending on the design.  

2)	The installation requires less than 50 Mb of disk space.  
	The amount of disk needed during simulation will vary based 
	on the size of the circuit and its activity. 

3)      Windows 2000, Windows ME, Windows NT (version 4.0 or higher).



INSTALLATION:

To install Silos 2001 or HyperFault from the CD-ROM, see the readme.txt 
file at the top level of the CD-ROM.

EXAMPLES SUBDIRECTORY

ANALOG.SPJ      -       Project file for Analog to Digital converter 
			circuit that models the analog portion at 
			the behavioral level and the digital portion  
			at the gate level.  To run this example, see
			"Tutorial/Analog Behavioral Modeling (AHDL)"
			in the on-line help for the Silos 2001 User's
			Manual.  

CODE_COVERAGE.SPJ -     Project file for demonstrating code coverage
			for the Line report and Operator report for
			Verilog HDL behavioral code.  To run this 
			example, see "Tutorial/Code Coverage"
			in the on-line help for the Silos 2001 User's
			Manual.  

CODE_COVERAGE2.SPJ -    Project file for merging code coverage results
			from two different simulations using the same
			behavioral model and different testbenches.  
			To run this example, see "Tutorial/Code Coverage"
			in the on-line help for the Silos 2001 User's
			Manual.  

FLTSIM.SPJ	-	Project file for circuit that demonstrates the
			features for fault simulation.  To run this 
			example, see "Tutorial/Fault Simulation 
			Examples Overview" in the on-line help for 
			the HyperFault User's Manual.

GATE.SPJ	-	Project file for circuit that demonstrates
			traceback at the gate level.  Traceback
			is useful for finding problems after 
			synthesis.
			To run this example, see "Tutorial/Gate Level
			Debugging" in the on-line help for the 
			Silos 2001 User's Manual.

RTL_.SPJ	-	Project file for circuit that demonstrates
			features for debugging an RTL design.
			To run this example, see "Tutorial/RTL 
			(Behavioral)  Debugging" in the on-line help 
			for the Silos 2001 User's Manual.

RTL_ERR.SPJ	-	Project file for circuit that shows how
			to automatically open the source file for
			displaying a syntax error.
			To run this example, see "Tutorial/Error
			Reporting" in the on-line help for the Silos 2001 
			User's Manual.
			 
VENDING.SPJ	-	Project file for circuit that demonstrates
			features for a finite state machine.  To run this 
			example, see "Tutorial/Finite State Machine Entry" 
			in the on-line help for the Silos 2001 User's
			Manual.


*******************
IMPORTANT NOTICE
*******************


All versions of Silos, including this limited demonstration license, 
shall be treated as the confidential property of SIMUCAD, Inc.

This limited demonstration license is granted by SIMUCAD, Inc. and is
subject to the following conditions and limitations:

1)      There are no restrictions on making copies of this demonstration
	version of Silos (software and documentation).

2)      No person will decompile or disassemble this program or by any
	other similar means of reverse engineering undertake to discover
	the ideas, information and algorithms embodied in this program.

3)      This license is granted solely for the purpose of evaluating 
	SSE and use of this license for commercial purposes is
	strictly forbidden.



WARRANTY:

SIMUCAD makes no warranty of any kind, express or implied including,
without limitation, any warranties of merchantability and/or fitness
for a particular purpose. SIMUCAD shall not be liable for any damages, 
whether direct, indirect, special or consequential arising from a
failure of the program to operate in the manner desired by the user.
SIMUCAD shall not be liable for any damage to any property that may
be caused directly or indirectly by the software or duplication of
the software.


IN NO EVENT WILL SIMUCAD BE LIABLE FOR ANY DAMAGES INCLUDING ANY
LOST PROFITS, LOST SAVINGS OR OTHER INCIDENTAL OR CONSEQUENTIAL
DAMAGES ARISING OUT OF INABILITY TO USE THE PROGRAM, OR FOR ANY
OTHER CLAIM BY ANY OTHER PARTY.

COPYRIGHT NOTICES:

SIMUCAD and SILOS are registered trademarks of and SILOS III, Silos 2001, HyperFault,
SILOS II, SILOS, P/C-SILOS are trademarks of SIMUCAD, Inc.

Verilog is a registered trademark of Cadence Design Systems Inc.  
Other company and product names may be trademarks of the respective 
company with which they are associated. 
