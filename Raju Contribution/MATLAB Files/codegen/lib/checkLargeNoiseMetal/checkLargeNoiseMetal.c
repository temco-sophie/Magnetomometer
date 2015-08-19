/*
 * checkLargeNoiseMetal.c
 *
 * Code generation for function 'checkLargeNoiseMetal'
 *
 * C source code generated on: Wed Aug 19 06:21:38 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkLargeNoiseMetal.h"

/* Function Definitions */
real_T checkLargeNoiseMetal(real_T cvVal, real_T max_cv)
{
  real_T largenoisemetal_stat;

  /*  It checks the CV value and decides the presence of large metal around */
  if (cvVal > max_cv) {
    largenoisemetal_stat = 1.0;

    /* Large metal presence */
  } else {
    largenoisemetal_stat = 0.0;

    /* No large metal */
  }

  return largenoisemetal_stat;
}

/* End of code generation (checkLargeNoiseMetal.c) */
