/*
 * File: flipud.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "flipud.h"

/* Function Definitions */

/*
 * Arguments    : int x_data[]
 *                int x_size[1]
 * Return Type  : void
 */
void flipud(int x_data[], int x_size[1])
{
  int m;
  int md2;
  int i;
  int xtmp;
  int i3;
  m = x_size[0] - 1;
  md2 = x_size[0] >> 1;
  for (i = 0; i < md2; i++) {
    xtmp = x_data[i];
    i3 = m - i;
    x_data[i] = x_data[i3];
    x_data[i3] = xtmp;
  }
}

/*
 * File trailer for flipud.c
 *
 * [EOF]
 */
