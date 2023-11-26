#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <Event.h>
using namespace std;

class EventLocation {
private:
	string name;
	int maxSeats;

public:
	//constructor
	EventLocation(string _name, int _maxSeats) {
		this->name = _name;
		this->maxSeats = _maxSeats;
	}

	//setters & getters
	void setMaxSeats(int _maxSeats) {
		if (maxSeats >= 0 && maxSeats <= 30000)
			this->maxSeats = _maxSeats;
	}
	int setMaxSeats() {
		return maxSeats;
	}

	//copy constructor
	EventLocation(const EventLocation& el){
		this->name = el.name;
		this->maxSeats = el.maxSeats;
	}
};