#pragma once
#include<iostream>
#include<Event.h>
using namespace std;

class EventLocation {
private:
	char* name;
	int maxSeats;

public:
	//constructors
	EventLocation() {
		this->name = new char[strlen("match name") + 1];
		strcpy_s(this->name, strlen("match name") + 1, "match name");
		this->maxSeats = 0;
	}

	EventLocation(string _name, int _maxSeats) {
		if (name != nullptr && strlen(name) > 1)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else
		{
			cout << "Enter a valid event name:";

		}
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
		if (el.name != nullptr)
		{
			this->name = new char[strlen(el.name) + 1];
			strcpy_s(this->name, strlen(el.name) + 1, el.name);
		}
		else
		{
			this->name = new char[strlen("match name") + 1];
			strcpy_s(this->name, strlen("match name") + 1, "match name");
		}
		this->maxSeats = el.maxSeats;
	}

	// = operator
	EventLocation& operator=(const EventLocation& el)
	{
		if (this != &el)
		{
			delete[] name;

			if (el.name != nullptr)
			{
				this->name = new char[strlen(el .name) + 1];
				strcpy_s(this->name, strlen(el.name) + 1, el.name);
			}
			else
			{
				this->name = new char[strlen("match name") + 1];
				strcpy_s(this->name, strlen("match name") + 1, "match name");
			}

			this->maxSeats = el.maxSeats;
		}

		return *this;
	}
};