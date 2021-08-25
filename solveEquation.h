#ifndef SOLVEEQUATION_H_INCLUDED
#define SOLVEEQUATION_H_INCLUDED

/**
 *   This program solves quadratic equations \n
 *   The function returns the number of roots of the quadratic equation \n
 *   And also finds the roots of the quadratic equation. \n
 *
 *   @param [in] a - coefficient before $x^2$
 *   @param [in] b - coefficient before $x$
 *   @param [in] c - the free term of the equation
 *   @param [in] $x_1$ - root of the equation. The program changes the value at the address
 *   @param [in] $x_2$ - root of the equation. The program changes the value at the address
 *   @return The number of the roots
*/

int solveSquareEquation(double a, double b, double c, double *x1, double *x2);

/**
 *   This function solves linear equations
 *   @param [in] a - coefficient before x
 *   @param [in] b - the free term of the equation
 *   @param [in] x - root of the equation. The program changes the value at the address
 *   @return The number of the roots
*/

int solveLinearEquation(double a, double b, double *x);

#endif // SOLVEEQUATION_H_INCLUDED
