#include <iostream>
#include "Menu.h"
#include "../DataTypes/Complex.h"

void menu()
{
    int manageNumber;
    while (true)
    {
        printMainMenu();
        manageNumber = getIntegerInRange(1, 4);
        switch (manageNumber)
        {
        case 1:
            tryVector();
            break;
        case 2:
            runTests();
            break;
        case 3:
            return;
        default:
            return;
        }
    }
}

void runTests()
{
    testVector();
    testComplex();
}

void tryVector()
{
    int type;
    printTypes();
    type = getIntegerInRange(1, 2);
    int manageNumber;
    printOperationChoice();
    manageNumber = getIntegerInRange(1, 4);
    switch (manageNumber)
    {
    case 1:
        if (type == 1)
        {
            vectorAddition(createIntegerVectorManually, printInteger);
            break;
        }
        vectorAddition(createComplexVectorManually, printComplex);
        break;
    case 2:
        if (type == 1)
        {
            vectorMultiplicationByScalar(createIntegerVectorManually, printInteger, createInteger);
            break;
        }
        vectorMultiplicationByScalar(createComplexVectorManually, printComplex, createComplex);
        break;
    case 3:
        if (type == 1)
        {
            vectorNorm(createIntegerVectorManually, printInteger);
            break;
        }
        vectorNorm(createComplexVectorManually, printComplex);
        break;
    case 4:
        if (type == 1)
        {
            vectorScalarMultiplication(createIntegerVectorManually, printInteger);
            break;
        }
        vectorScalarMultiplication(createComplexVectorManually, printComplex);
        break;
    default:
        return;
    }
}

int getIntegerInRange(int min, int max)
{
    while (true)
    {
        int number;
        std::cin >> number;
        if (!cin)
        {
            cout << "Input a number." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if (number <= max && number >= min)
        {
            return number;
        }
        cout << "Number out of range" << endl;
    }
}

IntegerVector createIntegerVectorManually()
{
    int length = 0;
    cout << "Enter the length (<100)" << endl;
    length = getIntegerInRange(0, 99);
    int nums[length];
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "] element =" << endl;
        nums[i] = createInteger();
    }
    return IntegerVector(nums, length);
};

ComplexVector createComplexVectorManually()
{
    int length = 0;
    cout << "Enter the length (<100)" << endl;
    length = getIntegerInRange(0, 99);
    dt::Complex nums[length];
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "] element =" << endl;
        nums[i] = createComplex();
    }
    return ComplexVector(nums, length);
};

int createInteger()
{
    int number;
    std::cin >> number;
    return number;
}

void printInteger(int number)
{
    cout << number << endl;
}

dt::Complex createComplex()
{
    dt::Complex number;
    double real, img;
    std::cout << "Real part: ";
    std::cin >> real;
    std::cout
        << "Imaginary part: ";
    std::cin >> img;
    number.setImg(img);
    number.setReal(real);
    cout << number.getReal() << " + i" << number.getImg() << endl;
    return number;
}

void printComplex(dt::Complex number)
{
    cout << number.getReal() << " + i" << number.getImg() << endl;
}

int createRandomIntNumber(int maxNumber)
{
    return rand() % maxNumber;
}
