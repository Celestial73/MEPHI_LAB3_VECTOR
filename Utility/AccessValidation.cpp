#include <iostream>
#include "AccessValidation.h"
#include <string>

void validateAccessByIndex(int index, const char *function, int size)
{
    validateListNotEmpty(function, size);
    validateIndex(index, function, size);
}

void validateListNotEmpty(const char *function, int size)
{
    std::string failedFunctionName = function;
    if (size == 0)
    {
        throw std::logic_error(failedFunctionName + " function failed \nError: ReadingEmptyList");
    }
}

void validateIndex(int index, const char *function, int size)
{
    std::string failedFunctionName = function;
    if (index >= size)
    {
        throw std::invalid_argument(failedFunctionName + " function failed \nError: IndexOutOfRange");
    }
    if (index < 0)
    {
        throw std::invalid_argument(failedFunctionName + " function failed \nError: NegativeIndexValue");
    }
}