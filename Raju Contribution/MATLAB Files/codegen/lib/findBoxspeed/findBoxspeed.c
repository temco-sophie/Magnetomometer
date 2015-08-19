/*
 * findBoxspeed.c
 *
 * Code generation for function 'findBoxspeed'
 *
 * C source code generated on: Wed Aug 19 03:53:34 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findBoxspeed.h"

/* Function Definitions */
real_T findBoxspeed(const real_T test_obtData[222])
{
  real_T speed_box;
  real_T contOne;
  real_T temp[222];
  int32_T i;

  /*  It automatically calculates the box speed i.e target speed that lies in */
  /*  opto coverage. */
  /* INPUT test_obtData  data obtained in matrix form */
  /* OUTPUT speed_box  scalar variable equivalent to speed of box. */
  contOne = 0.0;
  memset(&temp[0], 0, 222U * sizeof(real_T));
  for (i = 0; i < 221; i++) {
    if ((test_obtData[i] == 1.0) && (test_obtData[1 + i] == 1.0)) {
      /* Continous check */
      if (1 + i == 221) {
        /* if last element has 100            */
        contOne += 2.0;
        temp[i] = contOne;
      } else {
        contOne++;
      }
    }

    if ((contOne > 0.0) && (test_obtData[i] == 1.0) && (test_obtData[1 + i] ==
         0.0)) {
      /* Ending check */
      contOne++;
    }

    if ((contOne == 0.0) && (test_obtData[i] == 1.0) && (test_obtData[1 + i] ==
         0.0)) {
      /* Just for single '1' */
      contOne = 1.0;
    }

    if ((contOne > 0.0) && (test_obtData[i] == 0.0)) {
      temp[i] = contOne;
      contOne = 0.0;
    }
  }

  speed_box = temp[0];
  for (i = 1; i + 1 < 223; i++) {
    if (temp[i] > speed_box) {
      speed_box = temp[i];
    }
  }

  return speed_box;
}

/* End of code generation (findBoxspeed.c) */
