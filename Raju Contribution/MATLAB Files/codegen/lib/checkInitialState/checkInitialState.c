/*
 * checkInitialState.c
 *
 * Code generation for function 'checkInitialState'
 *
 * C source code generated on: Wed Aug 19 05:59:18 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkInitialState.h"
#include "mean.h"
#include "checkInitialState_emxutil.h"
#include "findCV.h"

/* Function Definitions */
void checkInitialState(const real_T resultant[222], real_T speed_box, real_T
  cvVal_all[3], real_T avg_all[3])
{
  int32_T i0;
  int32_T i1;
  real_T y;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  real_T b_y;
  emxArray_real_T *b_resultant;
  real_T resultant_data[222];
  int32_T resultant_size[1];
  emxArray_real_T b_resultant_data;
  emxArray_real_T *c_resultant;
  real_T c_resultant_data[222];
  int32_T b_resultant_size[1];
  emxArray_real_T d_resultant_data;
  if (50.0 + speed_box > 222.0) {
    i0 = 0;
    i1 = -1;
  } else {
    i0 = (int32_T)(50.0 + speed_box) - 1;
    i1 = 221;
  }

  /*  This function calculates the coefficient of variation (CV) */
  /*  INPUT resultant -> input vector */
  /*  OUTPUT cvVal -> scalar, coefficient of variation value */
  y = resultant[0];
  ix = 0;
  xbar = resultant[0];
  for (k = 0; k < 49; k++) {
    y += resultant[k + 1];
    ix++;
    xbar += resultant[ix];
  }

  xbar /= 50.0;
  ix = 0;
  r = resultant[0] - xbar;
  b_y = r * r;
  for (k = 0; k < 49; k++) {
    ix++;
    r = resultant[ix] - xbar;
    b_y += r * r;
  }

  emxInit_real_T(&b_resultant, 1);
  b_y /= 49.0;

  /* standard deviation */
  /* test_obtData */
  ix = b_resultant->size[0];
  b_resultant->size[0] = (int32_T)floor(speed_box) + 1;
  emxEnsureCapacity((emxArray__common *)b_resultant, ix, (int32_T)sizeof(real_T));
  k = (int32_T)floor(speed_box);
  for (ix = 0; ix <= k; ix++) {
    b_resultant->data[ix] = resultant[(int32_T)(50.0 + (real_T)ix) - 1];
  }

  xbar = findCV(b_resultant);
  resultant_size[0] = (i1 - i0) + 1;
  k = i1 - i0;
  emxFree_real_T(&b_resultant);
  for (ix = 0; ix <= k; ix++) {
    resultant_data[ix] = resultant[i0 + ix];
  }

  b_resultant_data.data = (real_T *)&resultant_data;
  b_resultant_data.size = (int32_T *)&resultant_size;
  b_resultant_data.allocatedSize = 222;
  b_resultant_data.numDimensions = 1;
  b_resultant_data.canFreeData = FALSE;
  r = findCV(&b_resultant_data);
  cvVal_all[0] = sqrt(b_y) / (y / 50.0);
  cvVal_all[1] = xbar;
  cvVal_all[2] = r;
  y = resultant[0];
  for (k = 0; k < 49; k++) {
    y += resultant[k + 1];
  }

  emxInit_real_T(&c_resultant, 1);
  ix = c_resultant->size[0];
  c_resultant->size[0] = (int32_T)floor(speed_box) + 1;
  emxEnsureCapacity((emxArray__common *)c_resultant, ix, (int32_T)sizeof(real_T));
  k = (int32_T)floor(speed_box);
  for (ix = 0; ix <= k; ix++) {
    c_resultant->data[ix] = resultant[(int32_T)(50.0 + (real_T)ix) - 1];
  }

  xbar = mean(c_resultant);
  b_resultant_size[0] = (i1 - i0) + 1;
  k = i1 - i0;
  emxFree_real_T(&c_resultant);
  for (i1 = 0; i1 <= k; i1++) {
    c_resultant_data[i1] = resultant[i0 + i1];
  }

  d_resultant_data.data = (real_T *)&c_resultant_data;
  d_resultant_data.size = (int32_T *)&b_resultant_size;
  d_resultant_data.allocatedSize = 222;
  d_resultant_data.numDimensions = 1;
  d_resultant_data.canFreeData = FALSE;
  r = mean(&d_resultant_data);
  avg_all[0] = y / 50.0;
  avg_all[1] = xbar;
  avg_all[2] = r;
}

/* End of code generation (checkInitialState.c) */
