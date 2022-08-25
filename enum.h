/** @brief Solving of quadratic equation
 * Solves a square equation a*x^2 + b*x + c = 0;
 * @file ios.h
 * @param[in] a a - coefficient
 * @param[in] b b - coefficient
 * @param[in] c c - coefficient
 * @param[out] x1 x1 - pointer to the first root
 * @param[out] x2 x2 - pointer to the first root
 * 
 * @return Program exit status
 *
 */

#ifndef ENUM_H
#define ENUM_H

enum TypeOfRoots
{
	NOROOTS,
	ONEROOT,
	TWOROOTS,
	IRRROOTS = -2,
	INFINITE = -1
};

enum ErrCodes
{
    X1NULL = -10,
	X2NULL,
    X1EQUX2,
    AINCVAL,
    BINCVAL,
    CINCVAL,
	DINCVAL
};

#endif