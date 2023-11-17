#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <class ElementType>
class Queue {

private:
    class Node {
    public:
        ElementType data;
        Node* next;

        /* Constructors and Destructors */
        Node(const ElementType& newData);
    };

    Node* queueHead;
    Node* queueTail;

public:
    /* Constructors and Destructors */
    Queue();
    ~Queue();

    /* Public Interface Methods */

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue 
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const;
};

#include "Queue.cpp" // Include the implementation file

#endif // QUEUE_H
