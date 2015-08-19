/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Wed Aug 19 05:59:18 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkInitialState.h"
#include "mean.h"

/* Function Definitions */
real_T mean(const emxArray_real_T *x)
{
  real_T y;
  int32_T k;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  y /= (real_T)x->size[0];
  return y;
}

/* End of code generation (mean.c) */
