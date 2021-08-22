#include <cassert>
#include <cmath>
#include "solveEquation.h"

const double PRECISION = 1e-6;

enum roots_number {INF = -1, noRoots = 0, oneRoot = 1, twoRoots = 2};

void testSquareEquationAllCoeffsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 0, &x1, &x2) == INF && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptC() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 1, &x1, &x2) == noRoots && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptB() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 0, &x1, &x2) == oneRoot && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 1, &x1, &x2) == oneRoot && abs(x1+1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptA() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 0, &x1, &x2) == oneRoot && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationsTheSquareRootOfNegativeNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 1, &x1, &x2) == noRoots && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationsTheSquareRootOfPositiveNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, -1, &x1, &x2) == twoRoots && abs(x1-1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationDiscriminantIsNegative() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 1, 1, &x1, &x2) == noRoots && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationDiscriminantIsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 2, 1, &x1, &x2) == oneRoot && abs(x1+1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationDiscriminantIsPositive() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, -5, 4, &x1, &x2) == twoRoots && abs(x1-4) < PRECISION && abs(x2-1) < PRECISION);
}
