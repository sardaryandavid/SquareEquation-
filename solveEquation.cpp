#include <cassert>
#include <cmath>

const double PRECISION = 1e-6;

enum roots_number {INF = -1, noRoots = 0, oneRoot = 1, twoRoots = 2};

int isZero(double a);

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
