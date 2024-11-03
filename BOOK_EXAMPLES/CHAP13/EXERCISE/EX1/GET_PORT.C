#include "acc_user.h"

int get_in_ports()
{
  handle  mod, port;
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

    port = acc_next_port(mod, port); /* go to the next port */
  }

  io_printf("Input Ports = %d \n", input_ctr);
  acc_close(); 

}

