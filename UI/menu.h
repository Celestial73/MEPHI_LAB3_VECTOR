#pragma once

#include <iostream>
#include "PrintFunctions.h"
#include "../DataStructures/LinkedList.h"
#include "../DataStructures/DynamicArray.h"
#include "../DataStructures/ArraySequence.h"
#include "../DataStructures/ListSequence.h"
#include "../tests/DynamicArray_tests.h"
#include "../tests/LinkedList_tests.h"
#include "../tests/ArraySequence_tests.h"
#include "../tests/ImmutableArraySequence_tests.h"
#include "../tests/listSequence_tests.h"
#include "../tests/Vector_tests.h"
#include "../tests/SquareMatrix_tests.h"
#include "../tests/Complex_tests.h"

typedef ds::Vector<int, intSquareRoot, getIntegerZero, getIntegerOne> IntegerVector;
typedef ds::Vector<dt::Complex, dt::Complex::sqrt, dt::Complex::getZero, dt::Complex::getOne> ComplexVector;

typedef ds::SquareMatrix<int, intSquareRoot, getIntegerZero, getIntegerOne> IntegerSquareMatrix;
typedef ds::SquareMatrix<dt::Complex, dt::Complex::sqrt, dt::Complex::getZero, dt::Complex::getOne> ComplexSquareMatrix;
void menu();

// Utility
int createInteger();

void runTests();
void tryVector();
void trySquareMatrix();
int createRandomIntNumber(int maxNumber);
IntegerVector createIntegerVectorManually();
ComplexVector createComplexVectorManually();
IntegerSquareMatrix createIntegerSquareMatrixManually();
ComplexSquareMatrix createComplexSquareMatrixManually();
dt::Complex createComplex();
void manageRowColumnOperations(int type, int rowColumnFlag);
int getIntegerInRange(int min, int max);

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void vectorAddition(ds::Vector<T, squareRoot, getZeroValue, getOneValue> createVectorManually(), void print(T))
{
    cout << "Input the first vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector1 = createVectorManually();
    cout << "Input the second vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector2 = createVectorManually();
    if (vector1.getSize() != vector2.getSize())
    {
        cout << "Can't add vectors of different sizes! " << endl;
        return;
    }
    vector1.add(vector2);
    cout << endl
         << "The vector after addition: " << endl;
    printVector(&vector1, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void vectorMultiplicationByScalar(ds::Vector<T, squareRoot, getZeroValue, getOneValue> createVectorManually(), void print(T), T create())
{
    cout << "Input the vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector1 = createVectorManually();
    cout << "Input the scalar " << endl;
    T scalar = create();
    vector1.multiplyByScalar(scalar);
    cout << endl
         << "The vector after multiplication is: " << endl;
    printVector(&vector1, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void vectorNorm(ds::Vector<T, squareRoot, getZeroValue, getOneValue> createVectorManually(), void print(T))
{
    cout << "Input the vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector = createVectorManually();
    T norm = vector.norm();
    cout << endl
         << "The norm is:" << endl;
    print(norm);
    cout << endl;
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void vectorScalarMultiplication(ds::Vector<T, squareRoot, getZeroValue, getOneValue> createVectorManually(), void print(T))
{
    cout << "Input the first vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector1 = createVectorManually();
    cout << "Input the second vector: " << endl;
    ds::Vector<T, squareRoot, getZeroValue, getOneValue> vector2 = createVectorManually();
    if (vector1.getSize() != vector2.getSize())
    {
        cout << "Can't multiply vectors of different sizes! " << endl;
        return;
    }
    T multiplicationResult = vector1.scalarMultiply(vector2);
    cout << endl
         << "The result of multiplication is: " << endl;
    print(multiplicationResult);
    cout << endl;
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void martixAddition(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T))
{
    cout << "Input the first matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix1 = createMatrixManually();
    cout << "Input the second matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix2 = createMatrixManually();
    if (matrix1.getSize() != matrix2.getSize())
    {
        cout << "Can't add matrices of different sizes! " << endl;
        return;
    }
    matrix1.add(matrix2);
    cout << endl
         << "The matrix after addition: " << endl;
    printSquareMatrix(&matrix1, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixMultiplicationByScalar(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Input the scalar " << endl;
    T scalar = create();
    matrix.multiplyByScalar(scalar);
    cout << endl
         << "The matrix after multiplication is: " << endl;
    printSquareMatrix(&matrix, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixNorm(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T))
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    T norm = matrix.norm();
    cout << endl
         << "The norm is:" << endl;
    print(norm);
    cout << endl;
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixSwapRows(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select the first row to swap (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Select the second row to swap (input its index): " << endl;
    int j = getIntegerInRange(0, matrix.getSize() - 1);
    matrix.swapRows(i, j);
    printSquareMatrix(&matrix, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixSwapColumns(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select the first column to swap (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Select the second column to swap (input its index): " << endl;
    int j = getIntegerInRange(0, matrix.getSize() - 1);
    matrix.swapColumns(i, j);
    printSquareMatrix(&matrix, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixAddRows(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select a row (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Select the second row to add it to the first one (input its index): " << endl;
    int j = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Input a scalar to multiply the secound row by: " << endl;
    T scalar = create();
    matrix.addRowToRow(i, j, scalar);
    printSquareMatrix(&matrix, print);
    cout << endl;
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixAddColumns(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select a column (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Select the second column to add it to the first one (input its index): " << endl;
    int j = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Input a scalar to multiply the secound column by: " << endl;
    T scalar = create();
    matrix.addColumnToColumn(i, j, scalar);
    printSquareMatrix(&matrix, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixMultiplyRow(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select a row (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Input a scalar to multiply the row by: " << endl;
    T scalar = create();
    matrix.multiplyRowByScalar(i, scalar);
    printSquareMatrix(&matrix, print);
}

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void matrixMultiplyColumn(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> createMatrixManually(), void print(T), T create())
{
    cout << "Input the matrix: " << endl;
    ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> matrix = createMatrixManually();
    cout << "Select a column (input its index): " << endl;
    int i = getIntegerInRange(0, matrix.getSize() - 1);
    cout << "Input a scalar to multiply the column by: " << endl;
    T scalar = create();
    matrix.multiplyColumnByScalar(i, scalar);
    printSquareMatrix(&matrix, print);
}