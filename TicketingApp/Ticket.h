#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

enum ticketType{VIP, GoldenCircle, Tribune, other };

class Ticket {
private:
	int ticketID;
	ticketType type;
public:
	//constructor
	Ticket(int _ticketID, ticketType _type) {
		this->ticketID = _ticketID;
		this->type = _type;
	}

	//setters
	void setTicketID(int _ticketID) {
		this->ticketID = _ticketID;
	}
	void setType(ticketType _type) {
		if (type >= 0 && type <= 4)
			this->type = type;
	}

	//getters
	int getTicketID() {
		return ticketID;
	}
	int getType() {
		return type;
	}

	//copy constructor
	Ticket(const Ticket& t) {
		this->ticketID = t.ticketID;
		this->type = t.type;
	}
};