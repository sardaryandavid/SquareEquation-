#ifndef SOLVEEQUATION_H_INCLUDED
#define SOLVEEQUATION_H_INCLUDED

enum roots_number {
    infRoots = -1,
    noRoots,
    oneRoot,
    twoRoots
};

/**
 *   This program solves quadratic equation \n
 *   The function returns the number of roots of the quadratic equation \n
 *   And also finds the roots of the quadratic equation. \n
 *
 *   @param [in] a - coefficient before $x^2$
 *   @param [in] b - coefficient before $x$
 *   @param [in] c - the free term of the equation
 *   @param [out] $x_1$ - root of the equation. The program changes the value at the address
 *   @param [out] $x_2$ - root of the equation. The program changes the value at the address
 *   @return The number of the roots
*/
int solveSquareEquation(double a, double b, double c, double *x1, double *x2);

/**
 *   This function solves linear equation
 *   @param [in] a - coefficient before x
 *   @param [in] b - the free term of the equation
 *   @param [out] x - root of the equation. The program changes the value at the address
 *   @return The number of the roots
*/
int solveLinearEquation(double a, double b, double *x);

/**
 *   This function checks whether the number is zero
 *   @param [in] a - the number that is compared with zero
 *   @return if a is zero the program returns 1, else 0
*/
int isZero(double a);

#endif // SOLVEEQUATION_H_INCLUDED
