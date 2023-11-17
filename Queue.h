/*
*
* Queue.h
*
* Class Invariant: FIFO / LILO Order 
*
* Implementation: Singly-headed, single-linked list
*
* Authors: Anne Lavergne, Katya Kubyshkin
*
* Date last modified: Nov 17 2023
* 
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdbool.h>

template <class ElementType>
class Queue {

    private:
        class Node {

            public:
                ElementType & element; 
                Node* next;

                Node(); 
                Node(ElementType & newElement);
                ~Node();
        };

        Node* queueHead;
        unsigned int queueSize; 

        /* Getter Methods */


    public: 

        /* Constructors and Destructors */

        // Description: creates new empty queue
        // Time Efficiency: O(1)
        Queue(); 

        // Description: Deletes an entire queue 
        // Postcondition: Queue empty, memory released. 
        // Time efficiency: O(n)
        ~Queue();

        // Description: Returns true if this Queue is empty, otherwise false.
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of this Queue's data structure) 
        //              and returns true if successful, otherwise false.
        // Time Efficiency: O(1)
        bool enqueue(ElementType & newElement);

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
        ElementType & peek() const;
};
#include "Queue.cpp"
#endif