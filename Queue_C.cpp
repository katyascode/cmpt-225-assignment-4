#include "Queue.h"

/* Node Class Implementation */
template <class ElementType>
Queue<ElementType>::Node::Node(const ElementType& newData) : data(newData), next(nullptr) {}

/* Queue Class Implementation */
template <class ElementType>
Queue<ElementType>::Queue() : queueHead(nullptr), queueTail(nullptr) {}

template <class ElementType>
Queue<ElementType>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return queueHead == nullptr;
}

template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement) {
    Node* newNode = new Node(newElement);
    if (isEmpty()) {
        queueHead = newNode;
        queueTail = newNode;
    } else {
        queueTail->next = newNode;
        queueTail = newNode;
    }
    return true;
}

template <class ElementType>
void Queue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue empty. No elements to dequeue.");
    }

    Node* temp = queueHead;
    queueHead = queueHead->next;
    delete temp;

    // If the queue is now empty, update the tail as well
    if (isEmpty()) {
        queueTail = nullptr;
    }
}

template <class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue empty. No elements to peek.");
    }
    return queueHead->data;
}
