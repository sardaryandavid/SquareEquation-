#include <stdio.h>
#include <assert.h>

#define INF -1

int solveSquareEquation(double a, double b, double c, double *x1, double *x2);
int equal(double a, double b);
int isZero(double a);
void printRoots(double x1, double x2, int roots_number);

void testSquareEquationAllCoeffsZero();
void testSquareEquationAllCoeffsZeroExceptC();
void testSquareEquationAllCoeffsZeroExceptB();
void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero();
void testSquareEquationAllCoeffsZeroExceptA();
void testSquareEquationsTheSquareRootOfPositiveNumber();
void testSquareEquationDiscriminantIsNegative();
void testSquareEquationDiscriminantIsZero();
void testSquareEquationDiscriminantIsPositive();

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    int roots_number = 0;

    void testSquareEquationAllCoeffsZero();
    void testSquareEquationAllCoeffsZeroExceptC();
    void testSquareEquationAllCoeffsZeroExceptB();
    void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero();
    void testSquareEquationAllCoeffsZeroExceptA();
    void testSquareEquationsTheSquareRootOfPositiveNumber();
    void testSquareEquationDiscriminantIsNegative();
    void testSquareEquationDiscriminantIsZero();
    void testSquareEquationDiscriminantIsPositive();

    printf("This program solves equations of the following type: ax^2 + bx + c = 0\n");
    printf("Please, enter:\n");

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    roots_number = solveSquareEquation(a, b, c, &x1, &x2);

    printRoots(x1, x2, roots_number);

    return 0;
}

int solveSquareEquation(double a, double b, double c,double *x1, double *x2) {
    int roots_number = 0;
    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c))
               roots_number = INF;
            else
               roots_number = 0;
        }
        else {
            roots_number = 1;
            *x1 = *x2 = -c / b;
        }
    }

    else {
        if (isZero(b)) {
            if (isZero(c)) {
                roots_number = 1;
                *x1 = *x2 = 0;
            }
            else {
                if (c / a < -1e-6)
                    roots_number = 0;
                else {
                    roots_number = 2;
                    *x1 = c / a;
                    *x2 = -c / a;
                }
            }
        }
        else {
            double discriminant = b * b - 4 * a * c;
            if (discriminant < -1e-6)
                roots_number = 0;
            if (discriminant >= -1e-6) {
                *x1 = (-b + sqrt(discriminant))/ (2 * a);
                *x2 = (-b - sqrt(discriminant))/ (2 * a);
                if(!isZero(discriminant))
                    roots_number = 2;
                else
                    roots_number = 1;
            }
        }

    }
    return roots_number;
}

int isZero(double a) {
    return (fabs(a) <= 1e-6);
}

void printRoots(double x1, double x2, int roots_number) {
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
    case INF:
        printf("Unlimited number of roots");
        break;
    }
}

void testSquareEquationAllCoeffsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 0, &x1, &x2) == INF && x1 == 0 && x2 == 0);
}

void testSquareEquationAllCoeffsZeroExceptC() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 0, 1, &x1, &x2) == 0 && x1 == 0 && x2 == 0);
}

void testSquareEquationAllCoeffsZeroExceptB() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 0, &x1, &x2) == 0 && x1 == 0 && x2 == 0);
}

void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(0, 1, 1, &x1, &x2) == 1 && x1 == -1 && x2 == -1);
}

void testSquareEquationAllCoeffsZeroExceptA() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 0, &x1, &x2) == 1 && x1 == 0 && x2 == 0);
}

void testSquareEquationsTheSquareRootOfNegativeNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, 1, &x1, &x2) == 0 && x1 == 0 && x2 == 0);
}

void testSquareEquationsTheSquareRootOfPositiveNumber() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 0, -1, &x1, &x2) == 2 && x1 == 1 && x2 == -1);
}

void testSquareEquationDiscriminantIsNegative() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 1, 1, &x1, &x2) == 0 && x1 == 0 && x2 == 0);
}

void testSquareEquationDiscriminantIsZero() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, 2, 1, &x1, &x2) == 1 && x1 == -1 && x2 == -1);
}

void testSquareEquationDiscriminantIsPositive() {
    double x1 = 0;
    double x2 = 0;
    assert(solveSquareEquation(1, -5, 4, &x1, &x2) == 2 && x1 == 4 && x2 == 1);
}
