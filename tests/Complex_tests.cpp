#include "Complex_tests.h"
#include "TestMacros.h"

void testComplexAbs()
{
    dt::Complex complexValue(3, 4);
    double abs = dt::Complex::abs(complexValue);
    IS_TRUE(abs == 5.0);
    std::cout << "Complex abs test passed" << std::endl;
}
void testComplexSqrt()
{
    dt::Complex complexValue(5, 12);
    dt::Complex root = dt::Complex::sqrt(complexValue);
    IS_TRUE(root.getImg() == 2);
    IS_TRUE(root.getReal() == 3);
    std::cout << "Complex sqrt test passed" << std::endl;
}

void testComplexPlus()
{
    dt::Complex complexValue1(5, 12);
    dt::Complex complexValue2(50, 120);
    dt::Complex additionResult = complexValue1 + complexValue2;
    IS_TRUE(additionResult.isEqual(dt::Complex(55, 132)));
    std::cout << "Complex plus test passed" << std::endl;
}
void testComplexStar()
{
    dt::Complex complexValue1(5, 12);
    dt::Complex complexValue2(50, 120);
    dt::Complex multiplicationResult = complexValue1 * complexValue2;
    IS_TRUE(multiplicationResult.isEqual(dt::Complex(-1190, 1200)));
    std::cout << "Complex plus test passed" << std::endl;
}

void testComplex()
{
    testComplexPlus();
    testComplexStar();
    testComplexAbs();
    testComplexSqrt();
    std::cout << "COMPLEX TESTS PASSED" << std::endl;
};