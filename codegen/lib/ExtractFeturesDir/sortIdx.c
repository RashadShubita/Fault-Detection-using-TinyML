/*
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "sortIdx.h"
#include "mergesort.h"

/* Function Definitions */

/*
 * Arguments    : const float x_data[]
 *                const int x_size[1]
 *                int idx_data[]
 *                int idx_size[1]
 * Return Type  : void
 */
void sortIdx(const float x_data[], const int x_size[1], int idx_data[], int
             idx_size[1])
{
  int loop_ub;
  idx_size[0] = (short)x_size[0];
  loop_ub = (short)x_size[0];
  if (0 <= loop_ub - 1) {
    memset(&idx_data[0], 0, (unsigned int)(loop_ub * (int)sizeof(int)));
  }

  b_mergesort(idx_data, x_data, x_size[0]);
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
