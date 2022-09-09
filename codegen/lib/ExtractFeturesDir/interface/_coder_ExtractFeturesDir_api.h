/*
 * File: _coder_ExtractFeturesDir_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

#ifndef _CODER_EXTRACTFETURESDIR_API_H
#define _CODER_EXTRACTFETURESDIR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_ExtractFeturesDir_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void ExtractFeturesDir(real32_T DataFFT[1024], real32_T BufferLen,
  real32_T Fs, real32_T *pks1, real32_T *pks2, real32_T *pks3, real32_T *locs1,
  real32_T *locs2, real32_T *locs3);
extern void ExtractFeturesDir_api(const mxArray * const prhs[3], int32_T nlhs,
  const mxArray *plhs[6]);
extern void ExtractFeturesDir_atexit(void);
extern void ExtractFeturesDir_initialize(void);
extern void ExtractFeturesDir_terminate(void);
extern void ExtractFeturesDir_xil_shutdown(void);
extern void ExtractFeturesDir_xil_terminate(void);

#endif

/*
 * File trailer for _coder_ExtractFeturesDir_api.h
 *
 * [EOF]
 */
