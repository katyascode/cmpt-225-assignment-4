/*
*
* Queue.cpp
*
* Class Invariant: FIFO / LILO Order 
*
* Implementation: Singly-headed, singly-linked list
*
* Author: Katya Kubyshkin
*
* Date last modified: Nov 17 2023
* 
*/

#include <stdbool.h>
#include "Queue.h"
#include "EmptyDataCollectionException.h"


/* Constructors and Destructors */

// Description: creates and initializes new, empty queue. 
// Time Efficiency: O(1)
template <class ElementType>
Queue<ElementType>::Queue() {
    head = nullptr;
}


// Description: Deletes an entire queue 
// Postcondition: Queue empty, memory released. 
// Time efficiency: O(n)
template <class ElementType>
Queue<ElementType>::~Queue() {
    while (head != nullptr) {
        dequeue();
    }
}


/* Public Interface */

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return (elementCount == 0);
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement) {
    //Create a new node containing the element
    Node* newNode = new Node(newElement);
    if (newNode == nullptr) {
        return false; //Memory allocation failed.
    }

    //If empty, the head is the only element in the queue. 
    if (isEmpty()) {
        head = newNode;
        tail = newNode;  
    }

    //Otherwise, append to the back of the linked list
    tail->next = newNode; 
    tail = newNode; 
    elementCount++;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue() {
    //Check that the queue is not empty. 
    if (isEmpty()) {
        throw EmptyDataCollectionException("Queue empty. No elements to remove.");
    }

    Node* dequeueNode = head; 
    head = head->next; 
    delete dequeueNode;
    elementCount--; 

    if (isEmpty()) {
        head = nullptr;
        tail = nullptr; 
    }
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("Queue empty. No elements to peek.");
    }
    return head->element; 
}