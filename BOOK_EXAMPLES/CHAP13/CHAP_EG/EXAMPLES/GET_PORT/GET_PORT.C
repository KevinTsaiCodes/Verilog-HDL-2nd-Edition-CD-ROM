#include "acc_user.h"

int get_ports()
{
	handle	mod, port;
	int input_ctr = 0;
	int output_ctr = 0;
	int inout_ctr = 0;

	acc_initialize();

	mod = acc_handle_tfarg(1); /* get a handle to the module instance
														    first argument in the system task argument
														    list */

	port = acc_handle_port(mod, 0); /* get the first port of the module */

	while( port != null ) /* loop for all ports */
	{
		if (acc_fetch_direction(port) == accInput) /* Input port */
		{
				io_printf("Input Port %s \n", acc_fetch_fullname(port)); 
																						/* full hierarchical name */
																											
				input_ctr++;
		}
		else if (acc_fetch_direction(port) == accOutput) /* Output port */
		{
				io_printf("Output Port %s \n", acc_fetch_fullname(port));
				output_ctr++;
		}
		else if (acc_fetch_direction(port) == accInout) /* Inout port */
		{
				io_printf("Inout Port %s \n", acc_fetch_fullname(port));
				inout_ctr++;
		}

		port = acc_next_port(mod, port); /* go to the next port */
	}

	io_printf("Input Ports = %d Output Ports = %d, Inout ports = %d\n\n",
												input_ctr, output_ctr, inout_ctr);
	acc_close(); 

}

