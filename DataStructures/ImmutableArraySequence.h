#pragma once

#include "DynamicArray.h"
#include "ImmutableSequence.h"
#include "../utility/AccessValidation.h"

namespace ds
{
    template <class T>
    class ImmutableArraySequence : public ImmutableSequence<T>
    {

    private:
        DynamicArray<T> array;

    public:
        ImmutableArraySequence(T *items, int count)
        {
            array = DynamicArray<T>(items, count);
        }

        ImmutableArraySequence()
        {
            array = DynamicArray<T>();
        }
        ImmutableArraySequence(int size)
        {
            array = DynamicArray<T>(size);
        }

        ImmutableArraySequence(const ImmutableArraySequence<T> &other)
        {
            array = other.array;
        }

        explicit ImmutableArraySequence(const DynamicArray<T> &data)
        {
            array = data;
        }

        explicit ImmutableArraySequence(const ImmutableSequence<T> *other)
        {
            for (int i = 0; i < other->getSize(); i++)
            {
                append(other->get(i));
            }
        }
        void swapImmutableArraySequence(ImmutableArraySequence<T> &other)
        {
            std::swap(array, other.array);
        }

        int getSize() const
        {
            return array.getSize();
        }

        const T &getFirst() const
        {
            return array[0];
        }

        const T &getLast() const
        {
            return array[array.getSize() - 1];
        }

        const T &get(int index) const
        {
            return array.get(index);
        }

        const T &operator[](int index) const
        {
            return array[index];
        }

        bool operator==(ImmutableArraySequence<T> other)
        {
            return array == other.array;
        }

        ImmutableArraySequence<T> *set(const T item, int index) const
        {
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(array);
            newSeq->array.set(item, index);
            return newSeq;
        }

        ImmutableArraySequence<T> *getSubsequence(int startIndex, int endIndex) const
        {
            if (startIndex > endIndex)
            {
                throw std::invalid_argument("InvalidRange");
            }
            validateIndex(startIndex, __FUNCTION__, getSize());
            validateIndex(endIndex, __FUNCTION__, getSize());

            ImmutableArraySequence<T> *subSequence = new ImmutableArraySequence<T>;
            subSequence->array.resize(endIndex - startIndex + 1);
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                subSequence->array.set(get(i), i - startIndex);
            }
            return subSequence;
        }

        ImmutableArraySequence<T> *append(T item) const
        {
            int currentSize = getSize();
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(array);
            newSeq->array.resize(currentSize + 1);
            for (int i = 0; i < currentSize; i++)
            {
                newSeq->array.set(get(i), i);
            }
            newSeq->array.set(item, currentSize);
            return newSeq;
        }

        ImmutableArraySequence<T> *prepend(T item) const
        {
            int currentSize = getSize();
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(array);
            newSeq->array.resize(currentSize + 1);
            for (int i = 1; i < currentSize + 1; i++)
            {
                newSeq->array.set(get(i - 1), i);
            }
            newSeq->array.set(item, 0);
            return newSeq;
        }

        ImmutableArraySequence<T> *insertAt(T item, int index) const
        {
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(array);
            newSeq->array.resize(getSize() + 1);
            for (int i = newSeq->array.getSize() - 2; i >= index; i--)
            {
                newSeq->array.set(newSeq->array[i], i + 1);
            }
            newSeq->array[index] = item;
            return newSeq;
        }

        ImmutableArraySequence<T> *concat(const ImmutableSequence<T> &other) const
        {
            int thisSize = getSize();
            int otherSize = other.getSize();
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(array);
            newSeq->array.resize(thisSize + otherSize);
            for (int i = 0; i < otherSize; i++)
            {
                newSeq->array.set(other.get(i), thisSize + i);
            }
            return newSeq;
        }
    };
}