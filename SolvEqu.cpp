#include <stdio.h>
#include <math.h>
#include "enum.h"
#include "SolvEqu.h"

const double Eps = 1e-4;///< const for comparison double with 0

/**
 * @brief 
 * 
 * @param a a - compared argument
 * @return result of the comparison (1 for true, 0 for false)
 */
int iszero(const double a)
{
	return (fabs(a) < Eps);
}



/**
 * @brief counting discriminant
 * 
 * @param a a - coefficient
 * @param b b - coefficient
 * @param c c - coefficient
 * 
 * @return discriminant for the quadratic equation
 */
double calc_discr(struct coeffs us_coeff)
{
	return us_coeff.b*us_coeff.b - 4*us_coeff.a*us_coeff.c;
}

/**
 * @brief solving of linear case
 * 
 * @param b b - coefficient
 * @param c c - coefficient
 * @param x1 x1 - pointer to the root
 * 
 * @return number and typeof roots in the linear equation
 */
int solve_line_case(struct coeffs us_coeff, double* x1)
{
	/*if (x1 == NULL)
		return X1NULL;
	if (!isfinite(b))
		return BINCVAL;
	if (!isfinite(c))
		return CINCVAL;*/

	ASSERT(x1 != NULL);
	

	if (!iszero(us_coeff.b))
	{
		*x1 = -us_coeff.c/us_coeff.b;
		return ONEROOT;
	}

	else if (!iszero(us_coeff.c)) return NOROOTS;
	else return INFINITE;
}

/**
 * @brief solving of quadratic case
 * 
 * 
 * @param[in] a a - coefficient
 * @param[in] b b - coefficient
 * @param[in] c c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return number and typeof roots in the quadratic equation
 *
*/ 
int solve_quad_case(struct coeffs us_coeff, double* x1, double* x2)
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

	ASSERT(x1 != NULL);
	ASSERT(x2 != NULL);
	ASSERT(x1 != x2);

	double d = calc_discr(us_coeff);
    us_coeff.a = 2 * us_coeff.a;

	/*if (!isfinite(d))
		return DINCVAL;*/

	ASSERT(isfinite(d));

	if (iszero(d))
	{
		*x1 = -us_coeff.b / us_coeff.a;
		return ONEROOT;
	}

	else if (d > 0)
	{
		d = sqrt(d);
		*x1 = (-us_coeff.b + d) / us_coeff.a;
		*x2 = (-us_coeff.b - d) / us_coeff.a;
		return TWOROOTS;
	}

	else
	{
		*x1 = -us_coeff.b / us_coeff.a;
		*x2 = fabs(sqrt(-d)/ us_coeff.a);
		return IRRROOTS;
	}
}

/**
 * @brief solving equation
 * 
 * Solves a square equation a*x^2 + b*x + c = 0;
 * 
 * @param[in] a a - coefficient
 * @param[in] b b - coefficient
 * @param[in] c c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return number and typeof roots in the equation
 *
 */
int solution(struct coeffs us_coeff, double* x1, double* x2)
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

	ASSERT(x1 != NULL);
	ASSERT(x2 != NULL);
	ASSERT(x1 != x2);

	if (iszero(us_coeff.a)) 
        return solve_line_case(us_coeff, x1);
	else
		return solve_quad_case(us_coeff, x1, x2);
}