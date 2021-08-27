#include <cassert>
#include <math.h>
#include <stdio.h>
#include "solveEquation.h"

const double PRECISION = 1e-6;

int solveSquareEquation(const double a, const double b, const double c, double *x1, double *x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (isZero(a)) {
        int rootsNumber = solveLinearEquation(b, c, x1);
        return rootsNumber;
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
        *x2 =  c / a;
        return twoRoots;
    }

    if (c == 0) {
        *x1 = 0;
        int rootsNumber = solveLinearEquation(a, b, x2);
        if(rootsNumber == infRoots) {
            return rootsNumber;
        }

        return rootsNumber + oneRoot;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < -PRECISION) {
        return noRoots;
    }

    if (isZero(discriminant)) {
        *x1 = *x2 = -b / (2 * a);
        return oneRoot;
    }

    *x1 = (-b + sqrt(discriminant))/ (2 * a);
    *x2 = (-b - sqrt(discriminant))/ (2 * a);

    return twoRoots;
}

int solveLinearEquation(const double a, const double b, double *x) {
    if (isZero(a)) {
        if (isZero(b)) {
            return infRoots;
        }

        return noRoots;
    }

    *x = -b / a;

    return oneRoot;
}

int isZero(const double value) {
    return (fabs(value) <= PRECISION);
}


