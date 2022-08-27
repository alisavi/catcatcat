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
#include <string.h>
#include "ComLinePars.h"
#include "enum.h"
#include "SolvEqu.h"
#include "io.h"
#include "test.h"

int main(const int argc, char *argv[])
{
	

	double x1 = 0;
	double x2 = 0;
	int    f  = 0;

	struct coeffs us_coeff = {};

	printf("This is programm for solving quadratic equations.\n"		\
		   "Print 't' to run tests\n"									\
		   "Print 'h' for help\n");
	
	if (argc > 1)
		com_pars(argv[1]);

	do
	{
		input(&us_coeff.a, &us_coeff.b, &us_coeff.c);

		int numberofroots = solution(us_coeff, &x1, &x2);

		//if (numberofroots < -2)
		//	print_err_msg((ErrCodes)numberofroots);

		output((TypeOfRoots)numberofroots, x1, x2);
		printf("Would you like to try again?(Y/n)\n");
		
		f = getchar();
		if (check_sp_simb(f))
		{
			buff_clean();
			f = 'Y';
		}

	} while (f == 'Y');

	return 0;
}