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

extern int get_ports();
extern int my_monitor();
extern int my_stop_finish();

s_tfcell veriusertfs[] =
{
    { usertask, 0, 0 , 0, get_ports,0 , "$get_ports",0 },
    { usertask, 0, 0 , 0, my_monitor,0 , "$my_monitor",0 },
    { usertask, 0, 0 , 0, my_stop_finish,0 , "$my_stop_finish",0 },

    {0} /*** final entry must be 0 ***/
};


