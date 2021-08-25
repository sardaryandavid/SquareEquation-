#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

extern double PRECISION;

/**
 *   This function launches other tests \n
 *   These tests check whether the program gives the correct answers in particular cases
 *   If the program gives the correct answer nothing will happen
 *   Otherwise, there will be an error message
 *   @return if the program passed all the tests, nothing will happen. Otherwise, an error
 *           message will be displayed

*/
void startAllTestsForSquareEquation();

void testSquareEquationAllCoeffsZero();
void testSquareEquationAllCoeffsZeroExceptC();
void testSquareEquationAllCoeffsZeroExceptB();
void testSquareEquationAisZeroTheLastestTwoCoeffsIsNotZero();
void testSquareEquationAllCoeffsZeroExceptA();
void testSquareEquationsTheSquareRootOfNegativeNumber();
void testSquareEquationsTheSquareRootOfPositiveNumber();
void testSquareEquationDiscriminantIsNegative();
void testSquareEquationDiscriminantIsZero();
void testSquareEquationDiscriminantIsPositive();

#endif // TESTS_H_INCLUDED
