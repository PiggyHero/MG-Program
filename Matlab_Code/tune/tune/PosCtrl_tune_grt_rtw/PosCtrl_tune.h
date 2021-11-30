/*
 * PosCtrl_tune.h
 *
 * Code generation for model "PosCtrl_tune".
 *
 * Model version              : 1.72
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Apr 28 15:08:23 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PosCtrl_tune_h_
#define RTW_HEADER_PosCtrl_tune_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PosCtrl_tune_COMMON_INCLUDES_
# define PosCtrl_tune_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* PosCtrl_tune_COMMON_INCLUDES_ */

#include "PosCtrl_tune_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T pqr[3];                       /* '<S3>/p,q,r' */
  real_T Constant[4];                  /* '<S8>/Constant' */
  real_T q[4];                         /* '<S8>/q' */
  real_T DotProduct;                   /* '<S8>/Dot Product' */
  real_T Divide[4];                    /* '<S8>/Divide' */
  real_T xe[3];                        /* '<S7>/xe' */
  real_T Saturation1[3];               /* '<S1>/Saturation1' */
  real_T Sum1;                         /* '<S40>/Sum1' */
  real_T Gain1;                        /* '<S51>/Gain1' */
  real_T Saturation3;                  /* '<S51>/Saturation3' */
  real_T Product;                      /* '<S32>/Product' */
  real_T Product1;                     /* '<S32>/Product1' */
  real_T Product2;                     /* '<S32>/Product2' */
  real_T Product3;                     /* '<S32>/Product3' */
  real_T Sum;                          /* '<S32>/Sum' */
  real_T sqrt_c;                       /* '<S31>/sqrt' */
  real_T Product_d;                    /* '<S30>/Product' */
  real_T Product3_p;                   /* '<S20>/Product3' */
  real_T Product1_k;                   /* '<S30>/Product1' */
  real_T Product2_n;                   /* '<S20>/Product2' */
  real_T Product2_p;                   /* '<S30>/Product2' */
  real_T Product1_kg;                  /* '<S20>/Product1' */
  real_T Product3_py;                  /* '<S30>/Product3' */
  real_T Product_c;                    /* '<S20>/Product' */
  real_T Product3_n;                   /* '<S23>/Product3' */
  real_T Product2_i;                   /* '<S23>/Product2' */
  real_T Sum_e;                        /* '<S23>/Sum' */
  real_T Product1_f;                   /* '<S26>/Product1' */
  real_T Product2_k;                   /* '<S26>/Product2' */
  real_T Sum_i;                        /* '<S26>/Sum' */
  real_T Product3_e;                   /* '<S21>/Product3' */
  real_T Product2_g;                   /* '<S21>/Product2' */
  real_T Sum_c;                        /* '<S21>/Sum' */
  real_T Product3_l;                   /* '<S24>/Product3' */
  real_T Product2_o;                   /* '<S24>/Product2' */
  real_T Product1_i;                   /* '<S24>/Product1' */
  real_T Product_b;                    /* '<S24>/Product' */
  real_T Product1_d;                   /* '<S27>/Product1' */
  real_T Product2_a;                   /* '<S27>/Product2' */
  real_T Sum_h;                        /* '<S27>/Sum' */
  real_T Product1_a;                   /* '<S22>/Product1' */
  real_T Product2_n1;                  /* '<S22>/Product2' */
  real_T Sum_d;                        /* '<S22>/Sum' */
  real_T Product1_n;                   /* '<S25>/Product1' */
  real_T Product2_pf;                  /* '<S25>/Product2' */
  real_T Sum_ey;                       /* '<S25>/Sum' */
  real_T Product3_i;                   /* '<S28>/Product3' */
  real_T Product2_c;                   /* '<S28>/Product2' */
  real_T Product1_ia;                  /* '<S28>/Product1' */
  real_T Product_p;                    /* '<S28>/Product' */
  real_T VectorConcatenate[9];         /* '<S29>/Vector Concatenate' */
  real_T Transpose[9];                 /* '<S7>/Transpose' */
  real_T vb[3];                        /* '<S7>/vb' */
  real_T Product1_b[3];                /* '<S7>/Product1' */
  real_T Sum7;                         /* '<S40>/Sum7' */
  real_T Gain;                         /* '<S54>/Gain' */
  real_T DiscreteTimeIntegrator;       /* '<S54>/Discrete-Time Integrator' */
  real_T DerivativeGain;               /* '<S54>/Derivative Gain' */
  real_T TSamp;                        /* '<S57>/TSamp' */
  real_T Uk1;                          /* '<S57>/UD' */
  real_T Diff;                         /* '<S57>/Diff' */
  real_T Sum_j;                        /* '<S54>/Sum' */
  real_T Sum3;                         /* '<S40>/Sum3' */
  real_T Gain1_k;                      /* '<S52>/Gain1' */
  real_T Saturation3_e;                /* '<S52>/Saturation3' */
  real_T Sum2;                         /* '<S40>/Sum2' */
  real_T Gain_l;                       /* '<S55>/Gain' */
  real_T DiscreteTimeIntegrator_b;     /* '<S55>/Discrete-Time Integrator' */
  real_T DerivativeGain_a;             /* '<S55>/Derivative Gain' */
  real_T TSamp_h;                      /* '<S58>/TSamp' */
  real_T Uk1_n;                        /* '<S58>/UD' */
  real_T Diff_l;                       /* '<S58>/Diff' */
  real_T Sum_f;                        /* '<S55>/Sum' */
  real_T Saturation1_d;                /* '<S40>/Saturation1' */
  real_T Sum18;                        /* '<S39>/Sum18' */
  real_T Gain_j;                       /* '<S46>/Gain' */
  real_T Saturation4;                  /* '<S39>/Saturation4' */
  real_T Sum21;                        /* '<S39>/Sum21' */
  real_T Gain_f;                       /* '<S43>/Gain' */
  real_T DiscreteTimeIntegrator_j;     /* '<S43>/Discrete-Time Integrator' */
  real_T DerivativeGain_o;             /* '<S43>/Derivative Gain' */
  real_T TSamp_m;                      /* '<S48>/TSamp' */
  real_T Uk1_c;                        /* '<S48>/UD' */
  real_T Diff_c;                       /* '<S48>/Diff' */
  real_T Sum_m;                        /* '<S43>/Sum' */
  real_T Saturation;                   /* '<S39>/Saturation' */
  real_T Saturation2;                  /* '<S40>/Saturation2' */
  real_T Sum19;                        /* '<S39>/Sum19' */
  real_T Gain_h;                       /* '<S45>/Gain' */
  real_T Saturation3_j;                /* '<S39>/Saturation3' */
  real_T Sum22;                        /* '<S39>/Sum22' */
  real_T Gain_m;                       /* '<S42>/Gain' */
  real_T DiscreteTimeIntegrator_o;     /* '<S42>/Discrete-Time Integrator' */
  real_T DerivativeGain_j;             /* '<S42>/Derivative Gain' */
  real_T TSamp_a;                      /* '<S47>/TSamp' */
  real_T Uk1_j;                        /* '<S47>/UD' */
  real_T Diff_cp;                      /* '<S47>/Diff' */
  real_T Sum_n;                        /* '<S42>/Sum' */
  real_T Saturation1_e;                /* '<S39>/Saturation1' */
  real_T Sum17;                        /* '<S39>/Sum17' */
  real_T Gain_jp;                      /* '<S44>/Gain' */
  real_T DiscreteTimeIntegrator_bv;    /* '<S44>/Discrete-Time Integrator' */
  real_T DerivativeGain_d;             /* '<S44>/Derivative Gain' */
  real_T TSamp_l;                      /* '<S49>/TSamp' */
  real_T Uk1_o;                        /* '<S49>/UD' */
  real_T Diff_o;                       /* '<S49>/Diff' */
  real_T Sum_g;                        /* '<S44>/Sum' */
  real_T Saturation2_i;                /* '<S39>/Saturation2' */
  real_T Sum4;                         /* '<S40>/Sum4' */
  real_T Gain1_g;                      /* '<S53>/Gain1' */
  real_T Saturation3_jn;               /* '<S53>/Saturation3' */
  real_T Sum_l;                        /* '<S40>/Sum' */
  real_T Gain_e;                       /* '<S56>/Gain' */
  real_T DiscreteTimeIntegrator_e;     /* '<S56>/Discrete-Time Integrator' */
  real_T DerivativeGain_c;             /* '<S56>/Derivative Gain' */
  real_T TSamp_h5;                     /* '<S59>/TSamp' */
  real_T Uk1_g;                        /* '<S59>/UD' */
  real_T Diff_b;                       /* '<S59>/Diff' */
  real_T Sum_mz;                       /* '<S56>/Sum' */
  real_T az;                           /* '<S40>/az' */
  real_T Sum6;                         /* '<S40>/Sum6' */
  real_T Gain_a;                       /* '<S40>/Gain' */
  real_T Saturation_p;                 /* '<S40>/Saturation' */
  real_T Output_Limits1[4];            /* '<S2>/Output_Limits1' */
  real_T Sum_cd[4];                    /* '<S1>/Sum' */
  real_T Gain1_d[4];                   /* '<S1>/Gain1' */
  real_T Step;                         /* '<S1>/Step' */
  real_T Sum1_a;                       /* '<S1>/Sum1' */
  real_T Product1_d5[3];               /* '<S1>/Product1' */
  real_T Saturation_m[4];              /* '<S1>/Saturation' */
  real_T Divide_b[9];                  /* '<S6>/Divide' */
  real_T Jw[3];                        /* '<S9>/J*w' */
  real_T Motor_Dynamics_1;             /* '<S4>/Motor_Dynamics_1' */
  real_T Motor_Dynamics_2;             /* '<S4>/Motor_Dynamics_2' */
  real_T Motor_Dynamics_3;             /* '<S4>/Motor_Dynamics_3' */
  real_T Motor_Dynamics_4;             /* '<S4>/Motor_Dynamics_4' */
  real_T Sum_ce[3];                    /* '<S5>/Sum' */
  real_T jxk;                          /* '<S12>/j x k' */
  real_T kxi;                          /* '<S12>/k x i' */
  real_T ixj;                          /* '<S12>/i x j' */
  real_T kxj;                          /* '<S13>/k x j' */
  real_T ixk;                          /* '<S13>/i x k' */
  real_T jxi;                          /* '<S13>/j x i' */
  real_T Sum_k[3];                     /* '<S10>/Sum' */
  real_T Sum_jz[3];                    /* '<S6>/Sum' */
  real_T Product_n[3];                 /* '<S6>/Product' */
  real_T Product_ph[3];                /* '<S5>/Product' */
  real_T Add7[3];                      /* '<S5>/Add7' */
  real_T Add2[3];                      /* '<S5>/Add2' */
  real_T afm[3];                       /* '<S7>/a=f//m' */
  real_T jxk_b;                        /* '<S15>/j x k' */
  real_T kxi_n;                        /* '<S15>/k x i' */
  real_T ixj_i;                        /* '<S15>/i x j' */
  real_T kxj_c;                        /* '<S16>/k x j' */
  real_T ixk_j;                        /* '<S16>/i x k' */
  real_T jxi_l;                        /* '<S16>/j x i' */
  real_T Sum_n3[3];                    /* '<S14>/Sum' */
  real_T Sum_j1[3];                    /* '<S7>/Sum' */
  real_T Signal_Saturation_1;          /* '<S4>/Signal_Saturation_1' */
  real_T Signal_Saturation_2;          /* '<S4>/Signal_Saturation_2' */
  real_T Signal_Saturation_3;          /* '<S4>/Signal_Saturation_3' */
  real_T Signal_Saturation_4;          /* '<S4>/Signal_Saturation_4' */
  real_T Gain_fu;                      /* '<S33>/Gain' */
  real_T Sum1_m;                       /* '<S33>/Sum1' */
  real_T Gain_m3;                      /* '<S34>/Gain' */
  real_T Sum1_l;                       /* '<S34>/Sum1' */
  real_T Gain_h0;                      /* '<S35>/Gain' */
  real_T Sum1_b;                       /* '<S35>/Sum1' */
  real_T Gain_g;                       /* '<S36>/Gain' */
  real_T Sum1_e;                       /* '<S36>/Sum1' */
  real_T IntegralGain;                 /* '<S42>/Integral Gain' */
  real_T IntegralGain_j;               /* '<S43>/Integral Gain' */
  real_T IntegralGain_h;               /* '<S44>/Integral Gain' */
  real_T IntegralGain_p;               /* '<S54>/Integral Gain' */
  real_T IntegralGain_c;               /* '<S55>/Integral Gain' */
  real_T IntegralGain_h4;              /* '<S56>/Integral Gain' */
  real_T M1;                           /* '<S2>/pwm_out2' */
  real_T M2;                           /* '<S2>/pwm_out2' */
  real_T M3;                           /* '<S2>/pwm_out2' */
  real_T M4;                           /* '<S2>/pwm_out2' */
  real_T phi;                          /* '<S40>/MATLAB Function' */
  real_T theta;                        /* '<S40>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionI[4];/* '<S5>/Propeller Model' */
  real_T Fb[3];                        /* '<S5>/Propeller Model' */
  real_T Fd[3];                        /* '<S5>/Propeller Model' */
  real_T Mb[3];                        /* '<S5>/Propeller Model' */
  real_T m[3];                         /* '<S5>/MATLAB Function' */
  real_T qdot[4];                      /* '<S8>/基于四元数模型' */
  real_T y[3];                         /* '<S8>/四元数转欧拉角' */
  real_T TmpSignalConversionAtSFunctio_p[4];/* '<S6>/陀螺力矩' */
  real_T Ga[3];                        /* '<S6>/陀螺力矩' */
} B_PosCtrl_tune_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S54>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S57>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S55>/Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S58>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S43>/Discrete-Time Integrator' */
  real_T UD_DSTATE_f;                  /* '<S48>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S42>/Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S47>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S44>/Discrete-Time Integrator' */
  real_T UD_DSTATE_lz;                 /* '<S49>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S56>/Discrete-Time Integrator' */
  real_T UD_DSTATE_m;                  /* '<S59>/UD' */
  real_T Divide_DWORK1[9];             /* '<S6>/Divide' */
  real_T Divide_DWORK3[9];             /* '<S6>/Divide' */
  real_T Divide_DWORK4[9];             /* '<S6>/Divide' */
  real_T Divide_DWORK5[9];             /* '<S6>/Divide' */
  int32_T Divide_DWORK2[3];            /* '<S6>/Divide' */
  int_T q_IWORK;                       /* '<S8>/q' */
} DW_PosCtrl_tune_T;

/* Continuous states (default storage) */
typedef struct {
  real_T pqr_CSTATE[3];                /* '<S3>/p,q,r' */
  real_T q_CSTATE[4];                  /* '<S8>/q' */
  real_T xe_CSTATE[3];                 /* '<S7>/xe' */
  real_T vb_CSTATE[3];                 /* '<S7>/vb' */
  real_T Motor_Dynamics_1_CSTATE;      /* '<S4>/Motor_Dynamics_1' */
  real_T Motor_Dynamics_2_CSTATE;      /* '<S4>/Motor_Dynamics_2' */
  real_T Motor_Dynamics_3_CSTATE;      /* '<S4>/Motor_Dynamics_3' */
  real_T Motor_Dynamics_4_CSTATE;      /* '<S4>/Motor_Dynamics_4' */
} X_PosCtrl_tune_T;

/* State derivatives (default storage) */
typedef struct {
  real_T pqr_CSTATE[3];                /* '<S3>/p,q,r' */
  real_T q_CSTATE[4];                  /* '<S8>/q' */
  real_T xe_CSTATE[3];                 /* '<S7>/xe' */
  real_T vb_CSTATE[3];                 /* '<S7>/vb' */
  real_T Motor_Dynamics_1_CSTATE;      /* '<S4>/Motor_Dynamics_1' */
  real_T Motor_Dynamics_2_CSTATE;      /* '<S4>/Motor_Dynamics_2' */
  real_T Motor_Dynamics_3_CSTATE;      /* '<S4>/Motor_Dynamics_3' */
  real_T Motor_Dynamics_4_CSTATE;      /* '<S4>/Motor_Dynamics_4' */
} XDot_PosCtrl_tune_T;

/* State disabled  */
typedef struct {
  boolean_T pqr_CSTATE[3];             /* '<S3>/p,q,r' */
  boolean_T q_CSTATE[4];               /* '<S8>/q' */
  boolean_T xe_CSTATE[3];              /* '<S7>/xe' */
  boolean_T vb_CSTATE[3];              /* '<S7>/vb' */
  boolean_T Motor_Dynamics_1_CSTATE;   /* '<S4>/Motor_Dynamics_1' */
  boolean_T Motor_Dynamics_2_CSTATE;   /* '<S4>/Motor_Dynamics_2' */
  boolean_T Motor_Dynamics_3_CSTATE;   /* '<S4>/Motor_Dynamics_3' */
  boolean_T Motor_Dynamics_4_CSTATE;   /* '<S4>/Motor_Dynamics_4' */
} XDis_PosCtrl_tune_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_PosCtrl_tune_T_ {
  real_T DEG2RAD;                      /* Variable: DEG2RAD
                                        * Referenced by:
                                        *   '<S40>/Saturation1'
                                        *   '<S40>/Saturation2'
                                        */
  real_T Kd_PITCH_AgngleRate;          /* Variable: Kd_PITCH_AgngleRate
                                        * Referenced by: '<S42>/Derivative Gain'
                                        */
  real_T Kd_ROLL_AgngleRate;           /* Variable: Kd_ROLL_AgngleRate
                                        * Referenced by: '<S43>/Derivative Gain'
                                        */
  real_T Kd_YAW_AngleRate;             /* Variable: Kd_YAW_AngleRate
                                        * Referenced by: '<S44>/Derivative Gain'
                                        */
  real_T Ki_PITCH_AgngleRate;          /* Variable: Ki_PITCH_AgngleRate
                                        * Referenced by: '<S42>/Integral Gain'
                                        */
  real_T Ki_ROLL_AgngleRate;           /* Variable: Ki_ROLL_AgngleRate
                                        * Referenced by: '<S43>/Integral Gain'
                                        */
  real_T Ki_YAW_AngleRate;             /* Variable: Ki_YAW_AngleRate
                                        * Referenced by: '<S44>/Integral Gain'
                                        */
  real_T Kp_PITCH_ANGLE;               /* Variable: Kp_PITCH_ANGLE
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Kp_PITCH_AgngleRate;          /* Variable: Kp_PITCH_AgngleRate
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T Kp_ROLL_ANGLE;                /* Variable: Kp_ROLL_ANGLE
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Kp_ROLL_AgngleRate;           /* Variable: Kp_ROLL_AgngleRate
                                        * Referenced by: '<S43>/Gain'
                                        */
  real_T Kp_YAW_AngleRate;             /* Variable: Kp_YAW_AngleRate
                                        * Referenced by: '<S44>/Gain'
                                        */
  real_T Kpxp;                         /* Variable: Kpxp
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Kpyp;                         /* Variable: Kpyp
                                        * Referenced by: '<S52>/Gain1'
                                        */
  real_T Kpzp;                         /* Variable: Kpzp
                                        * Referenced by: '<S53>/Gain1'
                                        */
  real_T Kvxd;                         /* Variable: Kvxd
                                        * Referenced by: '<S54>/Derivative Gain'
                                        */
  real_T Kvxi;                         /* Variable: Kvxi
                                        * Referenced by: '<S54>/Integral Gain'
                                        */
  real_T Kvxp;                         /* Variable: Kvxp
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T Kvyd;                         /* Variable: Kvyd
                                        * Referenced by: '<S55>/Derivative Gain'
                                        */
  real_T Kvyi;                         /* Variable: Kvyi
                                        * Referenced by: '<S55>/Integral Gain'
                                        */
  real_T Kvyp;                         /* Variable: Kvyp
                                        * Referenced by: '<S55>/Gain'
                                        */
  real_T Kvzd;                         /* Variable: Kvzd
                                        * Referenced by: '<S56>/Derivative Gain'
                                        */
  real_T Kvzi;                         /* Variable: Kvzi
                                        * Referenced by: '<S56>/Integral Gain'
                                        */
  real_T Kvzp;                         /* Variable: Kvzp
                                        * Referenced by: '<S56>/Gain'
                                        */
  real_T MAX_CONTROL_ANGLE_PITCH;      /* Variable: MAX_CONTROL_ANGLE_PITCH
                                        * Referenced by: '<S40>/Saturation2'
                                        */
  real_T MAX_CONTROL_ANGLE_RATE_PITCH; /* Variable: MAX_CONTROL_ANGLE_RATE_PITCH
                                        * Referenced by: '<S39>/Saturation3'
                                        */
  real_T MAX_CONTROL_ANGLE_RATE_ROLL;  /* Variable: MAX_CONTROL_ANGLE_RATE_ROLL
                                        * Referenced by: '<S39>/Saturation4'
                                        */
  real_T MAX_CONTROL_ANGLE_ROLL;       /* Variable: MAX_CONTROL_ANGLE_ROLL
                                        * Referenced by: '<S40>/Saturation1'
                                        */
  real_T MAX_CONTROL_VELOCITY_XY;      /* Variable: MAX_CONTROL_VELOCITY_XY
                                        * Referenced by:
                                        *   '<S51>/Saturation3'
                                        *   '<S52>/Saturation3'
                                        */
  real_T MAX_CONTROL_VELOCITY_Z;       /* Variable: MAX_CONTROL_VELOCITY_Z
                                        * Referenced by: '<S53>/Saturation3'
                                        */
  real_T MAX_MAN_THR;                  /* Variable: MAX_MAN_THR
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T ModelInit_PosE[3];            /* Variable: ModelInit_PosE
                                        * Referenced by: '<S7>/xe'
                                        */
  real_T ModelInit_RPM;                /* Variable: ModelInit_RPM
                                        * Referenced by:
                                        *   '<S4>/Motor_Dynamics_1'
                                        *   '<S4>/Motor_Dynamics_2'
                                        *   '<S4>/Motor_Dynamics_3'
                                        *   '<S4>/Motor_Dynamics_4'
                                        */
  real_T ModelParam_motorCr;           /* Variable: ModelParam_motorCr
                                        * Referenced by:
                                        *   '<S33>/Gain'
                                        *   '<S34>/Gain'
                                        *   '<S35>/Gain'
                                        *   '<S36>/Gain'
                                        */
  real_T ModelParam_motorJm;           /* Variable: ModelParam_motorJm
                                        * Referenced by: '<S1>/Jrp'
                                        */
  real_T ModelParam_motorT;            /* Variable: ModelParam_motorT
                                        * Referenced by:
                                        *   '<S4>/Motor_Dynamics_1'
                                        *   '<S4>/Motor_Dynamics_2'
                                        *   '<S4>/Motor_Dynamics_3'
                                        *   '<S4>/Motor_Dynamics_4'
                                        */
  real_T ModelParam_motorWb;           /* Variable: ModelParam_motorWb
                                        * Referenced by:
                                        *   '<S33>/Constant'
                                        *   '<S34>/Constant'
                                        *   '<S35>/Constant'
                                        *   '<S36>/Constant'
                                        */
  real_T ModelParam_rotorCm;           /* Variable: ModelParam_rotorCm
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T ModelParam_rotorCt;           /* Variable: ModelParam_rotorCt
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T ModelParam_uavCd;             /* Variable: ModelParam_uavCd
                                        * Referenced by: '<S5>/Constant7'
                                        */
  real_T ModelParam_uavJ[9];           /* Variable: ModelParam_uavJ
                                        * Referenced by: '<S1>/转动惯量'
                                        */
  real_T ModelParam_uavMass;           /* Variable: ModelParam_uavMass
                                        * Referenced by:
                                        *   '<S1>/mass'
                                        *   '<S1>/质量'
                                        */
  real_T ModelParam_uavR;              /* Variable: ModelParam_uavR
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T Saturation_I_RP_Max;          /* Variable: Saturation_I_RP_Max
                                        * Referenced by:
                                        *   '<S42>/Discrete-Time Integrator'
                                        *   '<S43>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_RP_Min;          /* Variable: Saturation_I_RP_Min
                                        * Referenced by:
                                        *   '<S42>/Discrete-Time Integrator'
                                        *   '<S43>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_Y_Max;           /* Variable: Saturation_I_Y_Max
                                        * Referenced by: '<S44>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_Y_Min;           /* Variable: Saturation_I_Y_Min
                                        * Referenced by: '<S44>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_ah;              /* Variable: Saturation_I_ah
                                        * Referenced by:
                                        *   '<S54>/Discrete-Time Integrator'
                                        *   '<S55>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_az;              /* Variable: Saturation_I_az
                                        * Referenced by: '<S56>/Discrete-Time Integrator'
                                        */
  real_T THR_HOVER;                    /* Variable: THR_HOVER
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S57>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_i;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
                               * Referenced by: '<S58>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_k;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                               * Referenced by: '<S48>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_b;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                               * Referenced by: '<S47>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_a;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_a
                               * Referenced by: '<S49>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_o;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                               * Referenced by: '<S59>/UD'
                               */
  real_T xd_Value;                     /* Expression: 0
                                        * Referenced by: '<Root>/xd'
                                        */
  real_T yd_Value;                     /* Expression: 0
                                        * Referenced by: '<Root>/yd'
                                        */
  real_T zd_Value;                     /* Expression: -10
                                        * Referenced by: '<Root>/zd'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<Root>/偏航角'
                                        */
  real_T Constant2_Value[4];           /* Expression: [1000,1000,1000,1000]
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T pqr_IC;                       /* Expression: 0
                                        * Referenced by: '<S3>/p,q,r'
                                        */
  real_T Constant_Value[4];            /* Expression: [1,0,0,0]
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Saturation1_UpperSat[3];      /* Expression: [inf,inf,0]
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat[3];      /* Expression: [-inf,-inf,-inf]
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 2
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 2
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 2
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 2
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T vb_IC;                        /* Expression: 0
                                        * Referenced by: '<S7>/vb'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S54>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S54>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S57>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                           * Referenced by: '<S55>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S55>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_i;                 /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S58>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                           * Referenced by: '<S43>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S43>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S48>/TSamp'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S42>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S42>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S47>/TSamp'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 1
                                        * Referenced by: '<S39>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S39>/Saturation1'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ga;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ga
                           * Referenced by: '<S44>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S44>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_a;                 /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S49>/TSamp'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 0.5
                                        * Referenced by: '<S39>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -0.5
                                        * Referenced by: '<S39>/Saturation2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                           * Referenced by: '<S56>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S56>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_c;                 /* Computed Parameter: TSamp_WtEt_c
                                        * Referenced by: '<S59>/TSamp'
                                        */
  real_T az_UpperSat;                  /* Expression: 0.4
                                        * Referenced by: '<S40>/az'
                                        */
  real_T az_LowerSat;                  /* Expression: -0.4
                                        * Referenced by: '<S40>/az'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Output_Limits1_UpperSat;      /* Expression: 2000
                                        * Referenced by: '<S2>/Output_Limits1'
                                        */
  real_T Output_Limits1_LowerSat;      /* Expression: 1000
                                        * Referenced by: '<S2>/Output_Limits1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T g_Value[3];               /* Expression: [0,0,ModelParam_envGravityAcc]
                                    * Referenced by: '<S1>/g'
                                    */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant_Value_i[9];          /* Expression: eye(3)
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Motor_Dynamics_1_B;           /* Expression: 1
                                        * Referenced by: '<S4>/Motor_Dynamics_1'
                                        */
  real_T Motor_Dynamics_2_B;           /* Expression: 1
                                        * Referenced by: '<S4>/Motor_Dynamics_2'
                                        */
  real_T Motor_Dynamics_3_B;           /* Expression: 1
                                        * Referenced by: '<S4>/Motor_Dynamics_3'
                                        */
  real_T Motor_Dynamics_4_B;           /* Expression: 1
                                        * Referenced by: '<S4>/Motor_Dynamics_4'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Signal_Saturation_1_UpperSat; /* Expression: 1
                                        * Referenced by: '<S4>/Signal_Saturation_1'
                                        */
  real_T Signal_Saturation_1_LowerSat; /* Expression: 0
                                        * Referenced by: '<S4>/Signal_Saturation_1'
                                        */
  real_T Signal_Saturation_2_UpperSat; /* Expression: 1
                                        * Referenced by: '<S4>/Signal_Saturation_2'
                                        */
  real_T Signal_Saturation_2_LowerSat; /* Expression: 0
                                        * Referenced by: '<S4>/Signal_Saturation_2'
                                        */
  real_T Signal_Saturation_3_UpperSat; /* Expression: 1
                                        * Referenced by: '<S4>/Signal_Saturation_3'
                                        */
  real_T Signal_Saturation_3_LowerSat; /* Expression: 0
                                        * Referenced by: '<S4>/Signal_Saturation_3'
                                        */
  real_T Signal_Saturation_4_UpperSat; /* Expression: 1
                                        * Referenced by: '<S4>/Signal_Saturation_4'
                                        */
  real_T Signal_Saturation_4_LowerSat; /* Expression: 0
                                        * Referenced by: '<S4>/Signal_Saturation_4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PosCtrl_tune_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_PosCtrl_tune_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[17];
  real_T odeF[3][17];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PosCtrl_tune_T PosCtrl_tune_P;

/* Block signals (default storage) */
extern B_PosCtrl_tune_T PosCtrl_tune_B;

/* Continuous states (default storage) */
extern X_PosCtrl_tune_T PosCtrl_tune_X;

/* Block states (default storage) */
extern DW_PosCtrl_tune_T PosCtrl_tune_DW;

/* Model entry point functions */
extern void PosCtrl_tune_initialize(void);
extern void PosCtrl_tune_step(void);
extern void PosCtrl_tune_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PosCtrl_tune_T *const PosCtrl_tune_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Reshape1' : Reshape block reduction
 * Block '<S29>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PosCtrl_tune'
 * '<S1>'   : 'PosCtrl_tune/四旋翼动力学模型 '
 * '<S2>'   : 'PosCtrl_tune/控制系统'
 * '<S3>'   : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型'
 * '<S4>'   : 'PosCtrl_tune/四旋翼动力学模型 /动力单元模型'
 * '<S5>'   : 'PosCtrl_tune/四旋翼动力学模型 /控制效率模型'
 * '<S6>'   : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型'
 * '<S7>'   : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体运动学模型'
 * '<S8>'   : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角'
 * '<S9>'   : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型/J*w'
 * '<S10>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型/wx(Jw)'
 * '<S11>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型/陀螺力矩'
 * '<S12>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型/wx(Jw)/Subsystem'
 * '<S13>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体动力学模型/wx(Jw)/Subsystem1'
 * '<S14>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体运动学模型/Vbxw'
 * '<S15>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体运动学模型/Vbxw/Subsystem'
 * '<S16>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/刚体运动学模型/Vbxw/Subsystem1'
 * '<S17>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM'
 * '<S18>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转欧拉角'
 * '<S19>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/基于四元数模型'
 * '<S20>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A11'
 * '<S21>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A12'
 * '<S22>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A13'
 * '<S23>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A21'
 * '<S24>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A22'
 * '<S25>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A23'
 * '<S26>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A31'
 * '<S27>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A32'
 * '<S28>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/A33'
 * '<S29>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/Create 3x3 Matrix'
 * '<S30>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/Quaternion Normalize'
 * '<S31>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S32>'  : 'PosCtrl_tune/四旋翼动力学模型 /刚体模型/计算旋转矩阵和欧拉角/四元数转DCM/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S33>'  : 'PosCtrl_tune/四旋翼动力学模型 /动力单元模型/Throttle To RPM Gain _1'
 * '<S34>'  : 'PosCtrl_tune/四旋翼动力学模型 /动力单元模型/Throttle To RPM Gain _2'
 * '<S35>'  : 'PosCtrl_tune/四旋翼动力学模型 /动力单元模型/Throttle To RPM Gain _3'
 * '<S36>'  : 'PosCtrl_tune/四旋翼动力学模型 /动力单元模型/Throttle To RPM Gain _4'
 * '<S37>'  : 'PosCtrl_tune/四旋翼动力学模型 /控制效率模型/MATLAB Function'
 * '<S38>'  : 'PosCtrl_tune/四旋翼动力学模型 /控制效率模型/Propeller Model'
 * '<S39>'  : 'PosCtrl_tune/控制系统/AttitudeControl'
 * '<S40>'  : 'PosCtrl_tune/控制系统/position_control'
 * '<S41>'  : 'PosCtrl_tune/控制系统/pwm_out2'
 * '<S42>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_pitchRate'
 * '<S43>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_rollRate'
 * '<S44>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_yawRate'
 * '<S45>'  : 'PosCtrl_tune/控制系统/AttitudeControl/P_pitch '
 * '<S46>'  : 'PosCtrl_tune/控制系统/AttitudeControl/P_roll '
 * '<S47>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_pitchRate/Discrete Derivative'
 * '<S48>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_rollRate/Discrete Derivative'
 * '<S49>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_yawRate/Discrete Derivative'
 * '<S50>'  : 'PosCtrl_tune/控制系统/position_control/MATLAB Function'
 * '<S51>'  : 'PosCtrl_tune/控制系统/position_control/px'
 * '<S52>'  : 'PosCtrl_tune/控制系统/position_control/py'
 * '<S53>'  : 'PosCtrl_tune/控制系统/position_control/pz'
 * '<S54>'  : 'PosCtrl_tune/控制系统/position_control/vx '
 * '<S55>'  : 'PosCtrl_tune/控制系统/position_control/vy '
 * '<S56>'  : 'PosCtrl_tune/控制系统/position_control/vz '
 * '<S57>'  : 'PosCtrl_tune/控制系统/position_control/vx /Discrete Derivative'
 * '<S58>'  : 'PosCtrl_tune/控制系统/position_control/vy /Discrete Derivative'
 * '<S59>'  : 'PosCtrl_tune/控制系统/position_control/vz /Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_PosCtrl_tune_h_ */
