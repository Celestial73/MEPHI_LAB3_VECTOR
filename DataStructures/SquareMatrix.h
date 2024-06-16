#pragma once
#include "./ArraySequence.h"
#include "./Sequence.h"
#include <cmath>

namespace ds
{
    template <typename T, T (*squareRoot)(const T &), T (*getZeroValue)(), T (*getOneValue)()>
    class SquareMatrix
    {
    public:
        SquareMatrix(int size) : size(size), data(new ArraySequence<Sequence<T> *>(size))
        {
            for (int i = 0; i < size; i++)
            {
                data->set(new ArraySequence<T>(size), i);
            }
        }

        SquareMatrix(T **items, int count) : size(count), data(new ArraySequence<Sequence<T> *>(size))
        {
            for (int i = 0; i < size; i++)
            {
                T *currentRow = items[i];
                data->set(new ArraySequence<T>(currentRow, size), i);
            }
        }

        SquareMatrix(SquareMatrix<T, squareRoot, getZeroValue, getOneValue> const &other) : size(other.size), data(new ArraySequence<Sequence<T> *>(size))
        {
            for (size_t i = 0; i != size; ++i)
            {
                ArraySequence<T> *row = new ArraySequence<T>(other.getRow(i));
                data->set(row, i);
            }
        }

        SquareMatrix() : size(0), data(new ArraySequence<Sequence<T> *>(size))
        {
        }

        ~SquareMatrix()
        {
            for (int i = 0; i < size; i++)
            {
                delete getRow(i);
            }
            delete data;
        }

        bool operator==(SquareMatrix<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            if (size != other.getSize())
                return 0;

            for (int i = 0; i < other.getSize(); i++)
            {
                for (int j = 0; j < getSize(); j++)
                {
                    if (this->get(i, j) != other.get(i, j))
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }

        // SquareMatrix<T, squareRoot, getZeroValue, getOneValue> &operator=(SquareMatrix<T, squareRoot, getZeroValue, getOneValue> &other)
        // {
        //     data = other.data;
        //     return *this;
        // }

        size_t getSize() const
        {
            return size;
        }

        const T &get(int m, int n) const
        {
            return data->get(m)->get(n);
        }

        void set(const T value, int m, int n)
        {
            data->get(m)->set(value, n);
        }

        void add(const SquareMatrix<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            checkSizeEqual(other);
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    set(get(i, j) + other.get(i, j), i, j);
                }
            }
        }

        void multiplyByScalar(const T scalar)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    set(get(i, j) * scalar, i, j);
                }
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
                for (int j = 0; j < size; j++)
                {
                    T element = get(i, j);
                    sum = sum + (element * element);
                }
            }
            return squareRoot(sum);
        }

        void swapRows(int i, int j)
        {
            Sequence<T> *temp = getRow(i);
            data->set(getRow(j), i);
            data->set(temp, j);
        }

        void swapColumns(int i, int j)
        {
            for (int m = 0; m < size; m++)
            {
                T temp = get(m, i);
                set(get(m, j), m, i);
                set(temp, m, j);
            }
        }

        void addRowToRow(int i, int j, T &scalar)
        {
            for (int n = 0; n < size; n++)
            {
                set(get(i, n) + get(j, n) * scalar, i, n);
            }
        }

        void addColumnToColumn(int i, int j, T &scalar)
        {
            for (int m = 0; m < size; m++)
            {
                set(get(m, i) + get(m, j) * scalar, m, i);
            }
        }

        void multiplyRowByScalar(int i, T &scalar)
        {
            for (int n = 0; n < size; n++)
            {
                set(get(i, n) * scalar, i, n);
            }
        }

        void multiplyColumnByScalar(int i, T &scalar)
        {
            for (int m = 0; m < size; m++)
            {
                set(get(m, i) * scalar, m, i);
            }
        }

    private:
        size_t size;
        Sequence<Sequence<T> *> *data;

        Sequence<T> *getRow(int m) const
        {
            return data->get(m);
        }

        void checkSizeEqual(const SquareMatrix<T, squareRoot, getZeroValue, getOneValue> &other)
        {
            if (getSize() != other.getSize())
            {
                throw std::invalid_argument("Matrixes of different sizes");
            }
        }
    };
}