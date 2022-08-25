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

int iszero(double a);
double calc_discr(double a, double b, double c);
int solve_line_case(double b, double c, double* x1);
int solve_quad_case(double a, double b, double c, double* x1, double* x2);
int solution(double a, double b, double c, double* x1, double* x2);

#endif