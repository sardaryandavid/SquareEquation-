#include <cstdio>
#include <cassert>
#include <math.h>
#include "solveEquation.h"
#include "tests.h"

//#define TESTS

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

/**
 *   This function read coefficient
 *   @param [out] - change coefficient by address
*/
void readCoefficient(const char symbol, double *coefficient);

int main()
{
#ifdef TESTS
    printf("Start testing!\n");
    startAllUnitTestsForSquareEquation();
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

    readCoefficient('a', &a);
    readCoefficient('b', &b);
    readCoefficient('c', &c);

//    printf("a = "); //! TODO
//    scanf("%lf", &a);
//
//    printf("b = ");
//    scanf("%lf", &b);
//
//    printf("c = ");
//    scanf("%lf", &c);

    double x1 = 0;
    double x2 = 0;

    int roots_number = solveSquareEquation(a, b, c, &x1, &x2);

    printRoots(x1, x2, roots_number);
}

void printRoots(const double x1, const double x2, const int roots_number) {
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch(roots_number) {
        case noRoots:
            printf("No roots\n");
            break;

        case oneRoot:
            printf("x = %lf\n", x1);
            break;

        case twoRoots:
            printf("x1 = %lf, x2 = %lf\n", x1, x2);
            break;

        case infRoots:
            printf("Unlimited number of roots\n");
            break;

        default:
            printf("Error. Wrong number of roots: %d\n", roots_number);
            break;
    }
}

void readCoefficient(const char symbol, double *coefficient) {
    int success = 0;
    char readSymbol;

    printf("%c = ", symbol);

    while(success == 0) {
        if (scanf("%lf", coefficient) == 0) {
            fflush(stdin);
            printf("Please, enter the number:\n");
            printf("%c = ", symbol);
        }

        else {
            while((readSymbol = getchar()) != '\n') {
                if(!(readSymbol >= '0' && readSymbol <= '9')) {
                    printf("Please, enter the number:\n");
                    printf("%c = ", symbol);
                    fflush(stdin);
                }
            }
            success += 1;
        }
    }
}

