/*
 * REALTIME_PART2_robust_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART2_robust".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  3 12:13:29 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART2_robust.h"
#include "REALTIME_PART2_robust_private.h"

/* Block parameters (default storage) */
P_REALTIME_PART2_robust_T REALTIME_PART2_robust_P = {
  /* Variable: ctrl
   * Referenced by:
   *   '<S1>/K_w'
   *   '<S1>/K_w1'
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
    0.00738943792248622,
    0.0
  },

  /* Variable: sens
   * Referenced by: '<Root>/pulse2deg'
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

  /* Variable: GAMMA
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 2.6239169346461475, -10.026706169945816 },

  /* Variable: H0
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.0, 1.0 },

  /* Variable: Ki
   * Referenced by: '<S1>/High-pass filter1'
   */
  3.312677243586271,

  /* Variable: N_u
   * Referenced by:
   *   '<S1>/Input feedforward'
   *   '<S1>/Input feedforward1'
   */
  0.0,

  /* Variable: N_x
   * Referenced by:
   *   '<S1>/State feedforward	'
   *   '<S1>/State feedforward	1'
   */
  { 1.0, -0.0 },

  /* Variable: PHI
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  0.00021219218923340666,

  /* Variable: deg2rad
   * Referenced by:
   *   '<Root>/deg2rad'
   *   '<S1>/deg2rad'
   *   '<S1>/deg2rad1'
   *   '<S1>/deg2rads1'
   *   '<S1>/deg2rads2'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<Root>/degs2rpm1'
   */
  0.16666666666666666,

  /* Variable: step_size
   * Referenced by: '<Root>/Step'
   */
  50.0,

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

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
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

  /* Expression: 0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: [Ke(2),Ke(3)].'
   * Referenced by: '<S1>/State feedback'
   */
  { 9.4697492045406673, 0.18562351754206197 },

  /* Expression: [1 0]
   * Referenced by: '<S1>/High-pass filter1'
   */
  { 1.0, 0.0 },

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay3'
   */
  0.0,

  /* Expression: [Ke(2),Ke(3)].'
   * Referenced by: '<S1>/State feedback1'
   */
  { 9.4697492045406673, 0.18562351754206197 },

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.16563386217931356,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Saturation1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation1'
   */
  -10.0,

  /* Computed Parameter: SpeedFilter1_A
   * Referenced by: '<Root>/Speed Filter1'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: SpeedFilter1_C
   * Referenced by: '<Root>/Speed Filter1'
   */
  { 15791.367041742973, 0.0 },

  /* Expression: [0 0;0 0]
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  0.0,

  /* Expression: J0(:,2)
   * Referenced by: '<Root>/Gain'
   */
  { 1.0, 10.028834210232345 },

  /* Expression: 0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay2'
   */
  0.0,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  0U
};
