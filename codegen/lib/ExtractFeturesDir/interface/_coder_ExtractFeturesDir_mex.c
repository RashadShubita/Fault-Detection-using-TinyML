/*
 * File: _coder_ExtractFeturesDir_mex.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include "_coder_ExtractFeturesDir_api.h"
#include "_coder_ExtractFeturesDir_mex.h"

/* Function Declarations */
static void ExtractFeturesDir_mexFunction(int32_T nlhs, mxArray *plhs[6],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[6]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void ExtractFeturesDir_mexFunction(int32_T nlhs, mxArray *plhs[6],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[6];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        17, "ExtractFeturesDir");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "ExtractFeturesDir");
  }

  /* Call the function. */
  ExtractFeturesDir_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(ExtractFeturesDir_atexit);

  /* Module initialization. */
  ExtractFeturesDir_initialize();

  /* Dispatch the entry-point. */
  ExtractFeturesDir_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  ExtractFeturesDir_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_ExtractFeturesDir_mex.c
 *
 * [EOF]
 */
