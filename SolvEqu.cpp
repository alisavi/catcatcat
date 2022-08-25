#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "enum.h"
#include "SolvEqu.h"

const double Eps = 1e-6;

int iszero(double a)
{
	return (fabs(a) < Eps);
}

double discriminant(double a, double b, double c)
{
	return b*b - 4*a*c;
}

int solve_line_case(double b, double c, double* x1)
{
	/*if (x1 == NULL)
		return X1NULL;

	if (!isfinite(b))
		return BINCVAL;

	if (!isfinite(c))
		return CINCVAL;*/

	assert(x1 != NULL);
	assert(isfinite(b));
	assert(isfinite(c));

	if (!iszero(b))
	{
		*x1 = -c/b;
		return ONEROOT;
	}

	else if (!iszero(c)) return NOROOTS;
	else return INFINITE;
}

/**
 * Solves a square equation a*x^2 + b*x + c = 0;
 *
 * @brief Solving of quadratic equation
 * @file ios.h
 *
 * @param[in] a a - coefficient
 * @param[in] b b - coefficient
 * @param[in] c c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return Program exit status
 *
*/
int solve_quad_case(double a, double b, double c, double* x1, double* x2)
{
	/*if (x1 == NULL)
		return X1NULL;

	if (x2 == NULL)
		return X2NULL;

    if (x1 == x2)
		return X1EQUX2;
	
	if (!isfinite(a))
		return AINCVAL;

	if (!isfinite(b))
		return BINCVAL;

	if (!isfinite(c))
		return CINCVAL;*/

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	double d = discriminant(a, b, c);
    a = 2 * a;

	/*if (!isfinite(d))
		return DINCVAL;*/

	assert(isfinite(d));

	if (iszero(d))
	{
		*x1 = -b / a;
		return ONEROOT;
	}

	else if (d > 0)
	{
		d = sqrt(d);
		*x1 = (-b + d) / a;
		*x2 = (-b - d) / a;
		return TWOROOTS;
	}

	else
	{
		*x1 = -b / a;
		*x2 = fabs(sqrt(-d)/ a);
		return IRRROOTS;
	}
}

int solution(double a, double b, double c, double* x1, double* x2)
{
	/*if (x1 == NULL)
		return X1NULL;

	if (x2 == NULL)
		return X2NULL;

    if (x1 == x2)
		return X1EQUX2;
	
	if (!isfinite(a))
		return AINCVAL;

	if (!isfinite(b))
		return BINCVAL;

	if (!isfinite(c))
		return CINCVAL;*/

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	if (iszero(a)) 
        return solve_line_case(b, c, x1);
	else
		return solve_quad_case(a, b, c, x1, x2);
}