/* 
 * BankSimApp.cpp
 * 
 * Description: Bank simulation application based on Queue, Binary Heap and Priority Queue classes.
 * 
 * Author: Katya Kubyshkin 
 * 
 * Date last modified: Nov 19 2023 
 */
#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h" // Also includes "BinaryHeap.h"

using std::cout; 
using std::cin;

bool tellerAvailable = false;
int currentTime = 0;
int totalWaitTime = 0;
double totalCustomers = 0;

// Function declarations
void simulate();
void processArrival(Event& arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine);
void processDeparture(Event& departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine);

int main() {
    /* Need: 
     * Total number of people processed 
     * Average amount of time spent waiting 
     * cout Simulation Begins at the start; Simulation Ends at the end 
     * Processing an arrival event at time: 
     * Processing a departure event at time: */
    simulate();
    return 0;
}

void simulate() {
    Queue<Event>* bankLine = new Queue<Event>(); 
    PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>();
    tellerAvailable = true; 

    // Initialize data variables to compute necessary statistics
    totalCustomers = 0;
    double averageCustomerWaitTime = 0;
    
    cout << "Simulation Begins" << std::endl;

    // Read file and add events to queue while file is non-empty
    int time, length;
    while(cin >> time >> length) {
        // Create arrival event with corresponding inputs for time, length
        Event newArrivalEvent = Event('A', time, length);
        eventPriorityQueue->enqueue(newArrivalEvent);
        totalCustomers++;
    }

    // Event loop
    while(!eventPriorityQueue->isEmpty()) {
        Event newEvent = eventPriorityQueue->peek(); 
        currentTime = newEvent.getTime();

        if (newEvent.isArrival()) {
            processArrival(newEvent, eventPriorityQueue, bankLine);
        } else {
            processDeparture(newEvent, eventPriorityQueue, bankLine);
        }
    }

    cout << "Simulation Ends" << std::endl;

    // Produce final stats
    cout << "\nFinal Statistics:\n";
    cout << "\tTotal number of people processed: " << totalCustomers << std::endl;
    if (totalCustomers > 0) {
        averageCustomerWaitTime = static_cast<double>(totalWaitTime) / totalCustomers;
        cout << "\tAverage amount of time spent waiting: " << averageCustomerWaitTime << std::endl;
    }

}

void processArrival(Event& arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine) {
    eventPriorityQueue->dequeue(); 
    Event customer = arrivalEvent;

    if (bankLine->isEmpty() && tellerAvailable) {
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent = Event('D', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
        tellerAvailable = false;
    } else {
        bankLine->enqueue(customer); // Customer??? What values goes here 
    }
    currentTime = customer.getTime();
    cout << "Processing an arrival event at time:  " << customer.getTime() << std::endl;
}

void processDeparture(Event& departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine) {
    eventPriorityQueue->dequeue(); 
    int departureTime;
    
    if (!bankLine->isEmpty()) {
        Event customer = bankLine->peek(); 
        bankLine->dequeue(); 

        departureTime = currentTime + customer.getLength();
        totalWaitTime += (departureTime - customer.getTime());

        Event newDepartureEvent = Event('D', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
    } else {
        tellerAvailable = true;
    }

    cout << "Processing a departure event at time: " << departureTime << std::endl;
}