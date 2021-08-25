#include <cassert>
#include <cmath>
#include "tests.h"
#include "solveEquation.h"
#include <cstdio>

void startAllTestsForSquareEquation() {
    testSquareEquationAllCoeffsZero();

    testSquareEquationAllCoeffsZeroExceptC();
    testSquareEquationAllCoeffsZeroExceptB();
    testSquareEquationAllCoeffsZeroExceptA();

    testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero();


    testSquareEquationsTheSquareRootOfNegativeNumber();
    testSquareEquationsTheSquareRootOfPositiveNumber();

    testSquareEquationDiscriminantIsNegative();
    testSquareEquationDiscriminantIsZero();
    testSquareEquationDiscriminantIsPositive();
}

void testSquareEquationAllCoeffsZero() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(0, 0, 0, &x1, &x2) == infRoots);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationAllCoeffsZeroExceptC() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(0, 0, 1, &x1, &x2) == noRoots);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationAllCoeffsZeroExceptB() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(0, 1, 0, &x1, &x2) == oneRoot);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(0, 1, 1, &x1, &x2) == oneRoot);
    assert(isZero(x1+1));
    assert(isZero(x2+1));
}

void testSquareEquationAllCoeffsZeroExceptA() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(1, 0, 0, &x1, &x2) == oneRoot);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationsTheSquareRootOfNegativeNumber() {
    double x1 = 0;
    double x2 = 0;

    assert(solveSquareEquation(1, 0, 1, &x1, &x2) == noRoots);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationsTheSquareRootOfPositiveNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, -1, &x1, &x2) == twoRoots);
    assert(isZero(x1-1));
    assert(isZero(x2+1));
}

void testSquareEquationDiscriminantIsNegative() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 1, 1, &x1, &x2) == noRoots);
    assert(isZero(x1));
    assert(isZero(x2));
}

void testSquareEquationDiscriminantIsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 2, 1, &x1, &x2) == oneRoot);
    assert(isZero(x1+1));
    assert(isZero(x2+1));
}

void testSquareEquationDiscriminantIsPositive() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, -5, 4, &x1, &x2) == twoRoots);
    assert(isZero(x1-4));
    assert(isZero(x2-1));
}
