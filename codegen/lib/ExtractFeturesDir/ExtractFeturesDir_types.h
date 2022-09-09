/*
 * File: ExtractFeturesDir_types.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

#ifndef EXTRACTFETURESDIR_TYPES_H
#define EXTRACTFETURESDIR_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  float *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/
#endif

/*
 * File trailer for ExtractFeturesDir_types.h
 *
 * [EOF]
 */
