/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 08-Dec-2020 19:49:34
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "ExtractFeturesDir.h"
#include "main.h"
#include "ExtractFeturesDir_terminate.h"
#include "ExtractFeturesDir_initialize.h"

/* Function Declarations */
static void argInit_1x1024_real32_T(float result[1024]);
static float argInit_real32_T(void);
static void main_ExtractFeturesDir(void);

/* Function Definitions */

/*
 * Arguments    : float result[1024]
 * Return Type  : void
 */
static void argInit_1x1024_real32_T(float result[1024])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 1024; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real32_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ExtractFeturesDir(void)
{
  float fv0[1024];
  float pks1;
  float pks2;
  float pks3;
  float locs1;
  float locs2;
  float locs3;

  /* Initialize function 'ExtractFeturesDir' input arguments. */
  /* Initialize function input argument 'DataFFT'. */
  /* Call the entry-point 'ExtractFeturesDir'. */
  argInit_1x1024_real32_T(fv0);
  ExtractFeturesDir(fv0, argInit_real32_T(), argInit_real32_T(), &pks1, &pks2,
                    &pks3, &locs1, &locs2, &locs3);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  ExtractFeturesDir_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_ExtractFeturesDir();

  /* Terminate the application.
     You do not need to do this more than one time. */
  ExtractFeturesDir_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
