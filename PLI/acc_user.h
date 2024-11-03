
/*
 _______________________________________________________
 |
 |       Verilog Release Number   :   1.6a.4
 |                    File Name   :   acc_user.h
 |                      SCCS ID   :   5.2
 |     SCCS Delta Creation Date   :   11/8/91
 |     SCCS Delta Creation Time   :   16:30:33
 |   SCCS Delta Extraction Date   :   11/8/91
 |   SCCS Delta Extraction Time   :   16:47:59
 |
 -------------------------------------------------------
 */
/*** File acc_user.c ***/
/*** This file is to be included in files which call access routines ***/

#define ACCUSERH 1

/**********************************************************************/
/*** General constant definitions ***/

#ifndef ACCH

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

typedef int *HANDLE;
typedef int *handle;

#define bool int
#define true 1
#define TRUE 1
#define false 0
#define FALSE 0

#define exfunc
#define local static
#define null 0L

extern bool acc_error_flag;

#endif

/**********************************************************************/
/*** Type and configuration constant definitions ***/

#define    accModule               20
#define    accScope                21
#define    accNet                  25
#define    accReg                  30
#define    accRegister             30
#define    accPort                 35
#define    accTerminal             45
#define    accInputTerminal        46
#define    accOutputTerminal       47
#define    accInoutTerminal        48
#define    accCombPrim            140
#define    accSeqPrim             142
#define    accAndGate             144
#define    accNandGate            146
#define    accNorGate             148
#define    accOrGate              150
#define    accXorGate             152
#define    accXnorGate            154
#define    accBufGate             156
#define    accNotGate             158
#define    accBufif0Gate          160
#define    accBufif1Gate          162
#define    accNotif0Gate          164
#define    accNotif1Gate          166
#define    accNmosGate            168
#define    accPmosGate            170
#define    accCmosGate            172
#define    accRnmosGate           174
#define    accRpmosGate           176
#define    accRcmosGate           178
#define    accRtranGate           180
#define    accRtranif0Gate        182
#define    accRtranif1Gate        184
#define    accTranGate            186
#define    accTranif0Gate         188
#define    accTranif1Gate         190
#define    accPullupGate          192
#define    accPulldownGate        194
#define    accIntegerParam        200
#define    accIntParam            200
#define    accRealParam           202
#define    accStringParam         204
#define    accPath                206
#define    accTchk                208
#define    accPrimitive           210
#define    accBit                 212
#define    accPortBit             214
#define    accNetBit              216
#define    accRegBit              218
#define    accParameter           220
#define    accSpecparam           222
#define    accTopModule           224
#define    accModuleInstance      226
#define    accCellInstance        228
#define    accModPath             230
#define    accPrimPath            232
#define    accWirePath            234
#define    accModNetPath          236 /*alias for accInterModPath*/
#define    accInterModPath        236
#define    accTermPath            238
#define    accModTermPath         240
#define    accTermModPath         242
#define    accScalarPort          250
#define    accBitSelectPort       252
#define    accPartSelectPort      254
#define    accVectorPort          256
#define    accConcatPort          258
#define    accWire                260
#define    accWand                261
#define    accWor                 262
#define    accTri                 263
#define    accTriand              264
#define    accTrior               265
#define    accTri0                266
#define    accTri1                267
#define    accTrireg              268
#define    accSupply0             269
#define    accSupply1             270
#define    accNamedEvent          280
#define    accEventVar            280
#define    accIntegerVar          281
#define    accIntVar              281
#define    accRealVar             282
#define    accTimeVar             283
#define    accScalar              300
#define    accVector              302
#define    accCollapsedNet        304
#define    accExpandedVector      306
#define    accUnExpandedVector	  307
#define    accProtected           308
#define    accVlogSimPath         310
#define    accExpandedPath        312
#define    accSwXlInvisibleNet    314
#define    accAcceleratedNet      316
#define    accSetup               366
#define    accHold                367
#define    accWidth               368
#define    accPeriod              369
#define    accRecovery            370
#define    accSkew                371
#define    accNochange            376
#define    accNoChange            376
#define    accSetuphold           377
#define    accInput               402
#define    accOutput              404
#define    accInout               406
#define    accMixedIo             407
#define    accPositive            408
#define    accNegative            410
#define    accUnknown             412
#define    accPathTerminal        420
#define    accPathInput           422
#define    accPathOutput          424
#define    accDataPath            426
#define    accTchkTerminal        428
#define    accBitSelect           500
#define    accPartSelect          502
#define    accTask                504
#define    accFunction            506
#define    accStatement           508
#define    accTaskCall            510
#define    accFunctionCall        512
#define    accSystemTask          514
#define    accSystemFunction      516
#define    accSystemRealFunction  518
#define    accUserTask            520
#define    accUserFunction        522
#define    accUserRealFunction    524
#define    accAssignmentStat      526
#define    accContAssignStat      527
#define    accNullStat            528
#define    accDelayStat           530
#define    accAssignDelayStat     532
#define    accRtlDelayStat        534
#define    accAssignEventStat     536
#define    accAssignMultiStat     537
#define    accRtlEventStat        538
#define    accRtlMultiStat        539
#define    accGenEventStat        540
#define    accDisableStat         542
#define    accAssignStat          544
#define    accDeassignStat        546
#define    accForceStat           548
#define    accReleaseStat         550
#define    accInitialStat         552
#define    accAlwaysStat          554
#define    accAtEventStat         556
#define    accUnnamedBeginStat    558
#define    accNamedBeginStat      560
#define    accUnnamedForkStat     562
#define    accNamedForkStat       564
#define    accIfStat              566
#define    accCaseStat            568
#define    accCaseZStat           570
#define    accCaseXStat           572
#define    accForeverStat         574
#define    accRepeatStat          576
#define    accWhileStat           578
#define    accForStat             580
#define    accWaitStat            582
#define    accConstant            600
#define    accConcat              610
#define    accOperator            620
#define	   accPlusOp		  630  
#define	   accMinusOp		  632  
#define	   accLogNotOp		  634  
#define	   accBitNegOp		  636  
#define	   accRedAndOp		  638  
#define	   accRedNandOp		  640  
#define	   accRedOrOp		  642  
#define	   accRedNorOp		  644  
#define	   accRedXorOp		  646  
#define	   accRedXnorOp		  648  
#define	   accSubOp		  650  
#define	   accDivOp		  652  
#define	   accModOp		  654  
#define	   accEqOp		  656  
#define	   accNeqOp		  658  
#define	   accEqeOp		  660  
#define	   accNeeOp		  662  
#define	   accGtOp		  664  
#define	   accGeOp		  666  
#define	   accLtOp		  668  
#define	   accLeOp		  670  
#define	   accLshOp		  672  
#define	   accRshOp		  674  
#define	   accAddOp		  676  
#define	   accMultOp		  678  
#define	   accLogAndOp		  680  
#define	   accLogOrOp		  682  
#define	   accBitAndOp		  684  
#define	   accBitOrOp		  686  
#define	   accBitXorOp		  688  
#define	   accBitXnorOp		  690  
#define	   accCondOp		  692  
#define	   accExprList		  694  
#define	   accMinTypMax		  696
#define	   accDupConcat		  698  
#define	   accUdpDefn		  700  
#define	   accSeqUdpDefn	  702  
#define	   accCombUdpDefn	  704  
#define	   accUdpEntry		  706  
#define	   accContAssign	  708  
#define	   accExpNamedPort	  710  
#define	   accAssignDriver	  712  
#define	   accModportDriver	  714  
#define	   accModPathHasIfnone	  715  
#define	   accTwoLimitTchk	  716  
#define	   accTimingModel	  718  
#define	   accMultiSrcInt	  720  
/*#define  accFault		  1000 Defined in "ext_user.h" */
/*#define  accIteratedBlockVar	  1001 Defined in "ext_user.h" */
/*#define accArrayElement	  1002 Defined in "ext_user.h" */
/*#define accLocalParam		  1003 Defined in "ext_user.h" */

/* acc_configure() parameters */
#define    accPathDelayCount        1
#define    accPathDelimStr          2
#define    accDisplayErrors         3
#define    accDefaultAttr0          4
#define    accToHiZDelay            5
#define    accEnableArgs            6
#define    accSpecitemScope         7
#define    accDisplayWarnings       8
#define    accWarnNestedLoconn      9
#define    accWarnNestedHiconn     10
#define    accDevelopmentVersion   11
#define    accMinMultiplier        12
#define    accTypMultiplier        13
#define    accMaxMultiplier        14
#define    accAttrDelimStr         15 
#define    accDelayCount           16
#define    accMapToMipd            17
#define    accDelayArrays          18
#define    accMinTypMaxDelays      19
#define    accUserErrorString      20
#define	   accTwoLimitChecks		  21  
#define	   accEnableUdpDefn		  22  
#define	   accSplitSetuphold		  23  
#define	   accSplitSetupHold		  23  
#define	   accBehavDrivers		  24  
#define	   accReturnExpPortNames	  25  
#define	   accShowContAssignLoads	  26  
#define	   accNoUnExpPortsErrors	  27  
#define	   accScaleDelays		  28  

/* Edge information used by acc_handle_tchk, etc. */
#define accNoedge         0
#define accNoEdge         0
#define accEdge01         1
#define accEdge10         2
#define accEdge0x         4
#define accEdgex1         8
#define accEdge1x        16 
#define accEdgex0        32 
#define accPosedge       13  /* accEdge01 & accEdge0x & accEdgex1 */
#define accPosEdge       13  /* accEdge01 & accEdge0x & accEdgex1 */
#define accNegedge       50  /* accEdge10 & accEdge1x & accEdgex0 */
#define accNegEdge       50  /* accEdge10 & accEdge1x & accEdgex0 */

/* Product types */
#define accVerilog        1
#define accVeritime       2
#define accVerifault      3

/* Version defines */
#define accVersion15Beta    1
#define accVersion15a       2
#define accVersion15b       3
#define accVersion15b1      4
#define accVersion15b2Beta  5
#define accVersion15b2      6
#define accVersion15b3      7
#define accVersion15b4      8
#define accVersion15b5      9
#define accVersion15cBeta  12
#define accVersion15c      16
#define accVersion15c03    20
#define accVersion15c04    21
#define accVersion15c10    24
#define accVersion15c30    28
#define accVersion15c40    32
#define accVersion15c41    33
#define accVersion16Beta   36
#define accVersion16Beta2  37
#define accVersion16Beta3  38
#define accVersion16Beta4  39
#define accVersion16       40
#define accVersion161      41
#define accVersion16aBeta  42
#define accVersion16aBeta3 43
#define accVersion16aBeta5 44
#define accVersion16a      45
#define accVersion16a1     46
#define accVersion16a3     47
#define accVersion16a4     48
#define accVersionLatest   accVersion16a4

/* Delay modes */
#define accDelayModeNone     0
#define accDelayModePath     1
#define accDelayModeDistrib  2
#define accDelayModeUnit     3
#define accDelayModeZero     4
#define accDelayModeVeritime 5


/*****************************
** typedefs for time structure
*/

typedef struct t_acc_time { 
    int type;        /* one of accTime accSimTime accRealTime */ 
    int low, high; /* for accTime and accSimTime */ 
    double real;   /* for accRealTime */ 
} s_acc_time, *p_acc_time;

/* t_acc_time types */
#define accTime            1  /* timescaled time */
#define accSimTime         2  /* internal simulation time */
#define accRealTime        3  /* timescaled real time */

/******************************************
** product types (Added 10.96 from pg. C-5 IEEE P1364 Oct 1995
*/
#define accSimulator 1
#define accFaultSimulator 3

/******************************************
** typedefs and defines for acc_set_value()
*/

typedef struct t_setval_delay { 
    s_acc_time time;
    int model;     
        /* accNoDelay */ 
        /* accInertialDelay */
        /* accTransportDelay */
        /* accPureTransportDelay */
        /* accForceFlag */
        /* accReleaseFlag */
        /* accAssignFlag */
        /* accDeassignFlag */
} s_setval_delay, *p_setval_delay; 
    

/* t_setval_delay types */
#define accNoDelay               0
#define accInertialDelay         1
#define accTransportDelay        2
#define accPureTransportDelay    3
/* Added 10/96 from IEEE 1364 pp C-4 */
#define accForceFlag		 4
#define accReleaseFlag		 5
#define accAssignFlag		 6
#define accDeassignFlag		 7
 
 
/*
 * Added 1/2/96 from p19-71 IEEE P1364 Apr. 1995.
 * Encoding:
 *	aval bval value
 *	   0    0     0
 *	   1    0     1
 *	   0    1     Z
 *	   1    1     X
 */
typedef struct t_acc_vecval
{
    int	aval;	/* bit-coding for each bit of vector: */
    int	bval;	/* ab: 00=3D0, 10=3D1, 11=3DX, 01=3DZ */
} s_acc_vecval, *p_acc_vecval;


typedef struct t_setval_value {
  int format; /* acc[[Bin,Oct,Dec,Hex]Str,Scalar,Int,Real]Val */
  union {
    char *str;
    int scalar; /* acc[0,1,X,Z] */
    int integer;
    double real;
    /*
     * Added 1/2/96 from p19-71 IEEE P1364 Apr. 1995.
     */
    p_acc_vecval vector;
  } value;
} s_setval_value, *p_setval_value,
  s_acc_value, *p_acc_value;
 
/* t_setval_value formats */
#define accBinStrVal             1
#define accOctStrVal             2
#define accDecStrVal             3
#define accHexStrVal             4
#define accScalarVal             5
#define accIntVal                6
#define accRealVal               7
#define accStringVal             8
#define accCompactVal            9
/*
 * Added 1/2/96 from pC-4 IEEE P1364 Apr. 1995.
 */
#define accVectorVal            10
#define accTimeVal		11  

/* scalar values */
#define acc0    0
#define acc1    1
#define accX    2
#define accZ    3


/**********************************************************************/
/*
 * includes for Value Change Link
 */

#define logic_value_change       1
#define strength_value_change    2
#define real_value_change        3
#define vector_value_change      4
#define event_value_change       5
#define integer_value_change     6
#define time_value_change        7
#define sregister_value_change   8
#define vregister_value_change   9 
#define realtime_value_change   10
#define compact_value_change    11


typedef void (*consumer_function) ();

/* structure that stores strengths */
typedef struct t_strengths {
    unsigned char    logic_value;
    unsigned char    strength1;
    unsigned char    strength2;
} s_strengths, *p_strengths;


typedef struct t_vc_record{
    unsigned int                  vc_reason;
    unsigned int                  vc_hightime;
    int                           vc_lowtime;
    char                          *user_data;
    union  {
        unsigned char      logic_value;
        double             real_value;
        handle             vector_handle;
        s_strengths        strengths_s;
    } out_value;
} s_vc_record, *p_vc_record;

/* logic values */
#define vcl0    acc0
#define vcl1    acc1
#define vclX    accX
#define vclZ    accZ

/* VCL strength values */
#define vclSupply            7
#define vclStrong            6
#define vclPull              5
#define vclLarge             4
#define vclWeak              3
#define vclMedium            2
#define vclSmall             1
#define vclHighZ             0

/* vcl bit flag definitions */
#define vcl_strength_flag    1
#define vcl_verilog_flag     2
#define vcl_veritime_flag    4
#define vcl_compact_flag     8


/* flags used with acc_vcl_add */
#define vcl_verilog_logic           (vcl_verilog_flag)
#define VCL_VERILOG_LOGIC           (vcl_verilog_flag)
 
#define vcl_verilog_strength        (vcl_verilog_flag + vcl_strength_flag)
#define VCL_VERILOG_STRENGTH        (vcl_verilog_flag + vcl_strength_flag)
 
/* flags used with acc_vcl_delete */
#define vcl_verilog             (vcl_verilog_flag)
#define VCL_VERILOG             (vcl_verilog_flag)

/* test whether strength information is requested for vcl */
#define vcl_setstr_m(flags_) ( flags_ |= vcl_strength_flag )
#define vcl_clearstr_m(flags_) ( flags_ &= ~vcl_strength_flag )
#define vcl_isstr_m(flags_) ( flags_ & vcl_strength_flag )

/* test whether Verilog information is requested for vcl */
#define vcl_setvl_m(flags_) ( flags_ |= vcl_verilog_flag )
#define vcl_clearvl_m(flags_) ( flags_ &= ~vcl_verilog_flag )
#define vcl_isvl_m(flags_) ( flags_ & vcl_verilog_flag )

/* test whether Veritime information is requested for vcl */
#define vcl_setvt_m(flags_) ( flags_ |= vcl_veritime_flag )
#define vcl_clearvt_m(flags_) ( flags_ &= ~vcl_veritime_flag )
#define vcl_isvt_m(flags_) ( flags_ & vcl_veritime_flag )

/* test whether vcl trigger is compact or normal */
#define vcl_setcompact_m(flags_) ( flags_ |= vcl_compact_flag )
#define vcl_clearcompact_m(flags_) ( flags_ &= ~vcl_compact_flag )
#define vcl_iscompact_m(flags_) ( flags_ & vcl_compact_flag )

/**********************************************************************/
/*** includes for acc_xlp_status ***/

#define MAX_NUMBER_OF_XLP  5

#define xlp_status_RUNNING    0
#define xlp_status_NO_XLP     1
#define xlp_status_IN_USE     2
#define xlp_status_AVAILABLE  3

/* structure that stores xlp status information */
typedef struct t_xlp_info {
    int  xlp_unit_number;
    int  xlp_memory_used;
    long xlp_transaction_count;
    long xlp_event_count;
    int  xlp_status[MAX_NUMBER_OF_XLP];
    int  xlp_owner [MAX_NUMBER_OF_XLP];
} s_xlp_info, *p_xlp_info;

/**********************************************************************/
/*** includes for the location structure ***/
/* structure that stores location */
typedef struct t_location {
    int line_no;
    char *filename;
} s_location, *p_location;

/**********************************************************************/
/*** acc_fetch_timescale_info structure - Copied from IEEE C-7 12/19/96 */
/**********************************************************************/
typedef struct t_timescale_info
{
    short unit;
    short precision;
} s_timescale_info, *p_timescale_info;

/**********************************************************************/
/*** includes for the time callbacks ***/
#define reason_begin_of_simtime     1
#define reason_end_of_simtime       2

/**********************************************************************/
/*
 * include information for stability checks
 */
#define accTaskFuncStable       0x0001
#define accSystfStable          0x0002
#define accPrimStable           0x0004
#define accContAssignStable     0x0008
#define accBehavStable          0x0010
#define accNetRegVarStable      0x0020
#define acc_taskfunc_stable     accTaskFuncStable
#define acc_systf_stable        accSystfStable
#define acc_primitive_stable    accPrimStable
#define acc_contassign_stable   accContAssignStable
#define acc_behav_stable        accBehavStable
#define acc_netreg_stable       accNetRegVarStable
#define acc_setstabflags_m(_flags,_pos)   (_flags |= _pos)
#define acc_clearstabflags_m(_flags,_pos) (_flags &= ~_pos)
#define acc_isstabflags_m(_flags,_pos)    (_flags & _pos)


/**********************************************************************/
/*** Routine declarations ***/

#ifndef ACCH

/* Handle routines */
handle  acc_handle_defn();
handle  acc_handle_object();
handle  acc_handle_port();
handle  acc_handle_terminal();
handle  acc_handle_parent();
handle  acc_handle_conn();
handle  acc_handle_tchk();
handle  acc_handle_pathout();
handle  acc_handle_pathin();
handle  acc_handle_tchkarg1();
handle  acc_handle_tchkarg2();
handle  acc_handle_modpath();
handle  acc_handle_path();
handle  acc_handle_simulated_net();
handle  acc_handle_loconn();
handle  acc_handle_hiconn();
handle  acc_handle_datapath();
handle  acc_handle_condition();
handle  acc_handle_by_name();
handle  acc_handle_by_location();
handle  acc_handle_scope();
handle  acc_handle_notifier();

/* Nexts routines */
handle  acc_next_terminal();
handle  acc_next_port();
handle  acc_next_child();
handle  acc_next_driver();
handle  acc_next_load();
handle  acc_next_primitive();
handle  acc_next_net();
handle  acc_next_topmod();
handle  acc_next_loconn();
handle  acc_next_hiconn();
handle  acc_next_modpath();
handle  acc_next_path(); /* alias for acc_next_modpath */
handle  acc_next_cell();
handle  acc_next_cell_load();
handle  acc_next_tchk();
handle  acc_next_parameter();
handle  acc_next_specparam();
handle  acc_next_portout();
handle  acc_next_bit();
handle  acc_next();
handle  acc_next_scope();
handle  acc_next_object();
handle  acc_next_input();
handle  acc_next_output();

/* Fetch routines */
/* As per IEEE1364 */
int	acc_fetch_argc();
char	**acc_fetch_argv();

char   *acc_fetch_value();
char   *acc_fetch_name();
char   *acc_fetch_fullname();
char   *acc_fetch_defname();
int     acc_fetch_type();
int     acc_fetch_fulltype();
char   *acc_fetch_type_str();
int     acc_fetch_index();
int     acc_fetch_direction();
bool    acc_fetch_delays();
bool    acc_fetch_pulsere();
double  acc_fetch_paramval();
double  acc_fetch_attribute();
int     acc_fetch_polarity();
int     acc_fetch_paramtype();
int     acc_fetch_delay_mode();
int     acc_fetch_size();
int     acc_fetch_range();
int     acc_fetch_edge();
void    acc_fetch_location();

/* Modify routines */
bool   acc_replace_delays();
bool   acc_append_delays();
bool   acc_set_pulsere();

/* Utility routines */
bool    acc_initialize();
void    acc_close();
void    acc_reset_buffer();
bool    acc_configure();
int     acc_count();
handle *acc_collect();
char   *acc_version();
char   *acc_product_version();
void    acc_free();
handle  acc_handle_tfinst();
handle  acc_handle_tfarg();
handle  acc_handle_itfarg();
double  acc_fetch_tfarg();
double  acc_fetch_itfarg();
int     acc_fetch_tfarg_int();
int     acc_fetch_itfarg_int();
char   *acc_fetch_tfarg_str();
char   *acc_fetch_itfarg_str();
char   *acc_set_scope(); 
int     acc_get_cputime();
bool    acc_compare_handles();
handle  acc_copy_handle();
int     acc_release_object();
bool    acc_object_of_type();
bool    acc_object_in_typelist();
handle  acc_handle_interactive_scope();
bool    acc_set_interactive_scope();
int     acc_set_value();


/* Value Change Link routines */
void acc_vcl_add();
void acc_vcl_delete();


/*
 * The below, original definition from Cadence, does not compile with ANSI
#define  acc_handle_calling_mod_m  acc_handle_parent(tf_getinstance())
 */
#define  acc_handle_calling_mod_m()  acc_handle_parent(tf_getinstance())

#ifdef __cplusplus
}
#endif /* cplusplus */

#endif
/**********************************************************************/
/* EOF /home1/verilog/Antarctic/source/SCCS/s.acc_user.h */


