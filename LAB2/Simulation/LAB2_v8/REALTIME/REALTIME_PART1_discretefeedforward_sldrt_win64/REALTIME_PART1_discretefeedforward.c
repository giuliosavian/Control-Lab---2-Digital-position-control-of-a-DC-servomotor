/*
 * REALTIME_PART1_discretefeedforward.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_discretefeedforward".
 *
 * Model version              : 1.39
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  3 12:21:30 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART1_discretefeedforward.h"
#include "REALTIME_PART1_discretefeedforward_private.h"
#include "REALTIME_PART1_discretefeedforward_dt.h"

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
B_REALTIME_PART1_discretefeedforward_T REALTIME_PART1_discretefeedforward_B;

/* Continuous states */
X_REALTIME_PART1_discretefeedforward_T REALTIME_PART1_discretefeedforward_X;

/* Block states (default storage) */
DW_REALTIME_PART1_discretefeedforward_T REALTIME_PART1_discretefeedforward_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PART1_discretefeedforward_T
  REALTIME_PART1_discretefeedforward_M_;
RT_MODEL_REALTIME_PART1_discretefeedforward_T *const
  REALTIME_PART1_discretefeedforward_M = &REALTIME_PART1_discretefeedforward_M_;
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
  (REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2])++;
  if ((REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] = 0;
  }

  REALTIME_PART1_discretefeedforward_M->Timing.sampleHits[2] =
    (REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0);
  (REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3])++;
  if ((REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3]) > 499)
  {                                    /* Sample time: [0.5s, 0.0s] */
    REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] = 0;
  }

  REALTIME_PART1_discretefeedforward_M->Timing.sampleHits[3] =
    (REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] == 0);
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  REALTIME_PART1_discretefeedforward_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  REALTIME_PART1_discretefeedforward_output();
  REALTIME_PART1_discretefeedforward_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  REALTIME_PART1_discretefeedforward_output();
  REALTIME_PART1_discretefeedforward_derivatives();

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
void REALTIME_PART1_discretefeedforward_output(void)
{
  /* local block i/o variables */
  real_T rtb_deg2rad;
  real_T derivativegain;
  real_T derivativegain_0;
  uint8_T rtb_Output;
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M)) {
    /* set solver stop time */
    if (!(REALTIME_PART1_discretefeedforward_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                            ((REALTIME_PART1_discretefeedforward_M->Timing.clockTickH0
        + 1) * REALTIME_PART1_discretefeedforward_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                            ((REALTIME_PART1_discretefeedforward_M->Timing.clockTick0
        + 1) * REALTIME_PART1_discretefeedforward_M->Timing.stepSize0 +
        REALTIME_PART1_discretefeedforward_M->Timing.clockTickH0 *
        REALTIME_PART1_discretefeedforward_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(REALTIME_PART1_discretefeedforward_M)) {
    REALTIME_PART1_discretefeedforward_M->Timing.t[0] = rtsiGetT
      (&REALTIME_PART1_discretefeedforward_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] == 0) {
    /* UnitDelay: '<S4>/Output' */
    rtb_Output = REALTIME_PART1_discretefeedforward_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S3>/Output' incorporates:
     *  Constant: '<S3>/Vector'
     *  UnitDelay: '<S4>/Output'
     */
    REALTIME_PART1_discretefeedforward_B.Output =
      REALTIME_PART1_discretefeedforward_P.RepeatingSequenceStair_OutValues[REALTIME_PART1_discretefeedforward_DW.Output_DSTATE];
  }

  /* Integrator: '<S1>/Integrator' */
  REALTIME_PART1_discretefeedforward_B.Integrator =
    REALTIME_PART1_discretefeedforward_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S1>/Zero-Order Hold' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold =
      REALTIME_PART1_discretefeedforward_B.Output;
  }

  /* Gain: '<S1>/derivative gain1' incorporates:
   *  Integrator: '<S1>/Integrator1'
   */
  REALTIME_PART1_discretefeedforward_B.derivativegain1 =
    REALTIME_PART1_discretefeedforward_P.rad2deg *
    REALTIME_PART1_discretefeedforward_X.Integrator1_CSTATE;

  /* ZeroOrderHold: '<S1>/Zero-Order Hold1' incorporates:
   *  ZeroOrderHold: '<S1>/Zero-Order Hold2'
   */
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S1>/Zero-Order Hold1' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1 =
      REALTIME_PART1_discretefeedforward_B.Integrator;

    /* ZeroOrderHold: '<S1>/Zero-Order Hold2' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold2 =
      REALTIME_PART1_discretefeedforward_B.derivativegain1;

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter =
        REALTIME_PART1_discretefeedforward_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PART1_discretefeedforward_P.EncoderInput_Channels,
                     &rtb_deg2rad, &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    REALTIME_PART1_discretefeedforward_B.pulse2deg =
      REALTIME_PART1_discretefeedforward_P.sens.enc.pulse2deg * rtb_deg2rad;

    /* Sum: '<Root>/Sum1' */
    REALTIME_PART1_discretefeedforward_B.Sum1 =
      REALTIME_PART1_discretefeedforward_B.ZeroOrderHold2 -
      REALTIME_PART1_discretefeedforward_B.pulse2deg;

    /* Gain: '<S2>/deg2rad' */
    rtb_deg2rad = REALTIME_PART1_discretefeedforward_P.deg2rad *
      REALTIME_PART1_discretefeedforward_B.Sum1;

    /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' incorporates:
     *  Gain: '<S2>/derivative gain'
     */
    REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_tmp =
      (REALTIME_PART1_discretefeedforward_P.ctrl.Kd * rtb_deg2rad -
       REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_DenCoef[1] *
       REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states) /
      REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_DenCoef[0];

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
     *  Delay: '<S2>/Delay'
     *  Gain: '<S2>/integral gain'
     *  Sum: '<S2>/Sum3'
     */
    REALTIME_PART1_discretefeedforward_B.DiscreteTimeIntegrator =
      (REALTIME_PART1_discretefeedforward_P.ctrl.Ki * rtb_deg2rad -
       REALTIME_PART1_discretefeedforward_DW.Delay_DSTATE) *
      REALTIME_PART1_discretefeedforward_P.DiscreteTimeIntegrator_gainval +
      REALTIME_PART1_discretefeedforward_DW.DiscreteTimeIntegrator_DSTATE;

    /* ManualSwitch: '<S2>/Manual Switch' */
    if (REALTIME_PART1_discretefeedforward_P.ManualSwitch_CurrentSetting == 1) {
      /* Gain: '<S2>/rpm2rads ' */
      derivativegain = REALTIME_PART1_discretefeedforward_P.rpm2rads *
        REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1;

      /* Signum: '<S2>/Sign ' */
      if (derivativegain < 0.0) {
        derivativegain_0 = -1.0;
      } else if (derivativegain > 0.0) {
        derivativegain_0 = 1.0;
      } else if (derivativegain == 0.0) {
        derivativegain_0 = 0.0;
      } else {
        derivativegain_0 = (rtNaN);
      }

      /* End of Signum: '<S2>/Sign ' */

      /* ManualSwitch: '<S2>/Manual Switch' incorporates:
       *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
       *  Gain: '<S2>/FF comp (BEMF)'
       *  Gain: '<S2>/FF comp (Coulomb fric)'
       *  Gain: '<S2>/FF comp (friction)'
       *  Gain: '<S2>/FF comp (inertia)'
       *  Gain: '<S2>/FF comp (viscous fric)'
       *  Gain: '<S2>/proportional gain'
       *  Gain: '<S2>/rpm2rads'
       *  Sum: '<S2>/Sum'
       *  Sum: '<S2>/Sum2'
       *  Sum: '<S2>/Sum4'
       *  Sum: '<S2>/Sum5'
       *  Sum: '<S2>/Sum7'
       */
      REALTIME_PART1_discretefeedforward_B.ManualSwitch =
        (((((REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_NumCoef[0]
             * REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_tmp +
             REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_NumCoef[1]
             * REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states)
            + REALTIME_PART1_discretefeedforward_P.ctrl.Kp * rtb_deg2rad) +
           REALTIME_PART1_discretefeedforward_B.DiscreteTimeIntegrator) +
          REALTIME_PART1_discretefeedforward_P.BEMF_comp * derivativegain) +
         (196.0 * REALTIME_PART1_discretefeedforward_P.Beq_hat * derivativegain
          + REALTIME_PART1_discretefeedforward_P.tau_hat * derivativegain_0) *
         REALTIME_PART1_discretefeedforward_P.friction_comp) +
        REALTIME_PART1_discretefeedforward_P.rpm2rads *
        REALTIME_PART1_discretefeedforward_B.ZeroOrderHold *
        REALTIME_PART1_discretefeedforward_P.inertia_comp;
    } else {
      /* ManualSwitch: '<S2>/Manual Switch' incorporates:
       *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
       *  Gain: '<S2>/proportional gain'
       *  Sum: '<S2>/Sum'
       */
      REALTIME_PART1_discretefeedforward_B.ManualSwitch =
        ((REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_NumCoef[0] *
          REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_tmp +
          REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_NumCoef[1] *
          REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states) +
         REALTIME_PART1_discretefeedforward_P.ctrl.Kp * rtb_deg2rad) +
        REALTIME_PART1_discretefeedforward_B.DiscreteTimeIntegrator;
    }

    /* End of ManualSwitch: '<S2>/Manual Switch' */

    /* Saturate: '<S2>/Saturation' */
    if (REALTIME_PART1_discretefeedforward_B.ManualSwitch >
        REALTIME_PART1_discretefeedforward_P.Saturation_UpperSat) {
      /* Saturate: '<S2>/Saturation' */
      REALTIME_PART1_discretefeedforward_B.Saturation =
        REALTIME_PART1_discretefeedforward_P.Saturation_UpperSat;
    } else if (REALTIME_PART1_discretefeedforward_B.ManualSwitch <
               REALTIME_PART1_discretefeedforward_P.Saturation_LowerSat) {
      /* Saturate: '<S2>/Saturation' */
      REALTIME_PART1_discretefeedforward_B.Saturation =
        REALTIME_PART1_discretefeedforward_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S2>/Saturation' */
      REALTIME_PART1_discretefeedforward_B.Saturation =
        REALTIME_PART1_discretefeedforward_B.ManualSwitch;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* ZeroOrderHold: '<S2>/Zero-Order Hold1' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_o =
      REALTIME_PART1_discretefeedforward_B.Saturation;

    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          REALTIME_PART1_discretefeedforward_P.AnalogOutput_RangeMode;
        parm.rangeidx =
          REALTIME_PART1_discretefeedforward_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &REALTIME_PART1_discretefeedforward_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_o)),
                       &parm);
      }
    }
  }

  /* End of ZeroOrderHold: '<S1>/Zero-Order Hold1' */

  /* Gain: '<Root>/degs2rpm' incorporates:
   *  TransferFcn: '<Root>/Speed Filter'
   */
  REALTIME_PART1_discretefeedforward_B.wlrpm =
    (REALTIME_PART1_discretefeedforward_P.SpeedFilter_C[0] *
     REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[0] +
     REALTIME_PART1_discretefeedforward_P.SpeedFilter_C[1] *
     REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[1]) *
    REALTIME_PART1_discretefeedforward_P.degs2rpm;

  /* TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_discretefeedforward_B.accrpms = 0.0;
  REALTIME_PART1_discretefeedforward_B.accrpms +=
    REALTIME_PART1_discretefeedforward_P.AccelerationFilter_C[0] *
    REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[0];
  REALTIME_PART1_discretefeedforward_B.accrpms +=
    REALTIME_PART1_discretefeedforward_P.AccelerationFilter_C[1] *
    REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[1];

  /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_n =
      REALTIME_PART1_discretefeedforward_B.wlrpm;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold_m =
      REALTIME_PART1_discretefeedforward_B.accrpms;
  }

  /* End of ZeroOrderHold: '<Root>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sum: '<S5>/FixPt Sum1' incorporates:
     *  Constant: '<S5>/FixPt Constant'
     */
    rtb_Output = (uint8_T)((uint32_T)rtb_Output +
      REALTIME_PART1_discretefeedforward_P.FixPtConstant_Value);

    /* Switch: '<S6>/FixPt Switch' */
    if (rtb_Output > REALTIME_PART1_discretefeedforward_P.LimitedCounter_uplimit)
    {
      /* Switch: '<S6>/FixPt Switch' incorporates:
       *  Constant: '<S6>/Constant'
       */
      REALTIME_PART1_discretefeedforward_B.FixPtSwitch =
        REALTIME_PART1_discretefeedforward_P.Constant_Value;
    } else {
      /* Switch: '<S6>/FixPt Switch' */
      REALTIME_PART1_discretefeedforward_B.FixPtSwitch = rtb_Output;
    }

    /* End of Switch: '<S6>/FixPt Switch' */
  }

  /* Gain: '<S1>/derivative gain' */
  REALTIME_PART1_discretefeedforward_B.derivativegain_p =
    REALTIME_PART1_discretefeedforward_P.rpm2rads *
    REALTIME_PART1_discretefeedforward_B.Integrator;
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S2>/K_w ' incorporates:
     *  Sum: '<S2>/Sum1'
     */
    REALTIME_PART1_discretefeedforward_B.K_w =
      (REALTIME_PART1_discretefeedforward_B.ManualSwitch -
       REALTIME_PART1_discretefeedforward_B.Saturation) *
      REALTIME_PART1_discretefeedforward_P.K_w;
  }
}

/* Model update function */
void REALTIME_PART1_discretefeedforward_update(void)
{
  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay: '<S4>/Output' */
    REALTIME_PART1_discretefeedforward_DW.Output_DSTATE =
      REALTIME_PART1_discretefeedforward_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states =
      REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_tmp;

    /* Update for Delay: '<S2>/Delay' */
    REALTIME_PART1_discretefeedforward_DW.Delay_DSTATE =
      REALTIME_PART1_discretefeedforward_B.K_w;

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    REALTIME_PART1_discretefeedforward_DW.DiscreteTimeIntegrator_DSTATE =
      REALTIME_PART1_discretefeedforward_B.DiscreteTimeIntegrator;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M)) {
    rt_ertODEUpdateContinuousStates
      (&REALTIME_PART1_discretefeedforward_M->solverInfo);
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
  if (!(++REALTIME_PART1_discretefeedforward_M->Timing.clockTick0)) {
    ++REALTIME_PART1_discretefeedforward_M->Timing.clockTickH0;
  }

  REALTIME_PART1_discretefeedforward_M->Timing.t[0] = rtsiGetSolverStopTime
    (&REALTIME_PART1_discretefeedforward_M->solverInfo);

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
    if (!(++REALTIME_PART1_discretefeedforward_M->Timing.clockTick1)) {
      ++REALTIME_PART1_discretefeedforward_M->Timing.clockTickH1;
    }

    REALTIME_PART1_discretefeedforward_M->Timing.t[1] =
      REALTIME_PART1_discretefeedforward_M->Timing.clockTick1 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize1 +
      REALTIME_PART1_discretefeedforward_M->Timing.clockTickH1 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART1_discretefeedforward_M->Timing.clockTick2)) {
      ++REALTIME_PART1_discretefeedforward_M->Timing.clockTickH2;
    }

    REALTIME_PART1_discretefeedforward_M->Timing.t[2] =
      REALTIME_PART1_discretefeedforward_M->Timing.clockTick2 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize2 +
      REALTIME_PART1_discretefeedforward_M->Timing.clockTickH2 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(REALTIME_PART1_discretefeedforward_M) &&
      REALTIME_PART1_discretefeedforward_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART1_discretefeedforward_M->Timing.clockTick3)) {
      ++REALTIME_PART1_discretefeedforward_M->Timing.clockTickH3;
    }

    REALTIME_PART1_discretefeedforward_M->Timing.t[3] =
      REALTIME_PART1_discretefeedforward_M->Timing.clockTick3 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize3 +
      REALTIME_PART1_discretefeedforward_M->Timing.clockTickH3 *
      REALTIME_PART1_discretefeedforward_M->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void REALTIME_PART1_discretefeedforward_derivatives(void)
{
  XDot_REALTIME_PART1_discretefeedforward_T *_rtXdot;
  _rtXdot = ((XDot_REALTIME_PART1_discretefeedforward_T *)
             REALTIME_PART1_discretefeedforward_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = REALTIME_PART1_discretefeedforward_B.Output;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE =
    REALTIME_PART1_discretefeedforward_B.derivativegain_p;

  /* Derivatives for TransferFcn: '<Root>/Speed Filter' */
  _rtXdot->SpeedFilter_CSTATE[0] = 0.0;
  _rtXdot->SpeedFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_P.SpeedFilter_A[0] *
    REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[0];
  _rtXdot->SpeedFilter_CSTATE[1] = 0.0;
  _rtXdot->SpeedFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_P.SpeedFilter_A[1] *
    REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[1];
  _rtXdot->SpeedFilter_CSTATE[1] +=
    REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[0];
  _rtXdot->SpeedFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_B.pulse2deg;

  /* Derivatives for TransferFcn: '<Root>/Acceleration Filter' */
  _rtXdot->AccelerationFilter_CSTATE[0] = 0.0;
  _rtXdot->AccelerationFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_P.AccelerationFilter_A[0] *
    REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[0];
  _rtXdot->AccelerationFilter_CSTATE[1] = 0.0;
  _rtXdot->AccelerationFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_P.AccelerationFilter_A[1] *
    REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[1];
  _rtXdot->AccelerationFilter_CSTATE[1] +=
    REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[0];
  _rtXdot->AccelerationFilter_CSTATE[0] +=
    REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_n;
}

/* Model initialize function */
void REALTIME_PART1_discretefeedforward_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART1_discretefeedforward_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        REALTIME_PART1_discretefeedforward_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_discretefeedforward_P.AnalogOutput_Channels,
                     &REALTIME_PART1_discretefeedforward_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for UnitDelay: '<S4>/Output' */
  REALTIME_PART1_discretefeedforward_DW.Output_DSTATE =
    REALTIME_PART1_discretefeedforward_P.Output_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  REALTIME_PART1_discretefeedforward_X.Integrator_CSTATE =
    REALTIME_PART1_discretefeedforward_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  REALTIME_PART1_discretefeedforward_X.Integrator1_CSTATE =
    REALTIME_PART1_discretefeedforward_P.Integrator1_IC;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter =
      REALTIME_PART1_discretefeedforward_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &REALTIME_PART1_discretefeedforward_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states =
    REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_InitialStates;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  REALTIME_PART1_discretefeedforward_DW.Delay_DSTATE =
    REALTIME_PART1_discretefeedforward_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  REALTIME_PART1_discretefeedforward_DW.DiscreteTimeIntegrator_DSTATE =
    REALTIME_PART1_discretefeedforward_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Speed Filter' */
  REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Speed Filter' */
  REALTIME_PART1_discretefeedforward_X.SpeedFilter_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_discretefeedforward_X.AccelerationFilter_CSTATE[1] = 0.0;
}

/* Model terminate function */
void REALTIME_PART1_discretefeedforward_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART1_discretefeedforward_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        REALTIME_PART1_discretefeedforward_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_discretefeedforward_P.AnalogOutput_Channels,
                     &REALTIME_PART1_discretefeedforward_P.AnalogOutput_FinalValue,
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
  REALTIME_PART1_discretefeedforward_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PART1_discretefeedforward_update();
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
  REALTIME_PART1_discretefeedforward_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PART1_discretefeedforward_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PART1_discretefeedforward_T
  *REALTIME_PART1_discretefeedforward(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PART1_discretefeedforward_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PART1_discretefeedforward_M, 0,
                sizeof(RT_MODEL_REALTIME_PART1_discretefeedforward_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                          &REALTIME_PART1_discretefeedforward_M->Timing.simTimeStep);
    rtsiSetTPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo, &rtmGetTPtr
                (REALTIME_PART1_discretefeedforward_M));
    rtsiSetStepSizePtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                       &REALTIME_PART1_discretefeedforward_M->Timing.stepSize0);
    rtsiSetdXPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                 &REALTIME_PART1_discretefeedforward_M->derivs);
    rtsiSetContStatesPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                         (real_T **)
                         &REALTIME_PART1_discretefeedforward_M->contStates);
    rtsiSetNumContStatesPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
      &REALTIME_PART1_discretefeedforward_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&REALTIME_PART1_discretefeedforward_M->solverInfo,
       &REALTIME_PART1_discretefeedforward_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&REALTIME_PART1_discretefeedforward_M->solverInfo,
       &REALTIME_PART1_discretefeedforward_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&REALTIME_PART1_discretefeedforward_M->solverInfo,
       &REALTIME_PART1_discretefeedforward_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                          (&rtmGetErrorStatus
      (REALTIME_PART1_discretefeedforward_M)));
    rtsiSetRTModelPtr(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                      REALTIME_PART1_discretefeedforward_M);
  }

  rtsiSetSimTimeStep(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                     MAJOR_TIME_STEP);
  REALTIME_PART1_discretefeedforward_M->intgData.y =
    REALTIME_PART1_discretefeedforward_M->odeY;
  REALTIME_PART1_discretefeedforward_M->intgData.f[0] =
    REALTIME_PART1_discretefeedforward_M->odeF[0];
  REALTIME_PART1_discretefeedforward_M->intgData.f[1] =
    REALTIME_PART1_discretefeedforward_M->odeF[1];
  REALTIME_PART1_discretefeedforward_M->intgData.f[2] =
    REALTIME_PART1_discretefeedforward_M->odeF[2];
  REALTIME_PART1_discretefeedforward_M->contStates = ((real_T *)
    &REALTIME_PART1_discretefeedforward_X);
  rtsiSetSolverData(&REALTIME_PART1_discretefeedforward_M->solverInfo, (void *)
                    &REALTIME_PART1_discretefeedforward_M->intgData);
  rtsiSetSolverName(&REALTIME_PART1_discretefeedforward_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      REALTIME_PART1_discretefeedforward_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimes =
      (&REALTIME_PART1_discretefeedforward_M->Timing.sampleTimesArray[0]);
    REALTIME_PART1_discretefeedforward_M->Timing.offsetTimes =
      (&REALTIME_PART1_discretefeedforward_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimes[0] = (0.0);
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimes[1] = (0.001);
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimes[2] = (0.01);
    REALTIME_PART1_discretefeedforward_M->Timing.sampleTimes[3] = (0.5);

    /* task offsets */
    REALTIME_PART1_discretefeedforward_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PART1_discretefeedforward_M->Timing.offsetTimes[1] = (0.0);
    REALTIME_PART1_discretefeedforward_M->Timing.offsetTimes[2] = (0.0);
    REALTIME_PART1_discretefeedforward_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(REALTIME_PART1_discretefeedforward_M,
             &REALTIME_PART1_discretefeedforward_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      REALTIME_PART1_discretefeedforward_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    REALTIME_PART1_discretefeedforward_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PART1_discretefeedforward_M, 5.0);
  REALTIME_PART1_discretefeedforward_M->Timing.stepSize0 = 0.001;
  REALTIME_PART1_discretefeedforward_M->Timing.stepSize1 = 0.001;
  REALTIME_PART1_discretefeedforward_M->Timing.stepSize2 = 0.01;
  REALTIME_PART1_discretefeedforward_M->Timing.stepSize3 = 0.5;

  /* External mode info */
  REALTIME_PART1_discretefeedforward_M->Sizes.checksums[0] = (2359504606U);
  REALTIME_PART1_discretefeedforward_M->Sizes.checksums[1] = (420702952U);
  REALTIME_PART1_discretefeedforward_M->Sizes.checksums[2] = (1562021451U);
  REALTIME_PART1_discretefeedforward_M->Sizes.checksums[3] = (2143924629U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    REALTIME_PART1_discretefeedforward_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PART1_discretefeedforward_M->extModeInfo,
      &REALTIME_PART1_discretefeedforward_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PART1_discretefeedforward_M->extModeInfo,
                        REALTIME_PART1_discretefeedforward_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PART1_discretefeedforward_M->extModeInfo, rtmGetTPtr
                (REALTIME_PART1_discretefeedforward_M));
  }

  REALTIME_PART1_discretefeedforward_M->solverInfoPtr =
    (&REALTIME_PART1_discretefeedforward_M->solverInfo);
  REALTIME_PART1_discretefeedforward_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PART1_discretefeedforward_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PART1_discretefeedforward_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PART1_discretefeedforward_M->blockIO = ((void *)
    &REALTIME_PART1_discretefeedforward_B);
  (void) memset(((void *) &REALTIME_PART1_discretefeedforward_B), 0,
                sizeof(B_REALTIME_PART1_discretefeedforward_T));

  /* parameters */
  REALTIME_PART1_discretefeedforward_M->defaultParam = ((real_T *)
    &REALTIME_PART1_discretefeedforward_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &REALTIME_PART1_discretefeedforward_X;
    REALTIME_PART1_discretefeedforward_M->contStates = (x);
    (void) memset((void *)&REALTIME_PART1_discretefeedforward_X, 0,
                  sizeof(X_REALTIME_PART1_discretefeedforward_T));
  }

  /* states (dwork) */
  REALTIME_PART1_discretefeedforward_M->dwork = ((void *)
    &REALTIME_PART1_discretefeedforward_DW);
  (void) memset((void *)&REALTIME_PART1_discretefeedforward_DW, 0,
                sizeof(DW_REALTIME_PART1_discretefeedforward_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PART1_discretefeedforward_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PART1_discretefeedforward_M->Sizes.numContStates = (6);/* Number of continuous states */
  REALTIME_PART1_discretefeedforward_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  REALTIME_PART1_discretefeedforward_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PART1_discretefeedforward_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PART1_discretefeedforward_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PART1_discretefeedforward_M->Sizes.numSampTimes = (4);/* Number of sample times */
  REALTIME_PART1_discretefeedforward_M->Sizes.numBlocks = (53);/* Number of blocks */
  REALTIME_PART1_discretefeedforward_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  REALTIME_PART1_discretefeedforward_M->Sizes.numBlockPrms = (54);/* Sum of parameter "widths" */
  return REALTIME_PART1_discretefeedforward_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
