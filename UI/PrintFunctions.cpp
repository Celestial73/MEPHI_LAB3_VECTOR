#include "PrintFunctions.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// template <typename T>
// void printArray(ds::ArraySequence<T> *array, void print(T))
// {
//     cout << "Array consists of " << array->getSize() << " numbers\n";
//     for (int i = 0; i < array->getSize(); i++)
//         print(array->get(i));
//     cout << std::endl;
// };

void printIntegerArray(ds::ArraySequence<int> *array)
{
    cout << "Array holds " << array->getSize() << " integers\n";
    int size = array->getSize();
    for (int i = 0; i < array->getSize(); i++)
    {
        cout << array->get(i) << std::endl;
    }
    cout << std::endl;
}

void printTypes()
{
    cout << "Choose the type" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - Complex" << endl;
};

void printVectorOperationChoice()
{
    cout << "What do you want to test?" << endl;

    cout << "Enter 1 - Addition" << endl;
    cout << "Enter 2 - Multiplication by scalar" << endl;
    cout << "Enter 3 - Norm" << endl;
    cout << "Enter 4 - Scalar multiplication" << endl;
};

void printSquareMatrixOperationChoice()
{
    cout << "What do you want to test?" << endl;

    cout << "Enter 1 - Addition" << endl;
    cout << "Enter 2 - Multiplication by scalar" << endl;
    cout << "Enter 3 - Norm" << endl;
    cout << "Enter 4 - Row/Columns operations" << endl;
}

void printRowColumnChoice()
{
    cout << "Do you want to operate on rows or colums?" << endl;

    cout << "Enter 1 - Rows" << endl;
    cout << "Enter 2 - Columns" << endl;
}

void printRowColumnsOperationsChoice()
{
    cout << "What operation do you want to test?" << endl;

    cout << "Enter 1 - Swap" << endl;
    cout << "Enter 2 - Multiplication by scalar" << endl;
    cout << "Enter 3 - Addition" << endl;
}

void printMainMenu()
{
    cout << "Enter 1 - To test a vector" << endl;
    cout << "Enter 2 - To test a square matrix" << endl;
    cout << "Enter 3 - To run tests" << endl;
    cout << "Enter 4 - To cancel" << endl;
};

void printComplex(dt::Complex number)
{
    cout << std::setfill(' ') << std::setw(4) << std::right << number.getReal() << " + i" << std::setfill(' ') << std::setw(4) << std::left << number.getImg() << "";
}

void printInteger(int number)
{
    cout << std::setfill(' ') << std::setw(4) << number << " ";
}