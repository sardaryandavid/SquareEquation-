#include <cstdio>
#include <cassert>
#include <math.h>

#include "solveEquation.h"
#include "tests.h"

#define TESTS

/**
 *  This function prints the roots of the equation (or their number)
 *
 *  @param x_1 - the root of the equation
 *  @param x_2 - the root of the equation
 *  @param roots_number - number of the roots
*/

void printRoots(const double x1, const double x2, const int roots_number);

/**
 *   This function reads data and prints answer
 *   @return The roots of the equation
*/

void launchProgram();

int main()
{
    #ifdef TESTS
        printf("Start testing\n");
        startAllTestsForSquareEquation();
        printf("All tests passed\n");
    #else
        launchProgram();
    #endif

    return 0;
}

void launchProgram() {
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
}

void printRoots(const double x1, const double x2, const int roots_number) {
    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(abs(roots_number) <= 2);

    switch(roots_number) {
        case noRoots:
            printf("No roots\n");
            break;
        case oneRoot:
            printf("x1 = %lf\n", x1);
            break;
        case twoRoots:
            printf("x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case infRoots:
            printf("Unlimited number of roots, %lf, %lf\n");
            break;
        default:
            printf("Something went wrong\n");
            break;
    }
}

