#pragma once
#include<iostream>
#include<Event.h>
using namespace std;

class EventLocation {
private:
	string name;
	int maxSeats;

public:
	//constructor
	EventLocation(string _name, int _maxSeats) {
		name = _name;
		maxSeats = _maxSeats;
	}

	//setters & getters
	void setMaxSeats(int _maxSeats) {
		maxSeats = _maxSeats;
	}
	int setMaxSeats() {
		return maxSeats;
	}

};