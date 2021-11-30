/*
 * PosCtrl_tune_data.c
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

#include "PosCtrl_tune.h"
#include "PosCtrl_tune_private.h"

/* Block parameters (default storage) */
P_PosCtrl_tune_T PosCtrl_tune_P = {
  /* Variable: DEG2RAD
   * Referenced by:
   *   '<S40>/Saturation1'
   *   '<S40>/Saturation2'
   */
  0.0174533,

  /* Variable: Kd_PITCH_AgngleRate
   * Referenced by: '<S42>/Derivative Gain'
   */
  0.001,

  /* Variable: Kd_ROLL_AgngleRate
   * Referenced by: '<S43>/Derivative Gain'
   */
  0.001,

  /* Variable: Kd_YAW_AngleRate
   * Referenced by: '<S44>/Derivative Gain'
   */
  0.0,

  /* Variable: Ki_PITCH_AgngleRate
   * Referenced by: '<S42>/Integral Gain'
   */
  0.02,

  /* Variable: Ki_ROLL_AgngleRate
   * Referenced by: '<S43>/Integral Gain'
   */
  0.02,

  /* Variable: Ki_YAW_AngleRate
   * Referenced by: '<S44>/Integral Gain'
   */
  0.01,

  /* Variable: Kp_PITCH_ANGLE
   * Referenced by: '<S45>/Gain'
   */
  6.5,

  /* Variable: Kp_PITCH_AgngleRate
   * Referenced by: '<S42>/Gain'
   */
  0.1,

  /* Variable: Kp_ROLL_ANGLE
   * Referenced by: '<S46>/Gain'
   */
  6.5,

  /* Variable: Kp_ROLL_AgngleRate
   * Referenced by: '<S43>/Gain'
   */
  0.1,

  /* Variable: Kp_YAW_AngleRate
   * Referenced by: '<S44>/Gain'
   */
  0.3,

  /* Variable: Kpxp
   * Referenced by: '<S51>/Gain1'
   */
  1.0,

  /* Variable: Kpyp
   * Referenced by: '<S52>/Gain1'
   */
  1.0,

  /* Variable: Kpzp
   * Referenced by: '<S53>/Gain1'
   */
  4.0,

  /* Variable: Kvxd
   * Referenced by: '<S54>/Derivative Gain'
   */
  2.0,

  /* Variable: Kvxi
   * Referenced by: '<S54>/Integral Gain'
   */
  5.0,

  /* Variable: Kvxp
   * Referenced by: '<S54>/Gain'
   */
  10.0,

  /* Variable: Kvyd
   * Referenced by: '<S55>/Derivative Gain'
   */
  0.01,

  /* Variable: Kvyi
   * Referenced by: '<S55>/Integral Gain'
   */
  0.4,

  /* Variable: Kvyp
   * Referenced by: '<S55>/Gain'
   */
  2.0,

  /* Variable: Kvzd
   * Referenced by: '<S56>/Derivative Gain'
   */
  0.1,

  /* Variable: Kvzi
   * Referenced by: '<S56>/Integral Gain'
   */
  0.5,

  /* Variable: Kvzp
   * Referenced by: '<S56>/Gain'
   */
  5.0,

  /* Variable: MAX_CONTROL_ANGLE_PITCH
   * Referenced by: '<S40>/Saturation2'
   */
  35.0,

  /* Variable: MAX_CONTROL_ANGLE_RATE_PITCH
   * Referenced by: '<S39>/Saturation3'
   */
  220.0,

  /* Variable: MAX_CONTROL_ANGLE_RATE_ROLL
   * Referenced by: '<S39>/Saturation4'
   */
  220.0,

  /* Variable: MAX_CONTROL_ANGLE_ROLL
   * Referenced by: '<S40>/Saturation1'
   */
  35.0,

  /* Variable: MAX_CONTROL_VELOCITY_XY
   * Referenced by:
   *   '<S51>/Saturation3'
   *   '<S52>/Saturation3'
   */
  5.0,

  /* Variable: MAX_CONTROL_VELOCITY_Z
   * Referenced by: '<S53>/Saturation3'
   */
  3.0,

  /* Variable: MAX_MAN_THR
   * Referenced by: '<S40>/Saturation'
   */
  0.9,

  /* Variable: ModelInit_PosE
   * Referenced by: '<S7>/xe'
   */
  { 0.0, 0.0, -10.0 },

  /* Variable: ModelInit_RPM
   * Referenced by:
   *   '<S4>/Motor_Dynamics_1'
   *   '<S4>/Motor_Dynamics_2'
   *   '<S4>/Motor_Dynamics_3'
   *   '<S4>/Motor_Dynamics_4'
   */
  557.142,

  /* Variable: ModelParam_motorCr
   * Referenced by:
   *   '<S33>/Gain'
   *   '<S34>/Gain'
   *   '<S35>/Gain'
   *   '<S36>/Gain'
   */
  1148.0,

  /* Variable: ModelParam_motorJm
   * Referenced by: '<S1>/Jrp'
   */
  0.0001287,

  /* Variable: ModelParam_motorT
   * Referenced by:
   *   '<S4>/Motor_Dynamics_1'
   *   '<S4>/Motor_Dynamics_2'
   *   '<S4>/Motor_Dynamics_3'
   *   '<S4>/Motor_Dynamics_4'
   */
  0.02,

  /* Variable: ModelParam_motorWb
   * Referenced by:
   *   '<S33>/Constant'
   *   '<S34>/Constant'
   *   '<S35>/Constant'
   *   '<S36>/Constant'
   */
  -141.4,

  /* Variable: ModelParam_rotorCm
   * Referenced by: '<S5>/Constant4'
   */
  1.779E-7,

  /* Variable: ModelParam_rotorCt
   * Referenced by: '<S5>/Constant3'
   */
  1.105E-5,

  /* Variable: ModelParam_uavCd
   * Referenced by: '<S5>/Constant7'
   */
  0.073,

  /* Variable: ModelParam_uavJ
   * Referenced by: '<S1>/转动惯量'
   */
  { 0.0211, 0.0, 0.0, 0.0, 0.0219, 0.0, 0.0, 0.0, 0.0366 },

  /* Variable: ModelParam_uavMass
   * Referenced by:
   *   '<S1>/mass'
   *   '<S1>/质量'
   */
  1.4,

  /* Variable: ModelParam_uavR
   * Referenced by: '<S5>/Constant5'
   */
  0.4,

  /* Variable: Saturation_I_RP_Max
   * Referenced by:
   *   '<S42>/Discrete-Time Integrator'
   *   '<S43>/Discrete-Time Integrator'
   */
  0.3,

  /* Variable: Saturation_I_RP_Min
   * Referenced by:
   *   '<S42>/Discrete-Time Integrator'
   *   '<S43>/Discrete-Time Integrator'
   */
  -0.3,

  /* Variable: Saturation_I_Y_Max
   * Referenced by: '<S44>/Discrete-Time Integrator'
   */
  0.2,

  /* Variable: Saturation_I_Y_Min
   * Referenced by: '<S44>/Discrete-Time Integrator'
   */
  -0.2,

  /* Variable: Saturation_I_ah
   * Referenced by:
   *   '<S54>/Discrete-Time Integrator'
   *   '<S55>/Discrete-Time Integrator'
   */
  3.43,

  /* Variable: Saturation_I_az
   * Referenced by: '<S56>/Discrete-Time Integrator'
   */
  5.0,

  /* Variable: THR_HOVER
   * Referenced by: '<S40>/Constant'
   */
  0.609,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S57>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
   * Referenced by: '<S58>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
   * Referenced by: '<S48>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
   * Referenced by: '<S47>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_a
   * Referenced by: '<S49>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
   * Referenced by: '<S59>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/xd'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/yd'
   */
  0.0,

  /* Expression: -10
   * Referenced by: '<Root>/zd'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/偏航角'
   */
  0.0,

  /* Expression: [1000,1000,1000,1000]
   * Referenced by: '<S1>/Constant2'
   */
  { 1000.0, 1000.0, 1000.0, 1000.0 },

  /* Expression: 0
   * Referenced by: '<S3>/p,q,r'
   */
  0.0,

  /* Expression: [1,0,0,0]
   * Referenced by: '<S8>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: [inf,inf,0]
   * Referenced by: '<S1>/Saturation1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [-inf,-inf,-inf]
   * Referenced by: '<S1>/Saturation1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 2
   * Referenced by: '<S23>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S26>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S21>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S27>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S22>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S25>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/vb'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S54>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S54>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S57>/TSamp'
   */
  1000.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
   * Referenced by: '<S55>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S55>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_i
   * Referenced by: '<S58>/TSamp'
   */
  1000.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
   * Referenced by: '<S43>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S43>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_e
   * Referenced by: '<S48>/TSamp'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S39>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S39>/Saturation'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
   * Referenced by: '<S42>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S42>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_b
   * Referenced by: '<S47>/TSamp'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S39>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S39>/Saturation1'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ga
   * Referenced by: '<S44>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S44>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_a
   * Referenced by: '<S49>/TSamp'
   */
  1000.0,

  /* Expression: 0.5
   * Referenced by: '<S39>/Saturation2'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S39>/Saturation2'
   */
  -0.5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
   * Referenced by: '<S56>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S56>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_c
   * Referenced by: '<S59>/TSamp'
   */
  1000.0,

  /* Expression: 0.4
   * Referenced by: '<S40>/az'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S40>/az'
   */
  -0.4,

  /* Expression: -1
   * Referenced by: '<S40>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S40>/Saturation'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S2>/Output_Limits1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S2>/Output_Limits1'
   */
  1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1>/Gain1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: [0,0,ModelParam_envGravityAcc]
   * Referenced by: '<S1>/g'
   */
  { 0.0, 0.0, 9.8 },

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: eye(3)
   * Referenced by: '<S6>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S4>/Motor_Dynamics_1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Motor_Dynamics_2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Motor_Dynamics_3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Motor_Dynamics_4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Signal_Saturation_1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Signal_Saturation_1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Signal_Saturation_2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Signal_Saturation_2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Signal_Saturation_3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Signal_Saturation_3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Signal_Saturation_4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Signal_Saturation_4'
   */
  0.0
};
