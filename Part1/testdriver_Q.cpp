#include <iostream>
#include "Queue.h"
#include "EmptyDataCollectionException.h"

int main() {
    try {
        // Create a queue of integers
        Queue<int> intQueue;

        // Enqueue some elements
        int element1 = 10;
        intQueue.enqueue(element1);

        int element2 = 20;
        intQueue.enqueue(element2);

        int element3 = 30;
        intQueue.enqueue(element3);

        // Peek at the front element
        std::cout << "Front Element: " << intQueue.peek() << std::endl;

        // Dequeue an element
        intQueue.dequeue();

        // Peek again after dequeue
        std::cout << "Front Element after Dequeue: " << intQueue.peek() << std::endl;

        // Dequeue the remaining elements
        intQueue.dequeue();
        intQueue.dequeue();

        // Try to dequeue from an empty queue (exception expected)
        intQueue.dequeue();  // This should throw an exception

    } catch (const EmptyDataCollectionException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
