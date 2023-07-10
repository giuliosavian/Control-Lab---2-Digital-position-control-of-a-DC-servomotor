/*
 * REALTIME_PART2_nominal_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART2_nominal".
 *
 * Model version              : 1.27
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  3 12:01:22 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART2_nominal.h"
#include "REALTIME_PART2_nominal_private.h"

/* Block parameters (default storage) */
P_REALTIME_PART2_nominal_T REALTIME_PART2_nominal_P = {
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
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.77823815141597852, -144.12146926400638 },

  /* Variable: H0
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.0, 1.0 },

  /* Variable: N_u
   * Referenced by: '<S1>/Input feedforward'
   */
  0.0,

  /* Variable: N_x
   * Referenced by: '<S1>/State feedforward	'
   */
  { 1.0, -0.0 },

  /* Variable: PHI
   * Referenced by: '<Root>/Discrete State-Space'
   */
  0.00021219218923342336,

  /* Variable: deg2rad
   * Referenced by:
   *   '<Root>/deg2rad'
   *   '<S1>/deg2rad'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<Root>/degs2rpm'
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

  /* Expression: [0 0;0 0]
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space'
   */
  0.0,

  /* Expression: J0(:,2)
   * Referenced by: '<Root>/Gain'
   */
  { 1.0, 144.15205720460713 },

  /* Expression: K'
   * Referenced by: '<S1>/State feedback'
   */
  { 8.6926845210080419, 0.11385377405921741 },

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Computed Parameter: SpeedFilter_A
   * Referenced by: '<Root>/Speed Filter'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: SpeedFilter_C
   * Referenced by: '<Root>/Speed Filter'
   */
  { 15791.367041742973, 0.0 }
};
