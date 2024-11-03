#include "acc_user.h"

char convert_to_char();
int display_net();

int my_monitor()
{
	handle net;
  char *netname ; /*pointer to store names of nets*/
  char *malloc();

	acc_initialize(); /*initialize environment*/

	net = acc_handle_tfarg(1); /*get a handle to the net to be monitored*/

	/*Find hierarchical name of net and store it*/
  netname = malloc(strlen(acc_fetch_fullname(net)));
  strcpy(netname,  acc_fetch_fullname(net));

	/* Call the VCL routine to add a signal to the monitoring list*/
	/* Pass four arguments to add_vcl_add task*/
	/* 1st : handle to the monitored object (net) 
		 2nd : Consumer C routine to call when the object value changes (display_net)
		 3rd : String to be passed to consumer C routine (netname)
		 4th : Predefined VCL flags: vcl_verilog_logic for logic monitoring
																 vcl_verilog_strength for strength monitoring */
	acc_vcl_add(net, display_net, netname, vcl_verilog_logic);

	acc_close();
}

/*Consumer routine. Called whenever any monitored net changes*/
display_net(vc_record)
p_vc_record vc_record; /*Structure p_vc_record predefined in acc_user.h*/
{

	/*Print time, name and new value of the changed net */
	io_printf("%d New value of net %s is %c \n", 
									vc_record->vc_lowtime,
									vc_record->user_data,
									convert_to_char(vc_record->out_value.logic_value));
}

/*Miscellaneous routine to convert predefined character constant to 
	ASCII character*/
char convert_to_char(logic_val)
char logic_val;
{
	char temp;

	switch(logic_val)
	{
		/*vcl0, vcl1, vclX and vclZ are predefined in acc_user.h*/
		case vcl0: temp='0';
							 break;
		case vcl1: temp='1';
							 break;
		case vclX: temp='X';
							 break;
		case vclZ: temp='Z';
							 break;
	}
	return(temp);
}

	


	
