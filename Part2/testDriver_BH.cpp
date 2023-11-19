#include <iostream>
#include "BinaryHeap.h"

int main() {
    // Create a BinaryHeap of integers
    BinaryHeap<int> minHeap = BinaryHeap<int>();

    minHeap.remove();

    // Insert elements into the heap
    int el1 = 3;
    minHeap.insert(el1);

    int el2 = 5;
    minHeap.insert(el2);

    int el3 = 1;
    minHeap.insert(el3);

    int el4 = 7;
    minHeap.insert(el4);

    int el5 = 2;
    minHeap.insert(el5);

    // Display the initial state of the heap
    std::cout << "Initial Heap: ";
    minHeap.print();
    std::cout << std::endl;

    // Remove elements from the heap
    minHeap.remove();
    minHeap.remove();

    // Display the state of the heap after removals
    std::cout << "Heap after removals: ";
    minHeap.print();
    std::cout << std::endl;

    // Insert more elements
    int el6 = 4; minHeap.insert(el6); int el7 = 6; minHeap.insert(el7);

    // Display the final state of the heap
    std::cout << "Final Heap: ";
    minHeap.print();
    std::cout << std::endl;

    return 0;
}
