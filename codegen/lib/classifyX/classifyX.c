/*
 * File: classifyX.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 01-Jan-2021 22:13:26
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "classifyX.h"
#include "CompactClassificationTree.h"

/* Function Definitions */

/*
 * CLASSIFYX Classify using KNN Model
 *   CLASSIFYX classifies the measurements in X
 *   using the KNN model in the file myKNN.mat, and then
 *   returns class labels in label.
 * Arguments    : const float X[8]
 * Return Type  : double
 */
double classifyX(const float X[8])
{
  double CompactMdl_ClassNames[4];
  bool CompactMdl_ClassLogicalIndices[4];
  double CompactMdl_CutPoint[9];
  static const double dv0[9] = { 871.08999999999992, 550.78, 1230.47, 0.0, 0.0,
    0.0, 1554.685, 0.0, 0.0 };

  int i;
  static const signed char iv0[5] = { 3, 4, 5, 7, 8 };

  signed char b_I[16];
  static const double CompactMdl_CutVar[9] = { 6.0, 6.0, 6.0, 0.0, 0.0, 0.0, 6.0,
    0.0, 0.0 };

  static const double CompactMdl_Children[18] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0, 9.0, 0.0, 0.0, 0.0, 0.0 };

  static const double CompactMdl_ClassProb[36] = { 0.27282728272827245,
    0.97844827586206906, 0.031019202363367734, 0.0, 1.0, 0.036363636363636279,
    0.028446389496717663, 0.0098522167487684487, 0.043307086614173151,
    0.23322332233223336, 0.0, 0.31314623338257019, 0.0, 0.0, 0.95454545454545459,
    0.0043763676148796393, 0.0049261083743842244, 0.00393700787401574,
    0.24092409240924109, 0.02155172413793098, 0.31610044313146235, 1.0, 0.0,
    0.00909090909090907, 0.46389496717724293, 0.98522167487684731,
    0.047244094488188892, 0.25302530253025313, 0.0, 0.33973412112259965, 0.0,
    0.0, 0.0, 0.50328227571115969, 0.0, 0.90551181102362233 };

  double CompactMdl_Cost[16];
  CompactMdl_ClassNames[0] = 1.0;
  CompactMdl_ClassLogicalIndices[0] = true;
  CompactMdl_ClassNames[1] = 2.0;
  CompactMdl_ClassLogicalIndices[1] = true;
  CompactMdl_ClassNames[2] = 3.0;
  CompactMdl_ClassLogicalIndices[2] = true;
  CompactMdl_ClassNames[3] = 4.0;
  CompactMdl_ClassLogicalIndices[3] = true;
  memcpy(&CompactMdl_CutPoint[0], &dv0[0], 9U * sizeof(double));
  for (i = 0; i < 5; i++) {
    CompactMdl_CutPoint[iv0[i]] = rtNaN;
  }

  for (i = 0; i < 16; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[5] = 1;
  b_I[10] = 1;
  b_I[15] = 1;
  for (i = 0; i < 16; i++) {
    CompactMdl_Cost[i] = 1.0 - (double)b_I[i];
  }

  return c_CompactClassificationTree_pre(CompactMdl_CutVar, CompactMdl_Children,
    CompactMdl_ClassProb, CompactMdl_CutPoint, CompactMdl_ClassNames,
    CompactMdl_ClassLogicalIndices, CompactMdl_Cost, X);
}

/*
 * File trailer for classifyX.c
 *
 * [EOF]
 */
