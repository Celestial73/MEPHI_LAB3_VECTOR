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
#include "../tests/Complex_tests.h"

typedef ds::Vector<int, intSquareRoot, getIntegerZero, getIntegerOne> IntegerVector;
typedef ds::Vector<dt::Complex, dt::Complex::sqrt, dt::Complex::getZero, dt::Complex::getOne> ComplexVector;

// Array
void menu();

// Utility
int createInteger();
float createFloat();
void printFloat(float);
void printInteger(int);
void runTests();
void tryVector();
int createRandomIntNumber(int maxNumber);
IntegerVector createIntegerVectorManually();
ComplexVector createComplexVectorManually();
void printComplex(dt::Complex);
dt::Complex createComplex();
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
}

// template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
// ds::Vector<T, squareRoot, getZeroValue, getOneValue> createVectorManually(T create())
// {
//     int length = 0;
//     cout << "Enter the length (<100)" << endl;
//     length = getIntegerInRange(0, 99);
//     T nums[length];
//     for (int i = 0; i < length; i++)
//     {
//         cout << "[" << i << "] element =" << endl;
//         nums[i] = create();
//     }
//     return ds::Vector<T, squareRoot, getZeroValue, getOneValue>(nums, length);
// }