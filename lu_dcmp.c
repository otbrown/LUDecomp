#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lu_dcmp.h"

static inline int lindex(const int ROW, const int COL, const int DIM) {
  return ROW * DIM + COL;
}

static void croutBetaSolve(const int ROW, const int COL, const int DIM,
                           double * const LU) {
  double sum = 0.0;
  for (int k = 0; k < ROW; ++k) {
    sum += LU[lindex(ROW,k,DIM)] * LU[lindex(k,COL,DIM)];
  }

  LU[lindex(ROW,COL,DIM)] -= sum;

  return;
}

static void croutAlphaSolve(const int ROW, const int COL, const int DIM,
                            double * const LU) {
  double sum = 0.0;
  for (int k = 0; k < COL; ++k) {
    sum += LU[lindex(ROW,k,DIM)] * LU[lindex(k,COL,DIM)];
  }

  LU[lindex(ROW,COL,DIM)] -= sum;
  LU[lindex(ROW,COL,DIM)] /= LU[lindex(COL,COL,DIM)];

  return;
}

void decompLU(const int DIM, double const * const A, double * const LU) {
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

  // main LU iterations
  // Crout's algorithm [see Numerical Recipes (3E), Press, Teukolsky,
  // Vetterling, and Flannery, (2007), Chapter 2.3.1, or Wikipedia]
  for (j = 0; j < DIM; ++j) {
    for (i = 0; i < j+1; ++i) {
      croutBetaSolve(i, j, DIM, LU);
    }
    for (i = j+1; i < DIM; ++i) {
      croutAlphaSolve(i, j, DIM, LU);
    }
  }

  return;
}
