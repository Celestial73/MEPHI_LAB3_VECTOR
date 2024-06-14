#pragma once

namespace ds
{
    template <typename T>
    class ImmutableSequence
    {
    public:
        virtual const T &getFirst() const = 0;
        virtual const T &getLast() const = 0;
        virtual const T &get(int index) const = 0;
        virtual const T &operator[](int index) const = 0;
        virtual int getSize() const = 0;

        // returning pointers to new objects
        virtual ImmutableSequence<T> *set(const T data, int index) const = 0;
        virtual ImmutableSequence<T> *insertAt(const T data, int index) const = 0;
        virtual ImmutableSequence<T> *append(const T value) const = 0;
        virtual ImmutableSequence<T> *prepend(const T value) const = 0;
        virtual ImmutableSequence<T> *getSubsequence(int startIndex, int endIndex) const = 0;
        virtual ImmutableSequence<T> *concat(const ImmutableSequence<T> &other) const = 0;
    };
}