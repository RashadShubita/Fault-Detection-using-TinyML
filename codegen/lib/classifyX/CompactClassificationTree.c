/*
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 01-Jan-2021 22:13:26
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "classifyX.h"
#include "CompactClassificationTree.h"

/* Function Definitions */

/*
 * Arguments    : const double obj_CutVar[9]
 *                const double obj_Children[18]
 *                const double obj_ClassProb[36]
 *                const double obj_CutPoint[9]
 *                const double obj_ClassNames[4]
 *                const bool obj_ClassLogicalIndices[4]
 *                const double obj_Cost[16]
 *                const float X[8]
 * Return Type  : double
 */
double c_CompactClassificationTree_pre(const double obj_CutVar[9], const double
  obj_Children[18], const double obj_ClassProb[36], const double obj_CutPoint[9],
  const double obj_ClassNames[4], const bool obj_ClassLogicalIndices[4], const
  double obj_Cost[16], const float X[8])
{
  double m;
  int exitg1;
  int i0;
  int partialTrueCount;
  static const signed char pruneList[9] = { 3, 1, 3, 0, 0, 0, 2, 0, 0 };

  int trueCount;
  double scores[4];
  signed char tmp_data[4];
  double unusedU4[4];
  bool exitg2;
  double d0;
  m = 1.0;
  do {
    exitg1 = 0;
    i0 = (int)m;
    partialTrueCount = i0 - 1;
    if ((pruneList[partialTrueCount] <= 0) || rtIsNaNF(X[(int)
         obj_CutVar[partialTrueCount] - 1])) {
      exitg1 = 1;
    } else if (X[(int)obj_CutVar[(int)m - 1] - 1] < obj_CutPoint[(int)m - 1]) {
      m = obj_Children[((int)m - 1) << 1];
    } else {
      m = obj_Children[1 + (((int)m - 1) << 1)];
    }
  } while (exitg1 == 0);

  trueCount = 0;
  scores[0] = 0.0;
  if (obj_ClassLogicalIndices[0]) {
    trueCount = 1;
  }

  scores[1] = 0.0;
  if (obj_ClassLogicalIndices[1]) {
    trueCount++;
  }

  scores[2] = 0.0;
  if (obj_ClassLogicalIndices[2]) {
    trueCount++;
  }

  scores[3] = 0.0;
  if (obj_ClassLogicalIndices[3]) {
    trueCount++;
  }

  partialTrueCount = 0;
  if (obj_ClassLogicalIndices[0]) {
    tmp_data[0] = 1;
    partialTrueCount = 1;
  }

  if (obj_ClassLogicalIndices[1]) {
    tmp_data[partialTrueCount] = 2;
    partialTrueCount++;
  }

  if (obj_ClassLogicalIndices[2]) {
    tmp_data[partialTrueCount] = 3;
    partialTrueCount++;
  }

  if (obj_ClassLogicalIndices[3]) {
    tmp_data[partialTrueCount] = 4;
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    scores[tmp_data[partialTrueCount] - 1] = obj_ClassProb[(i0 + 9 *
      partialTrueCount) - 1];
  }

  for (i0 = 0; i0 < 4; i0++) {
    partialTrueCount = i0 << 2;
    unusedU4[i0] = ((scores[0] * obj_Cost[partialTrueCount] + scores[1] *
                     obj_Cost[1 + partialTrueCount]) + scores[2] * obj_Cost[2 +
                    partialTrueCount]) + scores[3] * obj_Cost[3 +
      partialTrueCount];
  }

  if (!rtIsNaN(unusedU4[0])) {
    partialTrueCount = 1;
  } else {
    partialTrueCount = 0;
    trueCount = 2;
    exitg2 = false;
    while ((!exitg2) && (trueCount < 5)) {
      if (!rtIsNaN(unusedU4[trueCount - 1])) {
        partialTrueCount = trueCount;
        exitg2 = true;
      } else {
        trueCount++;
      }
    }
  }

  if (partialTrueCount == 0) {
    partialTrueCount = 1;
  } else {
    m = unusedU4[partialTrueCount - 1];
    i0 = partialTrueCount + 1;
    for (trueCount = i0; trueCount < 5; trueCount++) {
      d0 = unusedU4[trueCount - 1];
      if (m > d0) {
        m = d0;
        partialTrueCount = trueCount;
      }
    }
  }

  return obj_ClassNames[partialTrueCount - 1];
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
