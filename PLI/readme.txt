Overview of PLI in Silos 2001:

A subset of the "acc_" and "tf_" PLI routines is supported in Silos 2001.  
The list of the PLI routines supported by this version of Silos 2001 can 
be found in the "silos.def" file in this directory.  To find out if 
Simucad has implemented additional PLI routines, contact Simucad:

	support@simucad.com

or:

	510-487-9700x206 (phone)
	510-487-9721 (fax)

For information on the PLI routines, please refer to the IEEE 1364
Verilog HDL specification that can be obtained from IEEE.  

Operating systems for which PLI is currently available is Sun Solaris, 
Linux, Windows 98, Windows 2000, and Windows NT. Support for PLI routines 
originating from both the user and vendor is provided.  

The PLI support mechanism in Silos 2001 has the following advantages:

        o The user does not have create a new Silos executable 
	  file through re-loading the released executable 
	  "sse.exe", or "silos.exe", with PLI object files.
          One "sse.exe" or "silos.exe" executable only is required for all PLI support.

        o The user may not have to own or purchase a compiler or linker which
	  reduces the cost.  A compiler or linker is not necessary if the 
	  ".dll" PLI library file on the PC or the ".so" PLI library file on 
	  Unix is provided to the user by a vender.  If these library files are
	  not provided (so that the user has to create them from the source or
	  object files), or if the user plans to write their own PLI routines, 
	  the user will have to own or purchase a compiler or linker.
	  On the PC, the Microsoft Visual C++ compiler, version 6.0 or higher,
	  is a useful compiler to purchase if you do not already own a 
	  compiler.

        o The user/vendor that wants to write PLI routines has the freedom to
          choose their compiler and linker of preference.

        o The user does not have to merge multiple vendor "veriuser.c"
          tables into a single "veriuser.c" file, nor does the user ever 
          compile any merged "veriuser.c" files. The headache of merging
          multiple vendor's "veriuser.c" files does not exist.

        o Re-compilation of user/vendor PLI routines does not require
          a time-consuming re-link of the "sse.exe" or "silos.exe" 
	  executable before the new PLI version can be tried out.


How to make Silos 2001 aware of "$tfname" PLI functions:
===================================================
After starting Silos 2001, select the "Project/Files" menu item and select
the "PLI Library Files" group in the "File Group" list box.  Add the PLI library
file names with the "Add" button to the project and they will be loaded when 
you activate the "Load/Reload" button on the tool bar.  It is not necessary to
include PLI libraries which your design does not reference (by "$tfname"s).

That's all.  You are ready to simulate!

To get a list of PLI libraries already loaded from the command line enter
"pliload" without a file-name.

How to make a PLI library:
==========================
The method used to make a PLI library varies between operating systems. Note
you can make as many PLI libraries as you wish, and there may be some logic
to partitioning different PLI functions into different libraries:
Review the appropriate section:

Sun Solaris:
	If you do not already have object files ("*.o"), compile the PLI source
	code to make them.  You may use whatever compilation flags you like,
	below is an example:

	    "cc -g -c -I./ myfile.c"          # step to compile C source

	Be sure to compile the "veriuser.c" file that 
	contains the "veriusertfs" table for these object files.  
	Do not include in the "veriusertfs" table entries for PLI routines not
	in the object files.

	Below is an brief explanation of the arguments for the veriusertfs
	table:

 		/*  /* routine prototypes -/
 		*   extern int PLIbook_hello_calltf();
		*  /* table entries -/
 		*   {usertask,                     /* type of PLI routine -/
 		*     0,                           /* user_data value -/
 		*     0,                           /* checktf routine -/
 		*     0,                           /* sizetf routine -/
 		*     PLIbook_hello_calltf,        /* calltf routine -/
 		*     0,                           /* misctf routine -/
 		*     "$hello",                    /* system task/function name -/
 		*     1                            /* forward reference = true -/
 		*   },
		*/

	Below is a sample veriusertfs table from example file pli01.c:

		extern int putp_01_calltf();
		s_tfcell veriusertfs[] = {
 		 {usertask,     0, 0, 0, putp_01_calltf,  0, "$putp_test", 1},
 		 {0}
		};

	To make a PLI library named "mypli.so" (you may use any prefix to name
	this file), use the unix command:


	    "ld -o mylib.so -dy -G *.o"      # step to load object file

	where "*.o" expands to the object files (including the "veriuser.o"
	file. Note your object files may reference other libraries.
	In this case be sure to load "mypli.so" with those libraries, 
	e.g. math library, "ld -o mylib.so -dy -G *.o -lm"
	You can put this procedure into a makefile to make debugging your
        PLI routines go quickly:
            OBJS = a.o b.o c.o veriuser.o
            mylib.so : $(OBJS)
            	ld -o mylib.so -dy -G $(OBJS)
	
	An example, pli01.mak,  for Sun Solaris can found in this directory.

	After you have created the .so file, you will then need to use the 
	"!pliload" command to specify the .so file for Silos 2001.  The 
	"!pliload" command can be put in any input file, as long as it
	is not within a module boundary, i.e. in file test_bench.v:

	  
		!pliload mypli.so
		module test_bench;
			...
		endmodule

Windows NT 4.0 or higher, or Windows 2000 or Windows 98:

	0)  There are three examples for the PLI:

		-  pli01.c  - 	this is a simple PLI example.  This example is
				used in the below procedure that shows how to
				use the PLI with Silos 2001 and HyperFault. 

		-  pli02.c  -  	illustrates 2 methods for initializing a Verilog 
				memory through the PLI.

		-  pli03.c  -   this example illustrates how to use a C model 
				instead of a behavioral module.  Possible uses 
				would be to protect intellectual property or 
				write models in C that would be awkward to write 
				in HDL code.


	1) Use the MS Visual C++ version 6.0 or higher (32 bits).  The 
		below instructions are for Visual C++ 6.0

	2)  Put ".c" and ".h" files in a directory.        

	3) Using any text editor, create a text file "mypli.def" that contains 
	   the following lines:
		LIBRARY
		EXPORTS
		  veriusertfs
		  <sub1>
		  <sub2>
                  ...
	   where <sub1>, <sub2>, and so on are subroutines Silos 2001 will call.
           Typically these names will be the names in the "veriusertfs" table.
	   For example PLI01, the PLI01.DEF file would be:

		LIBRARY "pli01"
		EXPORTS
		  veriusertfs
		  putp_01_calltf

           where file "PLI01.C" (the PLI library) has the following source:

		extern int putp_01_calltf();
		s_tfcell veriusertfs[] = {
		  {usertask,     0, 0, 0, putp_01_calltf,  0, "$putp_test", 1},
		  {0}
		};
		int putp_01_calltf() {....}

	   Below is an brief explanation of the arguments for the veriusertfs
	   table:

 		/*  /* routine prototypes -/
 		*   extern int PLIbook_hello_calltf();
		*  /* table entries -/
 		*   {usertask,                     /* type of PLI routine -/
 		*     0,                           /* user_data value -/
 		*     0,                           /* checktf routine -/
 		*     0,                           /* sizetf routine -/
 		*     PLIbook_hello_calltf,        /* calltf routine -/
 		*     0,                           /* misctf routine -/
 		*     "$hello",                    /* system task/function name -/
 		*     1                            /* forward reference = true -/
 		*   },
		*/

	4) Open Visual C++ by double-clicking on its icon.

	5) To create a new project in Visual C++, select the "File/New" menu 
	   to open the "New" dialog box.  Select the "Projects" tab for the 
	   "New" dialog box, and then select "Win32 Dynamic-Link Library" 
	   in the "Projects" tab.  

	   For the "Location:" box in the "Projects" tab, use the 
	   button to the right of the "Location:"  box to set the 
	   location to the C files. 

	   For the "Projects" tab, add the project name in the 
	   "Project name" box.  As you type in the project name, notice that
	   it is added to the "Location:" box.  Delete the project name where
	   it is added into the "Location:" box.  Ensure that the radio button
	   "Create new workspace" is checked, and the "Platforms:" box
	   has "Win32" checked.  Click on the "OK" button to close the "New"
	   dialog box.  

	   The "Win32 Dynamic link library" box comes up.  
	   Choose the option "An empty DLL project".
	   Click on Finish button.  Click on the OK button for the "New
	   Project Information" box.  

	   Select "Project/Add to Project/Files" to open the 
	   "Insert Files into Project" dialog box.  Select the
	   .c files for the project.  Either double click on each or click
	   on the OK button to add the file to the project.

	   Select "Project/Add to Project/Files" to open the 
	   "Insert Files into Project" dialog box.  
	   Use the drop down arrow to set the "Files of type" box to 
	   "Definition Files (.def)" in the "Insert Files into Project" 
	    dialog box.  Select the mydef.def file for the project.

	   Select "Project/Add to Project/Files" to open the 
	   "Insert Files into Project" dialog box.  
	   Use the drop down arrow to set the "Files of type" box to 
	   Library Files (.lib) in the "Insert Files into Project" dialog box.  
	   Navigate to the Silos 2001 installation directory, and add the appropriate 
	   library file (the sse.lib for Silos 2001 (sse.exe), the
	   silos.lib for the Silos simulator (silos.exe),
	   the hse.lib for the HyperFault GUI (hse.exe), and the hyperflt.lib
	   for the HyperFault command line version (hyperflt.exe)).  Click
	   on the OK button to close the dialog box.

	7) Select the Project/Settings menu selection to open the "Project
	   Settings" dialog box.  Select the C/C++ tab.  The Category box
	   should set to General category.  Check the "Generate browse info"
	   selection.  Then in the Category box select Code Generation.  
	   For the "Use runtime library" box, select the "Multithreaded DLL".  
	   Next in the Category box select "Precompiled Headers".  Now select 
	   "Not using precompilied headers".  Then in the Category box 
	   select "Preprocessor".  In the "Additional include directories" box
	   enter the path to the pli subdirectory in the installation 
	   directory for Silos 2001, i.e.: 

		c:\silos3\pli

	   Select the "Link" tab for the Project Settings dialog box.  The 
	   Category should be set to "General".  Ensure that "Generate debug
	   info" is checked.

	   Next select the "Browse Info" tab for the Project Settings dialog 
	   box.  Check the "Build Browse info file" option.

	   Click on the OK button to close the Project Settings dialog box.

	8) Select the Build/Build pli01.dll menu selection.  The result of 
	   the build should be zero errors and zero warnings.

	9) To run the command line Silos simulator, you need to access the ".DLL" file 
	   by entering a "!pliload" command from you netlist.  For more information, 
	   see the "Silos 2001 PLI Interface Overview" in the on-line help file for Silos 2001.  

	   The "!pliload" command can be put in any input file, as long as it
	   is not within a module boundary, i.e. in file test_bench.v:

	  
		!pliload mypli.dll
		module test_bench;
			...
		endmodule

	   For Silos 2001, you can specify the .DLL library 
	   by selecting the Project/Files menu selection in Silos 2001.  
	   In the "Project Files" dialog box for Silos 2001, use the drop-down 
	   arrow in the "File Group" box to select "PLI Library Files".  
	   For example PLI01, navigate down the hierarchy to directory 
	   "C:\SILOS3\pli\Debug" and add file "PLI01.DLL" to the 
	   "Files in Group:" box with the "File Group" box to set to
	   "PLI Library Files".  

	   Then use the drop-down arrow in the "File Group" box to select 
	   "Source Files" and add file "PLI01.V".  Next click-on 
	   the "Close" button to close the "Project Files" dialog box.  
	   Then press the "Go" button and you should be able to simulate 
	   file "PLI01.V" with the PLI.

	10) To debug your PLI:
	    Start up Visual C++ if it is not already running.  
	    Select the Project/Settings menu selection to open the "Project Settings"
	    dialog box.  Select the "Debug" tab.  In the "Executable for debug session"
	    edit box, specify the path to the sse.exe executable in the installation 
	    directory for Silos 2001.  Click on the "OK" button to close the dialog box.

	    Use File/Open menu selection to open the pli01.c file in the Visual C++ program.    
	    Place the mouse cursor on line 38 of file pli01.c, and then click on the 
	    "Insert/Remove Breakpoint" toolbar button (the small "hand" icon). This will
	    insert a breakpoint on line 38 of file pli01.c.
	   

	    Click on the "Go" toolbar button in Visual C++ (the button with the sheet 
	    of paper and the down arrow icon).  Click Ok to the information box that 
	    pops up stating that the sse.exe is not compiled for debug information.  


	Compilers other than Visual C++:

        1) Compile all source code, including the "veriusertfs" source.
	2) Create a text file "mypli.def" that contains the same lines 
	   as for the Visual C++ compiler.
	3) To make a PLI library named "mypli.dll" link as follows
	      "link \DLL \DEF:"mypli.def" silos.lib *.obj \OUT:"mypli.dll"
	   and be sure to include any other link command line arguments
	   you customarily use.
	
	Each PLI library you make is self contained, that is, it contains a
	"veriusertfs" table that references just the PLI routines contained 
	in the library.


	***Important Note for the PC***

        Some user written PLI functions are declared with arguments in their
        C code definition, e.g.
                    int 
                    mypli(arg1, arg2)
                      int arg1, arg2;
        This code is ANSI incorrect, as the simulator calls the PLI functions
        without any arguments, e.g. mypli();.
        The sun compiler doesn't care if there is an argument mis-match
        between the simulator and the definition, HOWEVER, the Microsoft
        compiler will generate code that will cause an exception in the
        simulator.





Using "$tfname" calls with Fault Simulation:

The fault simulator will make "$tfname" calls.  The calls will be made
from the reference simulation and any partition in which a fault is
simulating.  The following PLI extension routines can be used to
obtain an identifier.  A return value of 0 indicates the PLI call is
being made from the reference simulation.  A positive return value
identifies the simulating fault from which the PLI call is being made.

	extern	int		 tf_getfaultid(void);
	extern	int		 tf_igetfaultid(void *instance_p);

Care must be taken if the PLI routine uses statics.

"$tfname" calls outside the device-under-test (See "$fs_dut(..)") are never
made from a simulating fault, as the module in which the calls are located
is outside the DUT.


Extension PLI routines - the following PLI functions are extensions to OVI 
Verilog:

If you use these routines, include the file "ext_user.h".

Fault Simulation:

	Synopsis: Get the next fault
	Syntax:   handle acc_next_fault(handle fault);
	Returns:  A handle to a fault.
	Arguments: Null to obtain the first fault, or a handle from a previous
                  call.

	`acc_next_fault` iterates all faults selected by the user.  The
	user selects faults in a number of ways, e.g. statistically by
	percentage, named exclusion, named inclusion, and `directives.
	The faults are returned in alphabetical order by name as retrieved
	through `acc_fetch_fullname`.




	Synopsis: Get the fault actually simulated
	Syntax:   handle acc_handle_simulated_fault(handle fault);
	Returns:  Null if the fault is already the simulated fault or
                  a handle to the simulated fault.
	Arguments: A handle to a fault.

	When fault collapsing is turned on (the default), redundant faults
	e.g. input and output faults on a buffer, are grouped together
	into a class.
	In each group of redundant faults only one fault is simulated, and 
	that fault represents the entire group. `acc_handle_simulated_fault`
	returns the simulated fault if it's argument fault is one in a group,
	but not the simulated one.




	Synopsis: Get the faults in a class
	Syntax:   handle acc_next_fault_in_class(reference_fault, object_fault);
	Returns:  null if there are no more faults in the class, or the
                  next fault in the class.
	Arguments: `reference_fault` is the handle to a simulated fault
                   `object_fault` is initially null, and subsequently the
                   previously returned handle.

	The reference fault must be the simulated fault.
	`acc_next_fault_in_class` does not return the simulated fault,
	even though the simulated fault is in the class.





	Synopsys: Get the next fault being simulated in this pass
	Syntax:   handle acc_next_simulated_fault_in_pass(handle fault);
	Returns:  A handle to a fault
	Arguments: initially null, then the previously returned handle.

	Logic initialization must occur prior to access to these faults.
	This can be accomplished by "initial #1 $mycall();"



	Synopsis: Get information about a fault handle
	Syntax:   int acc_fetch_fault_detection(handle fault)
                  int acc_fetch_fault_direction(handle fault)
                  int acc_fetch_fault_stuck(handle fault)
                  unsigned long acc_fetch_fault_time_detected
                                  (handle fault, unsigned long *hightime)
	Returns:  An integer nmonic:
                      `acc_fetch_fault_detection` returns `FAULT_UNDETECTED`,
                                                          `FAULT_HARD`,
                                                          `FAULT_OSCIL`,
                                                          `FAULT_POSS`
                                                          `FAULT_NOMEM`.
                      `acc_fetch_fault_direction` returns `FAULT_INPUT`,
                                                          `FAULT_OUTPUT`.
                      `acc_fetch_fault_stuck` returns     `FAULT_LOW`,
                                                          `FAULT_HIGH`.
                      `acc_fetch_fault_time_detected` returns a 64 bit time.
	Arguments: A handle to a fault.

	These routines return important information about a fault.
	Note `acc_fetch_fullname` will return the name of the fault.




	Synopsis: Get statistics about the state of the fault simulation
	Syntax:   void acc_fetch_fault_statistics(struct fault_statistics*fs);
	Returns:  fills the argument structure passed with info about
                  the fault simulation progress.  See file "ext_user.h"
                  for excruciating detail of the `fault_statistics` structure.
	Argument: Address of a `fault_statistic` structure that gets filled in.




	Synopsis: Get which simulating fault is calling the "$tfcall"
        Syntax:   tf_getfaultid(void), tf_igetfaultid(void *instance_p)
	Returns:  0 for the reference simulation, positive integers for each
                  simulating fault.
