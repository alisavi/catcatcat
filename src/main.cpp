/**
 * @file SolvQuadEqu.cpp
 * @brief programm solving quadratic equation using user's coefficients
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
1) main.cpp +
2) папки +
3) * ASSERT(ERR_CODE, ...) assert(int err_code, int cond, const ) *
4) naming funcs 
5) flags 
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../include/ComLinePars.h"
#include "../include/enum.h"
#include "../include/SolvEqu.h"
#include "../include/io.h"
#include "../include/test.h"

int main(const int argc, char *argv[])
{
	

	double x1 = 0;
	double x2 = 0;
	int    f  = 0;  //

	struct coeffs UsCoeff = {};

	printf("This is programm for solving quadratic equations.\n"		\
		   "Print 't' to run tests\n"									\
		   "Print 'h' for help\n");
	
	if (argc > 1)                                                         ///
		ComPars(argv[1]);

	do
	{
		input(&UsCoeff.a, &UsCoeff.b, &UsCoeff.c);

		int numberofroots = GetSolution(UsCoeff, &x1, &x2);

		output((TypeOfRoots)numberofroots, x1, x2);
		printf("Would you like to try again?(Y/n)\n");
		
		f = getchar();
		if (ExecSpecialOption(f))
		{
			BuffClean();
			f = 'Y';
		}

	} while (f == 'Y');

	return 0;
}