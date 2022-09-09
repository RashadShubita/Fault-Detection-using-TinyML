/*
 * File: ExtractFeturesDir.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "ExtractFeturesDir_emxutil.h"
#include "findpeaks.h"

/* Function Definitions */

/*
 * fAxis_F1 = zeros(1,1024)*0.1;
 * Arguments    : const float DataFFT[1024]
 *                float BufferLen
 *                float Fs
 *                float *pks1
 *                float *pks2
 *                float *pks3
 *                float *locs1
 *                float *locs2
 *                float *locs3
 * Return Type  : void
 */
void ExtractFeturesDir(const float DataFFT[1024], float BufferLen, float Fs,
  float *pks1, float *pks2, float *pks3, float *locs1, float *locs2, float
  *locs3)
{
  float b;
  emxArray_real32_T *fAxis_F1;
  int i0;
  int loop_ub;
  emxArray_real32_T *b_fAxis_F1;
  float auto_gen_tmp_0_data[2048];
  int auto_gen_tmp_0_size[2];
  float auto_gen_tmp_1_data[2048];
  int auto_gen_tmp_1_size[2];
  b = (BufferLen - 1.0F) / 2.0F;
  emxInit_real32_T(&fAxis_F1, 2);
  if (rtIsNaNF(b)) {
    i0 = fAxis_F1->size[0] * fAxis_F1->size[1];
    fAxis_F1->size[0] = 1;
    fAxis_F1->size[1] = 1;
    emxEnsureCapacity_real32_T(fAxis_F1, i0);
    fAxis_F1->data[0] = rtNaNF;
  } else if (b < 0.0F) {
    fAxis_F1->size[0] = 1;
    fAxis_F1->size[1] = 0;
  } else if (rtIsInfF(b) && (0.0F == b)) {
    i0 = fAxis_F1->size[0] * fAxis_F1->size[1];
    fAxis_F1->size[0] = 1;
    fAxis_F1->size[1] = 1;
    emxEnsureCapacity_real32_T(fAxis_F1, i0);
    fAxis_F1->data[0] = rtNaNF;
  } else {
    i0 = fAxis_F1->size[0] * fAxis_F1->size[1];
    fAxis_F1->size[0] = 1;
    loop_ub = (int)floorf(b);
    fAxis_F1->size[1] = loop_ub + 1;
    emxEnsureCapacity_real32_T(fAxis_F1, i0);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      fAxis_F1->data[i0] = (float)i0;
    }
  }

  emxInit_real32_T(&b_fAxis_F1, 2);
  i0 = b_fAxis_F1->size[0] * b_fAxis_F1->size[1];
  b_fAxis_F1->size[0] = 1;
  b_fAxis_F1->size[1] = fAxis_F1->size[1];
  emxEnsureCapacity_real32_T(b_fAxis_F1, i0);
  loop_ub = fAxis_F1->size[0] * fAxis_F1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fAxis_F1->data[i0] = fAxis_F1->data[i0] * Fs / BufferLen;
  }

  emxFree_real32_T(&fAxis_F1);
  findpeaks(DataFFT, b_fAxis_F1, auto_gen_tmp_0_data, auto_gen_tmp_0_size,
            auto_gen_tmp_1_data, auto_gen_tmp_1_size);
  emxFree_real32_T(&b_fAxis_F1);
  if (auto_gen_tmp_0_size[1] == 0) {
    *pks1 = 0.0F;
    *pks2 = 0.0F;
    *pks3 = 0.0F;
    *locs1 = 0.0F;
    *locs2 = 0.0F;
    *locs3 = 0.0F;
  } else if (auto_gen_tmp_0_size[1] == 1) {
    *pks1 = auto_gen_tmp_0_data[0];
    *locs1 = auto_gen_tmp_1_data[0];
    *pks2 = 0.0F;
    *locs2 = 0.0F;
    *pks3 = 0.0F;
    *locs3 = 0.0F;
  } else if (auto_gen_tmp_0_size[1] == 2) {
    *pks1 = auto_gen_tmp_0_data[0];
    *locs1 = auto_gen_tmp_1_data[0];
    *pks2 = auto_gen_tmp_0_data[1];
    *locs2 = auto_gen_tmp_1_data[1];
    *pks3 = 0.0F;
    *locs3 = 0.0F;
  } else {
    /* if NumPks == 3 */
    *pks1 = auto_gen_tmp_0_data[0];
    *locs1 = auto_gen_tmp_1_data[0];
    *pks2 = auto_gen_tmp_0_data[1];
    *locs2 = auto_gen_tmp_1_data[1];
    *pks3 = auto_gen_tmp_0_data[2];
    *locs3 = auto_gen_tmp_1_data[2];
  }
}

/*
 * File trailer for ExtractFeturesDir.c
 *
 * [EOF]
 */
