#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "enum.h"
#include "io.h"
#include "SolvEqu.h"

void buff_clean()
{
    while (getchar() != '\n');
}

void input(double* a, double* b, double* c)
{
	ASSERT(a != NULL);
	ASSERT(b != NULL);
	ASSERT(c != NULL);
    ASSERT(a != b);
    ASSERT(b != c);
    ASSERT(a != c);

	printf("a*x^2 + b*x + c = 0\nInput a, b, c separated with spaces: ");

	while (scanf(" %lg %lg %lg", a, b, c) != 3)
	{
		printf("incorrect input, try again\n");
		buff_clean();
	}
    buff_clean();
}

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
	}
}

void print_err_msg(ErrCodes err_code)
{
    switch(err_code)
    {   
        case X1NULL:
            printf("Pointer x1 has incorrect value\n");
            break;
	    case X2NULL:
            printf("Pointer x2 has incorrect value\n");
            break;
	    case X1EQUX2:
            printf("Pointer x1 and pointer x2 have identical value\n");
            break;
	    case AINCVAL:
            printf("Coefficient a has incorrect value\n");
            break;
	    case BINCVAL:
            printf("Coefficient b has incorrect value\n");
            break;
	    case CINCVAL:
            printf("Coefficient c has incorrect value\n");
            break;
	    case DINCVAL:
            printf("Discriminant has incorrect value\n");
            break;
        default:
            printf("There is an error somewhere, good luck in finding it\n");
            break;
    }
}