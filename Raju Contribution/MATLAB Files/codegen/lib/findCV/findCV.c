/*
 * findCV.c
 *
 * Code generation for function 'findCV'
 *
 * C source code generated on: Fri Sep 25 12:41:36 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findCV.h"

/* Function Definitions */
real_T findCV(const real_T resultant_data[189], const int32_T resultant_size[1])
{
  real_T cvVal;
  real_T y;
  int32_T k;
  int32_T d;
  real_T b_y;
  int32_T ix;
  real_T xbar;
  real_T r;

  /*  This function calculates the coefficient of variation (CV) */
  /*  INPUT resultant -> input vector */
  /*  OUTPUT cvVal -> scalar, coefficient of variation value */
  /*  Finding MEAN */
  if (resultant_size[0] == 0) {
    y = 0.0;
  } else {
    y = resultant_data[0];
    for (k = 2; k <= resultant_size[0]; k++) {
      y += resultant_data[k - 1];
    }
  }

  /*  Finding standard deviation */
  if (resultant_size[0] > 1) {
    d = resultant_size[0] - 1;
  } else {
    d = resultant_size[0];
  }

  if (resultant_size[0] == 0) {
    b_y = rtNaN;
  } else {
    ix = 0;
    xbar = resultant_data[0];
    for (k = 0; k <= resultant_size[0] - 2; k++) {
      ix++;
      xbar += resultant_data[ix];
    }

    xbar /= (real_T)resultant_size[0];
    ix = 0;
    r = resultant_data[0] - xbar;
    b_y = r * r;
    for (k = 0; k <= resultant_size[0] - 2; k++) {
      ix++;
      r = resultant_data[ix] - xbar;
      b_y += r * r;
    }

    b_y /= (real_T)d;
  }

  /* standard deviation */
  /*  Finding Coeeficient of variation */
  cvVal = sqrt(b_y) / (y / (real_T)resultant_size[0]);

  /* test_obtData */
  return cvVal;
}

/* End of code generation (findCV.c) */
