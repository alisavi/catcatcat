#include <stdio.h>
#include <math.h>
#include "../include/enum.h"
#include "../include/SolvEqu.h"

const double Eps = 1e-4;///< const for comparison double with 0

/**
 * @brief 
 * 
 * @param a a - compared argument
 * @return result of the comparison (1 for true, 0 for false)
 */
int IsZero(const double a)
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
double CalcDiscr(struct coeffs UsCoeff)  
{
	return UsCoeff.b * UsCoeff.b - 4 * UsCoeff.a * UsCoeff.c;
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
int SolveLineCase(struct coeffs UsCoeff, double* x1)
{
	/*if (x1 == NULL)
		return X1NULL;
	if (!isfinite(b))
		return BINCVAL;
	if (!isfinite(c))
		return CINCVAL;*/

	ASSERT(x1 != NULL);
	

	if (!IsZero(UsCoeff.b))
	{
		*x1 = -UsCoeff.c/UsCoeff.b;
		return ONEROOT;
	}

	else if (!IsZero(UsCoeff.c)) return NOROOTS;
	else return INFINITE;
}

/**
 * @brief solving of quadratic case
 * 
 * 
 * @param[in]  a  a - coefficient
 * @param[in]  b  b - coefficient
 * @param[in]  c  c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return number and typeof roots in the quadratic equation
 *
*/ 
int SolveQuadCase(struct coeffs UsCoeff, double* x1, double* x2)
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

	double d = CalcDiscr(UsCoeff);
    UsCoeff.a = 2 * UsCoeff.a;

	/*if (!isfinite(d))
		return DINCVAL;*/

	ASSERT(isfinite(d));

	if (IsZero(d))
	{
		*x1 = -UsCoeff.b / UsCoeff.a;
		return ONEROOT;
	}

	else if (d > 0)
	{
		d = sqrt(d);
		*x1 = (-UsCoeff.b + d) / UsCoeff.a;
		*x2 = (-UsCoeff.b - d) / UsCoeff.a;
		return TWOROOTS;
	}

	else
	{
		*x1 = -UsCoeff.b / UsCoeff.a;
		*x2 = fabs(sqrt(-d)/ UsCoeff.a);
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
int GetSolution(struct coeffs UsCoeff, double* x1, double* x2)
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

	// std::isfinite()
	// isinf + isnan 

	if (IsZero(UsCoeff.a)) 
        return SolveLineCase(UsCoeff, x1);
	else
		return SolveQuadCase(UsCoeff, x1, x2);
}