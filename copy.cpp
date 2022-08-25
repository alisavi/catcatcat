#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solv.h"
#include "io.h"

const double zero = 0.0000001;

enum TypeOfRoots
{
	NOROOTS,
	ONEROOT,
	TWOROOTS,
	IRRROOTS,
	INFINITE
};

enum IsCorrect
{
	INCORRECT,
	CORRECT
};

IsCorrect iszero(double a)
{
	if (fabs(a) < zero) return CORRECT;
	else return INCORRECT;
}

void input(double* a, double* b, double* c)
{
	assert(a != NULL);
	assert(b != NULL);
	assert(c != NULL);

	printf("a*x^2 + b*x + c = 0\nInput a, b, c separated with spaces: ");

	while (scanf(" %lg %lg %lg", a, b, c) != 3)
	{
		printf("incorrect input, try again\n");
		while (getchar()!='\n');
	}
}

double discr(double a, double b, double c)  ////
{
	return b*b - 4*a*c;
}

TypeOfRoots linear(double b, double c, double* x1)
{
	assert(x1 != NULL);

	printf("уравнение не квадратное\n");

	if (!iszero(b))
	{
		*x1 = -c/b;
		return ONEROOT;
	}
	else if (!iszero(c)) return NOROOTS;
	else return INFINITE;
}

TypeOfRoots solution(double a, double b, double c, double* x1, double* x2)
{
	assert(x1 != NULL);
	assert(x2 != NULL);

	if (iszero(a)) return linear(b, c, x1);

	double d = discriminant(a, b, c);

	if (iszero(d))
	{
		*x1 = -b/2/a;
		return ONEROOT;
	}

	else if (d > 0)
	{
		*x1 = (-b + sqrt(d))/2/a;
		*x2 = (-b - sqrt(d))/2/a;
		return TWOROOTS;
	}

	else
	{
		*x1 = -b/2/a;
		*x2 = fabs(sqrt(-d)/2/a);
		return IRRROOTS;
	}
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

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;

	do
	{
		input(&a,&b,&c);

		TypeOfRoots numberofroots = solution(a,b,c,&x1,&x2);

		output(numberofroots, x1, x2);
		printf("Would you like to try again?(Y/n)\n");

		int f = getchar();

	}while(getchar() == 'Y');

	return 0;
}