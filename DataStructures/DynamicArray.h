#pragma once
#include <iostream>
#include "../utility/AccessValidation.h"

namespace ds
{
    template <class T>
    class DynamicArray
    {
    public:
        DynamicArray(int size) : size(size), data(new T[size])
        {
        }

        DynamicArray(const T *items, int count) : size(count), data(new T[size])
        {
            for (size_t i = 0; i != size; ++i)
            {
                data[i] = items[i];
            }
        }

        DynamicArray(DynamicArray const &other) : size(other.size), data(new T[size])
        {
            for (size_t i = 0; i != size; ++i)
            {
                data[i] = other.data[i];
            }
        }

        DynamicArray() : size(0), data(nullptr)
        {
        }

        ~DynamicArray()
        {
            delete[] data;
        }

        bool operator==(const DynamicArray<T> &other) const
        {

            if (size != other.getSize())
                return 0;

            for (int i = 0; i < other.getSize(); i++)
            {
                if (data[i] != other.data[i])
                    return 0;
            }
            return 1;
        }

        T &operator[](int index) const
        {
            validateAccessByIndex(index, __FUNCTION__, size);
            return data[index];
        }

        DynamicArray &operator=(DynamicArray const &other)
        {
            if (this != &other)
            {
                DynamicArray tempArray(other);
                tempArray.swapArray(*this);
            }
            return *this;
        }

        size_t getSize() const
        {
            return size;
        }

        T &get(int index)
        {
            validateListNotEmpty(__FUNCTION__, size);
            validateIndex(index, __FUNCTION__, size);
            return data[index];
        }

        const T &get(int index) const
        {
            validateListNotEmpty(__FUNCTION__, size);
            validateIndex(index, __FUNCTION__, size);
            return data[index];
        }

        void set(const T value, int index)
        {
            validateListNotEmpty(__FUNCTION__, size);
            validateIndex(index, __FUNCTION__, size);
            data[index] = value;
        }

        void resize(size_t newSize)
        {
            DynamicArray newArray(newSize);
            size_t n = newSize > size ? size : newSize;
            for (size_t i = 0; i != n; ++i)
            {
                newArray.data[i] = data[i];
            }
            swapArray(newArray);
        }

    private:
        size_t size;
        T *data;

        // Function for swapping one array's data for another's.
        void swapArray(DynamicArray &other)
        {
            std::swap(size, other.size);
            std::swap(data, other.data);
        }
    };
}