#ifndef LU_DCMP_H
#define LU_DCMP_H

inline int lindex(const int, const int, const int, const int);

double * decompLU(const int, const int, double const * const);
double * initLUResult(const int, const int);
void croutBetaSolve(const int, const int, const int, const int, double const *);
void croutAlphaSolve(const int, const int, const int, const int, double const *);

#endif
