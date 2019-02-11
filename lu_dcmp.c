#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lu_dcmp.h"

static inline int lindex(const int ROW, const int COL, const int DIM) {
  return ROW * DIM + COL;
}

static void croutBetaSolve(const int ROW, const int COL, const int DIM,
                           double * const LU) {return;}
static void croutAlphaSolve(const int ROW, const int COL, const int DIM,
                            double * const LU) {return;}

void decompLU(const int DIM, double const * const A, double * const LU) {
  const int NUMEL = DIM * DIM;
  int i, j;

  // check that we're not being asked to overwrite A
  // have to trust that A and LU don't overlap...
  if (LU == A) {
    printf("Error: LU and A are the same memory address, this implementation "
           "cannot overwrite A. Please allocate new memory for the LU matrix.\n"
         );
    exit(1);
  }

  // initialise LU from A
  memcpy(LU, A, DIM * DIM * sizeof(double));

  // set diagonal elements to 1
  for (i = 0; i < NUMEL; i += DIM+1) LU[i] = 1.0;

  return;
}
