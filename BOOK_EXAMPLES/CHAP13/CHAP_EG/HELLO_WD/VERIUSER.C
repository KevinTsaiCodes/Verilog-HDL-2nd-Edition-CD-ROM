/* $Author: vince $ */
/* $Date: 1993/03/12 21:05:40 $ */
/* $Source: /net/cruncher/home3/verilog/VDH/Repository/source/veriuser.c,v $ */
/* $Revision: 46.4 $ */
/* $State: Exp $ */
/* $Locker:  $ */

/*
 * |-----------------------------------------------------------------------|
 * |                                                                       |
 * |   Copyright Cadence Design Systems, Inc. 1985, 1988.                  |
 * |     All Rights Reserved.       Licensed Software.                     |
 * |                                                                       |
 * |                                                                       |
 * | THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF CADENCE DESIGN SYSTEMS |
 * | The copyright notice above does not evidence any actual or intended   |
 * | publication of such source code.                                      |
 * |                                                                       |
 * |-----------------------------------------------------------------------|
 */

/*
 * |-------------------------------------------------------------|
 * |                                                             |
 * | PROPRIETARY INFORMATION, PROPERTY OF CADENCE DESIGN SYSTEMS |
 * |                                                             |
 * |-------------------------------------------------------------|
 */
/*****************************************************************************
*   This is the `veriuser.c' file.  For more information about the contents
*   of this file, please see `veriuser.doc'.
*****************************************************************************/

#include "veriuser.h"

char *veriuser_version_str = "";

int (*endofcompile_routines[])() = 
{
    /*** my_eoc_routine, ***/
    0 /*** final entry must be 0 ***/
};

bool err_intercept(level,facility,code)
int level; char *facility; char *code;
{ return(true); }

extern int hello_verilog();

s_tfcell veriusertfs[] =
{
    /*** Template for an entry:
    { usertask|userfunction, data,
      checktf(), sizetf(), calltf(), misctf(),
      "$tfname", forwref?, Vtool?, ErrMsg? },
    Example:
    { usertask, 0, my_check, 0, my_func, my_misctf, "$my_task" },
    ***/
    { usertask, 0, 0 , 0, hello_verilog , 0 , "$hello_verilog",0 },

    /*** add user entries here ***/

    {0} /*** final entry must be 0 ***/
};


