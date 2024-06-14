#pragma once

namespace ds
{
    template <typename T>
    class Sequence
    {
    public:
        virtual const T &getFirst() const = 0;
        virtual const T &getLast() const = 0;
        virtual const T &get(int index) const = 0;
        virtual int getSize() const = 0;

        // returning non-const references
        // to allow access to elements (this is a mutable structure)
        virtual T &operator[](int index) = 0;

        // returning non-const references to allow
        // method chaining: SequenceInstance.set().set().set()
        virtual Sequence<T> &set(const T &data, int index) = 0;
        virtual Sequence<T> &insertAt(const T &value, int index) = 0;
        virtual Sequence<T> &append(const T &value) = 0;
        virtual Sequence<T> &prepend(const T &value) = 0;
        virtual Sequence<T> &concat(const Sequence<T> &other) = 0;

        // returning pointers to new objects
        virtual Sequence<T> *copySequence() = 0;
        virtual Sequence<T> *getSubsequence(int startIndex, int endIndex) = 0;
    };
}