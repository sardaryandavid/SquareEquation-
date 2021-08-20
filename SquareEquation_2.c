#include <stdio.h>
#include <assert.h>

#define INF -1

int SolveSquareEquation(double a, double b, double c, double *x1, double *x2);
int equal(double a, double b);
int isZero(double a);
void print_roots(double x1, double x2, int roots_number);

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    int roots_number = 0;

    printf("This program solves equations of the following type: ax^2 + bx + c = 0\n");
    printf("Please, enter:\n");

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    roots_number = SolveSquareEquation(a, b, c, &x1, &x2);

    print_roots(x1, x2, roots_number);

    return 0;
}

int SolveSquareEquation(double a, double b, double c,double *x1, double *x2) {
    int roots_number = 0;
    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c))
               roots_number = INF;
            else
               roots_number = 0;
        }
        else
            roots_number = 1;
            *x1 = *x2 = -c / b;
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
                if(!equal(*x1, *x2))
                    roots_number = 2;
                else
                    roots_number = 1;
            }
        }

    }
    return roots_number;
}

int equal(double a, double b) {
    return (fabs(a - b) <= 1e-6);
}

int isZero(double a) {
    return equal(a, 0);
}

void print_roots(double x1, double x2, int roots_number) {
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
