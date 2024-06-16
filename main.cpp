#include <iostream>
#include "./UI/Menu.h"

#include "./tests/SquareMatrix_tests.h"

using namespace std;

int main()
{
    try
    {
        menu();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "END" << endl;
}