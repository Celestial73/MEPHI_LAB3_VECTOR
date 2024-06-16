
#include <complex>
#include <cmath>

#include "Vector_tests.h"

typedef ds::Vector<int, intSquareRoot, getIntegerZero, getIntegerOne> IntegerVector;
typedef ds::Vector<dt::Complex, dt::Complex::sqrt, dt::Complex::getZero, dt::Complex::getOne> ComplexVector;

void testIntegerVectorSizeConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    IS_TRUE(vector.getSize() == 5);
    std::cout << "Integer Vector sizeConstructor test passed" << std::endl;
}

void testIntegerVectorItemsConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    IS_TRUE(vector.getSize() == 5);
    for (size_t i = 0; i < vector.getSize(); i++)
    {
        IS_TRUE(vector.get(i) == (i + 1));
    }
    std::cout << "Integer Vector itemsConstructor test passed" << std::endl;
}

void testIntegerVectorGetters()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    IS_TRUE(vector.getSize() == 5);
    IS_TRUE(vector.get(2) == 3);
    IS_TRUE(vector.get(4) == 5);
    std::cout << "Integer Vector getters test passed" << std::endl;
}

void testIntegerVectorCopyConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    IntegerVector copiedVector(vector);
    IS_TRUE(copiedVector.getSize() == 5);
    for (size_t i = 0; i < copiedVector.getSize(); i++)
    {
        IS_TRUE(vector.get(i) == (i + 1));
    }
    std::cout << "Integer Vector CopyConstructor test passed" << std::endl;
}

void testIntegerVectorSetters()
{
    try
    {
        int items[] = {1, 2, 3, 4, 5};
        IntegerVector vector(items, 5);
        vector.set(10, 0);
        IS_TRUE(vector.get(0) == 10);
        std::cout << "Integer Vector setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testIntegerVectorEqualsOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector1(items, 5);
    IntegerVector vector2(items, 5);
    IS_TRUE(vector1 == vector2);
    int itemsModified[] = {1, 2, 3, 4, 6};
    IntegerVector vector3(itemsModified, 5);
    IS_TRUE(!(vector1 == vector3));
    std::cout << "Integer Vector equalsOperator test passed" << std::endl;
}

void testIntegerVectorAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    IntegerVector assgnVec = vector;
    IS_TRUE(assgnVec.getSize() == 5);
    for (size_t i = 0; i < assgnVec.getSize(); i++)
    {
        IS_TRUE(assgnVec.get(i) == (i + 1));
    }
    std::cout << "Integer Vector assignmentOperator test passed" << std::endl;
}

void testIntegerVectorAddition()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector1(items, 5);
    IntegerVector vector2(items, 5);
    vector1.add(vector2);
    for (int i = 0; i < 5; i++)
    {
        IS_TRUE(vector1.get(i) == (i + 1) * 2);
    }
    std::cout << "Integer Vector addition test passed" << std::endl;
}

void testIntegerVectorMultiplicationByScalar()
{
    int items[] = {1, 2, 3, 4, 5};
    IntegerVector vector(items, 5);
    vector.multiplyByScalar(5);
    for (int i = 0; i < 5; i++)
    {
        IS_TRUE(vector.get(i) == (i + 1) * 5);
    }
    std::cout << "Integer Vector multiplicationByScalar test passed" << std::endl;
}

void testIntegerVectorNorm()
{
    int items[] = {3, 4};
    IntegerVector vector(items, 2);
    int res = vector.norm();
    IS_TRUE(res == 5);
    std::cout << "Integer Vector norm test passed" << std::endl;
}

void testIntegerVectorScalarMultiplication()
{
    int items[] = {1, 2, 3};
    IntegerVector vector1(items, 3);
    IntegerVector vector2(items, 3);
    int res = vector1.scalarMultiply(vector2);
    IS_TRUE(res == 14);
    std::cout << "Integer Vector scalarMultiplication test passed" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const dt::Complex getComplexZero()
{
    return dt::Complex(0, 0);
}

const dt::Complex getComplexOne()
{
    return dt::Complex(1, 0);
}

void testComplexVectorItemsConstructor()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector(items, 5);
    IS_TRUE(vector.getSize() == 5);
    std::cout << "Integer Vector sizeConstructor test passed" << std::endl;
}

void testComplexVectorGetters()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector(items, 5);
    IS_TRUE(vector.getSize() == 5);
    IS_TRUE(vector.get(2).isEqual(dt::Complex(3, 3)));
    IS_TRUE(vector.get(4).isEqual(dt::Complex(5, 5)));
    std::cout << "Complex Vector getters test passed" << std::endl;
}

void testComplexVectorCopyConstructor()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector(items, 5);
    ComplexVector copiedVector(vector);
    IS_TRUE(copiedVector.getSize() == 5);
    for (size_t i = 0; i < copiedVector.getSize(); i++)
    {
        IS_TRUE(vector.get(i).isEqual(dt::Complex(i + 1, i + 1)));
    }
    std::cout << "Complex Vector CopyConstructor test passed" << std::endl;
}

void testComplexVectorSetters()
{
    try
    {
        dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
        ComplexVector vector(items, 5);
        vector.set(dt::Complex(10, 10), 0);
        IS_TRUE(vector.get(0).isEqual(dt::Complex(10, 10)));
        std::cout << "Complex Vector setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testComplexVectorEqualsOperator()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector1(items, 5);
    ComplexVector vector2(items, 5);
    IS_TRUE(vector1 == vector2);
    dt::Complex itemsModified[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(2, 5)};
    ComplexVector vector3(itemsModified, 5);
    IS_TRUE(!(vector1 == vector3));
    std::cout << "Complex Vector equalsOperator test passed" << std::endl;
}

void testComplexVectorAssignmentOperator()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector(items, 5);
    ComplexVector assgnVec = vector;
    IS_TRUE(assgnVec.getSize() == 5);
    for (size_t i = 0; i < assgnVec.getSize(); i++)
    {
        IS_TRUE(assgnVec.get(i) == dt::Complex(i + 1, i + 1));
    }
    std::cout << "Complex Vector assignmentOperator test passed" << std::endl;
}

void testComplexVectorAddition()
{
    dt::Complex items[] = {dt::Complex(1, 1), dt::Complex(2, 2), dt::Complex(3, 3), dt::Complex(4, 4), dt::Complex(5, 5)};
    ComplexVector vector1(items, 5);
    ComplexVector vector2(items, 5);
    vector1.add(vector2);
    for (int i = 0; i < 5; i++)
    {
        IS_TRUE(vector1.get(i) == dt::Complex((i + 1) * 2, (i + 1) * 2));
    }
    std::cout << "Complex Vector addition test passed" << std::endl;
}

void testComplexVectorMultiplicationByScalar()
{
    dt::Complex items[] = {dt::Complex(2, 3), dt::Complex(4, 2)};
    ComplexVector vector(items, 5);
    vector.multiplyByScalar(dt::Complex(2, 1));
    IS_TRUE(vector.get(0) == dt::Complex(1, 8));
    IS_TRUE(vector.get(1) == dt::Complex(6, 8));
    std::cout << "Complex Vector multiplicationByScalar test passed" << std::endl;
}

void testComplexVectorNorm()
{
    dt::Complex items[] = {dt::Complex(3, 3), dt::Complex(4, 4)};
    ComplexVector vector(items, 2);
    dt::Complex res = vector.norm();
    IS_TRUE(res == dt::Complex(5, 5));
    std::cout << "Complex Vector norm test passed" << std::endl;
}

void testComplexVectorScalarMultiplication()
{
    dt::Complex items[] = {dt::Complex(3, 3), dt::Complex(4, 4)};
    ComplexVector vector1(items, 2);
    ComplexVector vector2(items, 2);
    dt::Complex res = vector1.scalarMultiply(vector2);
    IS_TRUE(res == dt::Complex(0, 50));
    std::cout << "Complex Vector scalarMultiplication test passed" << std::endl;
}

void testVector()
{
    testIntegerVectorSizeConstructor();
    testIntegerVectorItemsConstructor();
    testIntegerVectorCopyConstructor();
    testIntegerVectorEqualsOperator();
    testIntegerVectorAssignmentOperator();
    testIntegerVectorGetters();
    testIntegerVectorSetters();
    testIntegerVectorAddition();
    testIntegerVectorMultiplicationByScalar();
    testIntegerVectorNorm();
    testIntegerVectorScalarMultiplication();
    std::cout << "INTEGER VECTOR TESTS PASSED" << std::endl;

    testComplexVectorItemsConstructor();
    testComplexVectorCopyConstructor();
    testComplexVectorEqualsOperator();
    testComplexVectorAssignmentOperator();
    testComplexVectorGetters();
    testComplexVectorSetters();
    testComplexVectorAddition();
    testComplexVectorMultiplicationByScalar();
    testComplexVectorNorm();
    testComplexVectorScalarMultiplication();

    std::cout << "COMPLEX VECTOR TESTS PASSED" << std::endl;
}