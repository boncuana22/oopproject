#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
using namespace std;

class EventLocation : public Event {
private:
	int maxSeats;
	const int maxAllowedSeats;  // constant member for the maximum allowed seats

public:

	// default constructor
	EventLocation() : Event(), maxSeats(0), maxAllowedSeats(0) {}

	// constructor with parameters
	EventLocation(const char* _name, int _maxSeats, const int _maxAllowedSeats)
		: Event(), maxSeats(_maxSeats), maxAllowedSeats(_maxAllowedSeats) {
	}

	// setters & getters
	void setMaxSeats(int _maxSeats) {
		if (maxSeats >= 0 && maxSeats <= 30000)
			this->maxSeats = _maxSeats;
	}
	int setMaxSeats() {
		return maxSeats;
	}

	// copy constructor
	EventLocation(const EventLocation& el) 
		: Event(el), maxSeats(el.maxSeats),maxAllowedSeats(el.maxAllowedSeats){}

	int getMaxAllowedSeats() const {
		return maxAllowedSeats;
	}

	// destructor
	~EventLocation() {
		// No need to delete name, it's already handled by the base class (Event)
	}
}; 