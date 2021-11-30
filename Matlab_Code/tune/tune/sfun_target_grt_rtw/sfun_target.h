/*
 * sfun_target.h
 *
 * Code generation for model "sfun_target".
 *
 * Model version              : 1.72
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Apr 28 15:06:10 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sfun_target_h_
#define RTW_HEADER_sfun_target_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef sfun_target_COMMON_INCLUDES_
# define sfun_target_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* sfun_target_COMMON_INCLUDES_ */

#include "sfun_target_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S17>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S20>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S18>/Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S21>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S6>/Discrete-Time Integrator' */
  real_T UD_DSTATE_f;                  /* '<S11>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S5>/Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S10>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S7>/Discrete-Time Integrator' */
  real_T UD_DSTATE_lz;                 /* '<S12>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S19>/Discrete-Time Integrator' */
  real_T UD_DSTATE_m;                  /* '<S22>/UD' */
} DW_sfun_target_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T yawRate_d;                    /* '<Root>/yawRate_d' */
  real_T p;                            /* '<Root>/p' */
  real_T q;                            /* '<Root>/q' */
  real_T r;                            /* '<Root>/r' */
  real_T roll;                         /* '<Root>/roll' */
  real_T pitch;                        /* '<Root>/pitch' */
  real_T yaw;                          /* '<Root>/yaw' */
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T z;                            /* '<Root>/z' */
  real_T vx;                           /* '<Root>/vx' */
  real_T vy;                           /* '<Root>/vy' */
  real_T vz;                           /* '<Root>/vz' */
  real_T xd;                           /* '<Root>/xd' */
  real_T yd;                           /* '<Root>/yd' */
  real_T zd;                           /* '<Root>/zd' */
} ExtU_sfun_target_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T PWM[4];                       /* '<Root>/PWM' */
} ExtY_sfun_target_T;

/* Parameters (default storage) */
struct P_sfun_target_T_ {
  real_T DEG2RAD;                      /* Variable: DEG2RAD
                                        * Referenced by:
                                        *   '<S3>/Saturation1'
                                        *   '<S3>/Saturation2'
                                        */
  real_T Kd_PITCH_AgngleRate;          /* Variable: Kd_PITCH_AgngleRate
                                        * Referenced by: '<S5>/Derivative Gain'
                                        */
  real_T Kd_ROLL_AgngleRate;           /* Variable: Kd_ROLL_AgngleRate
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  real_T Kd_YAW_AngleRate;             /* Variable: Kd_YAW_AngleRate
                                        * Referenced by: '<S7>/Derivative Gain'
                                        */
  real_T Ki_PITCH_AgngleRate;          /* Variable: Ki_PITCH_AgngleRate
                                        * Referenced by: '<S5>/Integral Gain'
                                        */
  real_T Ki_ROLL_AgngleRate;           /* Variable: Ki_ROLL_AgngleRate
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  real_T Ki_YAW_AngleRate;             /* Variable: Ki_YAW_AngleRate
                                        * Referenced by: '<S7>/Integral Gain'
                                        */
  real_T Kp_PITCH_ANGLE;               /* Variable: Kp_PITCH_ANGLE
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Kp_PITCH_AgngleRate;          /* Variable: Kp_PITCH_AgngleRate
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Kp_ROLL_ANGLE;                /* Variable: Kp_ROLL_ANGLE
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Kp_ROLL_AgngleRate;           /* Variable: Kp_ROLL_AgngleRate
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Kp_YAW_AngleRate;             /* Variable: Kp_YAW_AngleRate
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Kpxp;                         /* Variable: Kpxp
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Kpyp;                         /* Variable: Kpyp
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Kpzp;                         /* Variable: Kpzp
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Kvxd;                         /* Variable: Kvxd
                                        * Referenced by: '<S17>/Derivative Gain'
                                        */
  real_T Kvxi;                         /* Variable: Kvxi
                                        * Referenced by: '<S17>/Integral Gain'
                                        */
  real_T Kvxp;                         /* Variable: Kvxp
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Kvyd;                         /* Variable: Kvyd
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  real_T Kvyi;                         /* Variable: Kvyi
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  real_T Kvyp;                         /* Variable: Kvyp
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Kvzd;                         /* Variable: Kvzd
                                        * Referenced by: '<S19>/Derivative Gain'
                                        */
  real_T Kvzi;                         /* Variable: Kvzi
                                        * Referenced by: '<S19>/Integral Gain'
                                        */
  real_T Kvzp;                         /* Variable: Kvzp
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T MAX_CONTROL_ANGLE_PITCH;      /* Variable: MAX_CONTROL_ANGLE_PITCH
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T MAX_CONTROL_ANGLE_RATE_PITCH; /* Variable: MAX_CONTROL_ANGLE_RATE_PITCH
                                        * Referenced by: '<S2>/Saturation3'
                                        */
  real_T MAX_CONTROL_ANGLE_RATE_ROLL;  /* Variable: MAX_CONTROL_ANGLE_RATE_ROLL
                                        * Referenced by: '<S2>/Saturation4'
                                        */
  real_T MAX_CONTROL_ANGLE_ROLL;       /* Variable: MAX_CONTROL_ANGLE_ROLL
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T MAX_CONTROL_VELOCITY_XY;      /* Variable: MAX_CONTROL_VELOCITY_XY
                                        * Referenced by:
                                        *   '<S14>/Saturation3'
                                        *   '<S15>/Saturation3'
                                        */
  real_T MAX_CONTROL_VELOCITY_Z;       /* Variable: MAX_CONTROL_VELOCITY_Z
                                        * Referenced by: '<S16>/Saturation3'
                                        */
  real_T MAX_MAN_THR;                  /* Variable: MAX_MAN_THR
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_I_RP_Max;          /* Variable: Saturation_I_RP_Max
                                        * Referenced by:
                                        *   '<S5>/Discrete-Time Integrator'
                                        *   '<S6>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_RP_Min;          /* Variable: Saturation_I_RP_Min
                                        * Referenced by:
                                        *   '<S5>/Discrete-Time Integrator'
                                        *   '<S6>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_Y_Max;           /* Variable: Saturation_I_Y_Max
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_Y_Min;           /* Variable: Saturation_I_Y_Min
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_ah;              /* Variable: Saturation_I_ah
                                        * Referenced by:
                                        *   '<S17>/Discrete-Time Integrator'
                                        *   '<S18>/Discrete-Time Integrator'
                                        */
  real_T Saturation_I_az;              /* Variable: Saturation_I_az
                                        * Referenced by: '<S19>/Discrete-Time Integrator'
                                        */
  real_T THR_HOVER;                    /* Variable: THR_HOVER
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S20>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_i;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
                               * Referenced by: '<S21>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_k;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                               * Referenced by: '<S11>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_b;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                               * Referenced by: '<S10>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_a;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_a
                               * Referenced by: '<S12>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_o;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                               * Referenced by: '<S22>/UD'
                               */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S17>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S20>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_i;                 /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S21>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                           * Referenced by: '<S6>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S11>/TSamp'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S5>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S10>/TSamp'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ga;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ga
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_a;                 /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S12>/TSamp'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 0.5
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -0.5
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                           * Referenced by: '<S19>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S19>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt_c;                 /* Computed Parameter: TSamp_WtEt_c
                                        * Referenced by: '<S22>/TSamp'
                                        */
  real_T az_UpperSat;                  /* Expression: 0.4
                                        * Referenced by: '<S3>/az'
                                        */
  real_T az_LowerSat;                  /* Expression: -0.4
                                        * Referenced by: '<S3>/az'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Output_Limits1_UpperSat;      /* Expression: 2000
                                        * Referenced by: '<S1>/Output_Limits1'
                                        */
  real_T Output_Limits1_LowerSat;      /* Expression: 1000
                                        * Referenced by: '<S1>/Output_Limits1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sfun_target_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_sfun_target_T sfun_target_P;

/* Block states (default storage) */
extern DW_sfun_target_T sfun_target_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_sfun_target_T sfun_target_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_sfun_target_T sfun_target_Y;

/* Model entry point functions */
extern void sfun_target_initialize(void);
extern void sfun_target_step(void);
extern void sfun_target_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sfun_target_T *const sfun_target_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('PosCtrl_tune/控制系统')    - opens subsystem PosCtrl_tune/控制系统
 * hilite_system('PosCtrl_tune/控制系统/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PosCtrl_tune'
 * '<S1>'   : 'PosCtrl_tune/控制系统'
 * '<S2>'   : 'PosCtrl_tune/控制系统/AttitudeControl'
 * '<S3>'   : 'PosCtrl_tune/控制系统/position_control'
 * '<S4>'   : 'PosCtrl_tune/控制系统/pwm_out2'
 * '<S5>'   : 'PosCtrl_tune/控制系统/AttitudeControl/PID_pitchRate'
 * '<S6>'   : 'PosCtrl_tune/控制系统/AttitudeControl/PID_rollRate'
 * '<S7>'   : 'PosCtrl_tune/控制系统/AttitudeControl/PID_yawRate'
 * '<S8>'   : 'PosCtrl_tune/控制系统/AttitudeControl/P_pitch '
 * '<S9>'   : 'PosCtrl_tune/控制系统/AttitudeControl/P_roll '
 * '<S10>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_pitchRate/Discrete Derivative'
 * '<S11>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_rollRate/Discrete Derivative'
 * '<S12>'  : 'PosCtrl_tune/控制系统/AttitudeControl/PID_yawRate/Discrete Derivative'
 * '<S13>'  : 'PosCtrl_tune/控制系统/position_control/MATLAB Function'
 * '<S14>'  : 'PosCtrl_tune/控制系统/position_control/px'
 * '<S15>'  : 'PosCtrl_tune/控制系统/position_control/py'
 * '<S16>'  : 'PosCtrl_tune/控制系统/position_control/pz'
 * '<S17>'  : 'PosCtrl_tune/控制系统/position_control/vx '
 * '<S18>'  : 'PosCtrl_tune/控制系统/position_control/vy '
 * '<S19>'  : 'PosCtrl_tune/控制系统/position_control/vz '
 * '<S20>'  : 'PosCtrl_tune/控制系统/position_control/vx /Discrete Derivative'
 * '<S21>'  : 'PosCtrl_tune/控制系统/position_control/vy /Discrete Derivative'
 * '<S22>'  : 'PosCtrl_tune/控制系统/position_control/vz /Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_sfun_target_h_ */
