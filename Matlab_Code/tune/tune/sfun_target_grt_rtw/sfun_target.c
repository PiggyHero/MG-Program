/*
 * sfun_target.c
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

/* Block states (default storage) */
DW_sfun_target_T sfun_target_DW;

/* External inputs (root inport signals with default storage) */
ExtU_sfun_target_T sfun_target_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_sfun_target_T sfun_target_Y;

/* Real-time model */
RT_MODEL_sfun_target_T sfun_target_M_;
RT_MODEL_sfun_target_T *const sfun_target_M = &sfun_target_M_;

/* Model step function */
void sfun_target_step(void)
{
  real_T rtb_Sum7;
  real_T rtb_Sum2;
  real_T rtb_TSamp;
  real_T rtb_Sum21;
  real_T rtb_TSamp_p;
  real_T rtb_TSamp_j;
  real_T rtb_Saturation;
  real_T rtb_Sum17;
  real_T rtb_Saturation1;
  real_T rtb_Sum_ay;
  real_T rtb_TSamp_g;
  real_T rtb_Saturation2;
  real_T rtb_TSamp_f;
  real_T rtb_Saturation_o;
  real_T rtb_Sum;
  real_T rtb_Sum_m;
  real_T u0;
  real_T u0_tmp;

  /* Gain: '<S14>/Gain1' incorporates:
   *  Inport: '<Root>/x'
   *  Inport: '<Root>/xd'
   *  Sum: '<S3>/Sum1'
   */
  u0 = (sfun_target_U.xd - sfun_target_U.x) * sfun_target_P.Kpxp;

  /* Saturate: '<S14>/Saturation3' */
  if (u0 > sfun_target_P.MAX_CONTROL_VELOCITY_XY) {
    u0 = sfun_target_P.MAX_CONTROL_VELOCITY_XY;
  } else {
    if (u0 < -sfun_target_P.MAX_CONTROL_VELOCITY_XY) {
      u0 = -sfun_target_P.MAX_CONTROL_VELOCITY_XY;
    }
  }

  /* End of Saturate: '<S14>/Saturation3' */

  /* Sum: '<S3>/Sum7' incorporates:
   *  Inport: '<Root>/vx'
   */
  rtb_Sum7 = u0 - sfun_target_U.vx;

  /* SampleTimeMath: '<S20>/TSamp' incorporates:
   *  Gain: '<S17>/Derivative Gain'
   *
   * About '<S20>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = sfun_target_P.Kvxd * rtb_Sum7 * sfun_target_P.TSamp_WtEt;

  /* Sum: '<S17>/Sum' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  Gain: '<S17>/Gain'
   *  Sum: '<S20>/Diff'
   *  UnitDelay: '<S20>/UD'
   */
  rtb_Sum = (sfun_target_P.Kvxp * rtb_Sum7 +
             sfun_target_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    sfun_target_DW.UD_DSTATE);

  /* Gain: '<S15>/Gain1' incorporates:
   *  Inport: '<Root>/y'
   *  Inport: '<Root>/yd'
   *  Sum: '<S3>/Sum3'
   */
  u0 = (sfun_target_U.yd - sfun_target_U.y) * sfun_target_P.Kpyp;

  /* Saturate: '<S15>/Saturation3' */
  if (u0 > sfun_target_P.MAX_CONTROL_VELOCITY_XY) {
    u0 = sfun_target_P.MAX_CONTROL_VELOCITY_XY;
  } else {
    if (u0 < -sfun_target_P.MAX_CONTROL_VELOCITY_XY) {
      u0 = -sfun_target_P.MAX_CONTROL_VELOCITY_XY;
    }
  }

  /* End of Saturate: '<S15>/Saturation3' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  Inport: '<Root>/vy'
   */
  rtb_Sum2 = u0 - sfun_target_U.vy;

  /* SampleTimeMath: '<S21>/TSamp' incorporates:
   *  Gain: '<S18>/Derivative Gain'
   *
   * About '<S21>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_p = sfun_target_P.Kvyd * rtb_Sum2 * sfun_target_P.TSamp_WtEt_i;

  /* Sum: '<S18>/Sum' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Gain: '<S18>/Gain'
   *  Sum: '<S21>/Diff'
   *  UnitDelay: '<S21>/UD'
   */
  rtb_Sum_m = (sfun_target_P.Kvyp * rtb_Sum2 +
               sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a) + (rtb_TSamp_p -
    sfun_target_DW.UD_DSTATE_l);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Inport: '<Root>/yaw'
   */
  /* MATLAB Function '控制系统/position_control/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:3' */
  /* '<S13>:1:4' */
  rtb_Saturation1 = cos(sfun_target_U.yaw);
  rtb_Sum17 = sin(sfun_target_U.yaw);
  u0 = (-rtb_Sum17 * rtb_Sum + rtb_Saturation1 * rtb_Sum_m) / 9.8;

  /* Saturate: '<S3>/Saturation1' */
  rtb_TSamp_g = -sfun_target_P.MAX_CONTROL_ANGLE_ROLL * sfun_target_P.DEG2RAD;
  rtb_Saturation2 = sfun_target_P.MAX_CONTROL_ANGLE_ROLL * sfun_target_P.DEG2RAD;
  if (u0 > rtb_Saturation2) {
    u0 = rtb_Saturation2;
  } else {
    if (u0 < rtb_TSamp_g) {
      u0 = rtb_TSamp_g;
    }
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Gain: '<S9>/Gain' incorporates:
   *  Inport: '<Root>/roll'
   *  Sum: '<S2>/Sum18'
   */
  u0 = (u0 - sfun_target_U.roll) * sfun_target_P.Kp_ROLL_ANGLE;

  /* Saturate: '<S2>/Saturation4' */
  if (u0 > sfun_target_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
    u0 = sfun_target_P.MAX_CONTROL_ANGLE_RATE_ROLL;
  } else {
    if (u0 < -sfun_target_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
      u0 = -sfun_target_P.MAX_CONTROL_ANGLE_RATE_ROLL;
    }
  }

  /* End of Saturate: '<S2>/Saturation4' */

  /* Sum: '<S2>/Sum21' incorporates:
   *  Inport: '<Root>/p'
   */
  rtb_Sum21 = u0 - sfun_target_U.p;

  /* SampleTimeMath: '<S11>/TSamp' incorporates:
   *  Gain: '<S6>/Derivative Gain'
   *
   * About '<S11>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = sfun_target_P.Kd_ROLL_AgngleRate * rtb_Sum21 *
    sfun_target_P.TSamp_WtEt_e;

  /* Sum: '<S6>/Sum' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S6>/Gain'
   *  Sum: '<S11>/Diff'
   *  UnitDelay: '<S11>/UD'
   */
  rtb_Saturation = (sfun_target_P.Kp_ROLL_AgngleRate * rtb_Sum21 +
                    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n) +
    (rtb_TSamp_j - sfun_target_DW.UD_DSTATE_f);

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Saturation > sfun_target_P.Saturation_UpperSat) {
    rtb_Saturation = sfun_target_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < sfun_target_P.Saturation_LowerSat) {
      rtb_Saturation = sfun_target_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* MATLAB Function: '<S3>/MATLAB Function' */
  u0 = (-rtb_Saturation1 * rtb_Sum - rtb_Sum17 * rtb_Sum_m) / 9.8;

  /* Saturate: '<S3>/Saturation2' */
  rtb_TSamp_g = -sfun_target_P.MAX_CONTROL_ANGLE_PITCH * sfun_target_P.DEG2RAD;
  rtb_Saturation2 = sfun_target_P.MAX_CONTROL_ANGLE_PITCH *
    sfun_target_P.DEG2RAD;
  if (u0 > rtb_Saturation2) {
    u0 = rtb_Saturation2;
  } else {
    if (u0 < rtb_TSamp_g) {
      u0 = rtb_TSamp_g;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/pitch'
   *  Sum: '<S2>/Sum19'
   */
  u0 = (u0 - sfun_target_U.pitch) * sfun_target_P.Kp_PITCH_ANGLE;

  /* Saturate: '<S2>/Saturation3' */
  if (u0 > sfun_target_P.MAX_CONTROL_ANGLE_RATE_PITCH) {
    u0 = sfun_target_P.MAX_CONTROL_ANGLE_RATE_PITCH;
  } else {
    if (u0 < -sfun_target_P.MAX_CONTROL_ANGLE_RATE_PITCH) {
      u0 = -sfun_target_P.MAX_CONTROL_ANGLE_RATE_PITCH;
    }
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* Sum: '<S2>/Sum22' incorporates:
   *  Inport: '<Root>/q'
   */
  rtb_Sum = u0 - sfun_target_U.q;

  /* SampleTimeMath: '<S10>/TSamp' incorporates:
   *  Gain: '<S5>/Derivative Gain'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Sum_m = sfun_target_P.Kd_PITCH_AgngleRate * rtb_Sum *
    sfun_target_P.TSamp_WtEt_b;

  /* Sum: '<S5>/Sum' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S5>/Gain'
   *  Sum: '<S10>/Diff'
   *  UnitDelay: '<S10>/UD'
   */
  rtb_Saturation1 = (sfun_target_P.Kp_PITCH_AgngleRate * rtb_Sum +
                     sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c) +
    (rtb_Sum_m - sfun_target_DW.UD_DSTATE_c);

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_Saturation1 > sfun_target_P.Saturation1_UpperSat) {
    rtb_Saturation1 = sfun_target_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < sfun_target_P.Saturation1_LowerSat) {
      rtb_Saturation1 = sfun_target_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Sum: '<S2>/Sum17' incorporates:
   *  Inport: '<Root>/r'
   *  Inport: '<Root>/yawRate_d'
   */
  rtb_Sum17 = sfun_target_U.yawRate_d - sfun_target_U.r;

  /* SampleTimeMath: '<S12>/TSamp' incorporates:
   *  Gain: '<S7>/Derivative Gain'
   *
   * About '<S12>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_g = sfun_target_P.Kd_YAW_AngleRate * rtb_Sum17 *
    sfun_target_P.TSamp_WtEt_a;

  /* Sum: '<S7>/Sum' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/Gain'
   *  Sum: '<S12>/Diff'
   *  UnitDelay: '<S12>/UD'
   */
  rtb_Saturation2 = (sfun_target_P.Kp_YAW_AngleRate * rtb_Sum17 +
                     sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p) +
    (rtb_TSamp_g - sfun_target_DW.UD_DSTATE_lz);

  /* Saturate: '<S2>/Saturation2' */
  if (rtb_Saturation2 > sfun_target_P.Saturation2_UpperSat) {
    rtb_Saturation2 = sfun_target_P.Saturation2_UpperSat;
  } else {
    if (rtb_Saturation2 < sfun_target_P.Saturation2_LowerSat) {
      rtb_Saturation2 = sfun_target_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Gain: '<S16>/Gain1' incorporates:
   *  Inport: '<Root>/z'
   *  Inport: '<Root>/zd'
   *  Sum: '<S3>/Sum4'
   */
  u0 = (sfun_target_U.zd - sfun_target_U.z) * sfun_target_P.Kpzp;

  /* Saturate: '<S16>/Saturation3' */
  if (u0 > sfun_target_P.MAX_CONTROL_VELOCITY_Z) {
    u0 = sfun_target_P.MAX_CONTROL_VELOCITY_Z;
  } else {
    if (u0 < -sfun_target_P.MAX_CONTROL_VELOCITY_Z) {
      u0 = -sfun_target_P.MAX_CONTROL_VELOCITY_Z;
    }
  }

  /* End of Saturate: '<S16>/Saturation3' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/vz'
   */
  rtb_Sum_ay = u0 - sfun_target_U.vz;

  /* SampleTimeMath: '<S22>/TSamp' incorporates:
   *  Gain: '<S19>/Derivative Gain'
   *
   * About '<S22>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_f = sfun_target_P.Kvzd * rtb_Sum_ay * sfun_target_P.TSamp_WtEt_c;

  /* Sum: '<S19>/Sum' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   *  Gain: '<S19>/Gain'
   *  Sum: '<S22>/Diff'
   *  UnitDelay: '<S22>/UD'
   */
  u0 = (sfun_target_P.Kvzp * rtb_Sum_ay +
        sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g) + (rtb_TSamp_f -
    sfun_target_DW.UD_DSTATE_m);

  /* Saturate: '<S3>/az' */
  if (u0 > sfun_target_P.az_UpperSat) {
    u0 = sfun_target_P.az_UpperSat;
  } else {
    if (u0 < sfun_target_P.az_LowerSat) {
      u0 = sfun_target_P.az_LowerSat;
    }
  }

  /* End of Saturate: '<S3>/az' */

  /* Gain: '<S3>/Gain' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sum: '<S3>/Sum6'
   */
  rtb_Saturation_o = (u0 - sfun_target_P.THR_HOVER) * sfun_target_P.Gain_Gain;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Saturation_o > sfun_target_P.MAX_MAN_THR) {
    rtb_Saturation_o = sfun_target_P.MAX_MAN_THR;
  } else {
    if (rtb_Saturation_o < sfun_target_P.Saturation_LowerSat_c) {
      rtb_Saturation_o = sfun_target_P.Saturation_LowerSat_c;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* MATLAB Function: '<S1>/pwm_out2' */
  /* MATLAB Function '控制系统/pwm_out2': '<S4>:1' */
  /* '<S4>:1:8' */
  /* '<S4>:1:9' */
  /* '<S4>:1:11' */
  /* '<S4>:1:12' */
  /* '<S4>:1:13' */
  /* '<S4>:1:14' */
  u0_tmp = rtb_Saturation_o - rtb_Saturation;
  u0 = ((u0_tmp + rtb_Saturation1) + rtb_Saturation2) * 1000.0 + 1000.0;

  /* Saturate: '<S1>/Output_Limits1' */
  if (u0 > sfun_target_P.Output_Limits1_UpperSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[0] = sfun_target_P.Output_Limits1_UpperSat;
  } else if (u0 < sfun_target_P.Output_Limits1_LowerSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[0] = sfun_target_P.Output_Limits1_LowerSat;
  } else {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[0] = u0;
  }

  /* MATLAB Function: '<S1>/pwm_out2' */
  rtb_Saturation += rtb_Saturation_o;
  u0 = ((rtb_Saturation - rtb_Saturation1) + rtb_Saturation2) * 1000.0 + 1000.0;

  /* Saturate: '<S1>/Output_Limits1' */
  if (u0 > sfun_target_P.Output_Limits1_UpperSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[1] = sfun_target_P.Output_Limits1_UpperSat;
  } else if (u0 < sfun_target_P.Output_Limits1_LowerSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[1] = sfun_target_P.Output_Limits1_LowerSat;
  } else {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[1] = u0;
  }

  /* MATLAB Function: '<S1>/pwm_out2' */
  u0 = ((rtb_Saturation + rtb_Saturation1) - rtb_Saturation2) * 1000.0 + 1000.0;

  /* Saturate: '<S1>/Output_Limits1' */
  if (u0 > sfun_target_P.Output_Limits1_UpperSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[2] = sfun_target_P.Output_Limits1_UpperSat;
  } else if (u0 < sfun_target_P.Output_Limits1_LowerSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[2] = sfun_target_P.Output_Limits1_LowerSat;
  } else {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[2] = u0;
  }

  /* MATLAB Function: '<S1>/pwm_out2' */
  u0 = ((u0_tmp - rtb_Saturation1) - rtb_Saturation2) * 1000.0 + 1000.0;

  /* Saturate: '<S1>/Output_Limits1' */
  if (u0 > sfun_target_P.Output_Limits1_UpperSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[3] = sfun_target_P.Output_Limits1_UpperSat;
  } else if (u0 < sfun_target_P.Output_Limits1_LowerSat) {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[3] = sfun_target_P.Output_Limits1_LowerSat;
  } else {
    /* Outport: '<Root>/PWM' */
    sfun_target_Y.PWM[3] = u0;
  }

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S17>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE += sfun_target_P.Kvxi * rtb_Sum7 *
    sfun_target_P.DiscreteTimeIntegrator_gainval;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE >=
      sfun_target_P.Saturation_I_ah) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE = sfun_target_P.Saturation_I_ah;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE <=
        -sfun_target_P.Saturation_I_ah) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE =
        -sfun_target_P.Saturation_I_ah;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S20>/UD' */
  sfun_target_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S18>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a += sfun_target_P.Kvyi *
    rtb_Sum2 * sfun_target_P.DiscreteTimeIntegrator_gainva_g;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a >=
      sfun_target_P.Saturation_I_ah) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a =
      sfun_target_P.Saturation_I_ah;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a <=
        -sfun_target_P.Saturation_I_ah) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a =
        -sfun_target_P.Saturation_I_ah;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S21>/UD' */
  sfun_target_DW.UD_DSTATE_l = rtb_TSamp_p;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S6>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n +=
    sfun_target_P.Ki_ROLL_AgngleRate * rtb_Sum21 *
    sfun_target_P.DiscreteTimeIntegrator_gainva_l;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n >=
      sfun_target_P.Saturation_I_RP_Max) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n =
      sfun_target_P.Saturation_I_RP_Max;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n <=
        sfun_target_P.Saturation_I_RP_Min) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n =
        sfun_target_P.Saturation_I_RP_Min;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S11>/UD' */
  sfun_target_DW.UD_DSTATE_f = rtb_TSamp_j;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S5>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c +=
    sfun_target_P.Ki_PITCH_AgngleRate * rtb_Sum *
    sfun_target_P.DiscreteTimeIntegrator_gainva_b;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c >=
      sfun_target_P.Saturation_I_RP_Max) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c =
      sfun_target_P.Saturation_I_RP_Max;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c <=
        sfun_target_P.Saturation_I_RP_Min) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c =
        sfun_target_P.Saturation_I_RP_Min;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S10>/UD' */
  sfun_target_DW.UD_DSTATE_c = rtb_Sum_m;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p +=
    sfun_target_P.Ki_YAW_AngleRate * rtb_Sum17 *
    sfun_target_P.DiscreteTimeIntegrator_gainv_ga;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p >=
      sfun_target_P.Saturation_I_Y_Max) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p =
      sfun_target_P.Saturation_I_Y_Max;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p <=
        sfun_target_P.Saturation_I_Y_Min) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p =
        sfun_target_P.Saturation_I_Y_Min;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S12>/UD' */
  sfun_target_DW.UD_DSTATE_lz = rtb_TSamp_g;

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S19>/Integral Gain'
   */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g += sfun_target_P.Kvzi *
    rtb_Sum_ay * sfun_target_P.DiscreteTimeIntegrator_gainva_d;
  if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g >=
      sfun_target_P.Saturation_I_az) {
    sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g =
      sfun_target_P.Saturation_I_az;
  } else {
    if (sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g <=
        -sfun_target_P.Saturation_I_az) {
      sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g =
        -sfun_target_P.Saturation_I_az;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S22>/UD' */
  sfun_target_DW.UD_DSTATE_m = rtb_TSamp_f;

  /* Matfile logging */
  rt_UpdateTXYLogVars(sfun_target_M->rtwLogInfo,
                      (&sfun_target_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(sfun_target_M)!=-1) &&
        !((rtmGetTFinal(sfun_target_M)-sfun_target_M->Timing.taskTime0) >
          sfun_target_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sfun_target_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sfun_target_M->Timing.clockTick0)) {
    ++sfun_target_M->Timing.clockTickH0;
  }

  sfun_target_M->Timing.taskTime0 = sfun_target_M->Timing.clockTick0 *
    sfun_target_M->Timing.stepSize0 + sfun_target_M->Timing.clockTickH0 *
    sfun_target_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void sfun_target_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sfun_target_M, 0,
                sizeof(RT_MODEL_sfun_target_T));
  rtmSetTFinal(sfun_target_M, 100.0);
  sfun_target_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    sfun_target_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sfun_target_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sfun_target_M->rtwLogInfo, (NULL));
    rtliSetLogT(sfun_target_M->rtwLogInfo, "tout");
    rtliSetLogX(sfun_target_M->rtwLogInfo, "");
    rtliSetLogXFinal(sfun_target_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sfun_target_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(sfun_target_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(sfun_target_M->rtwLogInfo, 0);
    rtliSetLogDecimation(sfun_target_M->rtwLogInfo, 1);
    rtliSetLogY(sfun_target_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(sfun_target_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(sfun_target_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&sfun_target_DW, 0,
                sizeof(DW_sfun_target_T));

  /* external inputs */
  (void)memset(&sfun_target_U, 0, sizeof(ExtU_sfun_target_T));

  /* external outputs */
  (void) memset(&sfun_target_Y.PWM[0], 0,
                4U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(sfun_target_M->rtwLogInfo, 0.0, rtmGetTFinal
    (sfun_target_M), sfun_target_M->Timing.stepSize0, (&rtmGetErrorStatus
    (sfun_target_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE =
    sfun_target_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S20>/UD' */
  sfun_target_DW.UD_DSTATE = sfun_target_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_a =
    sfun_target_P.DiscreteTimeIntegrator_IC_m;

  /* InitializeConditions for UnitDelay: '<S21>/UD' */
  sfun_target_DW.UD_DSTATE_l = sfun_target_P.DiscreteDerivative_ICPrevScal_i;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_n =
    sfun_target_P.DiscreteTimeIntegrator_IC_c;

  /* InitializeConditions for UnitDelay: '<S11>/UD' */
  sfun_target_DW.UD_DSTATE_f = sfun_target_P.DiscreteDerivative_ICPrevScal_k;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_c =
    sfun_target_P.DiscreteTimeIntegrator_IC_l;

  /* InitializeConditions for UnitDelay: '<S10>/UD' */
  sfun_target_DW.UD_DSTATE_c = sfun_target_P.DiscreteDerivative_ICPrevScal_b;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_p =
    sfun_target_P.DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for UnitDelay: '<S12>/UD' */
  sfun_target_DW.UD_DSTATE_lz = sfun_target_P.DiscreteDerivative_ICPrevScal_a;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  sfun_target_DW.DiscreteTimeIntegrator_DSTATE_g =
    sfun_target_P.DiscreteTimeIntegrator_IC_i;

  /* InitializeConditions for UnitDelay: '<S22>/UD' */
  sfun_target_DW.UD_DSTATE_m = sfun_target_P.DiscreteDerivative_ICPrevScal_o;
}

/* Model terminate function */
void sfun_target_terminate(void)
{
  /* (no terminate code required) */
}
