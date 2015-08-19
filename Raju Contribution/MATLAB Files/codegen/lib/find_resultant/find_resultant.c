/*
 * find_resultant.c
 *
 * Code generation for function 'find_resultant'
 *
 * C source code generated on: Wed Aug 19 04:03:12 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "find_resultant.h"
#include "power.h"

/* Function Definitions */
void find_resultant(const real_T test_obtData[1776], real_T resultant[222])
{
  real_T dv0[222];
  real_T S2_nm[222];
  real_T dv1[222];
  real_T dv2[222];
  int32_T i;
  real_T dv3[222];
  real_T dv4[222];
  real_T b_S2_nm[222];

  /*  This function is to calcutate resultant of 6 sensor data. We have used */
  /*  square root of x1, y1 and z1 and similarly for x2, y2 and z2. and finally */
  /*  taking square root of two obtained result. */
  /*  INPUT test_obtData -> matrix containing all data */
  /*  OUTPUT resultant -> 1 column resultant vector */
  power(*(real_T (*)[222])&test_obtData[444], dv0);
  power(*(real_T (*)[222])&test_obtData[666], S2_nm);
  power(*(real_T (*)[222])&test_obtData[888], dv1);
  for (i = 0; i < 222; i++) {
    dv2[i] = (dv0[i] + S2_nm[i]) + dv1[i];
  }

  power(*(real_T (*)[222])&test_obtData[1110], dv0);
  power(*(real_T (*)[222])&test_obtData[1332], S2_nm);
  power(*(real_T (*)[222])&test_obtData[1554], dv1);
  for (i = 0; i < 222; i++) {
    dv3[i] = (dv0[i] + S2_nm[i]) + dv1[i];
  }

  b_power(dv3, S2_nm);
  b_power(dv2, dv4);
  power(dv4, dv0);
  memcpy(&b_S2_nm[0], &S2_nm[0], 222U * sizeof(real_T));
  power(b_S2_nm, S2_nm);
  for (i = 0; i < 222; i++) {
    dv1[i] = dv0[i] + S2_nm[i];
  }

  b_power(dv1, resultant);
}

/* End of code generation (find_resultant.c) */
