/* 
 * PriorityQueue.cpp
 * 
 * Description: Implementation file for PriorityQueue class. 
 * 
 * Author: Katya Kubyshkin 
 * 
 * Date last modified: Nov 19 2023
 */

#include <iostream>
#include "EmptyDataCollectionException.h"

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    binaryHeap = BinaryHeap<ElementType>();
}

template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    ~BinaryHeap<ElementType>(); 
}

template <class ElementType> 
bool PriorityQueue<ElementType>::isEmpty() const {
    return (binaryHeap.getElementCount()==0);
}

template <class ElementType> 
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement) {
    return binaryHeap.insert(newElement); 
}

template <class ElementType> 
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("No elements in Priority Queue. Cannot peek.");
    }

    binaryHeap.remove(); 
}

template <class ElementType> 
ElementType& PriorityQueue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("No elements in Priority Queue. Cannot peek.");
    }

    return binaryHeap.retrieve();
}