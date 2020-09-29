//Project 8
//Name - Sohaib Ali Khan, StarID - vi4362xq
//Instructor - Dr. Jie Meichsner
//Due Date - 8/4/2020 @ 11:50pm

/** File name - Project8.cpp
Purpose - Main program file for Project8.cpp*/





#include "LinkedQueue.h" // ADT Queue operations
#include "SL_PriorityQueue.h" 
#include "Event.h"


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int customerCount = 0;
int currentTime = 0;
int waitTime = 0;
bool tellerAvailable = true;

//Function prototypes
void processArrival(Event& newEvent, SL_PriorityQueue<Event>& eventListPQueue,
LinkedQueue<Event>& bankQueuePtr);

void processDeparture(Event& departureEvent, SL_PriorityQueue<Event>& eventListPQueue,
LinkedQueue<Event>& bankQueuePtr);






/** Gets the initial list of event times from the input file and stores in the priority queue eventListPQueue.
@pre There has to be an external file with the name input.txt containing the original list of event times.
*/

void simulate()
{

	LinkedQueue <Event> bankQueuePtr;

	SL_PriorityQueue <Event> eventListPQueue;

	Event newArrivalEvent;


	ifstream inputFile;
	inputFile.open("input.txt");


	while (!inputFile.eof())
	{

		 inputFile >> newArrivalEvent;

		 newArrivalEvent.setType("Arrival");

		 // cout << newArrivalEvent.getArrivalTime() << "\t" << newArrivalEvent.getTransactionTime() << "\t" << newArrivalEvent.getType() << endl;


		 eventListPQueue.add(newArrivalEvent);

		 customerCount++;

	} //end while

	inputFile.close(); //close the file


Event newEvent;




// // Event loop
while (!(eventListPQueue.isEmpty()))
{


newEvent = eventListPQueue.peek();




currentTime = newEvent.getArrivalTime();


if (newEvent.getType() == "Arrival")
{

	processArrival(newEvent, eventListPQueue, bankQueuePtr);
}

else if (newEvent.getType() == "Departure")
{

	processDeparture(newEvent, eventListPQueue, bankQueuePtr);
}

} //end while

} //end simulate



/** Calculates the arrival events according to the algorithm.
@param an Event object newEvent, Priority queue - eventListPQueue and LinkedQueue - bankQueuePtr
*/
// Processes an arrival event.
void processArrival(Event& newEvent, SL_PriorityQueue<Event>& eventListPQueue,
LinkedQueue<Event>& bankQueuePtr)

{

	Event newDepartureEvent;
	newDepartureEvent = newEvent;

// Remove this event from the event list
eventListPQueue.remove();

if (bankQueuePtr.isEmpty() && tellerAvailable == true)
{
 int departureTime = currentTime + newDepartureEvent.getTransactionTime();


// Event newDepartureEvent;
newDepartureEvent.setArrivalTime(departureTime);
newDepartureEvent.setTransactionTime(newDepartureEvent.getTransactionTime());
newDepartureEvent.setType("Departure");


eventListPQueue.add(newDepartureEvent);
tellerAvailable = false;

cout << "Processing an arrival event at time: \t" << currentTime << endl;


}

else
{
	bankQueuePtr.enqueue(newEvent);
	newDepartureEvent.setType("Departure");
	cout << "Processing an arrival event at time: \t" << currentTime << endl;
}

	
} //end processArrival




/** Calculates the departure events according to the algorithm.
@param an Event object newEvent, Priority queue - eventListPQueue and LinkedQueue - bankQueuePtr
*/
// Processes a departure event .
void processDeparture(Event& departureEvent, SL_PriorityQueue<Event>& eventListPQueue,
LinkedQueue<Event>& bankQueuePtr)
{
// Remove this event from the event list
eventListPQueue.remove();

if (!bankQueuePtr.isEmpty())
{
// Customer at front of line begins transaction
Event newDepartureEvent; 
newDepartureEvent = bankQueuePtr.peekFront();
bankQueuePtr.dequeue();

	if (newDepartureEvent.getArrivalTime() <= currentTime)
	{
		waitTime = waitTime + (currentTime - newDepartureEvent.getArrivalTime());

	}

int departureTime = currentTime + newDepartureEvent.getTransactionTime();
newDepartureEvent.setArrivalTime(departureTime);
newDepartureEvent.setType("Departure");


eventListPQueue.add(newDepartureEvent);

cout << "Processing a departure event at time: \t" << currentTime << endl;

}

else
{

tellerAvailable = true;
cout << "Processing a departure event at time: \t" << currentTime << endl;

}

} //end processDeparture



int main()
{

	simulate();

	double avgWaitTime = (double)waitTime / (double)customerCount;

	cout << "Simulation ends." << endl;
	cout << endl;
	cout << "Final Statistics: " << endl;
	cout << "\tTotal number of customers processed: " << customerCount << endl;
	cout << "\tAverage amount of time spent waiting: " << avgWaitTime << endl;


	return 0;
} //end main

