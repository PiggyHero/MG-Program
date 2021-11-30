/*
 * PosCtrl_tune.c
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

/* Block signals (default storage) */
B_PosCtrl_tune_T PosCtrl_tune_B;

/* Continuous states */
X_PosCtrl_tune_T PosCtrl_tune_X;

/* Block states (default storage) */
DW_PosCtrl_tune_T PosCtrl_tune_DW;

/* Real-time model */
RT_MODEL_PosCtrl_tune_T PosCtrl_tune_M_;
RT_MODEL_PosCtrl_tune_T *const PosCtrl_tune_M = &PosCtrl_tune_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 17;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PosCtrl_tune_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PosCtrl_tune_step();
  PosCtrl_tune_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PosCtrl_tune_step();
  PosCtrl_tune_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void rt_mrdivided3x3_snf(const real_T u0[9], const real_T u1[9], real_T y[9])
{
  real_T u0_0[9];
  real_T u1_0[9];
  int32_T ONE;
  int32_T THREE;
  int32_T r1;
  int32_T r2;
  real_T maxval;
  real_T a21;
  real_T x;
  for (THREE = 0; THREE < 9; THREE++) {
    maxval = u0[THREE];
    a21 = u1[THREE];
    u0_0[THREE] = maxval;
    u1_0[THREE] = a21;
  }

  THREE = 2;
  r1 = 0;
  r2 = 1;
  x = u1_0[0];
  x = fabs(x);
  maxval = x;
  x = u1_0[1];
  x = fabs(x);
  a21 = x;
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  x = u1_0[2];
  x = fabs(x);
  a21 = x;
  if (a21 > maxval) {
    r1 = 2;
    r2 = 1;
    THREE = 0;
  }

  u1_0[r2] /= u1_0[r1];
  u1_0[THREE] /= u1_0[r1];
  u1_0[r2 + 3] -= u1_0[r1 + 3] * u1_0[r2];
  u1_0[THREE + 3] -= u1_0[r1 + 3] * u1_0[THREE];
  u1_0[r2 + 6] -= u1_0[r1 + 6] * u1_0[r2];
  u1_0[THREE + 6] -= u1_0[r1 + 6] * u1_0[THREE];
  x = u1_0[THREE + 3];
  x = fabs(x);
  a21 = x;
  x = u1_0[r2 + 3];
  x = fabs(x);
  maxval = x;
  if (a21 > maxval) {
    ONE = r2 + 1;
    r2 = THREE;
    THREE = ONE - 1;
  }

  u1_0[THREE + 3] /= u1_0[r2 + 3];
  u1_0[THREE + 6] -= u1_0[THREE + 3] * u1_0[r2 + 6];
  y[3 * r1] = u0_0[0] / u1_0[r1];
  y[3 * r2] = u0_0[3] - y[3 * r1] * u1_0[r1 + 3];
  y[3 * THREE] = u0_0[6] - y[3 * r1] * u1_0[r1 + 6];
  y[3 * r2] /= u1_0[r2 + 3];
  y[3 * THREE] -= y[3 * r2] * u1_0[r2 + 6];
  y[3 * THREE] /= u1_0[THREE + 6];
  y[3 * r2] -= y[3 * THREE] * u1_0[THREE + 3];
  y[3 * r1] -= y[3 * THREE] * u1_0[THREE];
  y[3 * r1] -= y[3 * r2] * u1_0[r2];
  y[3 * r1 + 1] = u0_0[1] / u1_0[r1];
  y[3 * r2 + 1] = u0_0[4] - y[3 * r1 + 1] * u1_0[r1 + 3];
  y[3 * THREE + 1] = u0_0[7] - y[3 * r1 + 1] * u1_0[r1 + 6];
  y[3 * r2 + 1] /= u1_0[r2 + 3];
  y[3 * THREE + 1] -= y[3 * r2 + 1] * u1_0[r2 + 6];
  y[3 * THREE + 1] /= u1_0[THREE + 6];
  y[3 * r2 + 1] -= y[3 * THREE + 1] * u1_0[THREE + 3];
  y[3 * r1 + 1] -= y[3 * THREE + 1] * u1_0[THREE];
  y[3 * r1 + 1] -= y[3 * r2 + 1] * u1_0[r2];
  y[3 * r1 + 2] = u0_0[2] / u1_0[r1];
  y[3 * r2 + 2] = u0_0[5] - y[3 * r1 + 2] * u1_0[r1 + 3];
  y[3 * THREE + 2] = u0_0[8] - y[3 * r1 + 2] * u1_0[r1 + 6];
  y[3 * r2 + 2] /= u1_0[r2 + 3];
  y[3 * THREE + 2] -= y[3 * r2 + 2] * u1_0[r2 + 6];
  y[3 * THREE + 2] /= u1_0[THREE + 6];
  y[3 * r2 + 2] -= y[3 * THREE + 2] * u1_0[THREE + 3];
  y[3 * r1 + 2] -= y[3 * THREE + 2] * u1_0[THREE];
  y[3 * r1 + 2] -= y[3 * r2 + 2] * u1_0[r2];
}

/* Model step function */
void PosCtrl_tune_step(void)
{
  if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
    /* set solver stop time */
    if (!(PosCtrl_tune_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PosCtrl_tune_M->solverInfo,
                            ((PosCtrl_tune_M->Timing.clockTickH0 + 1) *
        PosCtrl_tune_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PosCtrl_tune_M->solverInfo,
                            ((PosCtrl_tune_M->Timing.clockTick0 + 1) *
        PosCtrl_tune_M->Timing.stepSize0 + PosCtrl_tune_M->Timing.clockTickH0 *
        PosCtrl_tune_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PosCtrl_tune_M)) {
    PosCtrl_tune_M->Timing.t[0] = rtsiGetT(&PosCtrl_tune_M->solverInfo);
  }

  {
    real_T Rbe[9];
    real_T tmp[12];
    real_T tmp_0[16];
    int32_T i;
    real_T z1;
    real_T z1_idx_0;
    real_T tmp_1;
    real_T z1_idx_1;
    real_T z1_idx_2;
    real_T u0;
    real_T u1;
    real_T u2;

    /* Integrator: '<S3>/p,q,r' */
    PosCtrl_tune_B.pqr[0] = PosCtrl_tune_X.pqr_CSTATE[0];
    PosCtrl_tune_B.pqr[1] = PosCtrl_tune_X.pqr_CSTATE[1];
    PosCtrl_tune_B.pqr[2] = PosCtrl_tune_X.pqr_CSTATE[2];
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* Constant: '<S8>/Constant' */
      PosCtrl_tune_B.Constant[0] = PosCtrl_tune_P.Constant_Value[0];
      PosCtrl_tune_B.Constant[1] = PosCtrl_tune_P.Constant_Value[1];
      PosCtrl_tune_B.Constant[2] = PosCtrl_tune_P.Constant_Value[2];
      PosCtrl_tune_B.Constant[3] = PosCtrl_tune_P.Constant_Value[3];
    }

    /* Integrator: '<S8>/q' */
    if (PosCtrl_tune_DW.q_IWORK != 0) {
      PosCtrl_tune_X.q_CSTATE[0] = PosCtrl_tune_B.Constant[0];
      PosCtrl_tune_X.q_CSTATE[1] = PosCtrl_tune_B.Constant[1];
      PosCtrl_tune_X.q_CSTATE[2] = PosCtrl_tune_B.Constant[2];
      PosCtrl_tune_X.q_CSTATE[3] = PosCtrl_tune_B.Constant[3];
    }

    PosCtrl_tune_B.q[0] = PosCtrl_tune_X.q_CSTATE[0];

    /* DotProduct: '<S8>/Dot Product' */
    u0 = PosCtrl_tune_B.q[0];
    u1 = PosCtrl_tune_B.q[0];
    u2 = u0 * u1;

    /* Integrator: '<S8>/q' */
    PosCtrl_tune_B.q[1] = PosCtrl_tune_X.q_CSTATE[1];

    /* DotProduct: '<S8>/Dot Product' */
    u0 = PosCtrl_tune_B.q[1];
    u1 = PosCtrl_tune_B.q[1];
    u2 += u0 * u1;

    /* Integrator: '<S8>/q' */
    PosCtrl_tune_B.q[2] = PosCtrl_tune_X.q_CSTATE[2];

    /* DotProduct: '<S8>/Dot Product' */
    u0 = PosCtrl_tune_B.q[2];
    u1 = PosCtrl_tune_B.q[2];
    u2 += u0 * u1;

    /* Integrator: '<S8>/q' */
    PosCtrl_tune_B.q[3] = PosCtrl_tune_X.q_CSTATE[3];

    /* DotProduct: '<S8>/Dot Product' */
    u0 = PosCtrl_tune_B.q[3];
    u1 = PosCtrl_tune_B.q[3];
    u2 += u0 * u1;
    PosCtrl_tune_B.DotProduct = u2;

    /* Product: '<S8>/Divide' */
    PosCtrl_tune_B.Divide[0] = PosCtrl_tune_B.q[0] / PosCtrl_tune_B.DotProduct;
    PosCtrl_tune_B.Divide[1] = PosCtrl_tune_B.q[1] / PosCtrl_tune_B.DotProduct;
    PosCtrl_tune_B.Divide[2] = PosCtrl_tune_B.q[2] / PosCtrl_tune_B.DotProduct;
    PosCtrl_tune_B.Divide[3] = PosCtrl_tune_B.q[3] / PosCtrl_tune_B.DotProduct;

    /* MATLAB Function: '<S8>/四元数转欧拉角' */
    /* :  Rbe = [q(1)*q(1) + q(2)*q(2) - q(3)*q(3) - q(4)*q(4), 2*(q(2)*q(3) - q(1)*q(4)), 2*(q(2)*q(4) + q(1)*q(3)) */
    /* :         2*(q(2)*q(3) + q(1)*q(4)), q(1)*q(1) - q(2)*q(2) + q(3)*q(3) - q(4)*q(4), 2*(q(3)*q(4) - q(1)*q(2)) */
    /* :         2*(q(2)*q(4) - q(1)*q(3)), 2*(q(3)*q(4) + q(1)*q(2)), q(1)*q(1) - q(2)*q(2) - q(3)*q(3) + q(4)*q(4)]; */
    Rbe[0] = ((PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[0] +
               PosCtrl_tune_B.Divide[1] * PosCtrl_tune_B.Divide[1]) -
              PosCtrl_tune_B.Divide[2] * PosCtrl_tune_B.Divide[2]) -
      PosCtrl_tune_B.Divide[3] * PosCtrl_tune_B.Divide[3];
    Rbe[1] = (PosCtrl_tune_B.Divide[1] * PosCtrl_tune_B.Divide[2] +
              PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[3]) * 2.0;
    Rbe[2] = (PosCtrl_tune_B.Divide[1] * PosCtrl_tune_B.Divide[3] -
              PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[2]) * 2.0;
    Rbe[5] = (PosCtrl_tune_B.Divide[2] * PosCtrl_tune_B.Divide[3] +
              PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[1]) * 2.0;
    Rbe[8] = ((PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[0] -
               PosCtrl_tune_B.Divide[1] * PosCtrl_tune_B.Divide[1]) -
              PosCtrl_tune_B.Divide[2] * PosCtrl_tune_B.Divide[2]) +
      PosCtrl_tune_B.Divide[3] * PosCtrl_tune_B.Divide[3];

    /* :  phi = atan2(Rbe(3,2),Rbe(3,3)); */
    /* :  theta = asin(-Rbe(3,1)); */
    /* :  psi = atan2(Rbe(2,1),Rbe(1,1)); */
    /* :  y = [phi theta psi]; */
    u0 = rt_atan2d_snf(Rbe[5], Rbe[8]);
    u1 = asin(-Rbe[2]);
    u2 = rt_atan2d_snf(Rbe[1], Rbe[0]);
    PosCtrl_tune_B.y[0] = u0;
    PosCtrl_tune_B.y[1] = u1;
    PosCtrl_tune_B.y[2] = u2;

    /* Integrator: '<S7>/xe' */
    PosCtrl_tune_B.xe[0] = PosCtrl_tune_X.xe_CSTATE[0];

    /* Saturate: '<S1>/Saturation1' */
    u0 = PosCtrl_tune_B.xe[0];
    u1 = PosCtrl_tune_P.Saturation1_LowerSat[0];
    u2 = PosCtrl_tune_P.Saturation1_UpperSat[0];
    if (u0 > u2) {
      u0 = u2;
    } else {
      if (u0 < u1) {
        u0 = u1;
      }
    }

    PosCtrl_tune_B.Saturation1[0] = u0;

    /* Integrator: '<S7>/xe' */
    PosCtrl_tune_B.xe[1] = PosCtrl_tune_X.xe_CSTATE[1];

    /* Saturate: '<S1>/Saturation1' */
    u0 = PosCtrl_tune_B.xe[1];
    u1 = PosCtrl_tune_P.Saturation1_LowerSat[1];
    u2 = PosCtrl_tune_P.Saturation1_UpperSat[1];
    if (u0 > u2) {
      u0 = u2;
    } else {
      if (u0 < u1) {
        u0 = u1;
      }
    }

    PosCtrl_tune_B.Saturation1[1] = u0;

    /* Integrator: '<S7>/xe' */
    PosCtrl_tune_B.xe[2] = PosCtrl_tune_X.xe_CSTATE[2];

    /* Saturate: '<S1>/Saturation1' */
    u0 = PosCtrl_tune_B.xe[2];
    u1 = PosCtrl_tune_P.Saturation1_LowerSat[2];
    u2 = PosCtrl_tune_P.Saturation1_UpperSat[2];
    if (u0 > u2) {
      u0 = u2;
    } else {
      if (u0 < u1) {
        u0 = u1;
      }
    }

    PosCtrl_tune_B.Saturation1[2] = u0;

    /* Sum: '<S40>/Sum1' incorporates:
     *  Constant: '<Root>/xd'
     */
    PosCtrl_tune_B.Sum1 = PosCtrl_tune_P.xd_Value - PosCtrl_tune_B.Saturation1[0];

    /* Gain: '<S51>/Gain1' */
    PosCtrl_tune_B.Gain1 = PosCtrl_tune_P.Kpxp * PosCtrl_tune_B.Sum1;

    /* Saturate: '<S51>/Saturation3' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY;
    if (PosCtrl_tune_B.Gain1 > PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY) {
      PosCtrl_tune_B.Saturation3 = PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY;
    } else if (PosCtrl_tune_B.Gain1 < z1_idx_0) {
      PosCtrl_tune_B.Saturation3 = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation3 = PosCtrl_tune_B.Gain1;
    }

    /* End of Saturate: '<S51>/Saturation3' */

    /* Product: '<S32>/Product' */
    PosCtrl_tune_B.Product = PosCtrl_tune_B.Divide[0] * PosCtrl_tune_B.Divide[0];

    /* Product: '<S32>/Product1' */
    PosCtrl_tune_B.Product1 = PosCtrl_tune_B.Divide[1] * PosCtrl_tune_B.Divide[1];

    /* Product: '<S32>/Product2' */
    PosCtrl_tune_B.Product2 = PosCtrl_tune_B.Divide[2] * PosCtrl_tune_B.Divide[2];

    /* Product: '<S32>/Product3' */
    PosCtrl_tune_B.Product3 = PosCtrl_tune_B.Divide[3] * PosCtrl_tune_B.Divide[3];

    /* Sum: '<S32>/Sum' */
    PosCtrl_tune_B.Sum = ((PosCtrl_tune_B.Product + PosCtrl_tune_B.Product1) +
                          PosCtrl_tune_B.Product2) + PosCtrl_tune_B.Product3;

    /* Sqrt: '<S31>/sqrt' */
    PosCtrl_tune_B.sqrt_c = sqrt(PosCtrl_tune_B.Sum);

    /* Product: '<S30>/Product' */
    PosCtrl_tune_B.Product_d = PosCtrl_tune_B.Divide[0] / PosCtrl_tune_B.sqrt_c;

    /* Product: '<S20>/Product3' */
    PosCtrl_tune_B.Product3_p = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product_d;

    /* Product: '<S30>/Product1' */
    PosCtrl_tune_B.Product1_k = PosCtrl_tune_B.Divide[1] / PosCtrl_tune_B.sqrt_c;

    /* Product: '<S20>/Product2' */
    PosCtrl_tune_B.Product2_n = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product1_k;

    /* Product: '<S30>/Product2' */
    PosCtrl_tune_B.Product2_p = PosCtrl_tune_B.Divide[2] / PosCtrl_tune_B.sqrt_c;

    /* Product: '<S20>/Product1' */
    PosCtrl_tune_B.Product1_kg = PosCtrl_tune_B.Product2_p *
      PosCtrl_tune_B.Product2_p;

    /* Product: '<S30>/Product3' */
    PosCtrl_tune_B.Product3_py = PosCtrl_tune_B.Divide[3] /
      PosCtrl_tune_B.sqrt_c;

    /* Product: '<S20>/Product' */
    PosCtrl_tune_B.Product_c = PosCtrl_tune_B.Product3_py *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S20>/Sum' */
    PosCtrl_tune_B.VectorConcatenate[0] = ((PosCtrl_tune_B.Product3_p +
      PosCtrl_tune_B.Product2_n) - PosCtrl_tune_B.Product1_kg) -
      PosCtrl_tune_B.Product_c;

    /* Product: '<S23>/Product3' */
    PosCtrl_tune_B.Product3_n = PosCtrl_tune_B.Product3_py *
      PosCtrl_tune_B.Product_d;

    /* Product: '<S23>/Product2' */
    PosCtrl_tune_B.Product2_i = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product2_p;

    /* Sum: '<S23>/Sum' */
    PosCtrl_tune_B.Sum_e = PosCtrl_tune_B.Product2_i - PosCtrl_tune_B.Product3_n;

    /* Gain: '<S23>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[1] = PosCtrl_tune_P.Gain_Gain *
      PosCtrl_tune_B.Sum_e;

    /* Product: '<S26>/Product1' */
    PosCtrl_tune_B.Product1_f = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product2_p;

    /* Product: '<S26>/Product2' */
    PosCtrl_tune_B.Product2_k = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S26>/Sum' */
    PosCtrl_tune_B.Sum_i = PosCtrl_tune_B.Product1_f + PosCtrl_tune_B.Product2_k;

    /* Gain: '<S26>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[2] = PosCtrl_tune_P.Gain_Gain_b *
      PosCtrl_tune_B.Sum_i;

    /* Product: '<S21>/Product3' */
    PosCtrl_tune_B.Product3_e = PosCtrl_tune_B.Product3_py *
      PosCtrl_tune_B.Product_d;

    /* Product: '<S21>/Product2' */
    PosCtrl_tune_B.Product2_g = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product2_p;

    /* Sum: '<S21>/Sum' */
    PosCtrl_tune_B.Sum_c = PosCtrl_tune_B.Product3_e + PosCtrl_tune_B.Product2_g;

    /* Gain: '<S21>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[3] = PosCtrl_tune_P.Gain_Gain_p *
      PosCtrl_tune_B.Sum_c;

    /* Product: '<S24>/Product3' */
    PosCtrl_tune_B.Product3_l = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product_d;

    /* Product: '<S24>/Product2' */
    PosCtrl_tune_B.Product2_o = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product1_k;

    /* Product: '<S24>/Product1' */
    PosCtrl_tune_B.Product1_i = PosCtrl_tune_B.Product2_p *
      PosCtrl_tune_B.Product2_p;

    /* Product: '<S24>/Product' */
    PosCtrl_tune_B.Product_b = PosCtrl_tune_B.Product3_py *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S24>/Sum' */
    PosCtrl_tune_B.VectorConcatenate[4] = ((PosCtrl_tune_B.Product3_l -
      PosCtrl_tune_B.Product2_o) + PosCtrl_tune_B.Product1_i) -
      PosCtrl_tune_B.Product_b;

    /* Product: '<S27>/Product1' */
    PosCtrl_tune_B.Product1_d = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product1_k;

    /* Product: '<S27>/Product2' */
    PosCtrl_tune_B.Product2_a = PosCtrl_tune_B.Product2_p *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S27>/Sum' */
    PosCtrl_tune_B.Sum_h = PosCtrl_tune_B.Product2_a - PosCtrl_tune_B.Product1_d;

    /* Gain: '<S27>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[5] = PosCtrl_tune_P.Gain_Gain_d *
      PosCtrl_tune_B.Sum_h;

    /* Product: '<S22>/Product1' */
    PosCtrl_tune_B.Product1_a = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product2_p;

    /* Product: '<S22>/Product2' */
    PosCtrl_tune_B.Product2_n1 = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S22>/Sum' */
    PosCtrl_tune_B.Sum_d = PosCtrl_tune_B.Product2_n1 -
      PosCtrl_tune_B.Product1_a;

    /* Gain: '<S22>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[6] = PosCtrl_tune_P.Gain_Gain_e *
      PosCtrl_tune_B.Sum_d;

    /* Product: '<S25>/Product1' */
    PosCtrl_tune_B.Product1_n = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product1_k;

    /* Product: '<S25>/Product2' */
    PosCtrl_tune_B.Product2_pf = PosCtrl_tune_B.Product2_p *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S25>/Sum' */
    PosCtrl_tune_B.Sum_ey = PosCtrl_tune_B.Product1_n +
      PosCtrl_tune_B.Product2_pf;

    /* Gain: '<S25>/Gain' */
    PosCtrl_tune_B.VectorConcatenate[7] = PosCtrl_tune_P.Gain_Gain_f *
      PosCtrl_tune_B.Sum_ey;

    /* Product: '<S28>/Product3' */
    PosCtrl_tune_B.Product3_i = PosCtrl_tune_B.Product_d *
      PosCtrl_tune_B.Product_d;

    /* Product: '<S28>/Product2' */
    PosCtrl_tune_B.Product2_c = PosCtrl_tune_B.Product1_k *
      PosCtrl_tune_B.Product1_k;

    /* Product: '<S28>/Product1' */
    PosCtrl_tune_B.Product1_ia = PosCtrl_tune_B.Product2_p *
      PosCtrl_tune_B.Product2_p;

    /* Product: '<S28>/Product' */
    PosCtrl_tune_B.Product_p = PosCtrl_tune_B.Product3_py *
      PosCtrl_tune_B.Product3_py;

    /* Sum: '<S28>/Sum' */
    PosCtrl_tune_B.VectorConcatenate[8] = ((PosCtrl_tune_B.Product3_i -
      PosCtrl_tune_B.Product2_c) - PosCtrl_tune_B.Product1_ia) +
      PosCtrl_tune_B.Product_p;
    for (i = 0; i < 3; i++) {
      /* Math: '<S7>/Transpose' */
      PosCtrl_tune_B.Transpose[3 * i] = PosCtrl_tune_B.VectorConcatenate[i];
      PosCtrl_tune_B.Transpose[3 * i + 1] = PosCtrl_tune_B.VectorConcatenate[i +
        3];
      PosCtrl_tune_B.Transpose[3 * i + 2] = PosCtrl_tune_B.VectorConcatenate[i +
        6];

      /* Integrator: '<S7>/vb' */
      PosCtrl_tune_B.vb[i] = PosCtrl_tune_X.vb_CSTATE[i];
    }

    /* Product: '<S7>/Product1' */
    memcpy(&Rbe[0], &PosCtrl_tune_B.Transpose[0], 9U * sizeof(real_T));
    u1 = PosCtrl_tune_B.vb[0];
    u2 = PosCtrl_tune_B.vb[1];
    tmp_1 = PosCtrl_tune_B.vb[2];
    for (i = 0; i < 3; i++) {
      u0 = Rbe[i] * u1;
      u0 += Rbe[i + 3] * u2;
      u0 += Rbe[i + 6] * tmp_1;
      PosCtrl_tune_B.Product1_b[i] = u0;
    }

    /* End of Product: '<S7>/Product1' */

    /* Sum: '<S40>/Sum7' */
    PosCtrl_tune_B.Sum7 = PosCtrl_tune_B.Saturation3 -
      PosCtrl_tune_B.Product1_b[0];

    /* Gain: '<S54>/Gain' */
    PosCtrl_tune_B.Gain = PosCtrl_tune_P.Kvxp * PosCtrl_tune_B.Sum7;

    /* Gain: '<S54>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain = PosCtrl_tune_P.Kvxd * PosCtrl_tune_B.Sum7;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE;

      /* SampleTimeMath: '<S57>/TSamp'
       *
       * About '<S57>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp = PosCtrl_tune_B.DerivativeGain *
        PosCtrl_tune_P.TSamp_WtEt;

      /* UnitDelay: '<S57>/UD' */
      PosCtrl_tune_B.Uk1 = PosCtrl_tune_DW.UD_DSTATE;

      /* Sum: '<S57>/Diff' */
      PosCtrl_tune_B.Diff = PosCtrl_tune_B.TSamp - PosCtrl_tune_B.Uk1;
    }

    /* Sum: '<S54>/Sum' */
    PosCtrl_tune_B.Sum_j = (PosCtrl_tune_B.Gain +
      PosCtrl_tune_B.DiscreteTimeIntegrator) + PosCtrl_tune_B.Diff;

    /* Sum: '<S40>/Sum3' incorporates:
     *  Constant: '<Root>/yd'
     */
    PosCtrl_tune_B.Sum3 = PosCtrl_tune_P.yd_Value - PosCtrl_tune_B.Saturation1[1];

    /* Gain: '<S52>/Gain1' */
    PosCtrl_tune_B.Gain1_k = PosCtrl_tune_P.Kpyp * PosCtrl_tune_B.Sum3;

    /* Saturate: '<S52>/Saturation3' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY;
    if (PosCtrl_tune_B.Gain1_k > PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY) {
      PosCtrl_tune_B.Saturation3_e = PosCtrl_tune_P.MAX_CONTROL_VELOCITY_XY;
    } else if (PosCtrl_tune_B.Gain1_k < z1_idx_0) {
      PosCtrl_tune_B.Saturation3_e = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation3_e = PosCtrl_tune_B.Gain1_k;
    }

    /* End of Saturate: '<S52>/Saturation3' */

    /* Sum: '<S40>/Sum2' */
    PosCtrl_tune_B.Sum2 = PosCtrl_tune_B.Saturation3_e -
      PosCtrl_tune_B.Product1_b[1];

    /* Gain: '<S55>/Gain' */
    PosCtrl_tune_B.Gain_l = PosCtrl_tune_P.Kvyp * PosCtrl_tune_B.Sum2;

    /* Gain: '<S55>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain_a = PosCtrl_tune_P.Kvyd * PosCtrl_tune_B.Sum2;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator_b =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a;

      /* SampleTimeMath: '<S58>/TSamp'
       *
       * About '<S58>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp_h = PosCtrl_tune_B.DerivativeGain_a *
        PosCtrl_tune_P.TSamp_WtEt_i;

      /* UnitDelay: '<S58>/UD' */
      PosCtrl_tune_B.Uk1_n = PosCtrl_tune_DW.UD_DSTATE_l;

      /* Sum: '<S58>/Diff' */
      PosCtrl_tune_B.Diff_l = PosCtrl_tune_B.TSamp_h - PosCtrl_tune_B.Uk1_n;
    }

    /* Sum: '<S55>/Sum' */
    PosCtrl_tune_B.Sum_f = (PosCtrl_tune_B.Gain_l +
      PosCtrl_tune_B.DiscreteTimeIntegrator_b) + PosCtrl_tune_B.Diff_l;

    /* MATLAB Function: '<S40>/MATLAB Function' */
    /* :  g=9.8; */
    /* :  phi = (-sin(psi)*eax + cos(psi)*eay)/g; */
    PosCtrl_tune_B.phi = (-sin(PosCtrl_tune_B.y[2]) * PosCtrl_tune_B.Sum_j + cos
                          (PosCtrl_tune_B.y[2]) * PosCtrl_tune_B.Sum_f) / 9.8;

    /* :  theta = (-cos(psi)*eax-sin(psi)*eay)/g; */
    PosCtrl_tune_B.theta = (-cos(PosCtrl_tune_B.y[2]) * PosCtrl_tune_B.Sum_j -
      sin(PosCtrl_tune_B.y[2]) * PosCtrl_tune_B.Sum_f) / 9.8;

    /* Saturate: '<S40>/Saturation1' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_ANGLE_ROLL * PosCtrl_tune_P.DEG2RAD;
    u0 = PosCtrl_tune_P.MAX_CONTROL_ANGLE_ROLL * PosCtrl_tune_P.DEG2RAD;
    if (PosCtrl_tune_B.phi > u0) {
      PosCtrl_tune_B.Saturation1_d = u0;
    } else if (PosCtrl_tune_B.phi < z1_idx_0) {
      PosCtrl_tune_B.Saturation1_d = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation1_d = PosCtrl_tune_B.phi;
    }

    /* End of Saturate: '<S40>/Saturation1' */

    /* Sum: '<S39>/Sum18' */
    PosCtrl_tune_B.Sum18 = PosCtrl_tune_B.Saturation1_d - PosCtrl_tune_B.y[0];

    /* Gain: '<S46>/Gain' */
    PosCtrl_tune_B.Gain_j = PosCtrl_tune_P.Kp_ROLL_ANGLE * PosCtrl_tune_B.Sum18;

    /* Saturate: '<S39>/Saturation4' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_ROLL;
    if (PosCtrl_tune_B.Gain_j > PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
      PosCtrl_tune_B.Saturation4 = PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_ROLL;
    } else if (PosCtrl_tune_B.Gain_j < z1_idx_0) {
      PosCtrl_tune_B.Saturation4 = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation4 = PosCtrl_tune_B.Gain_j;
    }

    /* End of Saturate: '<S39>/Saturation4' */

    /* Sum: '<S39>/Sum21' */
    PosCtrl_tune_B.Sum21 = PosCtrl_tune_B.Saturation4 - PosCtrl_tune_B.pqr[0];

    /* Gain: '<S43>/Gain' */
    PosCtrl_tune_B.Gain_f = PosCtrl_tune_P.Kp_ROLL_AgngleRate *
      PosCtrl_tune_B.Sum21;

    /* Gain: '<S43>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain_o = PosCtrl_tune_P.Kd_ROLL_AgngleRate *
      PosCtrl_tune_B.Sum21;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator_j =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n;

      /* SampleTimeMath: '<S48>/TSamp'
       *
       * About '<S48>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp_m = PosCtrl_tune_B.DerivativeGain_o *
        PosCtrl_tune_P.TSamp_WtEt_e;

      /* UnitDelay: '<S48>/UD' */
      PosCtrl_tune_B.Uk1_c = PosCtrl_tune_DW.UD_DSTATE_f;

      /* Sum: '<S48>/Diff' */
      PosCtrl_tune_B.Diff_c = PosCtrl_tune_B.TSamp_m - PosCtrl_tune_B.Uk1_c;
    }

    /* Sum: '<S43>/Sum' */
    PosCtrl_tune_B.Sum_m = (PosCtrl_tune_B.Gain_f +
      PosCtrl_tune_B.DiscreteTimeIntegrator_j) + PosCtrl_tune_B.Diff_c;

    /* Saturate: '<S39>/Saturation' */
    if (PosCtrl_tune_B.Sum_m > PosCtrl_tune_P.Saturation_UpperSat) {
      PosCtrl_tune_B.Saturation = PosCtrl_tune_P.Saturation_UpperSat;
    } else if (PosCtrl_tune_B.Sum_m < PosCtrl_tune_P.Saturation_LowerSat) {
      PosCtrl_tune_B.Saturation = PosCtrl_tune_P.Saturation_LowerSat;
    } else {
      PosCtrl_tune_B.Saturation = PosCtrl_tune_B.Sum_m;
    }

    /* End of Saturate: '<S39>/Saturation' */

    /* Saturate: '<S40>/Saturation2' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_ANGLE_PITCH * PosCtrl_tune_P.DEG2RAD;
    u0 = PosCtrl_tune_P.MAX_CONTROL_ANGLE_PITCH * PosCtrl_tune_P.DEG2RAD;
    if (PosCtrl_tune_B.theta > u0) {
      PosCtrl_tune_B.Saturation2 = u0;
    } else if (PosCtrl_tune_B.theta < z1_idx_0) {
      PosCtrl_tune_B.Saturation2 = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation2 = PosCtrl_tune_B.theta;
    }

    /* End of Saturate: '<S40>/Saturation2' */

    /* Sum: '<S39>/Sum19' */
    PosCtrl_tune_B.Sum19 = PosCtrl_tune_B.Saturation2 - PosCtrl_tune_B.y[1];

    /* Gain: '<S45>/Gain' */
    PosCtrl_tune_B.Gain_h = PosCtrl_tune_P.Kp_PITCH_ANGLE * PosCtrl_tune_B.Sum19;

    /* Saturate: '<S39>/Saturation3' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_PITCH;
    if (PosCtrl_tune_B.Gain_h > PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_PITCH) {
      PosCtrl_tune_B.Saturation3_j = PosCtrl_tune_P.MAX_CONTROL_ANGLE_RATE_PITCH;
    } else if (PosCtrl_tune_B.Gain_h < z1_idx_0) {
      PosCtrl_tune_B.Saturation3_j = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation3_j = PosCtrl_tune_B.Gain_h;
    }

    /* End of Saturate: '<S39>/Saturation3' */

    /* Sum: '<S39>/Sum22' */
    PosCtrl_tune_B.Sum22 = PosCtrl_tune_B.Saturation3_j - PosCtrl_tune_B.pqr[1];

    /* Gain: '<S42>/Gain' */
    PosCtrl_tune_B.Gain_m = PosCtrl_tune_P.Kp_PITCH_AgngleRate *
      PosCtrl_tune_B.Sum22;

    /* Gain: '<S42>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain_j = PosCtrl_tune_P.Kd_PITCH_AgngleRate *
      PosCtrl_tune_B.Sum22;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator_o =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c;

      /* SampleTimeMath: '<S47>/TSamp'
       *
       * About '<S47>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp_a = PosCtrl_tune_B.DerivativeGain_j *
        PosCtrl_tune_P.TSamp_WtEt_b;

      /* UnitDelay: '<S47>/UD' */
      PosCtrl_tune_B.Uk1_j = PosCtrl_tune_DW.UD_DSTATE_c;

      /* Sum: '<S47>/Diff' */
      PosCtrl_tune_B.Diff_cp = PosCtrl_tune_B.TSamp_a - PosCtrl_tune_B.Uk1_j;
    }

    /* Sum: '<S42>/Sum' */
    PosCtrl_tune_B.Sum_n = (PosCtrl_tune_B.Gain_m +
      PosCtrl_tune_B.DiscreteTimeIntegrator_o) + PosCtrl_tune_B.Diff_cp;

    /* Saturate: '<S39>/Saturation1' */
    if (PosCtrl_tune_B.Sum_n > PosCtrl_tune_P.Saturation1_UpperSat_e) {
      PosCtrl_tune_B.Saturation1_e = PosCtrl_tune_P.Saturation1_UpperSat_e;
    } else if (PosCtrl_tune_B.Sum_n < PosCtrl_tune_P.Saturation1_LowerSat_n) {
      PosCtrl_tune_B.Saturation1_e = PosCtrl_tune_P.Saturation1_LowerSat_n;
    } else {
      PosCtrl_tune_B.Saturation1_e = PosCtrl_tune_B.Sum_n;
    }

    /* End of Saturate: '<S39>/Saturation1' */

    /* Sum: '<S39>/Sum17' incorporates:
     *  Constant: '<Root>/偏航角'
     */
    PosCtrl_tune_B.Sum17 = PosCtrl_tune_P._Value - PosCtrl_tune_B.pqr[2];

    /* Gain: '<S44>/Gain' */
    PosCtrl_tune_B.Gain_jp = PosCtrl_tune_P.Kp_YAW_AngleRate *
      PosCtrl_tune_B.Sum17;

    /* Gain: '<S44>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain_d = PosCtrl_tune_P.Kd_YAW_AngleRate *
      PosCtrl_tune_B.Sum17;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator_bv =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p;

      /* SampleTimeMath: '<S49>/TSamp'
       *
       * About '<S49>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp_l = PosCtrl_tune_B.DerivativeGain_d *
        PosCtrl_tune_P.TSamp_WtEt_a;

      /* UnitDelay: '<S49>/UD' */
      PosCtrl_tune_B.Uk1_o = PosCtrl_tune_DW.UD_DSTATE_lz;

      /* Sum: '<S49>/Diff' */
      PosCtrl_tune_B.Diff_o = PosCtrl_tune_B.TSamp_l - PosCtrl_tune_B.Uk1_o;
    }

    /* Sum: '<S44>/Sum' */
    PosCtrl_tune_B.Sum_g = (PosCtrl_tune_B.Gain_jp +
      PosCtrl_tune_B.DiscreteTimeIntegrator_bv) + PosCtrl_tune_B.Diff_o;

    /* Saturate: '<S39>/Saturation2' */
    if (PosCtrl_tune_B.Sum_g > PosCtrl_tune_P.Saturation2_UpperSat) {
      PosCtrl_tune_B.Saturation2_i = PosCtrl_tune_P.Saturation2_UpperSat;
    } else if (PosCtrl_tune_B.Sum_g < PosCtrl_tune_P.Saturation2_LowerSat) {
      PosCtrl_tune_B.Saturation2_i = PosCtrl_tune_P.Saturation2_LowerSat;
    } else {
      PosCtrl_tune_B.Saturation2_i = PosCtrl_tune_B.Sum_g;
    }

    /* End of Saturate: '<S39>/Saturation2' */

    /* Sum: '<S40>/Sum4' incorporates:
     *  Constant: '<Root>/zd'
     */
    PosCtrl_tune_B.Sum4 = PosCtrl_tune_P.zd_Value - PosCtrl_tune_B.Saturation1[2];

    /* Gain: '<S53>/Gain1' */
    PosCtrl_tune_B.Gain1_g = PosCtrl_tune_P.Kpzp * PosCtrl_tune_B.Sum4;

    /* Saturate: '<S53>/Saturation3' */
    z1_idx_0 = -PosCtrl_tune_P.MAX_CONTROL_VELOCITY_Z;
    if (PosCtrl_tune_B.Gain1_g > PosCtrl_tune_P.MAX_CONTROL_VELOCITY_Z) {
      PosCtrl_tune_B.Saturation3_jn = PosCtrl_tune_P.MAX_CONTROL_VELOCITY_Z;
    } else if (PosCtrl_tune_B.Gain1_g < z1_idx_0) {
      PosCtrl_tune_B.Saturation3_jn = z1_idx_0;
    } else {
      PosCtrl_tune_B.Saturation3_jn = PosCtrl_tune_B.Gain1_g;
    }

    /* End of Saturate: '<S53>/Saturation3' */

    /* Sum: '<S40>/Sum' */
    PosCtrl_tune_B.Sum_l = PosCtrl_tune_B.Saturation3_jn -
      PosCtrl_tune_B.Product1_b[2];

    /* Gain: '<S56>/Gain' */
    PosCtrl_tune_B.Gain_e = PosCtrl_tune_P.Kvzp * PosCtrl_tune_B.Sum_l;

    /* Gain: '<S56>/Derivative Gain' */
    PosCtrl_tune_B.DerivativeGain_c = PosCtrl_tune_P.Kvzd * PosCtrl_tune_B.Sum_l;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
      PosCtrl_tune_B.DiscreteTimeIntegrator_e =
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g;

      /* SampleTimeMath: '<S59>/TSamp'
       *
       * About '<S59>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      PosCtrl_tune_B.TSamp_h5 = PosCtrl_tune_B.DerivativeGain_c *
        PosCtrl_tune_P.TSamp_WtEt_c;

      /* UnitDelay: '<S59>/UD' */
      PosCtrl_tune_B.Uk1_g = PosCtrl_tune_DW.UD_DSTATE_m;

      /* Sum: '<S59>/Diff' */
      PosCtrl_tune_B.Diff_b = PosCtrl_tune_B.TSamp_h5 - PosCtrl_tune_B.Uk1_g;
    }

    /* Sum: '<S56>/Sum' */
    PosCtrl_tune_B.Sum_mz = (PosCtrl_tune_B.Gain_e +
      PosCtrl_tune_B.DiscreteTimeIntegrator_e) + PosCtrl_tune_B.Diff_b;

    /* Saturate: '<S40>/az' */
    if (PosCtrl_tune_B.Sum_mz > PosCtrl_tune_P.az_UpperSat) {
      PosCtrl_tune_B.az = PosCtrl_tune_P.az_UpperSat;
    } else if (PosCtrl_tune_B.Sum_mz < PosCtrl_tune_P.az_LowerSat) {
      PosCtrl_tune_B.az = PosCtrl_tune_P.az_LowerSat;
    } else {
      PosCtrl_tune_B.az = PosCtrl_tune_B.Sum_mz;
    }

    /* End of Saturate: '<S40>/az' */

    /* Sum: '<S40>/Sum6' incorporates:
     *  Constant: '<S40>/Constant'
     */
    PosCtrl_tune_B.Sum6 = PosCtrl_tune_B.az - PosCtrl_tune_P.THR_HOVER;

    /* Gain: '<S40>/Gain' */
    PosCtrl_tune_B.Gain_a = PosCtrl_tune_P.Gain_Gain_g * PosCtrl_tune_B.Sum6;

    /* Saturate: '<S40>/Saturation' */
    if (PosCtrl_tune_B.Gain_a > PosCtrl_tune_P.MAX_MAN_THR) {
      PosCtrl_tune_B.Saturation_p = PosCtrl_tune_P.MAX_MAN_THR;
    } else if (PosCtrl_tune_B.Gain_a < PosCtrl_tune_P.Saturation_LowerSat_c) {
      PosCtrl_tune_B.Saturation_p = PosCtrl_tune_P.Saturation_LowerSat_c;
    } else {
      PosCtrl_tune_B.Saturation_p = PosCtrl_tune_B.Gain_a;
    }

    /* End of Saturate: '<S40>/Saturation' */

    /* MATLAB Function: '<S2>/pwm_out2' */
    /* :  idle_PWM = 1000; */
    /* :  scale = 1000; */
    /* :  M1 = (Thrust - Roll + Pitch + Yaw) * scale + idle_PWM; */
    PosCtrl_tune_B.M1 = (((PosCtrl_tune_B.Saturation_p -
      PosCtrl_tune_B.Saturation) + PosCtrl_tune_B.Saturation1_e) +
                         PosCtrl_tune_B.Saturation2_i) * 1000.0 + 1000.0;

    /* :  M2 = (Thrust + Roll - Pitch + Yaw) * scale + idle_PWM; */
    PosCtrl_tune_B.M2 = (((PosCtrl_tune_B.Saturation_p +
      PosCtrl_tune_B.Saturation) - PosCtrl_tune_B.Saturation1_e) +
                         PosCtrl_tune_B.Saturation2_i) * 1000.0 + 1000.0;

    /* :  M3 = (Thrust + Roll + Pitch - Yaw) * scale + idle_PWM; */
    PosCtrl_tune_B.M3 = (((PosCtrl_tune_B.Saturation_p +
      PosCtrl_tune_B.Saturation) + PosCtrl_tune_B.Saturation1_e) -
                         PosCtrl_tune_B.Saturation2_i) * 1000.0 + 1000.0;

    /* :  M4 = (Thrust - Roll - Pitch - Yaw) * scale + idle_PWM; */
    PosCtrl_tune_B.M4 = (((PosCtrl_tune_B.Saturation_p -
      PosCtrl_tune_B.Saturation) - PosCtrl_tune_B.Saturation1_e) -
                         PosCtrl_tune_B.Saturation2_i) * 1000.0 + 1000.0;

    /* Saturate: '<S2>/Output_Limits1' */
    if (PosCtrl_tune_B.M1 > PosCtrl_tune_P.Output_Limits1_UpperSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_UpperSat;
    } else if (PosCtrl_tune_B.M1 < PosCtrl_tune_P.Output_Limits1_LowerSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_LowerSat;
    } else {
      u0 = PosCtrl_tune_B.M1;
    }

    PosCtrl_tune_B.Output_Limits1[0] = u0;
    if (PosCtrl_tune_B.M2 > PosCtrl_tune_P.Output_Limits1_UpperSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_UpperSat;
    } else if (PosCtrl_tune_B.M2 < PosCtrl_tune_P.Output_Limits1_LowerSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_LowerSat;
    } else {
      u0 = PosCtrl_tune_B.M2;
    }

    PosCtrl_tune_B.Output_Limits1[1] = u0;
    if (PosCtrl_tune_B.M3 > PosCtrl_tune_P.Output_Limits1_UpperSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_UpperSat;
    } else if (PosCtrl_tune_B.M3 < PosCtrl_tune_P.Output_Limits1_LowerSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_LowerSat;
    } else {
      u0 = PosCtrl_tune_B.M3;
    }

    PosCtrl_tune_B.Output_Limits1[2] = u0;
    if (PosCtrl_tune_B.M4 > PosCtrl_tune_P.Output_Limits1_UpperSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_UpperSat;
    } else if (PosCtrl_tune_B.M4 < PosCtrl_tune_P.Output_Limits1_LowerSat) {
      u0 = PosCtrl_tune_P.Output_Limits1_LowerSat;
    } else {
      u0 = PosCtrl_tune_B.M4;
    }

    PosCtrl_tune_B.Output_Limits1[3] = u0;

    /* End of Saturate: '<S2>/Output_Limits1' */

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    PosCtrl_tune_B.Sum_cd[0] = PosCtrl_tune_B.Output_Limits1[0] -
      PosCtrl_tune_P.Constant2_Value[0];

    /* Gain: '<S1>/Gain1' */
    PosCtrl_tune_B.Gain1_d[0] = PosCtrl_tune_P.Gain1_Gain *
      PosCtrl_tune_B.Sum_cd[0];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    PosCtrl_tune_B.Sum_cd[1] = PosCtrl_tune_B.Output_Limits1[1] -
      PosCtrl_tune_P.Constant2_Value[1];

    /* Gain: '<S1>/Gain1' */
    PosCtrl_tune_B.Gain1_d[1] = PosCtrl_tune_P.Gain1_Gain *
      PosCtrl_tune_B.Sum_cd[1];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    PosCtrl_tune_B.Sum_cd[2] = PosCtrl_tune_B.Output_Limits1[2] -
      PosCtrl_tune_P.Constant2_Value[2];

    /* Gain: '<S1>/Gain1' */
    PosCtrl_tune_B.Gain1_d[2] = PosCtrl_tune_P.Gain1_Gain *
      PosCtrl_tune_B.Sum_cd[2];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    PosCtrl_tune_B.Sum_cd[3] = PosCtrl_tune_B.Output_Limits1[3] -
      PosCtrl_tune_P.Constant2_Value[3];

    /* Gain: '<S1>/Gain1' */
    PosCtrl_tune_B.Gain1_d[3] = PosCtrl_tune_P.Gain1_Gain *
      PosCtrl_tune_B.Sum_cd[3];

    /* Step: '<S1>/Step' */
    z1_idx_0 = PosCtrl_tune_M->Timing.t[0];
    if (z1_idx_0 < PosCtrl_tune_P.Step_Time) {
      PosCtrl_tune_B.Step = PosCtrl_tune_P.Step_Y0;
    } else {
      PosCtrl_tune_B.Step = PosCtrl_tune_P.Step_YFinal;
    }

    /* End of Step: '<S1>/Step' */

    /* Sum: '<S1>/Sum1' incorporates:
     *  Constant: '<S1>/mass'
     */
    PosCtrl_tune_B.Sum1_a = PosCtrl_tune_P.ModelParam_uavMass +
      PosCtrl_tune_B.Step;

    /* Product: '<S1>/Product1' incorporates:
     *  Constant: '<S1>/g'
     */
    PosCtrl_tune_B.Product1_d5[0] = PosCtrl_tune_B.Sum1_a *
      PosCtrl_tune_P.g_Value[0];
    PosCtrl_tune_B.Product1_d5[1] = PosCtrl_tune_B.Sum1_a *
      PosCtrl_tune_P.g_Value[1];
    PosCtrl_tune_B.Product1_d5[2] = PosCtrl_tune_B.Sum1_a *
      PosCtrl_tune_P.g_Value[2];

    /* Saturate: '<S1>/Saturation' */
    u0 = PosCtrl_tune_B.Gain1_d[0];
    if (u0 > PosCtrl_tune_P.Saturation_UpperSat_g) {
      u0 = PosCtrl_tune_P.Saturation_UpperSat_g;
    } else {
      if (u0 < PosCtrl_tune_P.Saturation_LowerSat_o) {
        u0 = PosCtrl_tune_P.Saturation_LowerSat_o;
      }
    }

    PosCtrl_tune_B.Saturation_m[0] = u0;
    u0 = PosCtrl_tune_B.Gain1_d[1];
    if (u0 > PosCtrl_tune_P.Saturation_UpperSat_g) {
      u0 = PosCtrl_tune_P.Saturation_UpperSat_g;
    } else {
      if (u0 < PosCtrl_tune_P.Saturation_LowerSat_o) {
        u0 = PosCtrl_tune_P.Saturation_LowerSat_o;
      }
    }

    PosCtrl_tune_B.Saturation_m[1] = u0;
    u0 = PosCtrl_tune_B.Gain1_d[2];
    if (u0 > PosCtrl_tune_P.Saturation_UpperSat_g) {
      u0 = PosCtrl_tune_P.Saturation_UpperSat_g;
    } else {
      if (u0 < PosCtrl_tune_P.Saturation_LowerSat_o) {
        u0 = PosCtrl_tune_P.Saturation_LowerSat_o;
      }
    }

    PosCtrl_tune_B.Saturation_m[2] = u0;
    u0 = PosCtrl_tune_B.Gain1_d[3];
    if (u0 > PosCtrl_tune_P.Saturation_UpperSat_g) {
      u0 = PosCtrl_tune_P.Saturation_UpperSat_g;
    } else {
      if (u0 < PosCtrl_tune_P.Saturation_LowerSat_o) {
        u0 = PosCtrl_tune_P.Saturation_LowerSat_o;
      }
    }

    PosCtrl_tune_B.Saturation_m[3] = u0;

    /* End of Saturate: '<S1>/Saturation' */
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* Product: '<S6>/Divide' incorporates:
       *  Constant: '<S1>/转动惯量'
       *  Constant: '<S6>/Constant'
       */
      rt_mrdivided3x3_snf(PosCtrl_tune_P.Constant_Value_i,
                          PosCtrl_tune_P.ModelParam_uavJ,
                          PosCtrl_tune_B.Divide_b);
    }

    /* Product: '<S9>/J*w' incorporates:
     *  Constant: '<S1>/转动惯量'
     */
    memcpy(&Rbe[0], &PosCtrl_tune_P.ModelParam_uavJ[0], 9U * sizeof(real_T));
    u1 = PosCtrl_tune_B.pqr[0];
    u2 = PosCtrl_tune_B.pqr[1];
    tmp_1 = PosCtrl_tune_B.pqr[2];

    /* StateSpace: '<S4>/Motor_Dynamics_1' */
    PosCtrl_tune_B.Motor_Dynamics_1 = 0.0;
    z1_idx_0 = 1.0 / PosCtrl_tune_P.ModelParam_motorT;
    PosCtrl_tune_B.Motor_Dynamics_1 += z1_idx_0 *
      PosCtrl_tune_X.Motor_Dynamics_1_CSTATE;

    /* StateSpace: '<S4>/Motor_Dynamics_2' */
    PosCtrl_tune_B.Motor_Dynamics_2 = 0.0;
    z1_idx_0 = 1.0 / PosCtrl_tune_P.ModelParam_motorT;
    PosCtrl_tune_B.Motor_Dynamics_2 += z1_idx_0 *
      PosCtrl_tune_X.Motor_Dynamics_2_CSTATE;

    /* StateSpace: '<S4>/Motor_Dynamics_3' */
    PosCtrl_tune_B.Motor_Dynamics_3 = 0.0;
    z1_idx_0 = 1.0 / PosCtrl_tune_P.ModelParam_motorT;
    PosCtrl_tune_B.Motor_Dynamics_3 += z1_idx_0 *
      PosCtrl_tune_X.Motor_Dynamics_3_CSTATE;

    /* StateSpace: '<S4>/Motor_Dynamics_4' */
    PosCtrl_tune_B.Motor_Dynamics_4 = 0.0;
    z1_idx_0 = 1.0 / PosCtrl_tune_P.ModelParam_motorT;
    PosCtrl_tune_B.Motor_Dynamics_4 += z1_idx_0 *
      PosCtrl_tune_X.Motor_Dynamics_4_CSTATE;

    /* SignalConversion generated from: '<S38>/ SFunction ' incorporates:
     *  MATLAB Function: '<S5>/Propeller Model'
     */
    PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[0] =
      PosCtrl_tune_B.Motor_Dynamics_1;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[1] =
      PosCtrl_tune_B.Motor_Dynamics_2;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[2] =
      PosCtrl_tune_B.Motor_Dynamics_3;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[3] =
      PosCtrl_tune_B.Motor_Dynamics_4;

    /* MATLAB Function: '<S5>/Propeller Model' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Constant: '<S5>/Constant4'
     *  Constant: '<S5>/Constant5'
     */
    /* :  M_rctcm = [-sin(pi/4)*R*Ct,sin(pi/4)*R*Ct,sin(pi/4)*R*Ct,-sin(pi/4)*R*Ct; */
    /* :              sin(pi/4)*R*Ct,-sin(pi/4)*R*Ct,sin(pi/4)*R*Ct,-sin(pi/4)*R*Ct; */
    /* :              Cm,Cm,-Cm,-Cm]; */
    /* :  Mb = M_rctcm*(w.^2); */
    z1_idx_0 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[0] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[0];
    z1_idx_1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[1] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[1];
    z1_idx_2 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[2] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[2];
    z1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[3] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[3];
    tmp[0] = -0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[3] = 0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[6] = 0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[9] = -0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[1] = 0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[4] = -0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[7] = 0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[10] = -0.70710678118654746 * PosCtrl_tune_P.ModelParam_uavR *
      PosCtrl_tune_P.ModelParam_rotorCt;
    tmp[2] = PosCtrl_tune_P.ModelParam_rotorCm;
    tmp[5] = PosCtrl_tune_P.ModelParam_rotorCm;
    tmp[8] = -PosCtrl_tune_P.ModelParam_rotorCm;
    tmp[11] = -PosCtrl_tune_P.ModelParam_rotorCm;
    for (i = 0; i < 3; i++) {
      /* Product: '<S9>/J*w' */
      PosCtrl_tune_B.Jw[i] = 0.0;
      PosCtrl_tune_B.Jw[i] += Rbe[i] * u1;
      PosCtrl_tune_B.Jw[i] += Rbe[i + 3] * u2;
      PosCtrl_tune_B.Jw[i] += Rbe[i + 6] * tmp_1;

      /* MATLAB Function: '<S5>/Propeller Model' */
      PosCtrl_tune_B.Mb[i] = 0.0;
      PosCtrl_tune_B.Mb[i] += tmp[i] * z1_idx_0;
      PosCtrl_tune_B.Mb[i] += tmp[i + 3] * z1_idx_1;
      PosCtrl_tune_B.Mb[i] += tmp[i + 6] * z1_idx_2;
      PosCtrl_tune_B.Mb[i] += tmp[i + 9] * z1;
    }

    /* MATLAB Function: '<S5>/Propeller Model' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Constant: '<S5>/Constant7'
     */
    /* :  Fb = [0; 0; -sum(Ct*(w.^2))]; */
    z1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[0] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[0];
    z1 *= PosCtrl_tune_P.ModelParam_rotorCt;
    z1_idx_0 = z1;
    z1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[1] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[1];
    z1 *= PosCtrl_tune_P.ModelParam_rotorCt;
    z1_idx_1 = z1;
    z1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[2] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[2];
    z1 *= PosCtrl_tune_P.ModelParam_rotorCt;
    z1_idx_2 = z1;
    z1 = PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[3] *
      PosCtrl_tune_B.TmpSignalConversionAtSFunctionI[3];
    z1 *= PosCtrl_tune_P.ModelParam_rotorCt;
    PosCtrl_tune_B.Fb[0] = 0.0;
    PosCtrl_tune_B.Fb[1] = 0.0;

    /* :  Fd = -Cd*Vb.*abs(Vb)*0.5; */
    u0 = -PosCtrl_tune_P.ModelParam_uavCd;
    z1_idx_0 += z1_idx_1;
    PosCtrl_tune_B.Fd[0] = fabs(PosCtrl_tune_B.vb[0]);
    PosCtrl_tune_B.Fd[0] = u0 * PosCtrl_tune_B.vb[0] * PosCtrl_tune_B.Fd[0] *
      0.5;
    z1_idx_0 += z1_idx_2;
    PosCtrl_tune_B.Fd[1] = fabs(PosCtrl_tune_B.vb[1]);
    PosCtrl_tune_B.Fd[1] = u0 * PosCtrl_tune_B.vb[1] * PosCtrl_tune_B.Fd[1] *
      0.5;
    z1_idx_0 += z1;
    PosCtrl_tune_B.Fd[2] = fabs(PosCtrl_tune_B.vb[2]);
    PosCtrl_tune_B.Fd[2] = u0 * PosCtrl_tune_B.vb[2] * PosCtrl_tune_B.Fd[2] *
      0.5;
    PosCtrl_tune_B.Fb[2] = -z1_idx_0;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* MATLAB Function: '<S5>/MATLAB Function' */
      /* :  m=zeros(1,3); */
      PosCtrl_tune_B.m[0] = 0.0;
      PosCtrl_tune_B.m[1] = 0.0;
      PosCtrl_tune_B.m[2] = 0.0;
    }

    /* SignalConversion generated from: '<S11>/ SFunction ' incorporates:
     *  MATLAB Function: '<S6>/陀螺力矩'
     */
    PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[0] =
      PosCtrl_tune_B.Motor_Dynamics_1;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[1] =
      PosCtrl_tune_B.Motor_Dynamics_2;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[2] =
      PosCtrl_tune_B.Motor_Dynamics_3;
    PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[3] =
      PosCtrl_tune_B.Motor_Dynamics_4;

    /* Sum: '<S5>/Sum' */
    /* :  Ga=zeros(3,1); */
    PosCtrl_tune_B.Sum_ce[0] = PosCtrl_tune_B.Mb[0] + PosCtrl_tune_B.m[0];
    PosCtrl_tune_B.Sum_ce[1] = PosCtrl_tune_B.Mb[1] + PosCtrl_tune_B.m[1];
    PosCtrl_tune_B.Sum_ce[2] = PosCtrl_tune_B.Mb[2] + PosCtrl_tune_B.m[2];

    /* MATLAB Function: '<S6>/陀螺力矩' incorporates:
     *  Constant: '<S1>/Jrp'
     */
    PosCtrl_tune_B.Ga[2] = 0.0;

    /* :  Ga(1)=Jrp*pqr(2)*(-MotorRads(1)-MotorRads(2)+MotorRads(3)+MotorRads(4)); */
    PosCtrl_tune_B.Ga[0] = (((-PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[0]
      - PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[1]) +
      PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[2]) +
      PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[3]) *
      (PosCtrl_tune_P.ModelParam_motorJm * PosCtrl_tune_B.pqr[1]);

    /* :  Ga(2)=Jrp*pqr(1)*( MotorRads(1)+MotorRads(2)-MotorRads(3)-MotorRads(4)); */
    PosCtrl_tune_B.Ga[1] = (((PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[0]
      + PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[1]) -
      PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[2]) -
      PosCtrl_tune_B.TmpSignalConversionAtSFunctio_p[3]) *
      (PosCtrl_tune_P.ModelParam_motorJm * PosCtrl_tune_B.pqr[0]);

    /* Product: '<S12>/j x k' */
    PosCtrl_tune_B.jxk = PosCtrl_tune_B.pqr[1] * PosCtrl_tune_B.Jw[2];

    /* Product: '<S12>/k x i' */
    PosCtrl_tune_B.kxi = PosCtrl_tune_B.pqr[2] * PosCtrl_tune_B.Jw[0];

    /* Product: '<S12>/i x j' */
    PosCtrl_tune_B.ixj = PosCtrl_tune_B.pqr[0] * PosCtrl_tune_B.Jw[1];

    /* Product: '<S13>/k x j' */
    PosCtrl_tune_B.kxj = PosCtrl_tune_B.pqr[2] * PosCtrl_tune_B.Jw[1];

    /* Product: '<S13>/i x k' */
    PosCtrl_tune_B.ixk = PosCtrl_tune_B.pqr[0] * PosCtrl_tune_B.Jw[2];

    /* Product: '<S13>/j x i' */
    PosCtrl_tune_B.jxi = PosCtrl_tune_B.pqr[1] * PosCtrl_tune_B.Jw[0];

    /* Sum: '<S10>/Sum' */
    PosCtrl_tune_B.Sum_k[0] = PosCtrl_tune_B.jxk - PosCtrl_tune_B.kxj;
    PosCtrl_tune_B.Sum_k[1] = PosCtrl_tune_B.kxi - PosCtrl_tune_B.ixk;
    PosCtrl_tune_B.Sum_k[2] = PosCtrl_tune_B.ixj - PosCtrl_tune_B.jxi;

    /* Sum: '<S6>/Sum' */
    PosCtrl_tune_B.Sum_jz[0] = (PosCtrl_tune_B.Sum_ce[0] + PosCtrl_tune_B.Ga[0])
      + PosCtrl_tune_B.Sum_k[0];
    PosCtrl_tune_B.Sum_jz[1] = (PosCtrl_tune_B.Sum_ce[1] + PosCtrl_tune_B.Ga[1])
      + PosCtrl_tune_B.Sum_k[1];
    PosCtrl_tune_B.Sum_jz[2] = (PosCtrl_tune_B.Sum_ce[2] + PosCtrl_tune_B.Ga[2])
      + PosCtrl_tune_B.Sum_k[2];

    /* Product: '<S6>/Product' */
    memcpy(&Rbe[0], &PosCtrl_tune_B.Divide_b[0], 9U * sizeof(real_T));
    u1 = PosCtrl_tune_B.Sum_jz[0];
    u2 = PosCtrl_tune_B.Sum_jz[1];
    tmp_1 = PosCtrl_tune_B.Sum_jz[2];
    for (i = 0; i < 3; i++) {
      PosCtrl_tune_B.Product_n[i] = 0.0;
      PosCtrl_tune_B.Product_n[i] += Rbe[i] * u1;
      PosCtrl_tune_B.Product_n[i] += Rbe[i + 3] * u2;
      PosCtrl_tune_B.Product_n[i] += Rbe[i + 6] * tmp_1;
    }

    /* End of Product: '<S6>/Product' */

    /* Product: '<S5>/Product' */
    memcpy(&Rbe[0], &PosCtrl_tune_B.VectorConcatenate[0], 9U * sizeof(real_T));
    u1 = PosCtrl_tune_B.Product1_d5[0];
    u2 = PosCtrl_tune_B.Product1_d5[1];
    tmp_1 = PosCtrl_tune_B.Product1_d5[2];
    for (i = 0; i < 3; i++) {
      u0 = Rbe[i] * u1;
      u0 += Rbe[i + 3] * u2;
      u0 += Rbe[i + 6] * tmp_1;
      PosCtrl_tune_B.Product_ph[i] = u0;

      /* Sum: '<S5>/Add7' */
      PosCtrl_tune_B.Add7[i] = PosCtrl_tune_B.Fb[i] + PosCtrl_tune_B.Fd[i];
    }

    /* End of Product: '<S5>/Product' */

    /* Sum: '<S5>/Add2' incorporates:
     *  Constant: '<S5>/Constant'
     */
    PosCtrl_tune_B.Add2[0] = (PosCtrl_tune_B.Product_ph[0] +
      PosCtrl_tune_B.Add7[0]) + PosCtrl_tune_P.Constant_Value_n;
    PosCtrl_tune_B.Add2[1] = (PosCtrl_tune_B.Product_ph[1] +
      PosCtrl_tune_B.Add7[1]) + PosCtrl_tune_P.Constant_Value_n;
    PosCtrl_tune_B.Add2[2] = (PosCtrl_tune_B.Product_ph[2] +
      PosCtrl_tune_B.Add7[2]) + PosCtrl_tune_P.Constant_Value_n;

    /* Product: '<S15>/j x k' */
    PosCtrl_tune_B.jxk_b = PosCtrl_tune_B.pqr[1] * PosCtrl_tune_B.vb[2];

    /* Product: '<S15>/k x i' */
    PosCtrl_tune_B.kxi_n = PosCtrl_tune_B.pqr[2] * PosCtrl_tune_B.vb[0];

    /* Product: '<S15>/i x j' */
    PosCtrl_tune_B.ixj_i = PosCtrl_tune_B.pqr[0] * PosCtrl_tune_B.vb[1];

    /* Product: '<S16>/k x j' */
    PosCtrl_tune_B.kxj_c = PosCtrl_tune_B.pqr[2] * PosCtrl_tune_B.vb[1];

    /* Product: '<S16>/i x k' */
    PosCtrl_tune_B.ixk_j = PosCtrl_tune_B.pqr[0] * PosCtrl_tune_B.vb[2];

    /* Product: '<S16>/j x i' */
    PosCtrl_tune_B.jxi_l = PosCtrl_tune_B.pqr[1] * PosCtrl_tune_B.vb[0];

    /* Sum: '<S14>/Sum' */
    PosCtrl_tune_B.Sum_n3[0] = PosCtrl_tune_B.jxk_b - PosCtrl_tune_B.kxj_c;
    PosCtrl_tune_B.Sum_n3[1] = PosCtrl_tune_B.kxi_n - PosCtrl_tune_B.ixk_j;
    PosCtrl_tune_B.Sum_n3[2] = PosCtrl_tune_B.ixj_i - PosCtrl_tune_B.jxi_l;

    /* Product: '<S7>/a=f//m' incorporates:
     *  Constant: '<S1>/质量'
     */
    PosCtrl_tune_B.afm[0] = PosCtrl_tune_B.Add2[0] /
      PosCtrl_tune_P.ModelParam_uavMass;

    /* Sum: '<S7>/Sum' */
    PosCtrl_tune_B.Sum_j1[0] = PosCtrl_tune_B.afm[0] - PosCtrl_tune_B.Sum_n3[0];

    /* Product: '<S7>/a=f//m' incorporates:
     *  Constant: '<S1>/质量'
     */
    PosCtrl_tune_B.afm[1] = PosCtrl_tune_B.Add2[1] /
      PosCtrl_tune_P.ModelParam_uavMass;

    /* Sum: '<S7>/Sum' */
    PosCtrl_tune_B.Sum_j1[1] = PosCtrl_tune_B.afm[1] - PosCtrl_tune_B.Sum_n3[1];

    /* Product: '<S7>/a=f//m' incorporates:
     *  Constant: '<S1>/质量'
     */
    PosCtrl_tune_B.afm[2] = PosCtrl_tune_B.Add2[2] /
      PosCtrl_tune_P.ModelParam_uavMass;

    /* Sum: '<S7>/Sum' */
    PosCtrl_tune_B.Sum_j1[2] = PosCtrl_tune_B.afm[2] - PosCtrl_tune_B.Sum_n3[2];

    /* MATLAB Function: '<S8>/基于四元数模型' */
    /* :  qdot=0.5*[0,-pqr(1),-pqr(2),-pqr(3);pqr(1),0,pqr(3),-pqr(2);pqr(2),-pqr(3),0,pqr(1);pqr(3),pqr(2),-pqr(1),0]*q; */
    tmp_0[0] = 0.0;
    tmp_0[4] = 0.5 * -PosCtrl_tune_B.pqr[0];
    tmp_0[8] = 0.5 * -PosCtrl_tune_B.pqr[1];
    tmp_0[12] = 0.5 * -PosCtrl_tune_B.pqr[2];
    tmp_0[1] = 0.5 * PosCtrl_tune_B.pqr[0];
    tmp_0[5] = 0.0;
    tmp_0[9] = 0.5 * PosCtrl_tune_B.pqr[2];
    tmp_0[13] = 0.5 * -PosCtrl_tune_B.pqr[1];
    tmp_0[2] = 0.5 * PosCtrl_tune_B.pqr[1];
    tmp_0[6] = 0.5 * -PosCtrl_tune_B.pqr[2];
    tmp_0[10] = 0.0;
    tmp_0[14] = 0.5 * PosCtrl_tune_B.pqr[0];
    tmp_0[3] = 0.5 * PosCtrl_tune_B.pqr[2];
    tmp_0[7] = 0.5 * PosCtrl_tune_B.pqr[1];
    tmp_0[11] = 0.5 * -PosCtrl_tune_B.pqr[0];
    tmp_0[15] = 0.0;
    for (i = 0; i < 4; i++) {
      PosCtrl_tune_B.qdot[i] = 0.0;
      PosCtrl_tune_B.qdot[i] += tmp_0[i] * PosCtrl_tune_B.Divide[0];
      PosCtrl_tune_B.qdot[i] += tmp_0[i + 4] * PosCtrl_tune_B.Divide[1];
      PosCtrl_tune_B.qdot[i] += tmp_0[i + 8] * PosCtrl_tune_B.Divide[2];
      PosCtrl_tune_B.qdot[i] += tmp_0[i + 12] * PosCtrl_tune_B.Divide[3];
    }

    /* End of MATLAB Function: '<S8>/基于四元数模型' */

    /* Saturate: '<S4>/Signal_Saturation_1' */
    u0 = PosCtrl_tune_B.Saturation_m[0];
    if (u0 > PosCtrl_tune_P.Signal_Saturation_1_UpperSat) {
      PosCtrl_tune_B.Signal_Saturation_1 =
        PosCtrl_tune_P.Signal_Saturation_1_UpperSat;
    } else if (u0 < PosCtrl_tune_P.Signal_Saturation_1_LowerSat) {
      PosCtrl_tune_B.Signal_Saturation_1 =
        PosCtrl_tune_P.Signal_Saturation_1_LowerSat;
    } else {
      PosCtrl_tune_B.Signal_Saturation_1 = u0;
    }

    /* End of Saturate: '<S4>/Signal_Saturation_1' */

    /* Saturate: '<S4>/Signal_Saturation_2' */
    u0 = PosCtrl_tune_B.Saturation_m[1];
    if (u0 > PosCtrl_tune_P.Signal_Saturation_2_UpperSat) {
      PosCtrl_tune_B.Signal_Saturation_2 =
        PosCtrl_tune_P.Signal_Saturation_2_UpperSat;
    } else if (u0 < PosCtrl_tune_P.Signal_Saturation_2_LowerSat) {
      PosCtrl_tune_B.Signal_Saturation_2 =
        PosCtrl_tune_P.Signal_Saturation_2_LowerSat;
    } else {
      PosCtrl_tune_B.Signal_Saturation_2 = u0;
    }

    /* End of Saturate: '<S4>/Signal_Saturation_2' */

    /* Saturate: '<S4>/Signal_Saturation_3' */
    u0 = PosCtrl_tune_B.Saturation_m[2];
    if (u0 > PosCtrl_tune_P.Signal_Saturation_3_UpperSat) {
      PosCtrl_tune_B.Signal_Saturation_3 =
        PosCtrl_tune_P.Signal_Saturation_3_UpperSat;
    } else if (u0 < PosCtrl_tune_P.Signal_Saturation_3_LowerSat) {
      PosCtrl_tune_B.Signal_Saturation_3 =
        PosCtrl_tune_P.Signal_Saturation_3_LowerSat;
    } else {
      PosCtrl_tune_B.Signal_Saturation_3 = u0;
    }

    /* End of Saturate: '<S4>/Signal_Saturation_3' */

    /* Saturate: '<S4>/Signal_Saturation_4' */
    u0 = PosCtrl_tune_B.Saturation_m[3];
    if (u0 > PosCtrl_tune_P.Signal_Saturation_4_UpperSat) {
      PosCtrl_tune_B.Signal_Saturation_4 =
        PosCtrl_tune_P.Signal_Saturation_4_UpperSat;
    } else if (u0 < PosCtrl_tune_P.Signal_Saturation_4_LowerSat) {
      PosCtrl_tune_B.Signal_Saturation_4 =
        PosCtrl_tune_P.Signal_Saturation_4_LowerSat;
    } else {
      PosCtrl_tune_B.Signal_Saturation_4 = u0;
    }

    /* End of Saturate: '<S4>/Signal_Saturation_4' */

    /* Gain: '<S33>/Gain' */
    PosCtrl_tune_B.Gain_fu = PosCtrl_tune_P.ModelParam_motorCr *
      PosCtrl_tune_B.Signal_Saturation_1;

    /* Sum: '<S33>/Sum1' incorporates:
     *  Constant: '<S33>/Constant'
     */
    PosCtrl_tune_B.Sum1_m = PosCtrl_tune_P.ModelParam_motorWb +
      PosCtrl_tune_B.Gain_fu;

    /* Gain: '<S34>/Gain' */
    PosCtrl_tune_B.Gain_m3 = PosCtrl_tune_P.ModelParam_motorCr *
      PosCtrl_tune_B.Signal_Saturation_2;

    /* Sum: '<S34>/Sum1' incorporates:
     *  Constant: '<S34>/Constant'
     */
    PosCtrl_tune_B.Sum1_l = PosCtrl_tune_P.ModelParam_motorWb +
      PosCtrl_tune_B.Gain_m3;

    /* Gain: '<S35>/Gain' */
    PosCtrl_tune_B.Gain_h0 = PosCtrl_tune_P.ModelParam_motorCr *
      PosCtrl_tune_B.Signal_Saturation_3;

    /* Sum: '<S35>/Sum1' incorporates:
     *  Constant: '<S35>/Constant'
     */
    PosCtrl_tune_B.Sum1_b = PosCtrl_tune_P.ModelParam_motorWb +
      PosCtrl_tune_B.Gain_h0;

    /* Gain: '<S36>/Gain' */
    PosCtrl_tune_B.Gain_g = PosCtrl_tune_P.ModelParam_motorCr *
      PosCtrl_tune_B.Signal_Saturation_4;

    /* Sum: '<S36>/Sum1' incorporates:
     *  Constant: '<S36>/Constant'
     */
    PosCtrl_tune_B.Sum1_e = PosCtrl_tune_P.ModelParam_motorWb +
      PosCtrl_tune_B.Gain_g;

    /* Gain: '<S42>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain = PosCtrl_tune_P.Ki_PITCH_AgngleRate *
      PosCtrl_tune_B.Sum22;

    /* Gain: '<S43>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain_j = PosCtrl_tune_P.Ki_ROLL_AgngleRate *
      PosCtrl_tune_B.Sum21;

    /* Gain: '<S44>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain_h = PosCtrl_tune_P.Ki_YAW_AngleRate *
      PosCtrl_tune_B.Sum17;

    /* Gain: '<S54>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain_p = PosCtrl_tune_P.Kvxi * PosCtrl_tune_B.Sum7;

    /* Gain: '<S55>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain_c = PosCtrl_tune_P.Kvyi * PosCtrl_tune_B.Sum2;

    /* Gain: '<S56>/Integral Gain' */
    PosCtrl_tune_B.IntegralGain_h4 = PosCtrl_tune_P.Kvzi * PosCtrl_tune_B.Sum_l;
  }

  if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(PosCtrl_tune_M->rtwLogInfo, (PosCtrl_tune_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
    real_T tmp;

    /* Update for Integrator: '<S8>/q' */
    PosCtrl_tune_DW.q_IWORK = 0;
    if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
      /* Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainval *
        PosCtrl_tune_B.IntegralGain_p;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE >=
          PosCtrl_tune_P.Saturation_I_ah) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE =
          PosCtrl_tune_P.Saturation_I_ah;
      } else {
        tmp = -PosCtrl_tune_P.Saturation_I_ah;
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE <= tmp) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE =
            -PosCtrl_tune_P.Saturation_I_ah;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S57>/UD' */
      PosCtrl_tune_DW.UD_DSTATE = PosCtrl_tune_B.TSamp;

      /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainva_g *
        PosCtrl_tune_B.IntegralGain_c;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a >=
          PosCtrl_tune_P.Saturation_I_ah) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a =
          PosCtrl_tune_P.Saturation_I_ah;
      } else {
        tmp = -PosCtrl_tune_P.Saturation_I_ah;
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a <= tmp) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a =
            -PosCtrl_tune_P.Saturation_I_ah;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S58>/UD' */
      PosCtrl_tune_DW.UD_DSTATE_l = PosCtrl_tune_B.TSamp_h;

      /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainva_l *
        PosCtrl_tune_B.IntegralGain_j;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n >=
          PosCtrl_tune_P.Saturation_I_RP_Max) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n =
          PosCtrl_tune_P.Saturation_I_RP_Max;
      } else {
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n <=
            PosCtrl_tune_P.Saturation_I_RP_Min) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n =
            PosCtrl_tune_P.Saturation_I_RP_Min;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S48>/UD' */
      PosCtrl_tune_DW.UD_DSTATE_f = PosCtrl_tune_B.TSamp_m;

      /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainva_b *
        PosCtrl_tune_B.IntegralGain;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c >=
          PosCtrl_tune_P.Saturation_I_RP_Max) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c =
          PosCtrl_tune_P.Saturation_I_RP_Max;
      } else {
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c <=
            PosCtrl_tune_P.Saturation_I_RP_Min) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c =
            PosCtrl_tune_P.Saturation_I_RP_Min;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S47>/UD' */
      PosCtrl_tune_DW.UD_DSTATE_c = PosCtrl_tune_B.TSamp_a;

      /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainv_ga *
        PosCtrl_tune_B.IntegralGain_h;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p >=
          PosCtrl_tune_P.Saturation_I_Y_Max) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p =
          PosCtrl_tune_P.Saturation_I_Y_Max;
      } else {
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p <=
            PosCtrl_tune_P.Saturation_I_Y_Min) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p =
            PosCtrl_tune_P.Saturation_I_Y_Min;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S49>/UD' */
      PosCtrl_tune_DW.UD_DSTATE_lz = PosCtrl_tune_B.TSamp_l;

      /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
      PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g +=
        PosCtrl_tune_P.DiscreteTimeIntegrator_gainva_d *
        PosCtrl_tune_B.IntegralGain_h4;
      if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g >=
          PosCtrl_tune_P.Saturation_I_az) {
        PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g =
          PosCtrl_tune_P.Saturation_I_az;
      } else {
        tmp = -PosCtrl_tune_P.Saturation_I_az;
        if (PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g <= tmp) {
          PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g =
            -PosCtrl_tune_P.Saturation_I_az;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */

      /* Update for UnitDelay: '<S59>/UD' */
      PosCtrl_tune_DW.UD_DSTATE_m = PosCtrl_tune_B.TSamp_h5;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PosCtrl_tune_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(PosCtrl_tune_M)!=-1) &&
          !((rtmGetTFinal(PosCtrl_tune_M)-(((PosCtrl_tune_M->Timing.clockTick1+
               PosCtrl_tune_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((PosCtrl_tune_M->Timing.clockTick1+
               PosCtrl_tune_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(PosCtrl_tune_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&PosCtrl_tune_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PosCtrl_tune_M->Timing.clockTick0)) {
      ++PosCtrl_tune_M->Timing.clockTickH0;
    }

    PosCtrl_tune_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PosCtrl_tune_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      PosCtrl_tune_M->Timing.clockTick1++;
      if (!PosCtrl_tune_M->Timing.clockTick1) {
        PosCtrl_tune_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PosCtrl_tune_derivatives(void)
{
  real_T tmp;
  XDot_PosCtrl_tune_T *_rtXdot;
  _rtXdot = ((XDot_PosCtrl_tune_T *) PosCtrl_tune_M->derivs);

  /* Derivatives for Integrator: '<S3>/p,q,r' */
  _rtXdot->pqr_CSTATE[0] = PosCtrl_tune_B.Product_n[0];
  _rtXdot->pqr_CSTATE[1] = PosCtrl_tune_B.Product_n[1];
  _rtXdot->pqr_CSTATE[2] = PosCtrl_tune_B.Product_n[2];

  /* Derivatives for Integrator: '<S8>/q' */
  _rtXdot->q_CSTATE[0] = PosCtrl_tune_B.qdot[0];
  _rtXdot->q_CSTATE[1] = PosCtrl_tune_B.qdot[1];
  _rtXdot->q_CSTATE[2] = PosCtrl_tune_B.qdot[2];
  _rtXdot->q_CSTATE[3] = PosCtrl_tune_B.qdot[3];

  /* Derivatives for Integrator: '<S7>/xe' */
  _rtXdot->xe_CSTATE[0] = PosCtrl_tune_B.Product1_b[0];

  /* Derivatives for Integrator: '<S7>/vb' */
  _rtXdot->vb_CSTATE[0] = PosCtrl_tune_B.Sum_j1[0];

  /* Derivatives for Integrator: '<S7>/xe' */
  _rtXdot->xe_CSTATE[1] = PosCtrl_tune_B.Product1_b[1];

  /* Derivatives for Integrator: '<S7>/vb' */
  _rtXdot->vb_CSTATE[1] = PosCtrl_tune_B.Sum_j1[1];

  /* Derivatives for Integrator: '<S7>/xe' */
  _rtXdot->xe_CSTATE[2] = PosCtrl_tune_B.Product1_b[2];

  /* Derivatives for Integrator: '<S7>/vb' */
  _rtXdot->vb_CSTATE[2] = PosCtrl_tune_B.Sum_j1[2];

  /* Derivatives for StateSpace: '<S4>/Motor_Dynamics_1' */
  _rtXdot->Motor_Dynamics_1_CSTATE = 0.0;
  tmp = -1.0 / PosCtrl_tune_P.ModelParam_motorT;
  _rtXdot->Motor_Dynamics_1_CSTATE += tmp *
    PosCtrl_tune_X.Motor_Dynamics_1_CSTATE;
  _rtXdot->Motor_Dynamics_1_CSTATE += PosCtrl_tune_P.Motor_Dynamics_1_B *
    PosCtrl_tune_B.Sum1_m;

  /* Derivatives for StateSpace: '<S4>/Motor_Dynamics_2' */
  _rtXdot->Motor_Dynamics_2_CSTATE = 0.0;
  tmp = -1.0 / PosCtrl_tune_P.ModelParam_motorT;
  _rtXdot->Motor_Dynamics_2_CSTATE += tmp *
    PosCtrl_tune_X.Motor_Dynamics_2_CSTATE;
  _rtXdot->Motor_Dynamics_2_CSTATE += PosCtrl_tune_P.Motor_Dynamics_2_B *
    PosCtrl_tune_B.Sum1_l;

  /* Derivatives for StateSpace: '<S4>/Motor_Dynamics_3' */
  _rtXdot->Motor_Dynamics_3_CSTATE = 0.0;
  tmp = -1.0 / PosCtrl_tune_P.ModelParam_motorT;
  _rtXdot->Motor_Dynamics_3_CSTATE += tmp *
    PosCtrl_tune_X.Motor_Dynamics_3_CSTATE;
  _rtXdot->Motor_Dynamics_3_CSTATE += PosCtrl_tune_P.Motor_Dynamics_3_B *
    PosCtrl_tune_B.Sum1_b;

  /* Derivatives for StateSpace: '<S4>/Motor_Dynamics_4' */
  _rtXdot->Motor_Dynamics_4_CSTATE = 0.0;
  tmp = -1.0 / PosCtrl_tune_P.ModelParam_motorT;
  _rtXdot->Motor_Dynamics_4_CSTATE += tmp *
    PosCtrl_tune_X.Motor_Dynamics_4_CSTATE;
  _rtXdot->Motor_Dynamics_4_CSTATE += PosCtrl_tune_P.Motor_Dynamics_4_B *
    PosCtrl_tune_B.Sum1_e;
}

/* Model initialize function */
void PosCtrl_tune_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  PosCtrl_tune_P.Saturation1_UpperSat[0] = rtInf;
  PosCtrl_tune_P.Saturation1_UpperSat[1] = rtInf;
  PosCtrl_tune_P.Saturation1_LowerSat[0] = rtMinusInf;
  PosCtrl_tune_P.Saturation1_LowerSat[1] = rtMinusInf;
  PosCtrl_tune_P.Saturation1_LowerSat[2] = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)PosCtrl_tune_M, 0,
                sizeof(RT_MODEL_PosCtrl_tune_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PosCtrl_tune_M->solverInfo,
                          &PosCtrl_tune_M->Timing.simTimeStep);
    rtsiSetTPtr(&PosCtrl_tune_M->solverInfo, &rtmGetTPtr(PosCtrl_tune_M));
    rtsiSetStepSizePtr(&PosCtrl_tune_M->solverInfo,
                       &PosCtrl_tune_M->Timing.stepSize0);
    rtsiSetdXPtr(&PosCtrl_tune_M->solverInfo, &PosCtrl_tune_M->derivs);
    rtsiSetContStatesPtr(&PosCtrl_tune_M->solverInfo, (real_T **)
                         &PosCtrl_tune_M->contStates);
    rtsiSetNumContStatesPtr(&PosCtrl_tune_M->solverInfo,
      &PosCtrl_tune_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PosCtrl_tune_M->solverInfo,
      &PosCtrl_tune_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PosCtrl_tune_M->solverInfo,
      &PosCtrl_tune_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PosCtrl_tune_M->solverInfo,
      &PosCtrl_tune_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PosCtrl_tune_M->solverInfo, (&rtmGetErrorStatus
      (PosCtrl_tune_M)));
    rtsiSetRTModelPtr(&PosCtrl_tune_M->solverInfo, PosCtrl_tune_M);
  }

  rtsiSetSimTimeStep(&PosCtrl_tune_M->solverInfo, MAJOR_TIME_STEP);
  PosCtrl_tune_M->intgData.y = PosCtrl_tune_M->odeY;
  PosCtrl_tune_M->intgData.f[0] = PosCtrl_tune_M->odeF[0];
  PosCtrl_tune_M->intgData.f[1] = PosCtrl_tune_M->odeF[1];
  PosCtrl_tune_M->intgData.f[2] = PosCtrl_tune_M->odeF[2];
  PosCtrl_tune_M->contStates = ((X_PosCtrl_tune_T *) &PosCtrl_tune_X);
  rtsiSetSolverData(&PosCtrl_tune_M->solverInfo, (void *)
                    &PosCtrl_tune_M->intgData);
  rtsiSetSolverName(&PosCtrl_tune_M->solverInfo,"ode3");
  rtmSetTPtr(PosCtrl_tune_M, &PosCtrl_tune_M->Timing.tArray[0]);
  rtmSetTFinal(PosCtrl_tune_M, 100.0);
  PosCtrl_tune_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(PosCtrl_tune_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PosCtrl_tune_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PosCtrl_tune_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PosCtrl_tune_M->rtwLogInfo, (NULL));
    rtliSetLogT(PosCtrl_tune_M->rtwLogInfo, "tout");
    rtliSetLogX(PosCtrl_tune_M->rtwLogInfo, "");
    rtliSetLogXFinal(PosCtrl_tune_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PosCtrl_tune_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PosCtrl_tune_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(PosCtrl_tune_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PosCtrl_tune_M->rtwLogInfo, 1);
    rtliSetLogY(PosCtrl_tune_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PosCtrl_tune_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PosCtrl_tune_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &PosCtrl_tune_B), 0,
                sizeof(B_PosCtrl_tune_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PosCtrl_tune_X, 0,
                  sizeof(X_PosCtrl_tune_T));
  }

  /* states (dwork) */
  (void) memset((void *)&PosCtrl_tune_DW, 0,
                sizeof(DW_PosCtrl_tune_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(PosCtrl_tune_M->rtwLogInfo, 0.0, rtmGetTFinal
    (PosCtrl_tune_M), PosCtrl_tune_M->Timing.stepSize0, (&rtmGetErrorStatus
    (PosCtrl_tune_M)));

  /* Start for Constant: '<S8>/Constant' */
  PosCtrl_tune_B.Constant[0] = PosCtrl_tune_P.Constant_Value[0];
  PosCtrl_tune_B.Constant[1] = PosCtrl_tune_P.Constant_Value[1];
  PosCtrl_tune_B.Constant[2] = PosCtrl_tune_P.Constant_Value[2];
  PosCtrl_tune_B.Constant[3] = PosCtrl_tune_P.Constant_Value[3];

  /* InitializeConditions for Integrator: '<S3>/p,q,r' */
  PosCtrl_tune_X.pqr_CSTATE[0] = PosCtrl_tune_P.pqr_IC;
  PosCtrl_tune_X.pqr_CSTATE[1] = PosCtrl_tune_P.pqr_IC;
  PosCtrl_tune_X.pqr_CSTATE[2] = PosCtrl_tune_P.pqr_IC;

  /* InitializeConditions for Integrator: '<S8>/q' */
  if (rtmIsFirstInitCond(PosCtrl_tune_M)) {
    PosCtrl_tune_X.q_CSTATE[0] = 1.0;
    PosCtrl_tune_X.q_CSTATE[1] = 0.0;
    PosCtrl_tune_X.q_CSTATE[2] = 0.0;
    PosCtrl_tune_X.q_CSTATE[3] = 0.0;
  }

  PosCtrl_tune_DW.q_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S8>/q' */

  /* InitializeConditions for Integrator: '<S7>/xe' */
  PosCtrl_tune_X.xe_CSTATE[0] = PosCtrl_tune_P.ModelInit_PosE[0];

  /* InitializeConditions for Integrator: '<S7>/vb' */
  PosCtrl_tune_X.vb_CSTATE[0] = PosCtrl_tune_P.vb_IC;

  /* InitializeConditions for Integrator: '<S7>/xe' */
  PosCtrl_tune_X.xe_CSTATE[1] = PosCtrl_tune_P.ModelInit_PosE[1];

  /* InitializeConditions for Integrator: '<S7>/vb' */
  PosCtrl_tune_X.vb_CSTATE[1] = PosCtrl_tune_P.vb_IC;

  /* InitializeConditions for Integrator: '<S7>/xe' */
  PosCtrl_tune_X.xe_CSTATE[2] = PosCtrl_tune_P.ModelInit_PosE[2];

  /* InitializeConditions for Integrator: '<S7>/vb' */
  PosCtrl_tune_X.vb_CSTATE[2] = PosCtrl_tune_P.vb_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S57>/UD' */
  PosCtrl_tune_DW.UD_DSTATE = PosCtrl_tune_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_a =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC_m;

  /* InitializeConditions for UnitDelay: '<S58>/UD' */
  PosCtrl_tune_DW.UD_DSTATE_l = PosCtrl_tune_P.DiscreteDerivative_ICPrevScal_i;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_n =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC_c;

  /* InitializeConditions for UnitDelay: '<S48>/UD' */
  PosCtrl_tune_DW.UD_DSTATE_f = PosCtrl_tune_P.DiscreteDerivative_ICPrevScal_k;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_c =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC_l;

  /* InitializeConditions for UnitDelay: '<S47>/UD' */
  PosCtrl_tune_DW.UD_DSTATE_c = PosCtrl_tune_P.DiscreteDerivative_ICPrevScal_b;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_p =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for UnitDelay: '<S49>/UD' */
  PosCtrl_tune_DW.UD_DSTATE_lz = PosCtrl_tune_P.DiscreteDerivative_ICPrevScal_a;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
  PosCtrl_tune_DW.DiscreteTimeIntegrator_DSTATE_g =
    PosCtrl_tune_P.DiscreteTimeIntegrator_IC_i;

  /* InitializeConditions for UnitDelay: '<S59>/UD' */
  PosCtrl_tune_DW.UD_DSTATE_m = PosCtrl_tune_P.DiscreteDerivative_ICPrevScal_o;

  /* InitializeConditions for StateSpace: '<S4>/Motor_Dynamics_1' */
  PosCtrl_tune_X.Motor_Dynamics_1_CSTATE = PosCtrl_tune_P.ModelInit_RPM *
    PosCtrl_tune_P.ModelParam_motorT;

  /* InitializeConditions for StateSpace: '<S4>/Motor_Dynamics_2' */
  PosCtrl_tune_X.Motor_Dynamics_2_CSTATE = PosCtrl_tune_P.ModelInit_RPM *
    PosCtrl_tune_P.ModelParam_motorT;

  /* InitializeConditions for StateSpace: '<S4>/Motor_Dynamics_3' */
  PosCtrl_tune_X.Motor_Dynamics_3_CSTATE = PosCtrl_tune_P.ModelInit_RPM *
    PosCtrl_tune_P.ModelParam_motorT;

  /* InitializeConditions for StateSpace: '<S4>/Motor_Dynamics_4' */
  PosCtrl_tune_X.Motor_Dynamics_4_CSTATE = PosCtrl_tune_P.ModelInit_RPM *
    PosCtrl_tune_P.ModelParam_motorT;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(PosCtrl_tune_M)) {
    rtmSetFirstInitCond(PosCtrl_tune_M, 0);
  }
}

/* Model terminate function */
void PosCtrl_tune_terminate(void)
{
  /* (no terminate code required) */
}
