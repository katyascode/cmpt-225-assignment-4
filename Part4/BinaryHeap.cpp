/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT template class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 * 
 * Author: Anne Lavergne, Katya Kubyshkin
 * 
 * Last Modification: Nov 19 2023
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file
#include "EmptyDataCollectionException.h" // Exception Class

using std::cout;

/* Private Methods */

// Description: Doubles size of array and copies over data if given array is full.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::resize(){
   // Create a new heap double the size of the original. 
   capacity *= 2; 
   ElementType* newElements = new ElementType[capacity]; 

   // Perform a deep copy of the array 
   for (unsigned int i = 0; i < elementCount; i++) {
      newElements[i] = elements[i]; 
   }

   delete[] elements; 
   elements = newElements;
}

// Description: Restores Minimum Binary Heap's properties when a new element is inserted.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfMinChild) {
   while (indexOfMinChild > 0) {
      unsigned int indexOfParent = (indexOfMinChild-1)/2;

      if (elements[indexOfMinChild] <= elements[indexOfParent]) {
         //Swap the two elements. 
         swap(&elements[indexOfMinChild], &elements[indexOfParent]);

         //Redefine index value to continue recursive process.
         indexOfMinChild = indexOfParent; 
      } else {
         break;
      }
   }
}

// Description: Utility method. Recursively put the array back into a Minimum Binary Heap.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
   
   // Find indices of children and root.
   unsigned int indexOfMinChild = indexOfRoot;
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      //Swap elements
      swap(&elements[indexOfRoot], &elements[indexOfMinChild]);

      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Swap function for reHeapUp and reHeapDown functions.
// Time Efficiency: O(1) 
template <class ElementType>
void BinaryHeap<ElementType>::swap(ElementType* a, ElementType* b) {
   ElementType temp = *a; 
   *a = *b; 
   *b = temp; 
}



/* Constructors and Destructors */
  
// Description: Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {
   elements = new ElementType[capacity];
   elementCount = 0;
}

// Description: Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    delete[] elements; 
}


/* Public Methods & Interface */

// Description: returns number of elements stored in the Minimum Binary Heap. 
// Time Efficiency: O(1)
template <class ElementType> 
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: inserts an element into the Binary Heap. 
// Time Efficiency: O(log2 n)
template <class ElementType> 
bool BinaryHeap<ElementType>::insert(ElementType & newElement) {
   // If binary heap empty, create a new one OR throw exception? 
   if (elementCount == capacity) {
      resize(); 
   }

   // Insert at the bottom of the minimum heap. 
   elements[elementCount] = newElement; 
   elementCount++; 
   reHeapUp(elementCount-1);
   return true; 
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() is we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const {
   if (elementCount == 0) {
      throw EmptyDataCollectionException("No elements in Binary Heap. Exiting...");
   }
   
   return elements[0];
}

/*
// Description: print() method for testing purposes. 
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::print() {
   cout << "{ ";;
   for (unsigned int i = 0; i < elementCount; i++) {
      cout << elements[i] << " ";
   }
   cout << "}";
}
*/