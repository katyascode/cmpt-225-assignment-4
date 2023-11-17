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
    queueHead = nullptr;
}


// Description: Deletes an entire queue 
// Postcondition: Queue empty, memory released. 
// Time efficiency: O(n)
template <class ElementType>
Queue<ElementType>::~Queue() {
    while (queueHead != nullptr) {
        Node* temp = queueHead; 
        queueHead = queueHead->next; 
        delete temp; 
    }
}

template <class ElementType>
Queue<ElementType>::Node::Node() {
    next = nullptr;
}

template <class ElementType>
Queue<ElementType>::Node::Node(ElementType & newElement) {
    element = newElement; 
    next = nullptr;
}

template <class ElementType>
Queue<ElementType>::Node::~Node() {
    next = nullptr;
}


/* Member Methods */


// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return (queueHead == nullptr);
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement) {
    //Create a new node containing the element
    Node* newNode = new Node(newElement);

    //If empty, the head is the only element in the queue. 
    if (isEmpty()) {
        queueHead = newNode; 
    }

    //Otherwise, traverse to the back of the linked list
    Node* current = queueHead; 
    while (current->next != nullptr) {
        current = current->next; 
    }

    //Append element to the back. 
    current->next = newNode;
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

    Node* temp = queueHead; 
    queueHead = temp->next; 
    delete temp; 
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
    return queueHead->element; 
}