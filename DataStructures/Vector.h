#pragma once
#include "./ArraySequence.h"
#include "./Sequence.h"
#include <cmath>

namespace ds
{
    template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
    class Vector
    {
    public:
        Vector(int size) : size(size), data(new ArraySequence<T>(size))
        {
        }

        Vector(const T *items, int count) : size(count), data(new ArraySequence<T>(size))
        {
            for (size_t i = 0; i != size; ++i)
            {
                data->set(items[i], i);
            }
        }

        Vector(Vector<T, squareRoot, getZeroValue, getOneValue> const &other) : size(other.size), data(new ArraySequence<T>(size))
        {
            for (size_t i = 0; i != size; ++i)
            {
                data->set(other.data->get(i), i);
            }
        }

        Vector() : size(0), data(new ArraySequence<T>())
        {
        }

        ~Vector()
        {
            delete data;
        }

        bool operator==(Vector<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            if (size != other.getSize())
                return 0;

            for (int i = 0; i < other.getSize(); i++)
            {
                if (!(data->get(i) == other.data->get(i)))
                    return 0;
            }
            return 1;
        }

        Vector<T, squareRoot, getZeroValue, getOneValue> &operator=(Vector<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            data = other.data;
            return *this;
        }

        // Getters and setters
        size_t getSize() const
        {
            return size;
        }

        const T &get(int index) const
        {
            return data->get(index);
        }

        void set(const T value, int index)
        {
            data->set(value, index);
        }

        void add(const Vector<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            for (int i = 0; i < size; i++)
            {
                set(get(i) + other.get(i), i);
            }
            return;
        }

        void multiplyByScalar(const T scalar)
        {
            for (int i = 0; i < size; i++)
            {
                set(get(i) * scalar, i);
            }
            return;
        }

        T norm()
        {
            T sum = getZeroValue();
            if (size == 0)
            {
                return sum;
            }
            for (int i = 0; i < size; i++)
            {
                sum = sum + ((get(i)) * (get(i)));
            }
            return squareRoot(sum);
        }

        T scalarMultiply(const Vector<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            T product;
            T sum = getZeroValue();
            if (size == 0 || other.getSize() == 0)
            {
                return (getZeroValue());
            }
            if (size != other.getSize())
            {
                throw std::invalid_argument("Multiplying vectors of different sizes.");
            }
            for (int i = 0; i < size; i++)
            {
                product = get(i) * other.get(i);
                sum = sum + product;
            }
            return sum;
        }

    private:
        size_t size;
        Sequence<T> *data;
    };
}