/**
 * @file test.cpp
 * @brief testing of functions
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "enum.h"
#include "SolvEqu.h"

/**
 * @brief testing function
 * 
 */
void test_solv_equ()
{
    double x1 = 0, x2 = 0;
    int nRoots = solve_quad_case(1, 4, 4, &x1, &x2);
    if (!(nRoots == TWOROOTS && x1 != 2 && x2 !=))
    {

    }

}