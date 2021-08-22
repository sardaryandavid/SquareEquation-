#include <cassert>
#include <cmath>

const double PRECISION = 1e-6;

enum roots_number {infRoots = -1, noRoots = 0, oneRoot = 1, twoRoots = 2};

int isZero(double a);
int solveLinearEquation(double a, double b, double *x);

int solveSquareEquation(double a, double b, double c, double *x1 = 0, double *x2 = 0) {
    assert(x1 != nullptr && x2 != nullptr);
    assert(std::isfinite(a) && std::isfinite(b) && std::isfinite(b));

    if (isZero(a)) {
        int roots_number = solveLinearEquation(b, c, x1);
        *x2 = *x1;
        return roots_number;
    }

    if (isZero(b)) {
        if (isZero(c)) {
            *x1 = *x2 = 0;
            return oneRoot;
        }

        if (-c / a < -PRECISION) {
            return noRoots;
        }

        *x1 = -c / a;
        *x2 = c / a;
        return twoRoots;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < -PRECISION) {
        return noRoots;
    }

    *x1 = (-b + sqrt(discriminant))/ (2 * a);
    *x2 = (-b - sqrt(discriminant))/ (2 * a);
    if (isZero(discriminant)) {
        return oneRoot;
    }

    return twoRoots;
}

int solveLinearEquation(double a, double b, double *x) {
    if(a == 0) {
        if(b == 0)
            return infRoots;

        return noRoots;
    }

    *x = -b / a;
    return 1;
}

int isZero(double a) {
    assert(std::isfinite(a));

    return (fabs(a) <= PRECISION);
}
