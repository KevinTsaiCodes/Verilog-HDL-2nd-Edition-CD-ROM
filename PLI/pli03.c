#include "acc_user.h"
#include "veriuser.h"

#include <malloc.h>
#include <string.h>

struct mymodel
{
    handle	 in;
    handle	 out;
    char	*in_value;
};


int (*endofcompile_routines[])() = 
{
    /*** my_eoc_routine, ***/
    0 /*** final entry must be 0 ***/
};

bool err_intercept(level,facility,code)
int level; char *facility; char *code;
{ return(true); }

int mymodel_init();
int mymodel();

s_tfcell veriusertfs[] =
{
    /*** Template for an entry:
    { usertask|userfunction, data,  checktf(), sizetf(), calltf(), misctf(),
      "$tfname" },
    Example:
    { usertask, 0, my_check, 0, my_func, my_misctf, "$my_task" },
    ***/

    /*** add user entries here ***/

    {usertask,0, 0,0, mymodel_init, mymodel, "$mymodel", 0},

    {0} /*** final entry must be 0 ***/
};

static void
set_reg_value(reg, val, time)
  handle reg;
  char  *val;
  int    time;
{
    s_setval_value value;
    s_setval_delay delay;

    value.format    = accBinStrVal;
    value.value.str = val;
    delay.model     = accInertialDelay;
    delay.time.type = accTime;
    delay.time.low  = time;
    delay.time.high = 0;
    
    acc_set_value(reg, &value, &delay);
}

int
mymodel(data, reason, argn)
  int data;
  int reason;
  int argn;
{
    struct mymodel	*model;
    char		*new_input;

    /*
     * One of the parameters changed value.
     */
    if (reason == reason_paramvc)
    {
	/*
	 * The `in`put argument of `$mymodel` changed.
	 */
	if (argn == 1)
	{
	    /*
	     * Get the model associated with the instance of the `$mymodel`
	     * call whose `in`put just changed.
	     */
	    if (!(model = (struct mymodel *)tf_getworkarea()))
		return 0;

	    /*
	     * Get the new `in`put value.
	     */
	    new_input = acc_fetch_value(model->in, "%b", 0);

	    /*
	     * The input is rising.
	     */
	    if (*new_input == '1' && *model->in_value != '1')
	    {
		/*
		 * Save the new value of the input.
		 */
		strcpy(model->in_value, new_input);

		/*
		 * Change the output in, say, 5ps.
		 */
		set_reg_value(model->out, new_input, 5);
	    }
	    /*
	     * else the input is falling.
	     */
	    else if (*new_input == '0' && *model->in_value != '0')
	    {
		/*
		 * Save the new value of the input.
		 */
		strcpy(model->in_value, new_input);

		/*
		 * Change the output in, say, 20ps.
		 */
		set_reg_value(model->out, new_input, 20);
	    }
	    /*
	     * else the input just changed strength.
	     */
	}
	/*
	 * else some other argument of `$mymodel` changed.
	 */
    }
    /*
     * else `$finish` was executed.
     */
    else if (reason == reason_finish)
    {
	/*
	 * Get the model associated with the instance of the `$mymodel`
	 * call whose `in`put just changed.
	 */
	if (model = (struct mymodel *)tf_getworkarea())
	{
	    /*
	     * Cleanup.
	     */
	    free(model->in_value);
	    free(model);
	}

	tf_setworkarea(0);
    }
    /*
     * else some other reason.
     */

    return 0;
}

int
mymodel_init()
{
    struct mymodel	*model;

    /*
     * Allocate memory for all variables necessary to manage a single instance
     * of the model.
     */
    model = (struct mymodel *)malloc(sizeof(struct mymodel));

    /*
     * Initialize this instance of the model.
     */
    model->in  = acc_handle_tfarg(1);
    model->out = acc_handle_tfarg(2);
    model->in_value = (char *)malloc(10 /* Big enough to hold a value */);

    /*
     * Save a copy of the present `in`put value.
     */
    strcpy(model->in_value, acc_fetch_value(model->in, "%b", 0));
    
    /*
     * Save the model data with this instance of `$mymodel`.
     */
    tf_setworkarea((char *)model);
    
    /*
     * Enable callback of `mymodel` whenever any argument to this instance
     * of `$mymodel` changes.
     */
    tf_asynchon();

    /*
     * Set initial output value to Unknown.
     */
    set_reg_value(model->out, "x", 0);

    return 0;
}

