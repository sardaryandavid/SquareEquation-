#include <cassert>
#include <math.h>
#include <stdio.h>
#include "solveEquation.h"

const double PRECISION = 1e-6;

int solveSquareEquation(double a, double b, double c, double *x1, double *x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(b));

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
        *x2 = +c / a;
        return twoRoots;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < -PRECISION) {
        return noRoots;
    }

    if(isZero(discriminant)) {
        *x1 = *x2 = -b / 2 * a;
        return oneRoot;
    }

    *x1 = (-b + sqrt(discriminant))/ (2 * a);
    *x2 = (-b - sqrt(discriminant))/ (2 * a);

    return twoRoots;
}

int solveLinearEquation(double a, double b, double *x) {
    if(isZero(a)) {
        if(isZero(b)) {
            return infRoots;
        }

        return noRoots;
    }

    *x = -b / a;

    return oneRoot;
}

int isZero(double a) {
    if(isinf(a)) {
        return 0;
    }

    return (fabs(a) <= PRECISION);
}

