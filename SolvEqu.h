

#ifndef SOLV_EQU_H
#define SOLV_EQU_H

int iszero(double a);
double discriminant(double a, double b, double c);

int solve_line_case(double b, double c, double* x1);


int solve_quad_case(double a, double b, double c, double* x1, double* x2);
int solution(double a, double b, double c, double* x1, double* x2);

#endif