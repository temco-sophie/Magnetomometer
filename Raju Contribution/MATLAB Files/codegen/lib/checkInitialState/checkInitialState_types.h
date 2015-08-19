/*
 * checkInitialState_types.h
 *
 * Code generation for function 'checkInitialState'
 *
 * C source code generated on: Wed Aug 19 05:59:14 2015
 *
 */

#ifndef __CHECKINITIALSTATE_TYPES_H__
#define __CHECKINITIALSTATE_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef struct_emxArray_real_T_222
#define struct_emxArray_real_T_222
struct emxArray_real_T_222
{
    real_T data[222];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_222*/
#ifndef typedef_emxArray_real_T_222
#define typedef_emxArray_real_T_222
typedef struct emxArray_real_T_222 emxArray_real_T_222;
#endif /*typedef_emxArray_real_T_222*/

#endif
/* End of code generation (checkInitialState_types.h) */
