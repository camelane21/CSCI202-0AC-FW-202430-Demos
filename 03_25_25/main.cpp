#include <iostream>
#include "unorderedLinkedList.h"

// lecture activity create the ordered linked list needed for your assignment (M02 Programming Assignment 2)

int main()
{
    unorderedLinkedList<int> list;
    list.insert(5);
    list.insert(8);
    list.insert(7);
    list.insert(2381);
    list.insert(2);
    int p = list.front();
    p = 7;
    list.print(std::cout);
    std::cout << std::endl;
    list.deleteNode(2381);
    list.print(std::cout);
    std::cout << std::endl;

    return 0;
}   
// I used the ordered linked list needed for my assignment (M02 Programming Assignment 2)
#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

#include "linkedList.h"

template <class Type>
class orderedLinkedList : public linkedList<Type>
{
public:
    void insert(const Type &newItem);
    void insertFirst(const Type &newItem) override { insert(newItem); }
    void insertLast(const Type &newItem) override { insert(newItem); }
    void deleteNode(const Type &deleteItem) override;
    bool search(const Type &searchItem) const override;
};

template <class Type>
void orderedLinkedList<Type>::insert(const Type &newItem)
{
    node<Type> *newNode = new node<Type>;
    newNode->info = new Type(newItem);
    newNode->link = nullptr;

    if (this->first == nullptr) // empty list
    {
        this->first = this->last = newNode;
    }
    else
    {
        node<Type> *current = this->first;
        node<Type> *trailCurrent = nullptr;

        while (current != nullptr && *(current->info) < newItem)
        {
            trailCurrent = current;
            current = current->link;
        }

        if (trailCurrent == nullptr)
        {
            newNode->link = this->first;
            this->first = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
        }

        if (current == nullptr)
        {
            this->last = newNode;
        }
    }

    this->count++;
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    if (this->first == nullptr) return;

    node<Type> *current = this->first;
    node<Type> *trailCurrent = nullptr;

    while (current != nullptr && *(current->info) != deleteItem)
    {
        trailCurrent = current;
        current = current->link;
    }

    if (current == nullptr) return;

    if (trailCurrent == nullptr)
    {
        this->first = this->first->link;
        if (this->first == nullptr) this->last = nullptr;
    }
    else
    {
        trailCurrent->link = current->link;
        if (current == this->last) this->last = trailCurrent;
    }

    delete current;
    this->count--;
}

template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const
{
    node<Type> *current = this->first;
    while (current != nullptr)
    {
        if (*(current->info) == searchItem) return true;
        current = current->link;
    }
    return false;
}

#endif
 Missing newline at the end of file.
