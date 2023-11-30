#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
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
	// constructors
	Event()
	{
		this->name = new char[strlen("match name") + 1];
		strcpy_s(this->name, strlen("match name") + 1, "match name");

		this->type = other;
	}

	Event(const char* _name, const string& _date, const string& _time)
		: name(nullptr), date(_date), time(_time), type(other) {
		if (_name != nullptr && strlen(_name) > 0) {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, _name); 
		}

		else {
			cout<< "Invalid event name." <<endl;
		}
		this->date = _date;
		this->time = _time;
	}

	// setters
	void setName(char* _name)
	{
		if (_name != nullptr && strlen(_name) > 0) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, _name);
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
	void setType(eventType type)
	{
		if (type >= 0 && type <= 4)
			this->type = type;
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


	// getters
	char* getName()
	{

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
	int getType() {
		return type;
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
	friend ostream& operator<<(ostream& out, Event e);
	friend istream& operator>>(istream& in, Event& e);
};

int Event::totalEvents = 0;

ostream& operator<<(ostream& out, Event e)
{
	out << endl;
	out << "Event name: " << e.name << endl;
	out << e.date;
	out << e.time;
	out << "Type: " << e.getType() << endl;
	return out;
}

istream& operator>>(istream& in, Event& e)
{
	cout << "\nEvent name: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);

	if (e.name != nullptr)
	{
		delete[] e.name;
		e.name = nullptr;
	}
	e.setName(buffer);

	in >> e.date;
	in >> e.time;

	//enum type 
	cout << "\nThe event type ( football_game, handball_game, basketball_game, other ): ";
	char type[100];
	in >> ws;
	in.getline(type, 99);
	e.setTypeString(type);

	return in;
}
