/*
 * sfun_target_data.c
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

#include "sfun_target.h"
#include "sfun_target_private.h"

/* Block parameters (default storage) */
P_sfun_target_T sfun_target_P = {
  /* Variable: DEG2RAD
   * Referenced by:
   *   '<S3>/Saturation1'
   *   '<S3>/Saturation2'
   */
  0.0174533,

  /* Variable: Kd_PITCH_AgngleRate
   * Referenced by: '<S5>/Derivative Gain'
   */
  0.001,

  /* Variable: Kd_ROLL_AgngleRate
   * Referenced by: '<S6>/Derivative Gain'
   */
  0.001,

  /* Variable: Kd_YAW_AngleRate
   * Referenced by: '<S7>/Derivative Gain'
   */
  0.0,

  /* Variable: Ki_PITCH_AgngleRate
   * Referenced by: '<S5>/Integral Gain'
   */
  0.02,

  /* Variable: Ki_ROLL_AgngleRate
   * Referenced by: '<S6>/Integral Gain'
   */
  0.02,

  /* Variable: Ki_YAW_AngleRate
   * Referenced by: '<S7>/Integral Gain'
   */
  0.01,

  /* Variable: Kp_PITCH_ANGLE
   * Referenced by: '<S8>/Gain'
   */
  6.5,

  /* Variable: Kp_PITCH_AgngleRate
   * Referenced by: '<S5>/Gain'
   */
  0.1,

  /* Variable: Kp_ROLL_ANGLE
   * Referenced by: '<S9>/Gain'
   */
  6.5,

  /* Variable: Kp_ROLL_AgngleRate
   * Referenced by: '<S6>/Gain'
   */
  0.1,

  /* Variable: Kp_YAW_AngleRate
   * Referenced by: '<S7>/Gain'
   */
  0.3,

  /* Variable: Kpxp
   * Referenced by: '<S14>/Gain1'
   */
  1.0,

  /* Variable: Kpyp
   * Referenced by: '<S15>/Gain1'
   */
  1.0,

  /* Variable: Kpzp
   * Referenced by: '<S16>/Gain1'
   */
  4.0,

  /* Variable: Kvxd
   * Referenced by: '<S17>/Derivative Gain'
   */
  2.0,

  /* Variable: Kvxi
   * Referenced by: '<S17>/Integral Gain'
   */
  5.0,

  /* Variable: Kvxp
   * Referenced by: '<S17>/Gain'
   */
  10.0,

  /* Variable: Kvyd
   * Referenced by: '<S18>/Derivative Gain'
   */
  0.01,

  /* Variable: Kvyi
   * Referenced by: '<S18>/Integral Gain'
   */
  0.4,

  /* Variable: Kvyp
   * Referenced by: '<S18>/Gain'
   */
  2.0,

  /* Variable: Kvzd
   * Referenced by: '<S19>/Derivative Gain'
   */
  0.1,

  /* Variable: Kvzi
   * Referenced by: '<S19>/Integral Gain'
   */
  0.5,

  /* Variable: Kvzp
   * Referenced by: '<S19>/Gain'
   */
  5.0,

  /* Variable: MAX_CONTROL_ANGLE_PITCH
   * Referenced by: '<S3>/Saturation2'
   */
  35.0,

  /* Variable: MAX_CONTROL_ANGLE_RATE_PITCH
   * Referenced by: '<S2>/Saturation3'
   */
  220.0,

  /* Variable: MAX_CONTROL_ANGLE_RATE_ROLL
   * Referenced by: '<S2>/Saturation4'
   */
  220.0,

  /* Variable: MAX_CONTROL_ANGLE_ROLL
   * Referenced by: '<S3>/Saturation1'
   */
  35.0,

  /* Variable: MAX_CONTROL_VELOCITY_XY
   * Referenced by:
   *   '<S14>/Saturation3'
   *   '<S15>/Saturation3'
   */
  5.0,

  /* Variable: MAX_CONTROL_VELOCITY_Z
   * Referenced by: '<S16>/Saturation3'
   */
  3.0,

  /* Variable: MAX_MAN_THR
   * Referenced by: '<S3>/Saturation'
   */
  0.9,

  /* Variable: Saturation_I_RP_Max
   * Referenced by:
   *   '<S5>/Discrete-Time Integrator'
   *   '<S6>/Discrete-Time Integrator'
   */
  0.3,

  /* Variable: Saturation_I_RP_Min
   * Referenced by:
   *   '<S5>/Discrete-Time Integrator'
   *   '<S6>/Discrete-Time Integrator'
   */
  -0.3,

  /* Variable: Saturation_I_Y_Max
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.2,

  /* Variable: Saturation_I_Y_Min
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  -0.2,

  /* Variable: Saturation_I_ah
   * Referenced by:
   *   '<S17>/Discrete-Time Integrator'
   *   '<S18>/Discrete-Time Integrator'
   */
  3.43,

  /* Variable: Saturation_I_az
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  5.0,

  /* Variable: THR_HOVER
   * Referenced by: '<S3>/Constant'
   */
  0.609,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S20>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
   * Referenced by: '<S21>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
   * Referenced by: '<S11>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
   * Referenced by: '<S10>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_a
   * Referenced by: '<S12>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
   * Referenced by: '<S22>/UD'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S20>/TSamp'
   */
  1000.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_i
   * Referenced by: '<S21>/TSamp'
   */
  1000.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_e
   * Referenced by: '<S11>/TSamp'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_b
   * Referenced by: '<S10>/TSamp'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation1'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ga
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_a
   * Referenced by: '<S12>/TSamp'
   */
  1000.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Saturation2'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S2>/Saturation2'
   */
  -0.5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_c
   * Referenced by: '<S22>/TSamp'
   */
  1000.0,

  /* Expression: 0.4
   * Referenced by: '<S3>/az'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S3>/az'
   */
  -0.4,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1>/Output_Limits1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Output_Limits1'
   */
  1000.0
};
