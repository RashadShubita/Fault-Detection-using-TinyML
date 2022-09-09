/*
 * File: mergesort.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "mergesort.h"
#include "sortLE.h"

/* Function Definitions */

/*
 * Arguments    : int idx_data[]
 *                const float x_data[]
 *                int n
 * Return Type  : void
 */
void b_mergesort(int idx_data[], const float x_data[], int n)
{
  int i4;
  int k;
  int i;
  int i2;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  int i5;
  int iwork_data[2048];
  i4 = n - 1;
  for (k = 1; k <= i4; k += 2) {
    if (sortLE(x_data, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }

  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }

  i = 2;
  while (i < n) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < n + 1; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        i4 = idx_data[q - 1];
        i5 = idx_data[p - 1];
        if (sortLE(x_data, i5, i4)) {
          iwork_data[k] = i5;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i4;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }

      j = qEnd;
    }

    i = i2;
  }
}

/*
 * File trailer for mergesort.c
 *
 * [EOF]
 */
