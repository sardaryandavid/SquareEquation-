#include <cstdio>
#include <cassert>
#include <cmath>
#include "tests.h"

const double PRECISION = 1e-6;

enum roots_number {INF = -1, noRoots = 0, oneRoot = 1, twoRoots = 2};

int solveSquareEquation(double a, double b, double c, double *x1, double *x2);
int isZero(double a);
void printRoots(double x1, double x2, int roots_number);

int main()
{
    testSquareEquationAllCoeffsZero();
    testSquareEquationAllCoeffsZeroExceptC();
    testSquareEquationAllCoeffsZeroExceptB();
    testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero();
    testSquareEquationAllCoeffsZeroExceptA();
    testSquareEquationsTheSquareRootOfPositiveNumber();
    testSquareEquationDiscriminantIsNegative();
    testSquareEquationDiscriminantIsZero();
    testSquareEquationDiscriminantIsPositive();
    testSquareEquationsTheSquareRootOfNegativeNumber();

    printf("This program solves equations of the following type: ax^2 + bx + c = 0\n");
    printf("Please, enter:\n");

    double a = 0;
    double b = 0;
    double c = 0;

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    double x1 = 0;
    double x2 = 0;

    int roots_number = solveSquareEquation(a, b, c, &x1, &x2);

    printRoots(x1, x2, roots_number);

    return 0;
}

int solveSquareEquation(double a, double b, double c, double *x1, double *x2) {

    assert(x1 != nullptr && x2 != nullptr);
    assert(std::isfinite(a) && std::isfinite(b) && std::isfinite(b));

    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c))
               return INF;
            return noRoots;
        }
        *x1 = *x2 = -c / b;
        return oneRoot;
    }

    if (isZero(b)) {
        if (isZero(c)) {
            *x1 = *x2 = 0;
            return oneRoot;
        }
        if (-c / a < -PRECISION)
            return noRoots;
        *x1 = -c / a;
        *x2 = c / a;
        return twoRoots;
    }
    else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < -PRECISION)
            return noRoots;
        *x1 = (-b + sqrt(discriminant))/ (2 * a);
        *x2 = (-b - sqrt(discriminant))/ (2 * a);
        if (!isZero(discriminant))
            return twoRoots;
        return oneRoot;
    }
}

int isZero(double a) {
    assert(std::isfinite(a));

    return (fabs(a) <= PRECISION);
}

void printRoots(double x1, double x2, int roots_number) {
    assert(std::isfinite(x1) && std::isfinite(x2) && std::abs(roots_number) <= 2);

    switch(roots_number) {
    case 0:
        printf("No roots");
        break;
    case 1:
        printf("x1 = x2 = %lf", x1);
        break;
    case 2:
        printf("x1 = %lf, x2 = %lf", x1, x2);
        break;
    case -1:
        printf("Unlimited number of roots");
        break;
    }
}

void testSquareEquationAllCoeffsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 0, &x1, &x2) == INF && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptC() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 1, &x1, &x2) == 0 && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptB() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 0, &x1, &x2) == 1 && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 1, &x1, &x2) == 1 && abs(x1+1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationAllCoeffsZeroExceptA() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 0, &x1, &x2) == 1 && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationsTheSquareRootOfNegativeNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 1, &x1, &x2) == 0 && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationsTheSquareRootOfPositiveNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, -1, &x1, &x2) == 2 && abs(x1-1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationDiscriminantIsNegative() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 1, 1, &x1, &x2) == 0 && abs(x1) < PRECISION && abs(x2) < PRECISION);
}

void testSquareEquationDiscriminantIsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 2, 1, &x1, &x2) == 1 && abs(x1+1) < PRECISION && abs(x2+1) < PRECISION);
}

void testSquareEquationDiscriminantIsPositive() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, -5, 4, &x1, &x2) == 2 && abs(x1-4) < PRECISION && abs(x2-1) < PRECISION);
}

