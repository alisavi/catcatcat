/**
 * @file SolvEqu.h
 * @brief solving quadratic or linear equation
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SOLV_EQU_H
#define SOLV_EQU_H

#define ASSERT(condition) if (!(condition)) printf("Error in %s\nin file %s\nin string %d\nin function %s",  \
                                            #condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);
#define STREQUAL(str1, str2) !strcmp()

int    IsZero       (double a);
double CalcDiscr    (struct coeffs UsCoeff);
int    SolveLineCase(struct coeffs UsCoeff, double* x1);
int    SolveQuadCase(struct coeffs UsCoeff, double* x1, double* x2);
int    GetSolution  (struct coeffs UsCoeff, double* x1, double* x2);

#endif