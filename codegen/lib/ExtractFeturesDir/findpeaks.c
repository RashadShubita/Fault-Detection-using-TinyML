/*
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "ExtractFeturesDir.h"
#include "findpeaks.h"
#include "ExtractFeturesDir_emxutil.h"
#include "sortIdx.h"
#include "eml_setop.h"
#include "flipud.h"

/* Type Definitions */
#ifndef struct_emxArray_real32_T_1024x2
#define struct_emxArray_real32_T_1024x2

struct emxArray_real32_T_1024x2
{
  float data[2048];
  int size[2];
};

#endif                                 /*struct_emxArray_real32_T_1024x2*/

#ifndef typedef_emxArray_real32_T_1024x2
#define typedef_emxArray_real32_T_1024x2

typedef struct emxArray_real32_T_1024x2 emxArray_real32_T_1024x2;

#endif                                 /*typedef_emxArray_real32_T_1024x2*/

/* Function Declarations */
static void c_removePeaksBelowMinPeakPromin(const float y[1024], int iPk_data[],
  int iPk_size[1], float pbPk_data[], int pbPk_size[1], int iLB_data[], int
  iLB_size[1], int iRB_data[], int iRB_size[1]);
static void getHalfMaxBounds(const float y[1024], const emxArray_real32_T *x,
  const int iPk_data[], const int iPk_size[1], const float base_data[], const
  int iLB_data[], const int iRB_data[], float bounds_data[], int bounds_size[2]);
static void getLeftBase(const float yTemp[1024], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1]);
static void getPeakBase(const float yTemp[1024], const int iPk_data[], const int
  iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], float peakBase_data[], int
  peakBase_size[1], int iLeftSaddle_data[], int iLeftSaddle_size[1], int
  iRightSaddle_data[], int iRightSaddle_size[1]);
static void getPeakWidth(const float y[1024], const emxArray_real32_T *x, const
  int iPk_data[], const int iPk_size[1], const float pbPk_data[], const int
  pbPk_size[1], int iLB_data[], int iLB_size[1], int iRB_data[], int iRB_size[1],
  float wxPk_data[], int wxPk_size[2]);
static void parse_inputs(const float Yin[1024], const emxArray_real32_T
  *varargin_1, float y[1024], emxArray_real32_T *x);

/* Function Definitions */

/*
 * Arguments    : const float y[1024]
 *                int iPk_data[]
 *                int iPk_size[1]
 *                float pbPk_data[]
 *                int pbPk_size[1]
 *                int iLB_data[]
 *                int iLB_size[1]
 *                int iRB_data[]
 *                int iRB_size[1]
 * Return Type  : void
 */
static void c_removePeaksBelowMinPeakPromin(const float y[1024], int iPk_data[],
  int iPk_size[1], float pbPk_data[], int pbPk_size[1], int iLB_data[], int
  iLB_size[1], int iRB_data[], int iRB_size[1])
{
  int x_size_idx_0;
  int idx;
  int ii;
  bool x_data[1024];
  bool exitg1;
  short ii_data[1024];
  int b_iPk_data[1024];
  float b_pbPk_data[1024];
  x_size_idx_0 = iPk_size[0];
  idx = iPk_size[0];
  for (ii = 0; ii < idx; ii++) {
    x_data[ii] = (y[iPk_data[ii] - 1] - pbPk_data[ii] >= 1.0F);
  }

  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size_idx_0 - 1)) {
    if (x_data[ii]) {
      idx++;
      ii_data[idx - 1] = (short)(ii + 1);
      if (idx >= x_size_idx_0) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (x_size_idx_0 == 1) {
    if (idx == 0) {
      x_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    x_size_idx_0 = 0;
  } else {
    x_size_idx_0 = idx;
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_iPk_data[ii] = iPk_data[ii_data[ii] - 1];
  }

  iPk_size[0] = x_size_idx_0;
  if (0 <= x_size_idx_0 - 1) {
    memcpy(&iPk_data[0], &b_iPk_data[0], (unsigned int)(x_size_idx_0 * (int)
            sizeof(int)));
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_pbPk_data[ii] = pbPk_data[ii_data[ii] - 1];
  }

  pbPk_size[0] = x_size_idx_0;
  if (0 <= x_size_idx_0 - 1) {
    memcpy(&pbPk_data[0], &b_pbPk_data[0], (unsigned int)(x_size_idx_0 * (int)
            sizeof(float)));
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_iPk_data[ii] = iLB_data[ii_data[ii] - 1];
  }

  iLB_size[0] = x_size_idx_0;
  if (0 <= x_size_idx_0 - 1) {
    memcpy(&iLB_data[0], &b_iPk_data[0], (unsigned int)(x_size_idx_0 * (int)
            sizeof(int)));
  }

  for (ii = 0; ii < x_size_idx_0; ii++) {
    b_iPk_data[ii] = iRB_data[ii_data[ii] - 1];
  }

  iRB_size[0] = x_size_idx_0;
  if (0 <= x_size_idx_0 - 1) {
    memcpy(&iRB_data[0], &b_iPk_data[0], (unsigned int)(x_size_idx_0 * (int)
            sizeof(int)));
  }
}

/*
 * Arguments    : const float y[1024]
 *                const emxArray_real32_T *x
 *                const int iPk_data[]
 *                const int iPk_size[1]
 *                const float base_data[]
 *                const int iLB_data[]
 *                const int iRB_data[]
 *                float bounds_data[]
 *                int bounds_size[2]
 * Return Type  : void
 */
static void getHalfMaxBounds(const float y[1024], const emxArray_real32_T *x,
  const int iPk_data[], const int iPk_size[1], const float base_data[], const
  int iLB_data[], const int iRB_data[], float bounds_data[], int bounds_size[2])
{
  int iLeft;
  int i2;
  int i;
  float refHeight_tmp;
  float refHeight;
  bounds_size[0] = iPk_size[0];
  bounds_size[1] = 2;
  iLeft = iPk_size[0] << 1;
  if (0 <= iLeft - 1) {
    memset(&bounds_data[0], 0, (unsigned int)(iLeft * (int)sizeof(float)));
  }

  i2 = iPk_size[0];
  for (i = 0; i < i2; i++) {
    refHeight_tmp = y[iPk_data[i] - 1] + base_data[i];
    refHeight = refHeight_tmp / 2.0F;
    iLeft = iPk_data[i];
    while ((iLeft >= iLB_data[i]) && (y[iLeft - 1] > refHeight)) {
      iLeft--;
    }

    if (iLeft < iLB_data[i]) {
      bounds_data[i] = x->data[iLB_data[i] - 1];
    } else {
      refHeight_tmp = x->data[iLeft - 1] + (x->data[iLeft] - x->data[iLeft - 1])
        * (0.5F * refHeight_tmp - y[iLeft - 1]) / (y[iLeft] - y[iLeft - 1]);
      if (rtIsNaNF(refHeight_tmp)) {
        if (rtIsInfF(base_data[i])) {
          refHeight_tmp = 0.5F * (x->data[iLeft - 1] + x->data[iLeft]);
        } else {
          refHeight_tmp = x->data[iLeft];
        }
      }

      bounds_data[i] = refHeight_tmp;
    }

    iLeft = iPk_data[i] - 1;
    while ((iLeft + 1 <= iRB_data[i]) && (y[iLeft] > refHeight)) {
      iLeft++;
    }

    if (iLeft + 1 > iRB_data[i]) {
      bounds_data[i + bounds_size[0]] = x->data[iRB_data[i] - 1];
    } else {
      refHeight_tmp = x->data[iLeft] + (x->data[iLeft - 1] - x->data[iLeft]) *
        (0.5F * (y[iPk_data[i] - 1] + base_data[i]) - y[iLeft]) / (y[iLeft - 1]
        - y[iLeft]);
      if (rtIsNaNF(refHeight_tmp)) {
        if (rtIsInfF(base_data[i])) {
          refHeight_tmp = 0.5F * (x->data[iLeft] + x->data[iLeft - 1]);
        } else {
          refHeight_tmp = x->data[iLeft - 1];
        }
      }

      bounds_data[i + bounds_size[0]] = refHeight_tmp;
    }
  }
}

/*
 * Arguments    : const float yTemp[1024]
 *                const int iPeak_data[]
 *                const int iPeak_size[1]
 *                const int iFinite_data[]
 *                const int iFinite_size[1]
 *                const int iInflect_data[]
 *                int iBase_data[]
 *                int iBase_size[1]
 *                int iSaddle_data[]
 *                int iSaddle_size[1]
 * Return Type  : void
 */
static void getLeftBase(const float yTemp[1024], const int iPeak_data[], const
  int iPeak_size[1], const int iFinite_data[], const int iFinite_size[1], const
  int iInflect_data[], int iBase_data[], int iBase_size[1], int iSaddle_data[],
  int iSaddle_size[1])
{
  int n;
  double peak_data[1024];
  double valley_data[1024];
  int iValley_data[1024];
  int i;
  int j;
  int k;
  float v;
  int iv;
  float p_tmp;
  int isv;
  iBase_size[0] = (short)iPeak_size[0];
  n = (short)iPeak_size[0];
  if (0 <= n - 1) {
    memset(&iBase_data[0], 0, (unsigned int)(n * (int)sizeof(int)));
  }

  iSaddle_size[0] = (short)iPeak_size[0];
  n = (short)iPeak_size[0];
  if (0 <= n - 1) {
    memset(&iSaddle_data[0], 0, (unsigned int)(n * (int)sizeof(int)));
  }

  n = (short)iFinite_size[0];
  if (0 <= n - 1) {
    memset(&peak_data[0], 0, (unsigned int)(n * (int)sizeof(double)));
  }

  n = (short)iFinite_size[0];
  if (0 <= n - 1) {
    memset(&valley_data[0], 0, (unsigned int)(n * (int)sizeof(double)));
  }

  n = (short)iFinite_size[0];
  if (0 <= n - 1) {
    memset(&iValley_data[0], 0, (unsigned int)(n * (int)sizeof(int)));
  }

  n = -1;
  i = 0;
  j = 0;
  k = 0;
  v = rtNaNF;
  iv = 1;
  while (k + 1 <= iPeak_size[0]) {
    while (iInflect_data[i] != iFinite_data[j]) {
      v = yTemp[iInflect_data[i] - 1];
      iv = iInflect_data[i];
      if (rtIsNaNF(yTemp[iInflect_data[i] - 1])) {
        n = -1;
      } else {
        while ((n + 1 > 0) && (valley_data[n] > v)) {
          n--;
        }
      }

      i++;
    }

    p_tmp = yTemp[iInflect_data[i] - 1];
    while ((n + 1 > 0) && (peak_data[n] < p_tmp)) {
      if (valley_data[n] < v) {
        v = (float)valley_data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    isv = iv;
    while ((n + 1 > 0) && (peak_data[n] <= p_tmp)) {
      if (valley_data[n] < v) {
        v = (float)valley_data[n];
        iv = iValley_data[n];
      }

      n--;
    }

    n++;
    peak_data[n] = yTemp[iInflect_data[i] - 1];
    valley_data[n] = v;
    iValley_data[n] = iv;
    if (iInflect_data[i] == iPeak_data[k]) {
      iBase_data[k] = iv;
      iSaddle_data[k] = isv;
      k++;
    }

    i++;
    j++;
  }
}

/*
 * Arguments    : const float yTemp[1024]
 *                const int iPk_data[]
 *                const int iPk_size[1]
 *                const int iFin_data[]
 *                const int iFin_size[1]
 *                const int iInflect_data[]
 *                const int iInflect_size[1]
 *                float peakBase_data[]
 *                int peakBase_size[1]
 *                int iLeftSaddle_data[]
 *                int iLeftSaddle_size[1]
 *                int iRightSaddle_data[]
 *                int iRightSaddle_size[1]
 * Return Type  : void
 */
static void getPeakBase(const float yTemp[1024], const int iPk_data[], const int
  iPk_size[1], const int iFin_data[], const int iFin_size[1], const int
  iInflect_data[], const int iInflect_size[1], float peakBase_data[], int
  peakBase_size[1], int iLeftSaddle_data[], int iLeftSaddle_size[1], int
  iRightSaddle_data[], int iRightSaddle_size[1])
{
  int iLeftBase_data[1024];
  int iLeftBase_size[1];
  int tmp_size[1];
  int tmp_data[1024];
  int b_tmp_size[1];
  int b_tmp_data[1024];
  int c_tmp_size[1];
  int c_tmp_data[1024];
  int iRightBase_data[1024];
  short csz_idx_0;
  int nx;
  int k;
  getLeftBase(yTemp, iPk_data, iPk_size, iFin_data, iFin_size, iInflect_data,
              iLeftBase_data, iLeftBase_size, iLeftSaddle_data, iLeftSaddle_size);
  tmp_size[0] = iPk_size[0];
  if (0 <= iPk_size[0] - 1) {
    memcpy(&tmp_data[0], &iPk_data[0], (unsigned int)(iPk_size[0] * (int)sizeof
            (int)));
  }

  flipud(tmp_data, tmp_size);
  b_tmp_size[0] = iFin_size[0];
  if (0 <= iFin_size[0] - 1) {
    memcpy(&b_tmp_data[0], &iFin_data[0], (unsigned int)(iFin_size[0] * (int)
            sizeof(int)));
  }

  flipud(b_tmp_data, b_tmp_size);
  c_tmp_size[0] = iInflect_size[0];
  if (0 <= iInflect_size[0] - 1) {
    memcpy(&c_tmp_data[0], &iInflect_data[0], (unsigned int)(iInflect_size[0] *
            (int)sizeof(int)));
  }

  flipud(c_tmp_data, c_tmp_size);
  getLeftBase(yTemp, tmp_data, tmp_size, b_tmp_data, b_tmp_size, c_tmp_data,
              iRightBase_data, c_tmp_size, iRightSaddle_data, iRightSaddle_size);
  flipud(iRightSaddle_data, iRightSaddle_size);
  tmp_size[0] = c_tmp_size[0];
  if (0 <= c_tmp_size[0] - 1) {
    memcpy(&tmp_data[0], &iRightBase_data[0], (unsigned int)(c_tmp_size[0] *
            (int)sizeof(int)));
  }

  flipud(tmp_data, tmp_size);
  tmp_size[0] = c_tmp_size[0];
  if (0 <= c_tmp_size[0] - 1) {
    memcpy(&tmp_data[0], &iRightBase_data[0], (unsigned int)(c_tmp_size[0] *
            (int)sizeof(int)));
  }

  flipud(tmp_data, tmp_size);
  if (iLeftBase_size[0] <= tmp_size[0]) {
    csz_idx_0 = (short)iLeftBase_size[0];
  } else {
    tmp_size[0] = c_tmp_size[0];
    if (0 <= c_tmp_size[0] - 1) {
      memcpy(&tmp_data[0], &iRightBase_data[0], (unsigned int)(c_tmp_size[0] *
              (int)sizeof(int)));
    }

    flipud(tmp_data, tmp_size);
    csz_idx_0 = (short)tmp_size[0];
  }

  peakBase_size[0] = csz_idx_0;
  nx = csz_idx_0;
  for (k = 0; k < nx; k++) {
    tmp_size[0] = c_tmp_size[0];
    if (0 <= c_tmp_size[0] - 1) {
      memcpy(&tmp_data[0], &iRightBase_data[0], (unsigned int)(c_tmp_size[0] *
              (int)sizeof(int)));
    }

    flipud(tmp_data, tmp_size);
    peakBase_data[k] = fmaxf(yTemp[iLeftBase_data[k] - 1], yTemp[tmp_data[k] - 1]);
  }
}

/*
 * Arguments    : const float y[1024]
 *                const emxArray_real32_T *x
 *                const int iPk_data[]
 *                const int iPk_size[1]
 *                const float pbPk_data[]
 *                const int pbPk_size[1]
 *                int iLB_data[]
 *                int iLB_size[1]
 *                int iRB_data[]
 *                int iRB_size[1]
 *                float wxPk_data[]
 *                int wxPk_size[2]
 * Return Type  : void
 */
static void getPeakWidth(const float y[1024], const emxArray_real32_T *x, const
  int iPk_data[], const int iPk_size[1], const float pbPk_data[], const int
  pbPk_size[1], int iLB_data[], int iLB_size[1], int iRB_data[], int iRB_size[1],
  float wxPk_data[], int wxPk_size[2])
{
  float base_data[1024];
  if (iPk_size[0] == 0) {
    iLB_size[0] = 0;
    iRB_size[0] = 0;
  } else {
    if (0 <= pbPk_size[0] - 1) {
      memcpy(&base_data[0], &pbPk_data[0], (unsigned int)(pbPk_size[0] * (int)
              sizeof(float)));
    }
  }

  getHalfMaxBounds(y, x, iPk_data, iPk_size, base_data, iLB_data, iRB_data,
                   wxPk_data, wxPk_size);
}

/*
 * Arguments    : const float Yin[1024]
 *                const emxArray_real32_T *varargin_1
 *                float y[1024]
 *                emxArray_real32_T *x
 * Return Type  : void
 */
static void parse_inputs(const float Yin[1024], const emxArray_real32_T
  *varargin_1, float y[1024], emxArray_real32_T *x)
{
  int i1;
  int loop_ub;
  memcpy(&y[0], &Yin[0], sizeof(float) << 10);
  i1 = x->size[0];
  x->size[0] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(x, i1);
  loop_ub = varargin_1->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    x->data[i1] = varargin_1->data[i1];
  }
}

/*
 * Arguments    : const float Yin[1024]
 *                const emxArray_real32_T *varargin_1
 *                float Ypk_data[]
 *                int Ypk_size[2]
 *                float Xpk_data[]
 *                int Xpk_size[2]
 * Return Type  : void
 */
void findpeaks(const float Yin[1024], const emxArray_real32_T *varargin_1, float
               Ypk_data[], int Ypk_size[2], float Xpk_data[], int Xpk_size[2])
{
  emxArray_real32_T *x;
  float y[1024];
  int nPk;
  int nInf;
  int nInflect;
  char dir;
  int kfirst;
  float ykfirst;
  bool isinfykfirst;
  int k;
  int iInfR_data[1024];
  float yk;
  int loop_ub;
  bool isinfyk;
  int iInfinite_data[1024];
  char previousdir;
  int iFinite_size[1];
  int iFinite_data[1024];
  int b_iFinite_data[1024];
  int iInfinite_size[1];
  int iInfR_size[1];
  int iPk_size[1];
  float yFinite[1024];
  float bPk_data[1024];
  int bPk_size[1];
  int iLB_data[1024];
  int iLB_size[1];
  int iRB_data[1024];
  int iRB_size[1];
  emxArray_real32_T_1024x2 b_yFinite;
  int c_data[2048];
  int y_data[2048];
  int idx_data[2048];
  int y_size[1];
  float b_y_data[2048];
  int s_data[2048];
  emxInit_real32_T(&x, 1);
  parse_inputs(Yin, varargin_1, y, x);
  nPk = 0;
  nInf = 0;
  nInflect = -1;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInfF;
  isinfykfirst = true;
  for (k = 0; k < 1024; k++) {
    yk = y[k];
    if (rtIsNaNF(y[k])) {
      yk = rtInfF;
      isinfyk = true;
    } else if (rtIsInfF(y[k]) && (y[k] > 0.0F)) {
      isinfyk = true;
      nInf++;
      iInfinite_data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }

    if (yk != ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          iInfR_data[nInflect] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if ('d' != previousdir) {
          nInflect++;
          iInfR_data[nInflect] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            b_iFinite_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if ('i' != previousdir) {
          nInflect++;
          iInfR_data[nInflect] = kfirst;
        }
      }

      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }

  if ((!isinfykfirst) && ((nInflect + 1 == 0) || (iInfR_data[nInflect] < 1024)))
  {
    nInflect++;
    iInfR_data[nInflect] = 1024;
  }

  if (1 > nPk) {
    loop_ub = 0;
  } else {
    loop_ub = nPk;
  }

  for (k = 0; k < loop_ub; k++) {
    iFinite_data[k] = b_iFinite_data[k];
  }

  iFinite_size[0] = loop_ub;
  if (0 <= loop_ub - 1) {
    memcpy(&b_iFinite_data[0], &iFinite_data[0], (unsigned int)(loop_ub * (int)
            sizeof(int)));
  }

  if (1 > nInf) {
    nInf = 0;
  }

  for (k = 0; k < nInf; k++) {
    iFinite_data[k] = iInfinite_data[k];
  }

  iInfinite_size[0] = nInf;
  if (0 <= nInf - 1) {
    memcpy(&iInfinite_data[0], &iFinite_data[0], (unsigned int)(nInf * (int)
            sizeof(int)));
  }

  if (1 > nInflect + 1) {
    kfirst = -1;
  } else {
    kfirst = nInflect;
  }

  for (k = 0; k <= kfirst; k++) {
    iFinite_data[k] = iInfR_data[k];
  }

  iInfR_size[0] = kfirst + 1;
  kfirst++;
  if (0 <= kfirst - 1) {
    memcpy(&iInfR_data[0], &iFinite_data[0], (unsigned int)(kfirst * (int)sizeof
            (int)));
  }

  nPk = 0;
  for (k = 0; k < loop_ub; k++) {
    ykfirst = y[b_iFinite_data[k] - 1];
    if ((ykfirst > rtMinusInfF) && (ykfirst - fmaxf(y[b_iFinite_data[k] - 2],
          y[b_iFinite_data[k]]) >= 0.0F)) {
      nPk++;
      iFinite_data[nPk - 1] = b_iFinite_data[k];
    }
  }

  if (1 > nPk) {
    iPk_size[0] = 0;
  } else {
    iPk_size[0] = nPk;
  }

  memcpy(&yFinite[0], &y[0], sizeof(float) << 10);
  for (k = 0; k < nInf; k++) {
    yFinite[iInfinite_data[k] - 1] = rtNaNF;
  }

  getPeakBase(yFinite, iFinite_data, iPk_size, b_iFinite_data, iFinite_size,
              iInfR_data, iInfR_size, bPk_data, bPk_size, iLB_data, iLB_size,
              iRB_data, iRB_size);
  c_removePeaksBelowMinPeakPromin(yFinite, iFinite_data, iPk_size, bPk_data,
    bPk_size, iLB_data, iLB_size, iRB_data, iRB_size);
  getPeakWidth(yFinite, x, iFinite_data, iPk_size, bPk_data, bPk_size, iLB_data,
               iLB_size, iRB_data, iRB_size, b_yFinite.data, b_yFinite.size);
  do_vectors(iFinite_data, iPk_size, iInfinite_data, iInfinite_size, c_data,
             bPk_size, b_iFinite_data, iFinite_size, iInfR_data, iInfR_size);
  if (bPk_size[0] < 1) {
    nPk = 0;
  } else {
    nPk = bPk_size[0];
  }

  if (nPk > 0) {
    y_data[0] = 1;
    kfirst = 1;
    for (k = 2; k <= nPk; k++) {
      kfirst++;
      y_data[k - 1] = kfirst;
    }
  }

  if (0 <= nPk - 1) {
    memcpy(&idx_data[0], &y_data[0], (unsigned int)(nPk * (int)sizeof(int)));
  }

  if (nPk != 0) {
    y_size[0] = nPk;
    for (k = 0; k < nPk; k++) {
      b_y_data[k] = y[c_data[idx_data[k] - 1] - 1];
    }

    sortIdx(b_y_data, y_size, s_data, bPk_size);
    loop_ub = bPk_size[0];
    for (k = 0; k < loop_ub; k++) {
      y_data[k] = idx_data[s_data[k] - 1];
    }

    nPk = bPk_size[0];
    if (0 <= bPk_size[0] - 1) {
      memcpy(&idx_data[0], &y_data[0], (unsigned int)(bPk_size[0] * (int)sizeof
              (int)));
    }
  }

  if (nPk > 3) {
    y_data[0] = idx_data[0];
    y_data[1] = idx_data[1];
    y_data[2] = idx_data[2];
    nPk = 3;
    memcpy(&idx_data[0], &y_data[0], (unsigned int)(3 * (int)sizeof(int)));
  }

  for (k = 0; k < nPk; k++) {
    s_data[k] = c_data[idx_data[k] - 1];
  }

  Ypk_size[0] = 1;
  Ypk_size[1] = nPk;
  for (k = 0; k < nPk; k++) {
    Ypk_data[k] = y[s_data[k] - 1];
  }

  Xpk_size[0] = 1;
  Xpk_size[1] = nPk;
  for (k = 0; k < nPk; k++) {
    Xpk_data[k] = x->data[s_data[k] - 1];
  }

  emxFree_real32_T(&x);
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
