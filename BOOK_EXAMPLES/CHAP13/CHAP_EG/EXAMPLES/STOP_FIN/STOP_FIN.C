#include "veriuser.h"

int my_stop_finish()
{

	if(tf_nump() == 1) /* if 1 argument is passed to the my_stop_finish 
												task, execute the following code */
	{
		if(tf_getp(1) == 0)	/* get value of argument. if the argument 
													 is 0 then stop the simulation*/				
		{
			io_printf("Mymessage: Simulation stopped at time %d\n", tf_gettime());
			tf_dostop(); /*stop the simulation*/
		}
		else if(tf_getp(1) == 1)	/* if the argument is 0 then terminate 
													 the simulation*/				
		{
			io_printf("Mymessage: Simulation finished at time %d\n", tf_gettime());
			tf_dofinish(); /*terminate the simulation*/
		}
		else
			/* Pass warning message */
			tf_warning("Bad arguments to \$my_stop_finish at time %d\n", 
																										tf_gettime());

	}

	else if(tf_nump() == 2) /* if 1 argument is passed to the my_stop_finish 
                        task, then print module instance from which the
												task was called */
  {
    if(tf_getp(1) == 0) /* if the argument is 0 then stop 
                           the simulation*/
    { 
      io_printf("Mymessage: Simulation stopped at time %d in instance  %s \n", 
																tf_gettime(), tf_mipname()); 
      tf_dostop(); /*stop the simulation*/
    }
    else if(tf_getp(1) == 1)  /* if the argument is 0 then terminate
                           the simulation*/
    {    
      io_printf("Mymessage: Simulation finished at time %d in instance  %s \n", 
																tf_gettime(), tf_mipname()); 
      tf_dofinish(); /*terminate the simulation*/
    }   
    else
			/* Pass warning message */
			tf_warning("Bad arguments to \$my_stop_finish at time %d\n", 
																										tf_gettime());
  }

}
