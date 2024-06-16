
#include <cmath>

#include "SquareMatrix_tests.h"
#include "../UI/PrintFunctions.h"

typedef ds::SquareMatrix<int, intSquareRoot, getIntegerZero, getIntegerOne> IntegerSquareMatrix;
typedef ds::SquareMatrix<dt::Complex, dt::Complex::sqrt, dt::Complex::getZero, dt::Complex::getOne> ComplexSquareMatrix;

void testIntegerSquareMatrixSizeConstructor()
{
    IntegerSquareMatrix squareMatrix(5);
    IS_TRUE(squareMatrix.getSize() == 5);
    std::cout << "Integer SquareMatrix sizeConstructor test passed" << std::endl;
}

void testIntegerSquareMatrixItemsConstructor()
{
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j])
        }
    }
    std::cout << "Integer SquareMatrix itemsConstructor test passed" << std::endl;
    delete[] itemPtrs;
}

void testIntegerSquareMatrixGetters()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    IS_TRUE(squareMatrix.getSize() == 5);
    IS_TRUE(squareMatrix.get(0, 0) == 1);
    IS_TRUE(squareMatrix.get(1, 1) == 7);
    IS_TRUE(squareMatrix.get(4, 4) == 25);
    std::cout << "Integer SquareMatrix getters test passed" << std::endl;
}

void testIntegerSquareMatrixCopyConstructor()
{
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);

    IntegerSquareMatrix copiedSquareMatrix(squareMatrix);
    IS_TRUE(squareMatrix.getSize() == 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j])
        }
    }
    std::cout << "Integer SquareMatrix CopyConstructor test passed" << std::endl;
}

void testIntegerSquareMatrixSetters()
{
    try
    {
        int **itemPtrs = createDummy2dIntegerArray(5);
        IntegerSquareMatrix squareMatrix(itemPtrs, 5);

        squareMatrix.set(10, 1, 1);
        IS_TRUE(squareMatrix.get(1, 1) == 10);
        std::cout << "Integer SquareMatrix setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testIntegerSquareMatrixEqualsOperator()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix1(itemPtrs, 5);
    IntegerSquareMatrix squareMatrix2(itemPtrs, 5);
    IS_TRUE(squareMatrix1 == squareMatrix2);
    squareMatrix1.set(100, 1, 1);
    IS_TRUE(!(squareMatrix1 == squareMatrix2));
    std::cout << "Integer SquareMatrix equalsOperator test passed" << std::endl;
}

// void testIntegerSquareMatrixAssignmentOperator()
// {
//     int items[] = {1, 2, 3, 4, 5};
//     IntegerSquareMatrix SquareMatrix(items, 5);
//     IntegerSquareMatrix assgnVec = SquareMatrix;
//     IS_TRUE(assgnVec.getSize() == 5);
//     for (size_t i = 0; i < assgnVec.getSize(); i++)
//     {
//         IS_TRUE(assgnVec.get(i) == (i + 1));
//     }
//     std::cout << "Integer SquareMatrix assignmentOperator test passed" << std::endl;
// }

void testIntegerSquareMatrixAddition()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix1(itemPtrs, 5);
    IntegerSquareMatrix squareMatrix2(itemPtrs, 5);
    squareMatrix1.add(squareMatrix2);
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix1.get(i, j) == items[i][j] * 2);
        }
    }
    std::cout << "Integer SquareMatrix addition test passed" << std::endl;
}

void testIntegerSquareMatrixMultiplicationByScalar()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int scalar = 5;
    squareMatrix.multiplyByScalar(scalar);
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j] * 5);
        }
    }
    std::cout << "Integer SquareMatrix multiplication By scalar test passed" << std::endl;
}

void testIntegerSquareMatrixNorm()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    int expecetedResult = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            expecetedResult += items[i][j] * items[i][j];
        }
    }
    IS_TRUE(squareMatrix.norm() == expecetedResult);
    std::cout << "Integer SquareMatrix norm test passed" << std::endl;
}

void testSwapRows()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int items[5][5] = {
        {11, 12, 13, 14, 15},
        {6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    squareMatrix.swapRows(0, 2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j]);
        }
    }
    std::cout << "Integer SquareMatrix swapRows test passed" << std::endl;
};
void testSwapColumns()
{
    int items[5][5] = {
        {2, 1, 3, 4, 5},
        {7, 6, 8, 9, 10},
        {12, 11, 13, 14, 15},
        {17, 16, 18, 19, 20},
        {22, 21, 23, 24, 25}};

    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);

    squareMatrix.swapColumns(0, 1);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j])
        }
    }
    std::cout << "Integer SquareMatrix swapColumns test passed" << std::endl;
};
void testMultiplyRow()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int scalar = 2;
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6 * 2, 7 * 2, 8 * 2, 9 * 2, 10 * 2},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    squareMatrix.multiplyRowByScalar(1, scalar);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j]);
        }
    }
    std::cout << "Integer SquareMatrix multiplyRowByScalar test passed" << std::endl;
};
void testMultiplyColumn()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int scalar = 2;
    squareMatrix.multiplyColumnByScalar(1, scalar);
    int items[5][5] = {
        {1, 2 * 2, 3, 4, 5},
        {6, 7 * 2, 8, 9, 10},
        {11, 12 * 2, 13, 14, 15},
        {16, 17 * 2, 18, 19, 20},
        {21, 22 * 2, 23, 24, 25}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j]);
        }
    }
    std::cout << "Integer SquareMatrix multiplyColumnByScalar test passed" << std::endl;
};

void testAddRowToRow()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int items[5][5] = {
        {1, 2, 3, 4, 5},
        {6 + 11 * 2, 7 + 12 * 2, 8 + 13 * 2, 9 + 14 * 2, 10 + 15 * 2},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    int scalar = 2;
    squareMatrix.addRowToRow(1, 2, scalar);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j]);
        }
    }
    std::cout << "Integer SquareMatrix addRowToRow test passed" << std::endl;
}

void testAddColumnToColumn()
{
    int **itemPtrs = createDummy2dIntegerArray(5);
    IntegerSquareMatrix squareMatrix(itemPtrs, 5);
    int scalar = 2;
    squareMatrix.addColumnToColumn(1, 2, scalar);
    int items[5][5] = {
        {1, 2 + 3 * 2, 3, 4, 5},
        {6, 7 + 8 * 2, 8, 9, 10},
        {11, 12 + 13 * 2, 13, 14, 15},
        {16, 17 + 18 * 2, 18, 19, 20},
        {21, 22 + 23 * 2, 23, 24, 25}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            IS_TRUE(squareMatrix.get(i, j) == items[i][j]);
        }
    }
    std::cout << "Integer SquareMatrix multiplyColumnByScalar test passed" << std::endl;
}

// void testIntegerSquareMatrixScalarMultiplication()
// {
//     int items[] = {1, 2, 3};
//     IntegerSquareMatrix SquareMatrix1(items, 3);
//     IntegerSquareMatrix SquareMatrix2(items, 3);
//     int res = SquareMatrix1.scalarMultiply(SquareMatrix2);
//     IS_TRUE(res == 14);
//     std::cout << "Integer SquareMatrix scalarMultiplication test passed" << std::endl;
// }

void testSquareMatrix()
{
    testIntegerSquareMatrixSizeConstructor();
    testIntegerSquareMatrixItemsConstructor();
    testIntegerSquareMatrixGetters();
    testIntegerSquareMatrixCopyConstructor();
    testIntegerSquareMatrixSetters();
    testIntegerSquareMatrixEqualsOperator();
    // testIntegerSquareMatrixAssignmentOperator();
    testIntegerSquareMatrixAddition();
    testIntegerSquareMatrixMultiplicationByScalar();
    // testIntegerSquareMatrixNorm();
    // testIntegerSquareMatrixScalarMultiplication();

    testSwapRows();
    testSwapColumns();
    testMultiplyRow();
    testMultiplyColumn();
    testAddRowToRow();
    testAddColumnToColumn();
    std::cout << "INTEGER SquareMatrix TESTS PASSED" << std::endl;
}