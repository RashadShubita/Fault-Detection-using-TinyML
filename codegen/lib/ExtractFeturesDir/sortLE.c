/*
 * File: sortLE.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "sortLE.h"

/* Function Definitions */

/*
 * Arguments    : const float v_data[]
 *                int idx1
 *                int idx2
 * Return Type  : bool
 */
bool sortLE(const float v_data[], int idx1, int idx2)
{
  bool p;
  float f0;
  f0 = v_data[idx1 - 1];
  if ((f0 >= v_data[idx2 - 1]) || rtIsNaNF(f0)) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

/*
 * File trailer for sortLE.c
 *
 * [EOF]
 */
