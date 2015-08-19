/*
 * power.c
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Wed Aug 19 04:03:12 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "find_resultant.h"
#include "power.h"

/* Function Definitions */
void b_power(const real_T a[222], real_T y[222])
{
  int32_T k;
  for (k = 0; k < 222; k++) {
    y[k] = sqrt(a[k]);
  }
}

void power(const real_T a[222], real_T y[222])
{
  int32_T k;
  for (k = 0; k < 222; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
