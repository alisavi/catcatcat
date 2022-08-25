/**
 * @file SolvQuadEqu.cpp
 * @brief programm solving quadratic equation using user's coefficients
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
#include "io.h"
#include "test.h"

int main()
{
	double a  = 0;
	double b  = 0;
	double c  = 0;
	double x1 = 0;
	double x2 = 0;

	test_solv_equ();

	do
	{
		input(&a,&b,&c);

		int numberofroots = solution(a, b, c, &x1, &x2);

		//if (numberofroots < -2)
		//	print_err_msg((ErrCodes)numberofroots);

		output((TypeOfRoots)numberofroots, x1, x2);
		printf("Would you like to try again?(Y/n)\n");

	} while (getchar() == 'Y');

	return 0;
}