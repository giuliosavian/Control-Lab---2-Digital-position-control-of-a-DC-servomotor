/*
 * REALTIME_PART1_differentmethods.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_differentmethods".
 *
 * Model version              : 1.40
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  3 11:55:49 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART1_differentmethods.h"
#include "REALTIME_PART1_differentmethods_private.h"
#include "REALTIME_PART1_differentmethods_dt.h"

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
B_REALTIME_PART1_differentmethods_T REALTIME_PART1_differentmethods_B;

/* Block states (default storage) */
DW_REALTIME_PART1_differentmethods_T REALTIME_PART1_differentmethods_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PART1_differentmethods_T
  REALTIME_PART1_differentmethods_M_;
RT_MODEL_REALTIME_PART1_differentmethods_T *const
  REALTIME_PART1_differentmethods_M = &REALTIME_PART1_differentmethods_M_;
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
  (REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1])++;
  if ((REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.05s, 0.0s] */
    REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1] = 0;
  }

  REALTIME_PART1_differentmethods_M->Timing.sampleHits[1] =
    (REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1] == 0);
}

/* Model output function */
void REALTIME_PART1_differentmethods_output(void)
{
  /* local block i/o variables */
  real_T rtb_DiscreteTransferFcn1;
  if (REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1] == 0) {
    /* Step: '<Root>/Step' */
    if (REALTIME_PART1_differentmethods_M->Timing.t[1] <
        REALTIME_PART1_differentmethods_P.Step_Time) {
      /* Step: '<Root>/Step' */
      REALTIME_PART1_differentmethods_B.Step =
        REALTIME_PART1_differentmethods_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      REALTIME_PART1_differentmethods_B.Step =
        REALTIME_PART1_differentmethods_P.step_size;
    }

    /* End of Step: '<Root>/Step' */

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PART1_differentmethods_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PART1_differentmethods_P.EncoderInput_Channels,
                     &rtb_DiscreteTransferFcn1, &parm);
    }

    /* Gain: '<Root>/pulse2deg2' */
    REALTIME_PART1_differentmethods_B.pulse2deg2 =
      REALTIME_PART1_differentmethods_P.sens.enc.pulse2deg *
      rtb_DiscreteTransferFcn1;

    /* Sum: '<Root>/Sum1' */
    REALTIME_PART1_differentmethods_B.edeg =
      REALTIME_PART1_differentmethods_B.Step -
      REALTIME_PART1_differentmethods_B.pulse2deg2;

    /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' incorporates:
     *  Gain: '<S1>/deg2rad'
     */
    REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_tmp =
      ((REALTIME_PART1_differentmethods_P.deg2rad *
        REALTIME_PART1_differentmethods_B.edeg -
        REALTIME_PART1_differentmethods_P.den_Cz[1] *
        REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[0]) -
       REALTIME_PART1_differentmethods_P.den_Cz[2] *
       REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[1]) /
      REALTIME_PART1_differentmethods_P.den_Cz[0];

    /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' */
    rtb_DiscreteTransferFcn1 = (REALTIME_PART1_differentmethods_P.num_Cz[0] *
      REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_tmp +
      REALTIME_PART1_differentmethods_P.num_Cz[1] *
      REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[0]) +
      REALTIME_PART1_differentmethods_P.num_Cz[2] *
      REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[1];

    /* ZeroOrderHold: '<S1>/Zero-Order Hold1' */
    REALTIME_PART1_differentmethods_B.ZeroOrderHold1 = rtb_DiscreteTransferFcn1;

    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          REALTIME_PART1_differentmethods_P.AnalogOutput_RangeMode;
        parm.rangeidx = REALTIME_PART1_differentmethods_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &REALTIME_PART1_differentmethods_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&REALTIME_PART1_differentmethods_B.ZeroOrderHold1)),
                       &parm);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Sum1' */
    {
      {
        double time = REALTIME_PART1_differentmethods_M->Timing.t[1];
        void *pData = (void *)&REALTIME_PART1_differentmethods_B.edeg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1990686176U, time, pData, size);
      }
    }
  }
}

/* Model update function */
void REALTIME_PART1_differentmethods_update(void)
{
  if (REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' */
    REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[1] =
      REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[0];
    REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[0] =
      REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_tmp;
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
  if (!(++REALTIME_PART1_differentmethods_M->Timing.clockTick0)) {
    ++REALTIME_PART1_differentmethods_M->Timing.clockTickH0;
  }

  REALTIME_PART1_differentmethods_M->Timing.t[0] =
    REALTIME_PART1_differentmethods_M->Timing.clockTick0 *
    REALTIME_PART1_differentmethods_M->Timing.stepSize0 +
    REALTIME_PART1_differentmethods_M->Timing.clockTickH0 *
    REALTIME_PART1_differentmethods_M->Timing.stepSize0 * 4294967296.0;
  if (REALTIME_PART1_differentmethods_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART1_differentmethods_M->Timing.clockTick1)) {
      ++REALTIME_PART1_differentmethods_M->Timing.clockTickH1;
    }

    REALTIME_PART1_differentmethods_M->Timing.t[1] =
      REALTIME_PART1_differentmethods_M->Timing.clockTick1 *
      REALTIME_PART1_differentmethods_M->Timing.stepSize1 +
      REALTIME_PART1_differentmethods_M->Timing.clockTickH1 *
      REALTIME_PART1_differentmethods_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void REALTIME_PART1_differentmethods_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART1_differentmethods_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART1_differentmethods_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_differentmethods_P.AnalogOutput_Channels,
                     &REALTIME_PART1_differentmethods_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = REALTIME_PART1_differentmethods_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &REALTIME_PART1_differentmethods_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' */
  REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[0] =
    REALTIME_PART1_differentmethods_P.DiscreteTransferFcn1_InitialStates;
  REALTIME_PART1_differentmethods_DW.DiscreteTransferFcn1_states[1] =
    REALTIME_PART1_differentmethods_P.DiscreteTransferFcn1_InitialStates;
}

/* Model terminate function */
void REALTIME_PART1_differentmethods_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PART1_differentmethods_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART1_differentmethods_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_differentmethods_P.AnalogOutput_Channels,
                     &REALTIME_PART1_differentmethods_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  REALTIME_PART1_differentmethods_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PART1_differentmethods_update();
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
  REALTIME_PART1_differentmethods_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PART1_differentmethods_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PART1_differentmethods_T *REALTIME_PART1_differentmethods(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PART1_differentmethods_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PART1_differentmethods_M, 0,
                sizeof(RT_MODEL_REALTIME_PART1_differentmethods_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      REALTIME_PART1_differentmethods_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    REALTIME_PART1_differentmethods_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    REALTIME_PART1_differentmethods_M->Timing.sampleTimes =
      (&REALTIME_PART1_differentmethods_M->Timing.sampleTimesArray[0]);
    REALTIME_PART1_differentmethods_M->Timing.offsetTimes =
      (&REALTIME_PART1_differentmethods_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PART1_differentmethods_M->Timing.sampleTimes[0] = (0.001);
    REALTIME_PART1_differentmethods_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    REALTIME_PART1_differentmethods_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PART1_differentmethods_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(REALTIME_PART1_differentmethods_M,
             &REALTIME_PART1_differentmethods_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      REALTIME_PART1_differentmethods_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    REALTIME_PART1_differentmethods_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PART1_differentmethods_M, 5.0);
  REALTIME_PART1_differentmethods_M->Timing.stepSize0 = 0.001;
  REALTIME_PART1_differentmethods_M->Timing.stepSize1 = 0.05;

  /* External mode info */
  REALTIME_PART1_differentmethods_M->Sizes.checksums[0] = (3524018984U);
  REALTIME_PART1_differentmethods_M->Sizes.checksums[1] = (4176785887U);
  REALTIME_PART1_differentmethods_M->Sizes.checksums[2] = (2255340674U);
  REALTIME_PART1_differentmethods_M->Sizes.checksums[3] = (612861198U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    REALTIME_PART1_differentmethods_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PART1_differentmethods_M->extModeInfo,
      &REALTIME_PART1_differentmethods_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PART1_differentmethods_M->extModeInfo,
                        REALTIME_PART1_differentmethods_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PART1_differentmethods_M->extModeInfo, rtmGetTPtr
                (REALTIME_PART1_differentmethods_M));
  }

  REALTIME_PART1_differentmethods_M->solverInfoPtr =
    (&REALTIME_PART1_differentmethods_M->solverInfo);
  REALTIME_PART1_differentmethods_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PART1_differentmethods_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PART1_differentmethods_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PART1_differentmethods_M->blockIO = ((void *)
    &REALTIME_PART1_differentmethods_B);
  (void) memset(((void *) &REALTIME_PART1_differentmethods_B), 0,
                sizeof(B_REALTIME_PART1_differentmethods_T));

  /* parameters */
  REALTIME_PART1_differentmethods_M->defaultParam = ((real_T *)
    &REALTIME_PART1_differentmethods_P);

  /* states (dwork) */
  REALTIME_PART1_differentmethods_M->dwork = ((void *)
    &REALTIME_PART1_differentmethods_DW);
  (void) memset((void *)&REALTIME_PART1_differentmethods_DW, 0,
                sizeof(DW_REALTIME_PART1_differentmethods_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PART1_differentmethods_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PART1_differentmethods_M->Sizes.numContStates = (0);/* Number of continuous states */
  REALTIME_PART1_differentmethods_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PART1_differentmethods_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PART1_differentmethods_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PART1_differentmethods_M->Sizes.numSampTimes = (2);/* Number of sample times */
  REALTIME_PART1_differentmethods_M->Sizes.numBlocks = (11);/* Number of blocks */
  REALTIME_PART1_differentmethods_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  REALTIME_PART1_differentmethods_M->Sizes.numBlockPrms = (23);/* Sum of parameter "widths" */
  return REALTIME_PART1_differentmethods_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
