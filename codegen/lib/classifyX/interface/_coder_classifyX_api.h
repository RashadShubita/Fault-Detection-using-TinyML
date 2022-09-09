/*
 * File: _coder_classifyX_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 01-Jan-2021 22:13:26
 */

#ifndef _CODER_CLASSIFYX_API_H
#define _CODER_CLASSIFYX_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_classifyX_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T classifyX(real32_T X[8]);
extern void classifyX_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void classifyX_atexit(void);
extern void classifyX_initialize(void);
extern void classifyX_terminate(void);
extern void classifyX_xil_shutdown(void);
extern void classifyX_xil_terminate(void);

#endif

/*
 * File trailer for _coder_classifyX_api.h
 *
 * [EOF]
 */
