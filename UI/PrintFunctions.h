#pragma once

#include <iostream>
#include "../DataStructures/ArraySequence.h"
#include "../DataStructures/ListSequence.h"
#include "../DataStructures/Vector.h"
void printIntegerArray(ds::ArraySequence<int> *array);
void printTypes();
void printOperationChoice();
void printManuallyQuestion();
void printMainMenu();

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