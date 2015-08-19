/*
 * checkInitialState_emxutil.h
 *
 * Code generation for function 'checkInitialState_emxutil'
 *
 * C source code generated on: Wed Aug 19 05:59:18 2015
 *
 */

#ifndef __CHECKINITIALSTATE_EMXUTIL_H__
#define __CHECKINITIALSTATE_EMXUTIL_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "checkInitialState_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
#endif
/* End of code generation (checkInitialState_emxutil.h) */
