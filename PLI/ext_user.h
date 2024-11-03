/*	Copyright (C) 1987-1993 Simucad Incorporated. 
 * 	              All Rights Reserved.
 *	This program contains confidential proprietary information
 *	which is not to be disclosed to unauthorized persons without
 *	the written consent of an officer of Simucad, Inc.
 *	The copyright is included to provide protection in the event
 *	of unauthorized or unintentional public disclosure.
 *
 * NAME
 *	"ext_user.h" - Extensions to "acc_user.h" PLI routines.
 * SYNOPSIS
 *
 * DESCRIPTION
 *
 * RETURN
 *
 * DIAGNOSTICS
 *
 * SEE ALSO
 * 	"acc_user.h"
 * NOTES
 */

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

/*
 * Fault detection.
 */
#define FAULT_UNDETECTED	(1<<0)	/* Undetected fault		*/
#define FAULT_HARD		(1<<1)	/* Hard detect			*/
#define FAULT_OSCIL		(1<<2)	/* Fault causes oscillation	*/
#define FAULT_POSS		(1<<3)	/* Possible detection		*/
#define FAULT_NOMEM		(1<<4)	/* Insufficient memory		*/
#define FAULT_HYPERTROPHIC	(1<<5)	/* Hypertrophic fault		*/
/*
 * Fault stuck level.
 */
#define	FAULT_LOW		0
#define	FAULT_HIGH		1

/*
 * Fault direction.
 */
#define FAULT_OUTPUT		0	/* Output stuck fault */
#define FAULT_INPUT		1	/* Input stuck fault */

/*
 * Added to type list from "acc_user.h".
 * Note "620" is the highest used type in "acc_user.h".
 * Note "1000" is arbitrarily chosen to hopefully not collide with additional
 * types added by Cadence.
 */
#define accFault		1000
#define accIteratedBlockVar	1001
#define accArrayElement		1002
#define accLocalParam		1003/* Don't know what's correct, not in IEEE*/
#define accRemoval		1004/* Don't know what's correct, not in IEEE*/
#define accRecrem		1005/* Don't know what's correct, not in IEEE*/
#define accTerminalBinding	1006

struct fault_statistics
{
    /*
     * `number_of_faults_selected` is the number of faults in the design
     * that have been selected.  The selection is influenced by the user
     * specified percentage coverage and any user specific excluded or included
     * faults.
     */
    int	 number_of_faults_selected;

    /*
     * Of the `number_of_faults_selected`, typically some are redundant, e.g.
     * input and output faults on a buffer.  In each group of redundant faults
     * only one fault is simulated, and that fault represents the entire
     * group.
     * `simulated_number_of_faults_selected` is the number of faults that
     * actually need to be simulated inorder to encompass the larger
     * `number_of_faults_selected`.
     */
    int	 simulated_number_of_faults_selected;
    /*
     * The following 4 numbers represent a detailed breakdown of
     * `simulated_number_of_faults_selected` by type and level.
     */
    int	 simulated_number_of_stuck_high;
    int	 simulated_number_of_stuck_low;
    int	 simulated_number_of_input_stuck_high;
    int	 simulated_number_of_input_stuck_low;

    /*
     * `number_of_faults_detected` is the number of faults detected,
     * measured against `number_of_faults_selected`.
     * `simulated_number_of_faults_detected` is the number of simulated faults
     * detected, measured against `simulated_number_of_faults_selected`.
     */
    int	 number_of_faults_detected;
    int	 simulated_number_of_faults_detected;

    /*
     * Section of information regarding iterative fault simulation,
     * i.e. "fsim/restart".
     */

    /*
     * `local_number_of_faults_simulated` is the number of faults that have been
     * simulated, including those faults still activly being simulated,
     * measured against `number_of_faults_selected`.
     * `simulated_local_number_of_faults_simulated` is the number of simulated
     * faults that have been simulated, including those faults still activly
     * being simulated,measured against `simulated_number_of_faults_selected`.
     * Note the command "fsim/restart", which is intended to allow replacment
     * of the input stimulus to accomplish iterative faulting, resets these
     * values to 0, which is why the field names contain "local".
     */
    int	 local_number_of_faults_simulated;
    int	 simulated_local_number_of_faults_simulated;

    /*
     * `local_number_of_faults_detected` is identical to
     * `number_of_faults_detected` and
     * `simulated_local_number_of_faults_detected` is identical to
     * `simulated_number_of_faults_detected`
     * except these values are reset to 0 when the command "fsim/restart"
     * is entered.
     * Note the ratio
     *   `local_number_of_faults_detected` / `local_number_of_faults_simulated
     * provides a percent detect for the current stimulus pattern.
     */
    int	 local_number_of_faults_detected;
    int	 simulated_local_number_of_faults_detected;

    /*
     * `local_number_of_faults_selected` is identical to
     * `number_of_faults_selected`, and
     * `simulated_local_number_of_faults_selected` is identical to
     * `simulated_number_of_faults_selected` except these values are
     * re-computed when the command "fsim/restart" is entered.
     * The re-computed value reflects only the remaining undetected
     * faults.
     */
    int	 local_number_of_faults_selected;
    int	 simulated_local_number_of_faults_selected;
};


#ifdef ANSI

extern	int		 acc_fetch_fault_detection(handle fault);
extern	int		 acc_fetch_fault_direction(handle fault);
extern	void		 acc_fetch_fault_statistics(struct fault_statistics*fs);
extern	int		 acc_fetch_fault_stuck(handle fault);
extern	char		*acc_fetch_test_node_of_detection(handle fault);
/*Use "acc_fetch_fullname" to print the name of the fault */
extern	unsigned int	 acc_fetch_fault_time_detected
(handle fault, unsigned int *hightime);
extern	handle		 acc_handle_simulated_fault(handle fault);
extern	handle		 acc_next_fault(handle fault);
extern	handle		 acc_next_fault_in_class
(handle simulated_fault, handle object_fault);
extern	handle		 acc_next_simulated_fault_in_pass(handle fault);
extern	int		 tf_getfaultid(void);
extern	int		 tf_igetfaultid(void *instance_p);
void			 acc_save_check_point();
void			 acc_restore_check_point();
extern	int		 acc_next_time_event(handle driver_handle, int	*aof_highvalue, int *aof_lowvalue);
extern	char		*verilog_element(char *verilog, char **state, int terminateOnIllegalIdentifierChar);
extern	int		 acc_parse_time(char *time, int *aoflowtime, int *aofhightime);


#else

extern	int		 acc_fetch_fault_detection();
extern	int		 acc_fetch_fault_direction();
extern	void		 acc_fetch_fault_statistics();
extern	int		 acc_fetch_fault_stuck();
extern	char		*acc_fetch_test_node_of_detection();
/*Use "acc_fetch_fullname" to print the name of the fault */
extern	unsigned int	 acc_fetch_fault_time_detected();
extern	handle		 acc_handle_simulated_fault();
extern	handle		 acc_next_fault();
extern	handle		 acc_next_fault_in_class();
extern	handle		 acc_next_simulated_fault_in_pass();
extern	int		 tf_getfaultid();
extern	int		 tf_igetfaultid();
void			 acc_save_check_point();
void			 acc_restore_check_point();
extern	int		 acc_next_time_event();
extern	char		*verilog_element();
extern	int		 acc_parse_time();

#endif /* ANSI */

#ifdef __cplusplus
}
#endif /* cplusplus */
