/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap Template ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 * 
 * Author: Katya Kubyshkin
 * 
 * Last Modification: Nov 19 2023
 *
 */  

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>

template <class ElementType> 
class BinaryHeap {
    
    private:
        ElementType* elements;
        unsigned int capacity = 10; // Default capacity
        unsigned int elementCount;

        // Helper functions
        void resize();
        void reHeapUp(unsigned int indexOfMinChild);
        void reHeapDown(unsigned int indexOfRoot);
        void swap(ElementType *a, ElementType *b); 

    public:
        /* Constructors and Destructors */

        // Description: Constructor
        BinaryHeap(); 

        // Description: Destructor
        ~BinaryHeap();
        

        /* Public Interface */

        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap. 
        //              It returns true if successful, otherwise false.      
        // Time Efficiency: O(log2 n)
        bool insert(ElementType & newElement);
            
        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1) 
        ElementType & retrieve() const;

        // Description: print() method for testing purposes
        // void print(); 
};
 
#include "BinaryHeap.cpp"
#endif