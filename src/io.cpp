#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../include/enum.h"
#include "../include/SolvEqu.h"
#include "../include/io.h"
#include "../include/test.h"

/**
 * @brief cleaning of the buffer
 * 
 */
void BuffClean()   ///
{
    while (getchar() != '\n');
}

/**
 * @brief reading and checking user's coefficients 
 * 
 * @param a a - coefficient
 * @param b b - coefficient
 * @param c c - coefficient
 */
void input(double* a, double* b, double* c)
{
	ASSERT(a != NULL);
	ASSERT(b != NULL);
	ASSERT(c != NULL);
    ASSERT(a != b);
    ASSERT(b != c);
    ASSERT(a != c);

	printf("\na*x^2 + b*x + c = 0\nInput a, b, c separated with spaces: ");

	while (scanf(" %lg %lg %lg", a, b, c) != 3)
	{
		if (!ExecSpecialOption(getchar()))
			printf("incorrect input, try again\n");
		else
			printf("Input a, b, c separated with spaces: ");
		BuffClean();
	}
    BuffClean();
}


/**
 * @brief checking for special symbols in incorrect input
 * @param f simbol to check
 * @return returning 1 if there was special symbol in the input, else returning 0
 */
int ExecSpecialOption(int f)
{
	if (f == 'h')
	{
		ShowHelp();
		return 1;
	}
	else if (f == 't')
	{
		TestSolvEqu();
		return 1;
	}
	else if (f == 'q')
	{
		exit(0);
	}
	else
		return 0;
}

/**
 * @brief displaying the result of equation
 * 
 * @param n  n  - type and number of roots
 * @param x1 x1 - first root 
 * @param x2 x2 - second root (optio)
 */
void output(TypeOfRoots n, double x1, double x2)
{
	switch(n)
	{
		case NOROOTS:
			printf("No roots\n");
			break;
		case ONEROOT:
			printf("x = %lg\n", x1);
			break;
		case TWOROOTS:
			printf("x1 = %lg\nx2 = %lg\n", x1, x2);
			break;
		case IRRROOTS:
			printf("x1 = %lg + i*%lg\nx2 = %lg - i*%lg\n", x1, x2, x1, x2);
			break;
		case INFINITE:
			printf("Infinite number of roots\n");
			break;
		default:
			printf("Incorrect number of roots\n");
	}
}

/**
 * @brief helping the poor user
 * 
 */
void ShowHelp()
{
		printf("\nprint 't' if you wanna run tests for the programm\n"			\
		"print 'q' if you wanna quit\n"											\
		"print 'h' if wanna see this output\n\n");
}

///**
// * @brief printing the type of error
// * 
// * @param err_code code of the error 
// */
// void PrintErrMsg(ErrCodes err_code)
// {
//     switch(err_code)
//     {   
//         case X1NULL:
//             printf("Pointer x1 has incorrect value\n");
//             break;
// 	    case X2NULL:
//             printf("Pointer x2 has incorrect value\n");
//             break;
// 	    case X1EQUX2:
//             printf("Pointer x1 and pointer x2 have identical value\n");
//             break;
// 	    case AINCVAL:
//             printf("Coefficient a has incorrect value\n");
//             break;
// 	    case BINCVAL:
//             printf("Coefficient b has incorrect value\n");
//             break;
// 	    case CINCVAL:
//             printf("Coefficient c has incorrect value\n");
//             break;
// 	    case DINCVAL:
//             printf("Discriminant has incorrect value\n");
//             break;
//         default:
//             printf("There is an error somewhere, good luck in finding it\n");
//             break;
//     }
// }