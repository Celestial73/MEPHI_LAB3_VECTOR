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
            trySquareMatrix();
            break;
        case 3:
            runTests();
            break;
        case 4:
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
    testSquareMatrix();
}

void tryVector()
{
    int type;
    printTypes();
    type = getIntegerInRange(1, 2);
    int manageNumber;
    printVectorOperationChoice();
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

void trySquareMatrix()
{
    int type;
    printTypes();
    type = getIntegerInRange(1, 2);
    int manageNumber;
    printSquareMatrixOperationChoice();
    manageNumber = getIntegerInRange(1, 4);
    switch (manageNumber)
    {
    case 1:
        if (type == 1)
        {
            martixAddition(createIntegerSquareMatrixManually, printInteger);
            break;
        }
        martixAddition(createComplexSquareMatrixManually, printComplex);
        break;
    case 2:
        if (type == 1)
        {
            matrixMultiplicationByScalar(createIntegerSquareMatrixManually, printInteger, createInteger);
            break;
        }
        matrixMultiplicationByScalar(createComplexSquareMatrixManually, printComplex, createComplex);
        break;
    case 3:
        if (type == 1)
        {
            matrixNorm(createIntegerSquareMatrixManually, printInteger);
            break;
        }
        matrixNorm(createComplexSquareMatrixManually, printComplex);
        break;
    case 4:
        int rowColumnFlag;
        printRowColumnChoice();
        rowColumnFlag = getIntegerInRange(1, 2);
        manageRowColumnOperations(type, rowColumnFlag);
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

void manageRowColumnOperations(int type, int rowColumnFlag)
{
    int operationCode;
    printRowColumnsOperationsChoice();
    operationCode = getIntegerInRange(1, 3);
    switch (operationCode)
    {
    case 1:
        if (type == 1)
        {
            if (rowColumnFlag == 1)
            {
                matrixSwapRows(createIntegerSquareMatrixManually, printInteger, createInteger);
                break;
            }
            matrixSwapColumns(createIntegerSquareMatrixManually, printInteger, createInteger);
            break;
        }
        if (rowColumnFlag == 1)
        {
            matrixSwapRows(createComplexSquareMatrixManually, printComplex, createComplex);
            break;
        }
        matrixSwapColumns(createComplexSquareMatrixManually, printComplex, createComplex);
        break;
    case 2:
        if (type == 1)
        {
            if (rowColumnFlag == 1)
            {
                matrixMultiplyRow(createIntegerSquareMatrixManually, printInteger, createInteger);
                break;
            }
            matrixMultiplyColumn(createIntegerSquareMatrixManually, printInteger, createInteger);
            break;
        }
        if (rowColumnFlag == 1)
        {
            matrixMultiplyRow(createComplexSquareMatrixManually, printComplex, createComplex);
            break;
        }
        matrixMultiplyColumn(createComplexSquareMatrixManually, printComplex, createComplex);
        break;
    case 3:
        if (type == 1)
        {
            if (rowColumnFlag == 1)
            {
                matrixAddRows(createIntegerSquareMatrixManually, printInteger, createInteger);
                break;
            }
            matrixAddColumns(createIntegerSquareMatrixManually, printInteger, createInteger);
            break;
        }
        if (rowColumnFlag == 1)
        {
            matrixAddRows(createComplexSquareMatrixManually, printComplex, createComplex);
            break;
        }
        matrixAddColumns(createComplexSquareMatrixManually, printComplex, createComplex);
        break;
    default:
        break;
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

IntegerSquareMatrix createIntegerSquareMatrixManually()
{
    int size = 0;
    cout << "Enter the size (<100)" << endl;
    size = getIntegerInRange(0, 99);

    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "][" << j << "] item: ";
            arr[i][j] = createInteger();
        }
    }
    return IntegerSquareMatrix(arr, size);
};

ComplexSquareMatrix createComplexSquareMatrixManually()
{
    int size = 0;
    cout << "Enter the size (<100)" << endl;
    size = getIntegerInRange(0, 99);

    dt::Complex **arr = new dt::Complex *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new dt::Complex[size];
        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "][" << j << "] item: ";
            arr[i][j] = createComplex();
        }
    }
    return ComplexSquareMatrix(arr, size);
};

int createInteger()
{
    int number;
    std::cin >> number;
    return number;
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

int createRandomIntNumber(int maxNumber)
{
    return rand() % maxNumber;
}
