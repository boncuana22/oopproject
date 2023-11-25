#include<iostream>
#include<Event.h>

//constructor with parameters
Event::Event (string _name, string _date, string _time) {
	name = _name;
	date = _date;
	time = _time;
}

//setters
void Event::setName(string _name) {
	name = _name;
}
void Event::setDate(string _date) {
	date = _date;
}
void Event::setTime(string _time) {
	time = _time;
}

//getters
string Event::getName() {
	return name;
}
string Event::getDate() {
	return date;
}
string Event::getTime() {
	return time;
}