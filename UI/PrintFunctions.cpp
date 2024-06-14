#include "PrintFunctions.h"

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

void printOperationChoice()
{
    cout << "What do you want to test?" << endl;

    cout << "Enter 1 - Addition" << endl;
    cout << "Enter 2 - Multiplication by scalar" << endl;
    cout << "Enter 3 - Norm calculation" << endl;
    cout << "Enter 4 - Sclalar multiplication" << endl;
};

// void printManuallyQuestion()
// {
//     cout << "Do you want to create the structure manually" << endl;
//     cout << "Enter 1 - Int" << endl;
//     cout << "Enter 2 - float" << endl;
// };

void printMainMenu()
{
    cout << "Enter 1 - To test a vector" << endl;
    cout << "Enter 2 - To run tests" << endl;
    cout << "Enter 3 - To Cancel" << endl;
};