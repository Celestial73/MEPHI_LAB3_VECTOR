#pragma once
#include <iostream>
#include "../utility/AccessValidation.h"
using namespace std;

namespace ds
{
    template <typename T>
    class Node
    {
    public:
        Node() : next(NULL){};
        Node(const T &data) : data(data), next(NULL){};

        void setData(const T &data)
        {
            this->data = data;
        };

        T &getData()
        {
            return this->data;
        };

        void setNext(Node<T> *node)
        {
            this->next = node;
        };

        Node<T> *getNext() const
        {
            return this->next;
        };

    private:
        T data;
        Node<T> *next;
    };

    template <typename T>
    class LinkedList
    {
    public:
        LinkedList() : head(NULL), tail(NULL), size(0){};

        LinkedList(const T *items, int count) : head(NULL), tail(NULL), size(0)
        {
            for (size_t i = 0; i < count; i++)
            {
                append(items[i]);
            }
        };
        LinkedList(int count) : head(NULL), tail(NULL), size(0)
        {
            for (size_t i = 0; i < count; i++)
            {
                append();
            }
        };

        LinkedList(LinkedList const &other) : size(0), head(NULL), tail(NULL)
        {
            Node<T> *otherListTraverseNode = other.head;
            for (size_t i = 0; i < other.size; i++)
            {
                this->append(otherListTraverseNode->getData());
                otherListTraverseNode = otherListTraverseNode->getNext();
            }
        }

        ~LinkedList()
        {
            Node<T> *deletionNode = head;
            Node<T> *traverseNode;
            while (deletionNode)
            {
                traverseNode = deletionNode->getNext();
                delete deletionNode;
                deletionNode = traverseNode;
            }
        }

        T &operator[](int index)
        {
            return getValue(index);
        }

        LinkedList &operator=(LinkedList const &other)
        {
            if (this != &other)
            {
                LinkedList tempList(other);
                tempList.swapList(*this);
            }
            return *this;
        }

        bool operator==(LinkedList<T> other)
        {
            if (size != other.getSize())
                return 0;

            Node<T> *thisListNode = this->head;
            Node<T> *otherListNode = other.head;
            for (int i = 0; i < other.getSize(); i++)
            {
                if (thisListNode->getData() != otherListNode->getData())
                {
                    return 0;
                }
                thisListNode = thisListNode->getNext();
                otherListNode = otherListNode->getNext();
            }
            return 1;
        }

        int getSize() const
        {
            return this->size;
        }
        const T &getFirst() const
        {
            validateListNotEmpty(__FUNCTION__, size);
            return this->head->getData();
        }
        const T &getLast() const
        {
            validateListNotEmpty(__FUNCTION__, size);
            return this->tail->getData();
        }

        const T &get(int index) const
        {
            return getValue(index);
        }

        void set(const T &item, int index)
        {
            Node<T> *accessedNode = getNode(index);
            accessedNode->setData(item);
        }

        void append(const T data)
        {
            Node<T> *newNode = new Node<T>(data);
            appendNode(newNode);
        }

        void prepend(const T &data)
        {
            Node<T> *newNode = new Node<T>(data);

            if (size == 0)
            {
                this->head = newNode;
                this->tail = newNode;
                this->head->setNext(NULL);
                this->size++;
                return;
            }
            newNode->setNext(this->head);
            this->head = newNode;
            this->size++;
            return;
        };

        LinkedList<T> *getSublist(int startIndex, int endIndex) const
        {
            validateAccessByIndex(startIndex, __FUNCTION__, size);
            validateAccessByIndex(endIndex, __FUNCTION__, size);
            if (startIndex > endIndex)
            {
                std::cout << __FUNCTION__ << " function failed" << std::endl;
                throw std::invalid_argument("InvalidIndexRange");
            }
            LinkedList<T> *sublist = new LinkedList<T>();
            Node<T> *traverseNode = this->getNode(startIndex);
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                sublist->append(traverseNode->getData());
                if (i != endIndex)
                {
                    traverseNode = traverseNode->getNext();
                }
            }
            return sublist;
        }

        void insertAt(const T &data, int index)
        {
            validateListNotEmpty(__FUNCTION__, size);
            // Can't use validateAccessByIndex(), because (index == size) case is acceptable
            // validateAccessByIndex() would throw an exception
            if (index > size)
            {
                std::cout << __FUNCTION__ << " function failed" << std::endl;
                throw std::invalid_argument("IndexOutOfRange");
            }
            Node<T> *newNode = new ds::Node<T>(data);
            if (index == 0)
            {
                newNode->setNext(this->head);
                this->head = newNode;
                return;
            }
            if (index == size)
            {
                this->tail->setNext(newNode);
                this->tail = newNode;
                return;
            }
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index - 1)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            newNode->setNext(traverseNode->getNext());
            traverseNode->setNext(newNode);
            size++;
            return;
        }

        void printList()
        {
            Node<T> *traverseNode = this->head;

            while (traverseNode != NULL)
            {
                cout << traverseNode->getData() << endl;
                traverseNode = traverseNode->getNext();
            }
            cout << endl;
        };

        // Appends the passed list to this list
        LinkedList<T> *concat(LinkedList<T> *other) const
        {
            LinkedList<T> *newList = new LinkedList<T>(*this);

            Node<T> *thisListNode = this->head;
            Node<T> *otherListNode = other->head;

            for (size_t i = 0; i < other->getSize(); i++)
            {
                newList->append(otherListNode->getData());
                otherListNode = otherListNode->getNext();
            }
            return newList;
        }

    private:
        Node<T> *head;
        Node<T> *tail;
        int size;

        void append()
        {
            Node<T> *newNode = new Node<T>();
            appendNode(newNode);
        }

        void appendNode(Node<T> *node)
        {
            if (size == 0)
            {
                this->head = node;
                this->tail = node;
                this->head->setNext(NULL);
                this->size++;
                return;
            }
            this->tail->setNext(node);
            this->tail = node;
            this->size++;
            return;
        }

        Node<T> *getNode(int index) const
        {
            validateAccessByIndex(index, __FUNCTION__, size);
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            return traverseNode;
        }

        T &getValue(int index) const
        {
            validateAccessByIndex(index, __FUNCTION__, size);
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            return traverseNode->getData();
        }

        void swapList(LinkedList &other)
        {
            std::swap(size, other.size);
            std::swap(head, other.head);
            std::swap(tail, other.tail);
        }
    };
};
