#pragma once

#include "LinkedList.h"
#include "Sequence.h"

namespace ds
{
    template <class T>
    class ListSequence : public Sequence<T>
    {

    private:
        LinkedList<T> list;

    public:
        ListSequence(const T *items, int count)
        {
            list = LinkedList<T>(items, count);
        }

        ListSequence() = default;
        ListSequence(int size)
        {
            list = LinkedList<T>(size);
        }

        ListSequence(const ListSequence<T> &other)
        {
            list = LinkedList(other.list);
        }

        explicit ListSequence(const LinkedList<T> &data)
        {
            list = data;
        }

        explicit ListSequence(const Sequence<T> *other)
        {
            for (int i = 0; i < other->getSize(); i++)
            {
                append(other->get(i));
            }
        }

        T &operator[](int index)
        {
            return list[index];
        }

        ListSequence<T> &operator=(ListSequence<T> other)
        {
            list = other.list;
            return *this;
        }

        int operator==(ListSequence<T> other)
        {
            return list == other.list;
        }

        const T &getFirst() const
        {
            return list.get(0);
        }

        const T &getLast() const
        {
            return list.getLast();
        }

        const T &get(int index) const
        {
            return list.get(index);
        }

        int getSize() const
        {
            return list.getSize();
        }
        Sequence<T> &set(const T &item, int index)
        {
            list.set(item, index);
            return *this;
        }

        Sequence<T> *copySequence()
        {
            return (new ListSequence<T>(*this));
        }

        ListSequence<T> &append(const T &item)
        {
            list.append(item);
            return *this;
        }

        ListSequence<T> *getSubsequence(int startIndex, int endIndex)
        {

            ListSequence<T> *subSequence = new ListSequence<T>(*list.getSublist(startIndex, endIndex));
            return subSequence;
        }

        ListSequence<T> &prepend(const T &item)
        {
            list.prepend(item);
            return *this;
        }

        ListSequence<T> &insertAt(const T &item, int index)
        {
            list.insertAt(item, index);
            return *this;
        }

        ListSequence<T> &concat(const Sequence<T> &other)
        {
            int otherSize = other.getSize();
            for (int i = 0; i < otherSize; i++)
            {
                append(other.get(i));
            }
            return *this;
        }
    };
}