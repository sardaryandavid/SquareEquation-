#include <cassert>
#include <cmath>
#include <stdio.h>
#include "tests.h"
#include "solveEquation.h"

void startAllUnitTestsForSquareEquation() {
    unitTestSquareEquation("testSquareEquationAllCoeffsZero"                       , 0, 0, 0 , infRoots, 0 , 0);
    unitTestSquareEquation("testSquareEquationAllCoeffsZeroExceptC"                , 0, 0, 1 , noRoots , 0 , 0);
    unitTestSquareEquation("testSquareEquationAllCoeffsZeroExceptB"                , 0, 1, 0 , oneRoot , 0 , 0);
    unitTestSquareEquation("testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero" , 0, 1, 1 , oneRoot , -1, 0);
    unitTestSquareEquation("testSquareEquationAllCoeffsZeroExceptA"                , 1, 0, 0 , oneRoot , 0 , 0);
    unitTestSquareEquation("testSquareEquationsTheSquareRootOfNegativeNumber"      , 1, 0, 1 , noRoots , 0 , 0);
    unitTestSquareEquation("testSquareEquationsTheSquareRootOfPositiveNumber"      , 1, 0, -1, twoRoots, 1 , -1);
    unitTestSquareEquation("testSquareEquationDiscriminantIsNegative"              , 1, 1, 1 , noRoots , 0 , 0);
    unitTestSquareEquation("testSquareEquationDiscriminantIsZero"                  , 1, 2, 1 , oneRoot , -1, -1);
    unitTestSquareEquation("testSquareEquationDiscriminantIsPositive"              , 1, -5, 4, twoRoots, 4 , 1);
    unitTestSquareEquation("testSquareEquationAllCoeffsNotZeroExceptC"             , 1, 1 , 0, twoRoots, 0, -1);
}

void unitTestSquareEquation(
    const char* testName,
    const double a, const double b, const double c,
    const int rootsNumberRef,
    const double x1Ref, const double x2Ref
) {
        double x1 = 0;
        double x2 = 0;
        int rootsNumber = solveSquareEquation(a, b, c, &x1, &x2);
        if(!isZero(rootsNumber - rootsNumberRef) || !isZero(x1 - x1Ref) || !isZero(x2 - x2Ref)) {
            printf(
               "Error! Test %s! Right answer: "
               "roots number = %d, x1 = %lf, x2 = %lf\n",
               testName, rootsNumberRef, x1Ref, x2Ref
            );
            printf(
                "Program answer: roots number = %d, "
                "x1 = %lf, x2 = %lf\n",
                rootsNumber, x1, x2
            );
        }
        else {
            printf("Test passed\n");
        }
}
