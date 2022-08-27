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
#include "../include/enum.h"
#include "../include/SolvEqu.h"
#include "../include/test.h"

/**
 * @brief testing function
 * 
 * prints number of successful tests
 */
void TestSolvEqu()               
{
    struct coeffs DefCoeff = {};
    double x1         = 0;
    double x2         = 0;
    double resx1      = 0;
    double resx2      = 0;
    int    nRoots     = 10;  // INV_VAL 
    int    resnRoots  = 10; ///
    int    nTests     = 0;
    int    nSuccTests = 0;

    FILE *fp = fopen("../test_data/testing_data", "r");    // name --> .h

    if (!fp)
    {
        printf("Could not open file with testing data\n");
    }

    else
    {
        while (!feof(fp))
        {
            DefCoeff.a = DefCoeff.b = DefCoeff.c = x1 = x2 = resx1 = resx2 = 0;
            nRoots = resnRoots = 10;

            ++nTests;

            fscanf(fp, "%lg %lg %lg %d %lg %lg", &DefCoeff.a, &DefCoeff.b, &DefCoeff.c, &nRoots, &x1, &x2); ///
            resnRoots = GetSolution(DefCoeff, &resx1, &resx2);

            // resnRoots 

            if (!(IsZero(resx1 - x1) && IsZero(resx2 - x2) && IsZero(resnRoots - nRoots)))
            {
                printf("FAILED (a = %lg, b = %lg, c = %lg)\nExpected:      x1 = %lg, x2 = %lg, nRoots = %d\n"   \
                                                           "Failed result: x1 = %lg, x2 = %lg, nRoots = %d\n",  \
                                                            DefCoeff.a, DefCoeff.b, DefCoeff.c, x1, x2, nRoots, resx1, resx2, resnRoots);
            }
            else
                ++nSuccTests;
        }
    
        printf("Number of successful tests: %d\\%d\n", nSuccTests, nTests);
    }

    fclose(fp);
}