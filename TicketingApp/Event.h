#pragma once
#include<iostream>
using namespace std;

class Event {
private:
	string name;
	string date;
	string time;
public:
	//default constructor
	Event(string name="", string date="",string time="");

	//setters
	void setName(string _name);
	void setDate(string _date);
	void setTime(string _time);

	//getters
	string getName();
	string getDate();
	string getTime();

};