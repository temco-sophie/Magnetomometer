/*
 * checkMetal.c
 *
 * Code generation for function 'checkMetal'
 *
 * C source code generated on: Wed Aug 19 06:19:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkMetal.h"

/* Function Definitions */
void checkMetal(real_T cvVal, real_T ref_cv, const real_T cvVal_all[3], const
                real_T avg_all[3], real_T *metal_stat, real_T flag_stat[2])
{
  int32_T flag_initial;
  int32_T flag_last;

  /*  It checks the CV value and decides the metal presence. */
  /*  INPUT cvVal -> calculated cv value */
  /*        ref_cv -> reference cv value for no metal case */
  /*        variation_cv -> used for acceptable variation for tolerance */
  /*  OUTPUT metal_stat -> 1 BOX present and 0 Noise present */
  /*      max_cv=ref_cv-variation_cv; %#codegen */
  flag_initial = 0;
  flag_last = 0;
  if ((cvVal >= ref_cv) && (avg_all[1] > avg_all[0])) {
    *metal_stat = 1.0;

    /* BOX present */
    /*      disp('CONTAMINATED BOX--METAL DETECTED'); */
  } else {
    *metal_stat = 0.0;

    /*     disp('CLEAN BOX-- NO METAL PRESENT'); */
  }

  if ((cvVal_all[0] > cvVal_all[1]) || (avg_all[0] > avg_all[1])) {
    flag_initial = 1;
  } else {
    if (avg_all[2] > avg_all[1]) {
      flag_last = 1;
    }
  }

  flag_stat[0] = flag_initial;
  flag_stat[1] = flag_last;
}

/* End of code generation (checkMetal.c) */
