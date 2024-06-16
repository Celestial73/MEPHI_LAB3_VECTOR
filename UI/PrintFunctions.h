#pragma once

#include <iostream>
#include "../DataStructures/ArraySequence.h"
#include "../DataStructures/ListSequence.h"
#include "../DataStructures/Vector.h"
#include "../DataStructures/SquareMatrix.h"
#include "../DataTypes/Complex.h"
#include "../DataTypes/Integer.h"

void printIntegerArray(ds::ArraySequence<int> *array);
void printTypes();
void printVectorOperationChoice();
void printMainMenu();
void printSquareMatrixOperationChoice();
void printRowColumnChoice();
void printRowColumnsOperationsChoice();

void printComplex(dt::Complex number);
void printInteger(int);

template <typename T>
void printArray(ds::ArraySequence<T> *array, void print(T))
{
    cout << "Array consists of " << array->getSize() << " numbers\n";
    for (int i = 0; i < array->getSize(); i++)
        print(array->get(i));
    cout << std::endl;
};

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void printVector(ds::Vector<T, squareRoot, getZeroValue, getOneValue> *vector, void print(T))
{
    cout << "Vector consists of " << vector->getSize() << " elements\n";
    for (int i = 0; i < vector->getSize(); i++)
    {
        print(vector->get(i));
    }
    cout << std::endl;
};

template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
void printSquareMatrix(ds::SquareMatrix<T, squareRoot, getZeroValue, getOneValue> *matrix, void print(T))
{
    cout << "Matrix has the size of " << matrix->getSize() << "\n";
    for (int i = 0; i < matrix->getSize(); i++)
    {
        for (int j = 0; j < matrix->getSize(); j++)
        {
            print(matrix->get(i, j));
        }
        cout << endl;
    }
    cout << std::endl;
};
