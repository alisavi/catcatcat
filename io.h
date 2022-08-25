/** @brief Solving of quadratic equation
 * Solves a square equation a*x^2 + b*x + c = 0;
 * @file ios.h
 * @param[in] a a - coefficient
 * @param[in] b b - coefficient
 * @param[in] c c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return Program exit status
 *
 */

#ifndef SOLV_IO_H
#define SOLV_IO_H

void input(double* a, double* b, double* c);
void output(TypeOfRoots n, double x1, double x2);
void buff_clean();
void print_err_msg(ErrCodes err_code);

#endif