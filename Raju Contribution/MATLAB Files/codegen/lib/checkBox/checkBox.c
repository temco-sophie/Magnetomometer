/*
 * checkBox.c
 *
 * Code generation for function 'checkBox'
 *
 * C source code generated on: Wed Aug 19 03:58:12 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "checkBox.h"

/* Function Definitions */
real_T checkBox(real_T ref_speed_box, real_T speed_box, real_T variation)
{
  real_T box_stat;

  /*  It detects whether the target is desired box or not. */
  /*  Here considered maximum opto ON (on our predifined range, min_speed to max_speed,) */
  /*  time is our desired box. */
  /* INPUT ref_speed_box -> the reference speed of box, we set usual speed of */
  /* normal box */
  /*       speed_box -> speed of box calculated */
  /*       variation -> possible variation in up and down in box speed */
  /*  OUTPUT box_stat -> 1 BOX present,-1 Nothing present and 0 Noise present */
  if ((speed_box > ref_speed_box - variation) && (speed_box < ref_speed_box +
       variation)) {
    box_stat = 1.0;

    /* BOX present */
  } else if (speed_box == 0.0) {
    box_stat = -1.0;

    /*  Nothing present */
  } else {
    box_stat = 0.0;

    /* Noise present */
  }

  return box_stat;
}

/* End of code generation (checkBox.c) */
