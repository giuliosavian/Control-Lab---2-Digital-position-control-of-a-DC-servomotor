/*
 * REALTIME_PART2_robust_exact.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART2_robust_exact".
 *
 * Model version              : 1.29
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  3 12:08:05 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART2_robust_exact.h"
#include "REALTIME_PART2_robust_exact_private.h"
#include "REALTIME_PART2_robust_exact_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_REALTIME_PART2_robust_exact_T REALTIME_PART2_robust_exact_B;

/* Continuous states */
X_REALTIME_PART2_robust_exact_T REALTIME_PART2_robust_exact_X;

/* Block states (default storage) */
DW_REALTIME_PART2_robust_exact_T REALTIME_PART2_robust_exact_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PART2_robust_exact_T REALTIME_PART2_robust_exact_M_;
RT_MODEL_REALTIME_PART2_robust_exact_T *const REALTIME_PART2_robust_exact_M =
  &REALTIME_PART2_robust_exact_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2])++;
  if ((REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.05s, 0.0s] */
    REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] = 0;
  }

  REALTIME_PART2_robust_exact_M->Timing.sampleHits[2] =
    (REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0);
}

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  REALTIME_PART2_robust_exact_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  REALTIME_PART2_robust_exact_output();
  REALTIME_PART2_robust_exact_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  REALTIME_PART2_robust_exact_output();
  REALTIME_PART2_robust_exact_derivatives();

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

/* Model output function */
void REALTIME_PART2_robust_exact_output(void)
{
  /* local block i/o variables */
  real_T rtb_thl_meas;
  real_T rtb_Delay;
  real_T rtb_Delay2;
  real_T rtb_deg2rad;
  real_T rtb_deg2rad1;
  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M)) {
    /* set solver stop time */
    if (!(REALTIME_PART2_robust_exact_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&REALTIME_PART2_robust_exact_M->solverInfo,
                            ((REALTIME_PART2_robust_exact_M->Timing.clockTickH0
        + 1) * REALTIME_PART2_robust_exact_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&REALTIME_PART2_robust_exact_M->solverInfo,
                            ((REALTIME_PART2_robust_exact_M->Timing.clockTick0 +
        1) * REALTIME_PART2_robust_exact_M->Timing.stepSize0 +
        REALTIME_PART2_robust_exact_M->Timing.clockTickH0 *
        REALTIME_PART2_robust_exact_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(REALTIME_PART2_robust_exact_M)) {
    REALTIME_PART2_robust_exact_M->Timing.t[0] = rtsiGetT
      (&REALTIME_PART2_robust_exact_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Step: '<Root>/Step' */
    if (REALTIME_PART2_robust_exact_M->Timing.t[2] <
        REALTIME_PART2_robust_exact_P.Step_Time) {
      rtb_deg2rad1 = REALTIME_PART2_robust_exact_P.Step_Y0;
    } else {
      rtb_deg2rad1 = REALTIME_PART2_robust_exact_P.step_size;
    }

    /* End of Step: '<Root>/Step' */

    /* Gain: '<S1>/deg2rad' */
    rtb_deg2rad = REALTIME_PART2_robust_exact_P.deg2rad * rtb_deg2rad1;

    /* Gain: '<S1>/Input feedforward' */
    REALTIME_PART2_robust_exact_B.Inputfeedforward =
      REALTIME_PART2_robust_exact_P.N_u * rtb_deg2rad;

    /* Gain: '<S1>/State feedback' incorporates:
     *  Delay: '<S1>/Delay1'
     *  Gain: '<S1>/State feedforward	'
     *  Sum: '<S1>/Sum2'
     */
    REALTIME_PART2_robust_exact_B.Statefeedback = (rtb_deg2rad *
      REALTIME_PART2_robust_exact_P.N_x[0] -
      REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[0]) *
      REALTIME_PART2_robust_exact_P.Statefeedback_Gain[0] + (rtb_deg2rad *
      REALTIME_PART2_robust_exact_P.N_x[1] -
      REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[1]) *
      REALTIME_PART2_robust_exact_P.Statefeedback_Gain[1];
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  TransferFcn: '<S1>/High-pass filter1'
   */
  REALTIME_PART2_robust_exact_B.Sum = REALTIME_PART2_robust_exact_P.Ki /
    REALTIME_PART2_robust_exact_P.Highpassfilter1_Denominator[0] *
    REALTIME_PART2_robust_exact_X.Highpassfilter1_CSTATE +
    (REALTIME_PART2_robust_exact_B.Inputfeedforward +
     REALTIME_PART2_robust_exact_B.Statefeedback);

  /* Saturate: '<S1>/Saturation' */
  if (REALTIME_PART2_robust_exact_B.Sum >
      REALTIME_PART2_robust_exact_P.Saturation_UpperSat) {
    /* Saturate: '<S1>/Saturation' */
    REALTIME_PART2_robust_exact_B.Saturation =
      REALTIME_PART2_robust_exact_P.Saturation_UpperSat;
  } else if (REALTIME_PART2_robust_exact_B.Sum <
             REALTIME_PART2_robust_exact_P.Saturation_LowerSat) {
    /* Saturate: '<S1>/Saturation' */
    REALTIME_PART2_robust_exact_B.Saturation =
      REALTIME_PART2_robust_exact_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S1>/Saturation' */
    REALTIME_PART2_robust_exact_B.Saturation = REALTIME_PART2_robust_exact_B.Sum;
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S1>/deg2rad1' */
    rtb_deg2rad1 *= REALTIME_PART2_robust_exact_P.deg2rad;

    /* Gain: '<Root>/deg2rad' incorporates:
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
     */
    rtb_thl_meas = REALTIME_PART2_robust_exact_P.DiscreteTransferFcn_NumCoef[1] *
      REALTIME_PART2_robust_exact_DW.DiscreteTransferFcn_states;

    /* Sum: '<S1>/Sum5' incorporates:
     *  Delay: '<S1>/Delay3'
     *  Gain: '<S1>/Input feedforward1'
     *  Gain: '<S1>/State feedback1'
     *  Gain: '<S1>/State feedforward	1'
     *  Sum: '<S1>/Sum7'
     */
    REALTIME_PART2_robust_exact_B.Sum5 = (((rtb_deg2rad1 *
      REALTIME_PART2_robust_exact_P.N_x[0] -
      REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[0]) *
      REALTIME_PART2_robust_exact_P.Statefeedback1_Gain[0] + (rtb_deg2rad1 *
      REALTIME_PART2_robust_exact_P.N_x[1] -
      REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[1]) *
      REALTIME_PART2_robust_exact_P.Statefeedback1_Gain[1]) +
      REALTIME_PART2_robust_exact_P.N_u * rtb_deg2rad1) + rtb_thl_meas;

    /* Saturate: '<S1>/Saturation1' */
    if (REALTIME_PART2_robust_exact_B.Sum5 >
        REALTIME_PART2_robust_exact_P.Saturation1_UpperSat) {
      /* Saturate: '<S1>/Saturation1' */
      REALTIME_PART2_robust_exact_B.Saturation1 =
        REALTIME_PART2_robust_exact_P.Saturation1_UpperSat;
    } else if (REALTIME_PART2_robust_exact_B.Sum5 <
               REALTIME_PART2_robust_exact_P.Saturation1_LowerSat) {
      /* Saturate: '<S1>/Saturation1' */
      REALTIME_PART2_robust_exact_B.Saturation1 =
        REALTIME_PART2_robust_exact_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<S1>/Saturation1' */
      REALTIME_PART2_robust_exact_B.Saturation1 =
        REALTIME_PART2_robust_exact_B.Sum5;
    }

    /* End of Saturate: '<S1>/Saturation1' */
  }

  /* ManualSwitch: '<Root>/Manual Switch2' */
  if (REALTIME_PART2_robust_exact_P.ManualSwitch2_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch2' */
    REALTIME_PART2_robust_exact_B.ManualSwitch2 =
      REALTIME_PART2_robust_exact_B.Saturation;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch2' */
    REALTIME_PART2_robust_exact_B.ManualSwitch2 =
      REALTIME_PART2_robust_exact_B.Saturation1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART2_robust_exact_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART2_robust_exact_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART2_robust_exact_P.AnalogOutput_Channels,
                     ((real_T*) (&REALTIME_PART2_robust_exact_B.ManualSwitch2)),
                     &parm);
    }
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PART2_robust_exact_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PART2_robust_exact_P.EncoderInput_Channels,
                     &rtb_thl_meas, &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    REALTIME_PART2_robust_exact_B.thl_meas =
      REALTIME_PART2_robust_exact_P.sens.enc.pulse2deg * rtb_thl_meas;

    /* Gain: '<Root>/deg2rad' */
    rtb_thl_meas = REALTIME_PART2_robust_exact_P.deg2rad *
      REALTIME_PART2_robust_exact_B.thl_meas;

    /* Sum: '<Root>/Sum' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space'
     *  Gain: '<Root>/Gain'
     */
    REALTIME_PART2_robust_exact_B.Sum_f[0] = REALTIME_PART2_robust_exact_P.H0[0]
      * REALTIME_PART2_robust_exact_DW.DiscreteStateSpace_DSTATE +
      REALTIME_PART2_robust_exact_P.Gain_Gain[0] * rtb_thl_meas;
    REALTIME_PART2_robust_exact_B.Sum_f[1] = REALTIME_PART2_robust_exact_P.H0[1]
      * REALTIME_PART2_robust_exact_DW.DiscreteStateSpace_DSTATE +
      REALTIME_PART2_robust_exact_P.Gain_Gain[1] * rtb_thl_meas;
  }

  /* Gain: '<Root>/degs2rpm1' incorporates:
   *  TransferFcn: '<Root>/Speed Filter1'
   */
  REALTIME_PART2_robust_exact_B.wlrpm =
    (REALTIME_PART2_robust_exact_P.SpeedFilter1_C[0] *
     REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[0] +
     REALTIME_PART2_robust_exact_P.SpeedFilter1_C[1] *
     REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[1]) *
    REALTIME_PART2_robust_exact_P.degs2rpm;
  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Delay: '<S1>/Delay2' */
    rtb_Delay2 = REALTIME_PART2_robust_exact_DW.Delay2_DSTATE;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[1] == 0) {
    /* Delay: '<S1>/Delay' */
    rtb_Delay = REALTIME_PART2_robust_exact_DW.Delay_DSTATE;
  }

  /* Gain: '<S1>/K_w' incorporates:
   *  Sum: '<S1>/Sum3'
   */
  REALTIME_PART2_robust_exact_B.K_w = (REALTIME_PART2_robust_exact_B.Sum -
    REALTIME_PART2_robust_exact_B.Saturation) *
    REALTIME_PART2_robust_exact_P.ctrl.Kw;
  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S1>/K_w1' incorporates:
     *  Sum: '<S1>/Sum8'
     */
    REALTIME_PART2_robust_exact_B.K_w1 = (REALTIME_PART2_robust_exact_B.Sum5 -
      REALTIME_PART2_robust_exact_B.Saturation1) *
      REALTIME_PART2_robust_exact_P.ctrl.Kw;

    /* Sum: '<S1>/Sum1' incorporates:
     *  Gain: '<S1>/deg2rads1'
     */
    REALTIME_PART2_robust_exact_B.Sum1 = rtb_deg2rad -
      REALTIME_PART2_robust_exact_P.deg2rad *
      REALTIME_PART2_robust_exact_B.thl_meas;

    /* Sum: '<S1>/Sum9' incorporates:
     *  Gain: '<S1>/deg2rads2'
     *  Sum: '<S1>/Sum6'
     */
    REALTIME_PART2_robust_exact_B.Sum9 = (rtb_deg2rad1 -
      REALTIME_PART2_robust_exact_P.deg2rad *
      REALTIME_PART2_robust_exact_B.thl_meas) - rtb_Delay2;

    /* SignalConversion generated from: '<Root>/Discrete State-Space' */
    REALTIME_PART2_robust_exact_B.TmpSignalConversionAtDiscreteStateSpaceInport1[
      0] = REALTIME_PART2_robust_exact_B.ManualSwitch2;
    REALTIME_PART2_robust_exact_B.TmpSignalConversionAtDiscreteStateSpaceInport1[
      1] = rtb_thl_meas;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S1>/Sum4' */
    REALTIME_PART2_robust_exact_B.Sum4 = REALTIME_PART2_robust_exact_B.Sum1 -
      rtb_Delay;
  }
}

/* Model update function */
void REALTIME_PART2_robust_exact_update(void)
{
  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
    REALTIME_PART2_robust_exact_DW.DiscreteTransferFcn_states =
      (REALTIME_PART2_robust_exact_B.Sum9 -
       REALTIME_PART2_robust_exact_P.DiscreteTransferFcn_DenCoef[1] *
       REALTIME_PART2_robust_exact_DW.DiscreteTransferFcn_states) /
      REALTIME_PART2_robust_exact_P.DiscreteTransferFcn_DenCoef[0];

    /* Update for Delay: '<S1>/Delay1' */
    REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[0] =
      REALTIME_PART2_robust_exact_B.Sum_f[0];

    /* Update for Delay: '<S1>/Delay3' */
    REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[0] =
      REALTIME_PART2_robust_exact_B.Sum_f[0];

    /* Update for Delay: '<S1>/Delay1' */
    REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[1] =
      REALTIME_PART2_robust_exact_B.Sum_f[1];

    /* Update for Delay: '<S1>/Delay3' */
    REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[1] =
      REALTIME_PART2_robust_exact_B.Sum_f[1];

    /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space' */
    REALTIME_PART2_robust_exact_DW.DiscreteStateSpace_DSTATE =
      (REALTIME_PART2_robust_exact_P.PHI *
       REALTIME_PART2_robust_exact_DW.DiscreteStateSpace_DSTATE +
       REALTIME_PART2_robust_exact_P.GAMMA[0] *
       REALTIME_PART2_robust_exact_B.TmpSignalConversionAtDiscreteStateSpaceInport1
       [0]) + REALTIME_PART2_robust_exact_P.GAMMA[1] *
      REALTIME_PART2_robust_exact_B.TmpSignalConversionAtDiscreteStateSpaceInport1
      [1];

    /* Update for Delay: '<S1>/Delay2' */
    REALTIME_PART2_robust_exact_DW.Delay2_DSTATE =
      REALTIME_PART2_robust_exact_B.K_w1;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S1>/Delay' */
    REALTIME_PART2_robust_exact_DW.Delay_DSTATE =
      REALTIME_PART2_robust_exact_B.K_w;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M)) {
    rt_ertODEUpdateContinuousStates(&REALTIME_PART2_robust_exact_M->solverInfo);
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
  if (!(++REALTIME_PART2_robust_exact_M->Timing.clockTick0)) {
    ++REALTIME_PART2_robust_exact_M->Timing.clockTickH0;
  }

  REALTIME_PART2_robust_exact_M->Timing.t[0] = rtsiGetSolverStopTime
    (&REALTIME_PART2_robust_exact_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART2_robust_exact_M->Timing.clockTick1)) {
      ++REALTIME_PART2_robust_exact_M->Timing.clockTickH1;
    }

    REALTIME_PART2_robust_exact_M->Timing.t[1] =
      REALTIME_PART2_robust_exact_M->Timing.clockTick1 *
      REALTIME_PART2_robust_exact_M->Timing.stepSize1 +
      REALTIME_PART2_robust_exact_M->Timing.clockTickH1 *
      REALTIME_PART2_robust_exact_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART2_robust_exact_M) &&
      REALTIME_PART2_robust_exact_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART2_robust_exact_M->Timing.clockTick2)) {
      ++REALTIME_PART2_robust_exact_M->Timing.clockTickH2;
    }

    REALTIME_PART2_robust_exact_M->Timing.t[2] =
      REALTIME_PART2_robust_exact_M->Timing.clockTick2 *
      REALTIME_PART2_robust_exact_M->Timing.stepSize2 +
      REALTIME_PART2_robust_exact_M->Timing.clockTickH2 *
      REALTIME_PART2_robust_exact_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void REALTIME_PART2_robust_exact_derivatives(void)
{
  XDot_REALTIME_PART2_robust_exact_T *_rtXdot;
  _rtXdot = ((XDot_REALTIME_PART2_robust_exact_T *)
             REALTIME_PART2_robust_exact_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/High-pass filter1' */
  _rtXdot->Highpassfilter1_CSTATE = 0.0;
  _rtXdot->Highpassfilter1_CSTATE +=
    -REALTIME_PART2_robust_exact_P.Highpassfilter1_Denominator[1] /
    REALTIME_PART2_robust_exact_P.Highpassfilter1_Denominator[0] *
    REALTIME_PART2_robust_exact_X.Highpassfilter1_CSTATE;
  _rtXdot->Highpassfilter1_CSTATE += REALTIME_PART2_robust_exact_B.Sum4;

  /* Derivatives for TransferFcn: '<Root>/Speed Filter1' */
  _rtXdot->SpeedFilter1_CSTATE[0] = 0.0;
  _rtXdot->SpeedFilter1_CSTATE[0] +=
    REALTIME_PART2_robust_exact_P.SpeedFilter1_A[0] *
    REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[0];
  _rtXdot->SpeedFilter1_CSTATE[1] = 0.0;
  _rtXdot->SpeedFilter1_CSTATE[0] +=
    REALTIME_PART2_robust_exact_P.SpeedFilter1_A[1] *
    REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[1];
  _rtXdot->SpeedFilter1_CSTATE[1] +=
    REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[0];
  _rtXdot->SpeedFilter1_CSTATE[0] += REALTIME_PART2_robust_exact_B.thl_meas;
}

/* Model initialize function */
void REALTIME_PART2_robust_exact_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART2_robust_exact_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART2_robust_exact_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART2_robust_exact_P.AnalogOutput_Channels,
                     &REALTIME_PART2_robust_exact_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<S1>/High-pass filter1' */
  REALTIME_PART2_robust_exact_X.Highpassfilter1_CSTATE = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[0] =
    REALTIME_PART2_robust_exact_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay3' */
  REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[0] =
    REALTIME_PART2_robust_exact_P.Delay3_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  REALTIME_PART2_robust_exact_DW.Delay1_DSTATE[1] =
    REALTIME_PART2_robust_exact_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay3' */
  REALTIME_PART2_robust_exact_DW.Delay3_DSTATE[1] =
    REALTIME_PART2_robust_exact_P.Delay3_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  REALTIME_PART2_robust_exact_DW.DiscreteTransferFcn_states =
    REALTIME_PART2_robust_exact_P.DiscreteTransferFcn_InitialStates;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = REALTIME_PART2_robust_exact_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &REALTIME_PART2_robust_exact_P.EncoderInput_Channels, NULL,
                   &parm);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Speed Filter1' */
  REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[0] = 0.0;
  REALTIME_PART2_robust_exact_X.SpeedFilter1_CSTATE[1] = 0.0;

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space' */
  REALTIME_PART2_robust_exact_DW.DiscreteStateSpace_DSTATE =
    REALTIME_PART2_robust_exact_P.DiscreteStateSpace_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  REALTIME_PART2_robust_exact_DW.Delay_DSTATE =
    REALTIME_PART2_robust_exact_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay2' */
  REALTIME_PART2_robust_exact_DW.Delay2_DSTATE =
    REALTIME_PART2_robust_exact_P.Delay2_InitialCondition;
}

/* Model terminate function */
void REALTIME_PART2_robust_exact_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART2_robust_exact_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART2_robust_exact_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART2_robust_exact_P.AnalogOutput_Channels,
                     &REALTIME_PART2_robust_exact_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  REALTIME_PART2_robust_exact_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PART2_robust_exact_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  REALTIME_PART2_robust_exact_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PART2_robust_exact_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PART2_robust_exact_T *REALTIME_PART2_robust_exact(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PART2_robust_exact_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PART2_robust_exact_M, 0,
                sizeof(RT_MODEL_REALTIME_PART2_robust_exact_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
                          &REALTIME_PART2_robust_exact_M->Timing.simTimeStep);
    rtsiSetTPtr(&REALTIME_PART2_robust_exact_M->solverInfo, &rtmGetTPtr
                (REALTIME_PART2_robust_exact_M));
    rtsiSetStepSizePtr(&REALTIME_PART2_robust_exact_M->solverInfo,
                       &REALTIME_PART2_robust_exact_M->Timing.stepSize0);
    rtsiSetdXPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
                 &REALTIME_PART2_robust_exact_M->derivs);
    rtsiSetContStatesPtr(&REALTIME_PART2_robust_exact_M->solverInfo, (real_T **)
                         &REALTIME_PART2_robust_exact_M->contStates);
    rtsiSetNumContStatesPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
      &REALTIME_PART2_robust_exact_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
      &REALTIME_PART2_robust_exact_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&REALTIME_PART2_robust_exact_M->solverInfo,
       &REALTIME_PART2_robust_exact_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
      &REALTIME_PART2_robust_exact_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
                          (&rtmGetErrorStatus(REALTIME_PART2_robust_exact_M)));
    rtsiSetRTModelPtr(&REALTIME_PART2_robust_exact_M->solverInfo,
                      REALTIME_PART2_robust_exact_M);
  }

  rtsiSetSimTimeStep(&REALTIME_PART2_robust_exact_M->solverInfo, MAJOR_TIME_STEP);
  REALTIME_PART2_robust_exact_M->intgData.y =
    REALTIME_PART2_robust_exact_M->odeY;
  REALTIME_PART2_robust_exact_M->intgData.f[0] =
    REALTIME_PART2_robust_exact_M->odeF[0];
  REALTIME_PART2_robust_exact_M->intgData.f[1] =
    REALTIME_PART2_robust_exact_M->odeF[1];
  REALTIME_PART2_robust_exact_M->intgData.f[2] =
    REALTIME_PART2_robust_exact_M->odeF[2];
  REALTIME_PART2_robust_exact_M->contStates = ((real_T *)
    &REALTIME_PART2_robust_exact_X);
  rtsiSetSolverData(&REALTIME_PART2_robust_exact_M->solverInfo, (void *)
                    &REALTIME_PART2_robust_exact_M->intgData);
  rtsiSetSolverName(&REALTIME_PART2_robust_exact_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      REALTIME_PART2_robust_exact_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    REALTIME_PART2_robust_exact_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    REALTIME_PART2_robust_exact_M->Timing.sampleTimes =
      (&REALTIME_PART2_robust_exact_M->Timing.sampleTimesArray[0]);
    REALTIME_PART2_robust_exact_M->Timing.offsetTimes =
      (&REALTIME_PART2_robust_exact_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PART2_robust_exact_M->Timing.sampleTimes[0] = (0.0);
    REALTIME_PART2_robust_exact_M->Timing.sampleTimes[1] = (0.001);
    REALTIME_PART2_robust_exact_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    REALTIME_PART2_robust_exact_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PART2_robust_exact_M->Timing.offsetTimes[1] = (0.0);
    REALTIME_PART2_robust_exact_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(REALTIME_PART2_robust_exact_M,
             &REALTIME_PART2_robust_exact_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = REALTIME_PART2_robust_exact_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    REALTIME_PART2_robust_exact_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PART2_robust_exact_M, 5.0);
  REALTIME_PART2_robust_exact_M->Timing.stepSize0 = 0.001;
  REALTIME_PART2_robust_exact_M->Timing.stepSize1 = 0.001;
  REALTIME_PART2_robust_exact_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  REALTIME_PART2_robust_exact_M->Sizes.checksums[0] = (1577769833U);
  REALTIME_PART2_robust_exact_M->Sizes.checksums[1] = (3051747887U);
  REALTIME_PART2_robust_exact_M->Sizes.checksums[2] = (3420597413U);
  REALTIME_PART2_robust_exact_M->Sizes.checksums[3] = (1566136501U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    REALTIME_PART2_robust_exact_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PART2_robust_exact_M->extModeInfo,
      &REALTIME_PART2_robust_exact_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PART2_robust_exact_M->extModeInfo,
                        REALTIME_PART2_robust_exact_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PART2_robust_exact_M->extModeInfo, rtmGetTPtr
                (REALTIME_PART2_robust_exact_M));
  }

  REALTIME_PART2_robust_exact_M->solverInfoPtr =
    (&REALTIME_PART2_robust_exact_M->solverInfo);
  REALTIME_PART2_robust_exact_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PART2_robust_exact_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PART2_robust_exact_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PART2_robust_exact_M->blockIO = ((void *)
    &REALTIME_PART2_robust_exact_B);
  (void) memset(((void *) &REALTIME_PART2_robust_exact_B), 0,
                sizeof(B_REALTIME_PART2_robust_exact_T));

  /* parameters */
  REALTIME_PART2_robust_exact_M->defaultParam = ((real_T *)
    &REALTIME_PART2_robust_exact_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &REALTIME_PART2_robust_exact_X;
    REALTIME_PART2_robust_exact_M->contStates = (x);
    (void) memset((void *)&REALTIME_PART2_robust_exact_X, 0,
                  sizeof(X_REALTIME_PART2_robust_exact_T));
  }

  /* states (dwork) */
  REALTIME_PART2_robust_exact_M->dwork = ((void *)
    &REALTIME_PART2_robust_exact_DW);
  (void) memset((void *)&REALTIME_PART2_robust_exact_DW, 0,
                sizeof(DW_REALTIME_PART2_robust_exact_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PART2_robust_exact_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PART2_robust_exact_M->Sizes.numContStates = (3);/* Number of continuous states */
  REALTIME_PART2_robust_exact_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  REALTIME_PART2_robust_exact_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PART2_robust_exact_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PART2_robust_exact_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PART2_robust_exact_M->Sizes.numSampTimes = (3);/* Number of sample times */
  REALTIME_PART2_robust_exact_M->Sizes.numBlocks = (45);/* Number of blocks */
  REALTIME_PART2_robust_exact_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  REALTIME_PART2_robust_exact_M->Sizes.numBlockPrms = (58);/* Sum of parameter "widths" */
  return REALTIME_PART2_robust_exact_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
