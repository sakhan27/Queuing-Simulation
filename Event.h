//Project 8
//Name - Sohaib Ali Khan, StarID - vi4362xq
//Instructor - Dr. Jie Meichsner
//Due Date - 8/4/2020 @ 11:50pm

/** File name - Event.h
Purpose - Header and Implementation file for Event class*/





#ifndef _EVENT
#define _EVENT
#include <string>
#include <iostream>

using namespace std;

class Event
{
private:

	string type;
	int arrivalTime;
	int transactionTime;
   
public:
   Event()
   {
   } //default constructor

   Event(int a, int t)
   {
		arrivalTime = a;
		transactionTime = t;
   } //Consturctor with 


   void setType(string ch)
   {
   	 type = ch;
   }

   void setArrivalTime(int a)
   {
	   arrivalTime = a;
   }
   void setTransactionTime(int t)
   {
	   transactionTime = t;
   }
   

   string getType()
   {
   	return type;
   }

   int getArrivalTime()
   {
	   return arrivalTime;
   }
   int getTransactionTime()
   {
	   return transactionTime;
   }

friend istream& operator >>(istream& ins, Event& target)
{
	ins >> target.arrivalTime >> target.transactionTime;

	return ins;
} // end Node

friend ostream& operator <<(ostream& outs, Event target)
{
	outs << target.arrivalTime << "\t"<<target.transactionTime << "\t" << target.type;

	return outs;
} // end Node


}; //end Event


//nonmemeber overloading operators
bool operator >(Event a1, Event a2)
{
	if (a1.getArrivalTime() < a2.getArrivalTime())
		return true;
	else
		return false;
}


bool operator >=(Event a1, Event a2)
{
	if (a1.getArrivalTime() <= a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator <(Event a1, Event a2)
{
	if (a1.getArrivalTime() > a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator <=(Event a1, Event a2)
{
	if (a1.getArrivalTime() >= a2.getArrivalTime())
		return true;
	else
		return false;
}


bool operator == (Event a1, Event a2)
{
	if (a1.getArrivalTime() == a2.getArrivalTime())
		return true;
	else
		return false;
}


bool operator!= (Event a1, Event a2)
{
	if (a1.getArrivalTime() != a2.getArrivalTime())
		return true;
	else
		return false;
}




#endif