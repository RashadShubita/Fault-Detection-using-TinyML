/*
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 01-Jan-2021 22:13:26
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "classifyX_types.h"

/* Function Declarations */
extern double c_CompactClassificationTree_pre(const double obj_CutVar[9], const
  double obj_Children[18], const double obj_ClassProb[36], const double
  obj_CutPoint[9], const double obj_ClassNames[4], const bool
  obj_ClassLogicalIndices[4], const double obj_Cost[16], const float X[8]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
