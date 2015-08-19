/*
 * findCV.c
 *
 * Code generation for function 'findCV'
 *
 * C source code generated on: Wed Aug 19 05:59:18 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkInitialState.h"
#include "findCV.h"
#include "mean.h"

/* Function Definitions */
real_T findCV(const emxArray_real_T *resultant)
{
  real_T cvVal;
  real_T meanVal;
  int32_T resultant_idx_0;
  int32_T d;
  real_T y;
  int32_T ix;
  real_T xbar;
  int32_T k;
  int32_T exitg2;
  real_T r;
  int32_T exitg1;

  /*  This function calculates the coefficient of variation (CV) */
  /*  INPUT resultant -> input vector */
  /*  OUTPUT cvVal -> scalar, coefficient of variation value */
  meanVal = mean(resultant);
  resultant_idx_0 = resultant->size[0];
  if (resultant_idx_0 > 1) {
    resultant_idx_0 = resultant->size[0];
    d = resultant_idx_0 - 1;
  } else {
    d = resultant->size[0];
  }

  resultant_idx_0 = resultant->size[0];
  if (resultant_idx_0 == 0) {
    y = rtNaN;
  } else {
    ix = 0;
    xbar = resultant->data[0];
    k = 0;
    do {
      exitg2 = 0;
      resultant_idx_0 = resultant->size[0];
      if (k <= resultant_idx_0 - 2) {
        ix++;
        xbar += resultant->data[ix];
        k++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    resultant_idx_0 = resultant->size[0];
    xbar /= (real_T)resultant_idx_0;
    ix = 0;
    r = resultant->data[0] - xbar;
    y = r * r;
    k = 0;
    do {
      exitg1 = 0;
      resultant_idx_0 = resultant->size[0];
      if (k <= resultant_idx_0 - 2) {
        ix++;
        r = resultant->data[ix] - xbar;
        y += r * r;
        k++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    y /= (real_T)d;
  }

  /* standard deviation */
  cvVal = sqrt(y) / meanVal;

  /* test_obtData */
  return cvVal;
}

/* End of code generation (findCV.c) */
