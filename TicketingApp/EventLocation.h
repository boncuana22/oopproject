#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
using namespace std;

class EventLocation : public Event {
private:
	string adress;
	int maxSeats;
	const int maxAllowedSeats;  // constant member for the maximum allowed seats

public:
	// default constructor
	EventLocation() : Event(), adress(""), maxSeats(0), maxAllowedSeats(2500) {}

	// constructor with parameters
	EventLocation(const char* _name, string _adress, int _maxSeats, const int _maxAllowedSeats)
		: Event(), adress(_adress), maxSeats(_maxSeats), maxAllowedSeats(_maxAllowedSeats) {
	}

	// setters & getters
	void setAdress(string _adress) {
		this->adress = _adress;
	}
	string getAdress() {
		return this->adress;
	}

	void setMaxSeats(int _maxSeats) {
		if (maxSeats >= 0 && maxSeats <= 30000)
			this->maxSeats = _maxSeats;
	}
	int getMaxSeats() const {
		return maxSeats;
	}

	int getMaxAllowedSeats() const {
		return maxAllowedSeats;
	}


	// copy constructor
	EventLocation(const EventLocation& el) 
		: Event(el), adress(el.adress), maxSeats(el.maxSeats),maxAllowedSeats(el.maxAllowedSeats){}


	void displayDetails(const EventLocation& ) {
		cout << "Event Location Details:\n";
		cout << "Name: " << getName() << endl;
		cout << "Address: " << getAdress() << endl;
		cout << "Max Seats: " << getMaxSeats() << endl;
	}

	// destructor
	~EventLocation() {
		// No need to delete name, it's already handled by the base class (Event)
	}

	//  << and >> operators
	friend ostream& operator<<(ostream& os, const EventLocation& el);
	friend istream& operator>>(istream& is, EventLocation& el);
}; 

// overloading << op
ostream& operator<<(ostream& os, const EventLocation& el)
{
	os << "Event Location Details:"<< endl;
	os << "Name: " << el.getName() << endl;
	os << "Address: " << el.adress << endl;
	os << "Max Seats: " << el.getMaxSeats() << endl;
	return os;
}

// overloading >> op
istream& operator>>(istream& is, EventLocation& el) {
	cout << "Enter Event Name: ";
	char buffer[100];
	is >> ws;
	is.getline(buffer, 99);
	el.setName(buffer);

	cout << "Enter Event Address: ";
	is >> ws;  
	is >> el.adress;

	cout << "Enter Max Seats: ";
	is >> el.maxSeats;

	is >> static_cast<Event&>(el);

	return is;
}
