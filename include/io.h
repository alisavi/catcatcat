/**
 * @file io.h
 *
 * @brief reading user's coefficients and writing the result
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SOLV_IO_H
#define SOLV_IO_H

#include "enum.h"

void ShowHelp();
void input(double* a, double* b, double* c);
void output(TypeOfRoots n, double x1, double x2);
void InputBuffClean();
int  ExecSpecialOption(int f);

#endif