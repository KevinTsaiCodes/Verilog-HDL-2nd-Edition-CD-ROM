
/*
 _______________________________________________________
 |
 |       Verilog Release Number   :   1.6a.4
 |                    File Name   :   veriuser.h
 |                      SCCS ID   :   5.2
 |     SCCS Delta Creation Date   :   11/8/91
 |     SCCS Delta Creation Time   :   16:40:59
 |   SCCS Delta Extraction Date   :   11/8/91
 |   SCCS Delta Extraction Time   :   16:47:56
 |
 -------------------------------------------------------
 */

/* Filename: veriuser.h */

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */


/* general defines */

#define true 1
#define false 0
#define TRUE 1
#define FALSE 0
#define bool int

/* defines for error interception */

#define ERR_MESSAGE  1
#define ERR_WARNING  2
#define ERR_ERROR    3
#define ERR_INTERNAL 4
#define ERR_SYSTEM   5


/* VERILOG user tasks and functions C header file */

typedef struct t_tfcell
{
    short type;         /* either usertask or userfunction */
    short data;         /* parameter for the following routines */
    int (*checktf)();   /* routine for checking parameters */
    int (*sizetf)();    /* for providing size of function return value */
    int (*calltf)();    /* routine called during simulation */
    int (*misctf)();    /* miscellaneous routine (see below) */
    char *tfname;       /* the name of the system task or function */
    int forwref;       /* indicates special parameters allowed */
    char *tfveritool;   /* Which Veritool owns the task */
    char *tferrmessage; /* An optional special case error message
                          which will be printed if the task is skipped */

    /* these components are for system usage only */
    int hash;
    struct t_tfcell *left_p;
    struct t_tfcell *right_p;
    char *namecell_p;
    int warning_printed;  /* Flag is set when skipping warning is printed */
} s_tfcell, *p_tfcell;


/* values for component 'type' in tfcell structure */
#define usertask 1
#define USERTASK 1
#define userfunction 2
#define USERFUNCTION 2
#define userrealfunction 3
#define USERREALFUNCTION 3


/* The routines checktf, sizetf, calltf and misctf are always
passed two arguments: 'data' and 'reason'.
The value for 'data' is defined as the second component
supplied by the user in the above table structure.
The value for 'reason' is defined as follows:

   reason_checktf    for checktf
   reason_sizetf     for sizetf
   reason_calltf     for calltf
   reason_save       for misctf during $save
   reason_restart    for misctf during $restart
   reason_disable    for misctf during disable
   reason_paramvc    for misctf at a parameter value change (when enabled)
   reason_synch      for misctf at end of time slot for synchronisation
   reason_finish     for misctf at finish of simulation
   reason_reactivate for misctf at a delayed reactivation event
   reason_rosynch    for misctf at end of time slot read-only synchronisation
   reason_paramdrc   for misctf at a driver value change (when enabled)

(see below for the #defines on these)

Note that any of the routine pointers maybe 0, in which
case the calls from VERILOG are not made.

For the misctf at a parameter value change, the parameter
number is passed as the 3rd argument.
*/

/* values for 'reason' passed as 2nd argument */
#define reason_checktf 1
#define REASON_CHECKTF 1
#define reason_sizetf 2
#define REASON_SIZETF 2
#define reason_calltf 3
#define REASON_CALLTF 3
#define reason_save 4
#define REASON_SAVE 4
#define reason_restart 5
#define REASON_RESTART 5
#define reason_disable 6
#define REASON_DISABLE 6
#define reason_paramvc 7
#define REASON_PARAMVC 7
#define reason_synch 8
#define REASON_SYNCH 8
#define reason_finish 9
#define REASON_FINISH 9
#define reason_reactivate 10
#define REASON_REACTIVATE 10
#define reason_rosynch 11
#define REASON_ROSYNCH 11
#define reason_diverge 12
#define REASON_DIVERGE 12
#define reason_converge 13
#define REASON_CONVERGE 13
#define reason_vld_interact 14
#define REASON_VLD_INTERACT 14
#define reason_paramdrc 15
#define REASON_PARAMDRC 15
#define reason_endofcompile 16
#define REASON_ENDOFCOMPILE 16
#define reason_scope 17
#define REASON_SCOPE 17
#define reason_interactive 18
#define REASON_INTERACTIVE 18
#define reason_reset 19
#define REASON_RESET 19
#define reason_endofreset 20
#define REASON_ENDOFRESET 20
#define reason_force 21 /* for 'force' and procedural 'assign' */
#define REASON_FORCE 21
#define reason_release 22 /* for 'release' and 'deassign' */
#define REASON_RELEASE 22
#define reason_snapsave 23
#define reason_endofsnapsave 24
#define reason_snaprestart 25
#define reason_endofsnaprestart 26
#define reason_startofsave 27    /* for $save and $incsave */
#define reason_startofrestart 28 /* only for $restart, not '-r' restart */
#define REASON_FAULTSIM_DONE 60 /* HyperFault */
#define reason_faultsim_done 60
#define REASON_MAX 60

/* NOTE: Whenever updating the reasons please update the name list
   called rstr in tf_ctest.c and the REASON_MAX number */

#ifdef IBMC
#if IBMC
/* this header file to be included for compiling on IBM 370 machines only */
#include "ibmc1.6_beta.h"
#endif
#endif

/* user error message string */
extern char *tf_error_message;

/******** utility routines *********************/
extern char *tf_getinstance();

extern int tf_nump();
extern int tf_inump();

extern int tf_typep();
extern int tf_itypep();

extern int tf_getp();
extern int tf_igetp();
extern void tf_putp();
extern void tf_iputp();

extern double tf_getrealp();
extern double tf_igetrealp();
extern void tf_putrealp();
extern void tf_iputrealp();

extern char *tf_strgetp();
extern char *tf_istrgetp();

extern struct t_tfexprinfo *tf_exprinfo();
extern struct t_tfexprinfo *tf_iexprinfo();
extern struct t_tfnodeinfo *tf_nodeinfo();
extern struct t_tfnodeinfo *tf_inodeinfo();

#ifdef ANSI
/* Solaris 2.2 compiler complains if "void" is left out */
extern void tf_evaluatep();
extern void tf_ievaluatep();
#else
extern tf_evaluatep();
extern tf_ievaluatep();
#endif /* !ANSI */

#ifdef ANSI
extern int tf_propagatep();
extern int tf_ipropagatep();
#else
extern tf_propagatep();
extern tf_ipropagatep();
#endif

#ifdef ANSI
/* Solaris 2.2 compiler complains if "void" is left out */
extern void tf_asynchon();
extern void tf_iasynchon();
extern void tf_asynchoff();
extern void tf_iasynchoff();
#else
/*
 * This is the declarations from OVI.
 */
extern tf_asynchon();
extern tf_iasynchon();
extern tf_asynchoff();
extern tf_iasynchoff();
#endif

#ifdef ANSI
/* Solaris 2.2 compiler complains if "void" is left out */
extern void tf_synchronize();
extern void tf_isynchronize();
#else
/*
 * This is the declarations from OVI.
 */
extern tf_synchronize();
extern tf_isynchronize();
#endif

extern int tf_gettime();
extern double tf_getrealtime();
extern double tf_igetrealtime();

extern int tf_igettimeprecision();
extern int tf_gettimeprecision();

#ifdef lint /* Placate LINT */
extern void io_printf(); 
#else
#ifdef ANSI
#ifdef PLI_VA_ARG
extern void io_printf(char *fmt, ...); 
#else /* !PLI_VA_ARG */
/* Solaris 2.2 compiler complains if "void" is left out */
extern void io_printf(); 
#endif /* !PLI_VA_ARG */
#else
/*
 * This is the declarations from OVI.
 */
extern io_printf(); 
#endif
#endif

#ifdef ANSI
/*
 * Solaris 2.2 compiler complains if "void" is left out
 */
#ifdef PLI_VA_ARG
extern void tf_text(char *fmt, ...);
extern void tf_error(char *fmt, ...);
extern void tf_warning(char *fmt, ...);
extern void tf_message(int level, char *facility, char *code, char *fmt, ...);
#else /* !PLI_VA_ARG */
extern void tf_text();
extern void tf_error();
extern void tf_warning();
extern void tf_message();
#endif /* !PLI_VA_ARG */
extern void tf_dostop();
extern void tf_dofinish();
#else
/*
 * These are the declarations from OVI.
 */
extern tf_error();
extern tf_warning();
extern tf_text();
extern tf_message();
extern tf_dostop();
extern tf_dofinish();
#endif

extern char *tf_dumpfilename();

extern char *tf_getcstringp();
extern char *tf_igetcstringp();

extern int tf_setdelay();
extern int tf_isetdelay();
extern int tf_setlongdelay();
extern int tf_isetlongdelay();
extern int tf_setrealdelay();
extern int tf_isetrealdelay();

#ifdef ANSI
extern int tf_clearalldelays();
extern int tf_iclearalldelays();
#else
extern tf_clearalldelays();
extern tf_iclearalldelays();
#endif

extern int tf_strdelputp();
extern int tf_istrdelputp();
extern int tf_strlongdelputp();
extern int tf_istrlongdelputp();
extern int tf_strrealdelputp();
extern int tf_istrrealdelputp();

extern int tf_copypvc_flag();
extern int tf_icopypvc_flag();
extern int tf_movepvc_flag();
extern int tf_imovepvc_flag();
extern int tf_testpvc_flag();
extern int tf_itestpvc_flag();
extern int tf_getpchange();
extern int tf_igetpchange();

extern int tf_write_save();
extern int tf_read_restart();
#ifdef ANSI
/* Solaris 2.2 compiler complains if "void" is left out */
extern void tf_setworkarea();
extern void tf_isetworkarea();
#else
/*
 * This is the declarations from OVI.
 */
extern tf_setworkarea();
extern tf_isetworkarea();
#endif
extern char *tf_getworkarea();
extern char *tf_igetworkarea();

#ifdef ANSI
extern int tf_setroutine();
extern int tf_isetroutine();
extern int tf_settflist();
extern int tf_isettflist();
#else
extern tf_setroutine();
extern tf_isetroutine();
extern tf_settflist();
extern tf_isettflist();
#endif

extern char *(*tf_getroutine())();
extern char *(*tf_igetroutine())();
extern char *tf_gettflist();
extern char *tf_igettflist();

extern char *tf_mipname();
extern char *tf_imipname();
extern char *tf_spname();
extern char *tf_ispname();

extern int tf_sizep();
extern int tf_isizep();

#ifdef lint /* Placate LINT */
extern void io_mcdprintf(); 
#else
#ifdef ANSI
#ifdef PLI_VA_ARG
extern void io_mcdprintf(int mcd, char *fmt, ...); 
#else /* !PLI_VA_ARG */
/*
 * Solaris 2.2 compiler complains if "void" is left out
 */
extern void io_mcdprintf(); 
#endif /* !PLI_VA_ARG */
#else /* !ANSI */
extern io_mcdprintf(); 
#endif /* !ANSI */
#endif

extern char *mc_scan_plusargs();

extern int tf_getlongp();
extern int tf_igetlongp();
/* As per IEEE1364, returns are void, not int. */
extern void tf_putlongp();
extern void tf_iputlongp();

extern int tf_getlongtime();
extern char *tf_strgettime();

#ifdef ANSI
/*
 * Solaris 2.2 compiler complains if "void" is left out
 */
extern void tf_rosynchronize();
extern void tf_irosynchronize();
#else
/*
 * These are the declarations from OVI.
 */
extern tf_rosynchronize();
extern tf_irosynchronize();
#endif

extern int tf_getnextlongtime();
extern int tf_getnextrealtime();
extern char *tf_longtime_tostr();

extern int tf_compare_long();
#ifdef ANSI
/*
 * Solaris 2.2 compiler complains if "void" is left out
 */
extern void tf_add_long();
extern void tf_subtract_long();
#else
/*
 * These are the declarations from OVI.
 */
extern tf_add_long();
extern tf_subtract_long();
#endif

extern void tf_multiply_long(); 
extern void tf_divide_long(); 

extern void tf_scale_realdelay(); 
extern void tf_scale_longdelay(); 
extern void tf_unscale_realdelay(); 
extern void tf_unscale_longdelay(); 

extern void tf_real_to_long(); 
extern void tf_long_to_real(); 
/***********************************************/




/* data structure for use with tf_exprinfo routine to get
   expression information
*/
typedef struct t_tfexprinfo
{
    short expr_type; /* expression type information, one of:
        tf_nullparam
        tf_string
        tf_readonly
        tf_readwrite
        tf_rwbitselect
        tf_rwpartselect
        tf_rwmemselect
        tf_readonlyreal
        tf_readwritereal
        */
    short padding;
    struct t_vecval *expr_value_p; /* pointer to expression value */
    double real_value; /* expression value for 'real' expressions */
    char *expr_string; /* pointer to string when parameter is a string */
    int expr_ngroups; /* no of groups in expression value */
    int expr_vec_size; /* no of bits in expression value */
    int expr_sign; /* sign of the expression value:
                       0 for unsigned , non-zero for signed */
    int expr_lhs_select; /* not used at present
        result of either:
            bit-select
            msb of part-select
            element selection
        */
    int expr_rhs_select; /* not used at present
        result of either:
            bit-select (same value as previous component)
            lsb of part-select
            element selection (same value as previous component)
        */
} s_tfexprinfo, *p_tfexprinfo;



/* data structure for use with tf_nodeinfo routine to get
   node information
*/
typedef struct t_tfnodeinfo
{
    short node_type; /* expression type information, one of:
        tf_null_node
        tf_reg_node
        tf_integer_node
        tf_time_node
        tf_netvector_node
        tf_netscalar_node
        tf_memory_node
        tf_real_node
        */
    short padding;
    union
    {
        struct t_vecval *vecval_p; /* reg, integer, time, net vector value */
        struct t_strengthval *strengthval_p; /* net scalar value */
        char *memoryval_p; /* memory value */
        double *real_val_p; /* type 'real' value */
    } node_value;
    char *node_symbol; /* identifying string of node */
    int node_ngroups; /* no of groups in node value */
    int node_vec_size; /* no of bits in node value */
    int node_sign; /* sign of the node value
                       0 for unsigned , non-zero for signed */
    int node_ms_index; /* not used at present
                           most significant index of node value */
    int node_ls_index; /* not used at present
                           least significant index of node value */
    int node_mem_size; /* no of elements in memory structure */
    int node_lhs_element; /* not used at present
                              lhs memory element address */
    int node_rhs_element; /* not used at present
                              rhs memory element address */
    int *node_handle; /*jjp052389 add handle field for access integration */
} s_tfnodeinfo, *p_tfnodeinfo;



/* data structure of vector values */
typedef struct t_vecval
{
    int avalbits; /* bit-coding for each bit of vector: */
    int bvalbits; /* ab: 00=0, 10=1, 11=X, 01=Z */
} s_vecval, *p_vecval;



/* data structure of scalar net strength values */
typedef struct t_strengthval
{
    int strength0; /* 0 strength component */
    int strength1; /* 1 strength component */
} s_strengthval, *p_strengthval;



/*
   data structure of memory values
   byte array organized in format:

        struct
        {
            char avalbits[ngroups];    bit-coding for each element:
            char bvalbits[ngroups];    ab: 00=0, 10=1, 11=X, 01=Z
        } memval[mem_size];

   with element addressed by left-hand-side index in
   declaration as the first word.
   N.B. this data structure cannot be represented in C, thus it
   it is declared as an array of char's.
*/




/* types used by tf_typep() and expr_type in tf_exprinfo structure */
#define tf_nullparam 0
#define TF_NULLPARAM 0
#define tf_string 1
#define TF_STRING 1
#define tf_specialparam 2
#define TF_SPECIALPARAM 2
#define tf_readonly 10
#define TF_READONLY 10
#define tf_readwrite 11
#define TF_READWRITE 11
#define tf_rwbitselect 12
#define TF_RWBITSELECT 12
#define tf_rwpartselect 13
#define TF_RWPARTSELECT 13
#define tf_rwmemselect 14
#define TF_RWMEMSELECT 14
#define tf_readonlyreal 15
#define TF_READONLYREAL 15
#define tf_readwritereal 16
#define TF_READWRITEREAL 16

/* types used by node_type in tf_nodeinfo structure */
#define tf_null_node 100
#define TF_NULL_NODE 100
#define tf_reg_node 101
#define TF_REG_NODE 101
#define tf_integer_node 102
#define TF_INTEGER_NODE 102
#define tf_time_node 103
#define TF_TIME_NODE 103
#define tf_netvector_node 104
#define TF_NETVECTOR_NODE 104
#define tf_netscalar_node 105
#define TF_NETSCALAR_NODE 105
#define tf_memory_node 106
#define TF_MEMORY_NODE 106
#define tf_real_node 107
#define TF_REAL_NODE 107

#ifdef __cplusplus
}
#endif /* cplusplus */
