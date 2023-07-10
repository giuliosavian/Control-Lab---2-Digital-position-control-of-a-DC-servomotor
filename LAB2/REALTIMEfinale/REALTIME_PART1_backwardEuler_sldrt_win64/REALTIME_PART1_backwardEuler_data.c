/*
 * REALTIME_PART1_backwardEuler_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_backwardEuler".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jun  7 09:04:03 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART1_backwardEuler.h"
#include "REALTIME_PART1_backwardEuler_private.h"

/* Block parameters (default storage) */
P_REALTIME_PART1_backwardEuler_T REALTIME_PART1_backwardEuler_P = {
  /* Variable: ctrl
   * Referenced by:
   *   '<S1>/derivative gain'
   *   '<S1>/integral gain'
   *   '<S1>/proportional gain'
   */
  {
    0.15,
    0.1,
    6.0,
    0.59115503379889756,
    1.0226419600694172,
    33.83207256390159,

    { -0.082194052794013, -0.081886754380687307 },
    8.61899149883295,
    0.23911664249305309,
    8.373760265906629,
    0.016196068380760022,
    0.09717641028456013,
    86.170709963311879,
    0.135621993870715,
    0.00738943792248622
  },

  /* Variable: sens
   * Referenced by: '<Root>/pulse2deg2'
   */
  {
    {
      0.5
    },

    {
      4096.0,
      0.087890625,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    }
  },

  /* Variable: K_w
   * Referenced by: '<S1>/K_w '
   */
  15.0,

  /* Variable: deg2rad
   * Referenced by: '<S1>/deg2rad'
   */
  0.017453292519943295,

  /* Variable: step_size
   * Referenced by: '<Root>/Step'
   */
  360.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: [1 -1]
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },

  /* Expression: [(Tl+T) -Tl]
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 0.024778875844972438, -0.01477887584497244 },

  /* Expression: 0
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0
};
