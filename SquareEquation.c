#include <stdio.h>

int SolveSquareEquation(double a, double b, double c);
int equal(double a, double b);
int isZero(double a);
int isPositive(double a);
int isNegative(double a);
void print(int result);
double x1 = 0;
double x2 = 0;
int result = 0;

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    printf("This program solve equation of the following type: ax^2 + bx + c = 0\n");
    printf("Please, enter:\n");

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    SolveSquareEquation(a, b, c);

    print(result);

    return 0;
}

int SolveSquareEquation(double a, double b, double c) {
    int result = 0;
    if(a == 0) {
        if(b == 0) {
            if(c == 0) {
                printf("unlimited number of roots");
                result = 1;
            }
            else {
                printf("No roots in real numbers");
                result = 1;
            }
        }
        else
            x1 = x2 = -c / a;
    }

    else {
        if(b == 0) {
            if(c == 0)
                x1 = x2 = 0;
            else {
                if(c/a < 0) {
                    printf("No roots");
                    result = 1;
                }
                else {
                    x1 = c / a;
                    x2 = -c / a;
                }
            }
        }
        else {
            double discriminant = b * b - 4 * a * c;
            if(isZero(discriminant))
                x1 = x2 = -b / (2 * a);
            if(isNegative(discriminant))
            {
                printf("No roots");
                result = 1;
            }
            if(isPositive(discriminant))
                x1 = (-b + sqrt(discriminant))/ (2 * a);
                x2 = (-b - sqrt(discriminant))/ (2 * a);
        }

    }
   return result;
}

int equal(double a, double b) {
    if((a - b) >= -1e-6 && (a - b) <= 1e-6)
        return 1;
    else
        return 0;
}

int isZero(double a) {
    if(a <= 1e-6 && a >= -1e-6)
        return 1;
    else
        return 0;
}

int isPositive(double a) {
    if(a > 1e-6)
        return 1;
    else
        return 0;
}

int isNegative(double a) {
    if(a < -1e-6)
        return 1;
    else
        return 0;
}

void print(int result) {
    if(!result)
        if(equal(x1, x2))
            printf("%lf", x1);
        else {
            printf("x1 = %.6lf\n", x1);
            printf("x2 = %.6lf\n", x2);
        }
}
