#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

enum eventType { football_game, handball_game, basketball_game, other };

class Event {
private:
	char* name;
	string date;
	string time;
	eventType type;
	static int totalEvents;  // static member to track the total number of events

public:
	// default constructor
	Event()
	{
		this->name = new char[strlen("match name") + 1];
		strcpy_s(this->name, strlen("match name") + 1, "match name");

		this->type = other;
	}

	// constructor with parameters
	Event(const char* _name, const string& _date, const string& _time)
		: name(nullptr), date(_date), time(_time), type(other) {
		if (_name != nullptr && strlen(_name) > 0) {
			this->name = new char[strlen(_name) + 1];
			strcpy_s(this->name, strlen(_name) + 1, _name);
		}

		else {
			cout << "Invalid event name." << endl;
		}
		this->date = _date;
		this->time = _time;
	}

	// setters
	void setName(char* _name)
	{
		if (_name != nullptr && strlen(_name) > 0) {
			delete[] this->name;
			this->name = new char[strlen(_name) + 1];
			strcpy_s(this->name, strlen(_name) + 1, _name);
		}
		else {
			cout << "Invalid event name." << endl;
		}
	}

	void setDate(string _date) {
		this->date = _date;
	}
	void setTime(string _time) {
		this->time = _time;
	}

	void setTypeString(string type)
	{
		if (type == "football_game")
			this->type = eventType::football_game;
		else
			if (type == "handball_game")
				this->type = eventType::handball_game;
			else
				if (type == "basketball_game")
					this->type = eventType::basketball_game;
				else
					if (type == "other")
						this->type = eventType::other;
	}

	static void setTotalEvents(int value) {
		totalEvents = value;
	}

	// getters
	char* getName() const {

		if (this->name != nullptr)
		{
			char* copyname = new char[strlen(this->name) + 1];
			strcpy_s(copyname, strlen(this->name) + 1, this->name);
			return copyname;
		}
		else
			return nullptr;
	}
	string getDate() {
		return date;
	}
	string getTime() {
		return time;
	}
	eventType getType() const {
		return type;
	}
	string getTypeString() const {
		switch (type) {
		case football_game: return "football_game";
		case handball_game: return "handball_game";
		case basketball_game: return "basketball_game";
		case other: return "other";
		default: return "unknown";
		}
	}

	// copy constructor
	Event(const Event& e) {
		if (e.name != nullptr)
		{
			this->name = new char[strlen(e.name) + 1];
			strcpy_s(this->name, strlen(e.name) + 1, e.name);
		}
		else
		{
			this->name = new char[strlen("match name") + 1];
			strcpy_s(this->name, strlen("match name") + 1, "match name");
		}
		this->date = e.date;
		this->time = e.time;
		this->type = e.type;
	}

	// static method to get the total number of events
	static int getTotalEvents() {
		return totalEvents;
	}

	// = operator
	Event& operator=(const Event& e)
	{
		if (this != &e)
		{
			delete[] name;

			if (e.name != nullptr)
			{
				this->name = new char[strlen(e.name) + 1];
				strcpy_s(this->name, strlen(e.name) + 1, e.name);
			}
			else
			{
				this->name = new char[strlen("match name") + 1];
				strcpy_s(this->name, strlen("match name") + 1, "match name");
			}

			this->type = e.type;
			this->date = e.date;
			this->time = e.time;
		}

		return *this;
	}

	// destructor
	~Event()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}
	}

	// << and >> operators
	friend ostream& operator<<(ostream& os, Event e);
	friend istream& operator>>(istream& is, Event& e);

};

int Event::totalEvents = 0;

// overloading << op
ostream& operator<<(ostream& os, Event e)
{
	os << endl << "Event info" << endl;
	os << "Name: " << e.name << endl;
	os << "Date: " << e.date << endl;
	os << "Time: " << e.time << endl;
	os << "Type: " << e.getTypeString() << endl;
	return os;
}

// overloading >> op
istream& operator>>(istream& is, Event& e) {
	cout << "\nEnter Event Name: ";
	char buffer[100];
	is >> ws;
	is.getline(buffer, 99);
	e.setName(buffer);

	cout << "Enter Event Date (format: dd.mm.yyyy): ";
	is >> e.date;

	cout << "Enter Event Time (format: hh:mm): ";
	is >> e.time;

	cout << "Enter Event Type (football_game, handball_game, basketball_game, other): ";
	string type;
	is >> ws;
	is >> type;
	e.setTypeString(type);

	return is;
}




