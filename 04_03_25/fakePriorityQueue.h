#ifndef PQUEUE_H
#define PQUEUE_H

#include "linkedQueue.h"

template <class t>
class fakePriorityQueue : public linkedQueue<t>
{
public:
    void enqueue(const t &);
};

template <class t>
void fakePriorityQueue<t>::enqueue(const t &queueElement)
{
    node<t> *newNode = new node<t>;
    newNode->data = new t(queueElement);
    newNode->link = nullptr;

    if (this->isEmptyQueue())
    {
        // Queue is empty, insert as first and last
        this->queueFront = this->queueRear = newNode;
    }
    else
    {
        node<t> *current = this->queueFront;
        node<t> *trailCurrent = nullptr;

        // Traverse to find the correct insert location (ties go after)
        while (current != nullptr && *(current->data) <= queueElement)
        {
            trailCurrent = current;
            current = current->link;
        }

        if (trailCurrent == nullptr)
        {
            // Insert at the front
            newNode->link = this->queueFront;
            this->queueFront = newNode;
        }
        else
        {
            // Insert after trailCurrent
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)
            {
                // Inserted at the end, update rear
                this->queueRear = newNode;
            }
        }
    }
}

#endif
