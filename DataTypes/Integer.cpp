#include "Integer.h"

int intSquareRoot(const int &value)
{
    return (int)sqrt(value);
}

int getIntegerZero()
{
    return (int)0;
}
int getIntegerOne()
{
    return (int)1;
}

int **createDummy2dIntegerArray(int size)
{
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = i * size + j + 1;
        }
    }
    return arr;
}