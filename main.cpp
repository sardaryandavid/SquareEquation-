#include <cstdio>
#include <cassert>
#include <cmath>
#include "tests.h"
#include "solveEquation.h"

const double PRECISION = 1e-6;

enum roots_number {INF = -1, noRoots = 0, oneRoot = 1, twoRoots = 2};

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
