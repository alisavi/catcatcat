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

	show_menu: printf("print 'r' if you wanna start solving quadratic equations\n"	\
		   "print 't' if you wanna run tests for the programm\n"					\
		   "print 'q' if you wanna quit\n"											\
		   "print 'm' if you wanna open the menu\n"									\
		   "print 'i' for information about the programm\n");

	inc_choice: int f = getchar();

	switch(f)
	{
		case 'r':
			do
			{
				input(&a,&b,&c);

				int numberofroots = solution(a, b, c, &x1, &x2);

				//if (numberofroots < -2)
				//	print_err_msg((ErrCodes)numberofroots);

				output((TypeOfRoots)numberofroots, x1, x2);
				printf("Would you like to try again?(Y/n)\n");

			} while (getchar() == 'Y');
			
			buff_clean();
			goto inc_choice;

		case 't':
			test_solv_equ();
			buff_clean();
			goto inc_choice;

		case 'q':
			return 0;

		case 'i':
			printf("no info yet\n");
			buff_clean();
			goto inc_choice;

		case 'm':
			buff_clean();
			goto show_menu;
			break;

		default:
			buff_clean();
			goto inc_choice;
	}

	return 0;
}