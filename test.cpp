#include <stdio.h>
#include <math.h>
#include <assert.h>

void test_solv_equ()
{
    double x1 = 0, x2 = 0;
    int nRoots = solve_quad_case(1, 4, 4, &x1, &x2);
}