/*///////////////////////////////////////////////////////////////////////
//
// title: C code for tf_putp() test to write a single simple value 
//
// This PLI C code uses tf_putp() to write a simple value to a Verilog
// system task/function argument (parameters).
//
///////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include "veriuser.h"

extern int putp_01_calltf();

char *veriuser_version_str = "";

int (*endofcompile_routines[])() = 
{
    /*** my_eoc_routine, ***/
    0 /*** final entry must be 0 ***/
};

bool err_intercept(level,facility,code)
int level; char *facility; char *code;
{ return(true); }

s_tfcell veriusertfs[] = {
  {usertask,     0, 0, 0, putp_01_calltf,  0, "$putp_test", 1},
  {0}
};


/* Use tf_putp() with a single task/function argument */
int putp_01_calltf() 
{
  int val = 1;
  io_printf("PLI Code:   tf_putp(1, val) is writing a value of %x (hex)\n",
    val);
  tf_putp(1, val);
  return(0);
}

