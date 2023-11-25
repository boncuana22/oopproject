#pragma once
#include<iostream>
using namespace std;

enum eventType { football_game, handball_game, basketball_game, other };

class Event {
private:
	char* name;
	string date;
	string time;
	eventType type;
public:
	//constructors
	Event()
	{
		this->name = new char[strlen("match name") + 1];
		strcpy_s(this->name, strlen("match name") + 1, "match name");

		this->type = other;
	}

	Event(const char* _name, string _date, string _time) {
		if (name != nullptr && strlen(name) > 1)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else
		{
			cout << "Enter a valid event name:";

		}
		this->date = _date;
		this->time = _time;
	}

	//setters
	void setName(char* _name)
	{
		if (name != nullptr && strlen(name) > 1)
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else
		{
			cout << "Enter a valid event name.";
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


	//getters
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

	//copy constructor
	Event(const Event& e) {
		if (e.name != nullptr)
		{
			this->name = new char[strlen(e.name) + 1];
			strcpy_s(this->name, strlen(e.name) + 1, e.name);
		}
		else
		{
			this->name = new char[strlen("unknown") + 1];
			strcpy_s(this->name, strlen("unknown") + 1, "unknown");
		}
		this->date = e.date;
		this->time = e.time;
		this->type = e.type;
	}

	//destructor
	~Event()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}
	}
};