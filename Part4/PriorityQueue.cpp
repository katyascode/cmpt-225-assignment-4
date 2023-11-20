/* 
 * PriorityQueue.cpp
 * 
 * Description: Implementation file for PriorityQueue template ADT class. 
 * 
 * Author: Katya Kubyshkin 
 * 
 * Date last modified: Nov 19 2023
 */

#include <iostream>
#include "EmptyDataCollectionException.h"


/* Constructors and Destructors */

// Description: Constructor 
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    binaryHeap = BinaryHeap<ElementType>();
}

// Description: Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
}

/* Public Interface */

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType> 
bool PriorityQueue<ElementType>::isEmpty() const {
    return (binaryHeap.getElementCount()==0);
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType> 
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement) {
    return binaryHeap.insert(newElement); 
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType> 
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("No elements in Priority Queue. Cannot peek.");
    }

    binaryHeap.remove(); 
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType> 
ElementType& PriorityQueue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("No elements in Priority Queue. Cannot peek.");
    }

    return binaryHeap.retrieve();
}