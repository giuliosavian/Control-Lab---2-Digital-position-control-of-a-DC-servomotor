/*
 * REALTIME_PART1_discretefeedforward_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_discretefeedforward".
 *
 * Model version              : 1.40
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jun  7 09:22:35 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REALTIME_PART1_discretefeedforward_types_h_
#define RTW_HEADER_REALTIME_PART1_discretefeedforward_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_
#define DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_

typedef struct {
  real_T N1;
  real_T eta1;
  real_T N2;
  real_T J72;
  real_T eta2;
  real_T N;
  real_T eta;
  real_T J;
} struct_tqEcQv8wI4rPb7WqAAnbuH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ux5kslWm198cPY7QGvAcLC_
#define DEFINED_TYPEDEF_FOR_struct_ux5kslWm198cPY7QGvAcLC_

typedef struct {
  real_T ts5;
  real_T Mp;
  real_T alpha;
  real_T damping_factor;
  real_T phi_m;
  real_T w_gc;
  creal_T frq_resp;
  real_T Delta_K;
  real_T Delta_phi;
  real_T Kp;
  real_T Td;
  real_T Ti;
  real_T Ki;
  real_T Kd;
  real_T T_L;
} struct_ux5kslWm198cPY7QGvAcLC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_
#define DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_

typedef struct {
  real_T Rs;
} struct_vHPMdAr9HfDgWNbG6U3SfC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_
#define DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_

typedef struct {
  real_T ppr;
  real_T pulse2deg;
  real_T pulse2rad;
  real_T deg2pulse;
  real_T rad2pulse;
} struct_nZqFUEOh71pPhzsMP64FWD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_
#define DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_

typedef struct {
  real_T R;
  real_T V;
  real_T th_deg;
  real_T th;
} struct_DqRrFctOcoTwJhkxMXTGZG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_
#define DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
} struct_t4jfYKvXkqvqbOrnXV9flF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_
#define DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
} struct_8LnTg2HasR61N4e63tMdJ;

#endif

/* Parameters (default storage) */
typedef struct P_REALTIME_PART1_discretefeedforward_T_
  P_REALTIME_PART1_discretefeedforward_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_REALTIME_PART1_discretefeedforward_T
  RT_MODEL_REALTIME_PART1_discretefeedforward_T;

#endif              /* RTW_HEADER_REALTIME_PART1_discretefeedforward_types_h_ */
