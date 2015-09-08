int checkBox( ref_speed_box, speed_box, variation)
{
  int box_stat;

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
    box_stat = 1;

    /* BOX present */
  } else if (speed_box == 0.0) {
    box_stat = -1;

    /*  Nothing present */
  } else {
    box_stat = 0;

    /* Noise present */
  }

  return box_stat;
}

