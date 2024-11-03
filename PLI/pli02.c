#include <stdio.h>
#include "veriuser.h"
#include "acc_user.h"

int (*endofcompile_routines[])() =
{
    /*** my_eoc_routine, ***/
    0 /*** final entry must be 0 ***/
};

bool err_intercept(level,facility,code)
int level; char *facility; char *code;
{ return(true); }

int	pli02();
int	pli02a();

s_tfcell veriusertfs[] =
{
    /*** Template for an entry:
    { usertask|userfunction, data,
      checktf(), sizetf(), calltf(), misctf(),
      "$tfname", forwref?, Vtool?, ErrMsg? },
    Example:
    { usertask, 0, my_check, 0, my_func, my_misctf, "$my_task" },
    ***/

    /*** add user entries here ***/

    {usertask,1234, 0,0, pli02,  0, "$pli02",  0},
    {usertask,1234, 0,0, pli02a, 0, "$pli02a", 0},


    {0} /*** final entry must be 0 ***/
};

int
pli02()
{
    tf_putp(2, tf_getp(1));
}

int
pli02a()
{
    char memory_name[1024];
    handle entire_memory;

    s_setval_value value_p;
    s_setval_delay delay_p;
    char *entire_value;

    strcpy(memory_name, tf_mipname());
    strcat(memory_name, ".");
    strcat(memory_name, "mem4");

    entire_memory = acc_handle_by_name(memory_name, 0);

    value_p.format      = accBinStrVal;
    
    /*
     * 1) Space, newline can separate the values of each memory element.
     * 2) If fewer binary digits are provided in an element, leading 0's are
     *    assumed.
     * 2) Values for all memory elements must be provided.
     */
    value_p.value.str   = "1111 1110 110111001011 1010 1001\n1000\n111\n0110\n0101\n0100\n0011 10 1 0";

    delay_p.model = accNoDelay;

    acc_set_value(entire_memory, &value_p, &delay_p);
}
