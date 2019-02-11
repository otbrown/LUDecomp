#include <stdlib.h>
#include <stdio.h>
#include "lu_dcmp.h"

static inline int lindex(const int ROW, const int COL, const int DIM) {
  return ROW * DIM + COL;
}

int main(void) {
  int i, j;
  const int DIM = 3;
  const size_t NBYTES = DIM * DIM * sizeof(double);
  double * A = malloc(NBYTES);
  double * LU = malloc(NBYTES);

  // initialise A
  A[0] = 1.0;
  A[1] = 2.0;
  A[2] = 4.0;
  A[3] = 3.0;
  A[4] = 8.0;
  A[5] = 14.0;
  A[6] = 2.0;
  A[7] = 6.0;
  A[8] = 13.0;

  // print A
  printf("A:\n");
  for (i = 0; i < DIM; ++i) {
    for (j = 0; j < DIM; ++j) {
      printf("%g ", A[lindex(i,j,DIM)]);
    }
    printf("\n");
  }
  printf("\n");

  // perform LU
  decompLU(DIM, A, LU);

  // print LU
  printf("LU:\n");
  for (i = 0; i < DIM; ++i) {
    for (j = 0; j < DIM; ++j) {
      printf("%g ", LU[lindex(i,j,DIM)]);
    }
    printf("\n");
  }
  printf("\n");

  // be free!
  free(A);
  free(LU);

  return 0;
}
