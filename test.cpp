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
#include <stdlib.h>
#include <math.h>
#include "enum.h"
#include "SolvEqu.h"
#include "test.h"

/**
 * @brief testing function
 * 
 * prints number of successful tests
 */
void test_solv_equ()
{
    struct coeffs def_coeff;
	def_coeff.a       = 0;
	def_coeff.b       = 0;
	def_coeff.c       = 0;
    double x1         = 0;
    double x2         = 0;
    double resx1      = 0;
    double resx2      = 0;
    int    nRoots     = 10;
    int    resnRoots  = 10;
    int    nTests     = 0;
    int    nSuccTests = 0;

    FILE *fp = fopen("testing_data.txt", "r");

    if (!fp)
    {
        printf("Could not open file with testing data\n");
    }

    else
    {
        while (!feof(fp))
        {
            def_coeff.a = def_coeff.b = def_coeff.c = x1 = x2 = resx1 = resx2 = 0;
            nRoots = resnRoots = 10;

            ++nTests;

            fscanf(fp, "%lg %lg %lg %d %lg %lg", &def_coeff.a, &def_coeff.b, &def_coeff.c, &nRoots, &x1, &x2);
            resnRoots = solution(def_coeff, &resx1, &resx2);

            if (!(iszero(resx1 - x1) && iszero(resx2 - x2) && iszero(resnRoots - nRoots)))
            {
                printf("FAILED (a = %lg, b = %lg, c = %lg)\nExpected:      x1 = %lg, x2 = %lg, nRoots = %d\n"   \
                                                           "Failed result: x1 = %lg, x2 = %lg, nRoots = %d\n",  \
                                                            def_coeff.a, def_coeff.b, def_coeff.c, x1, x2, nRoots, resx1, resx2, resnRoots);
            }
            else
                ++nSuccTests;
        }
    
        printf("Number of successful tests: %d\\%d\n", nSuccTests, nTests);
    }

    fclose(fp);
}