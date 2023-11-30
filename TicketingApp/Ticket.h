#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

enum ticketType{VIP, GoldenCircle, Tribune};

class Ticket {
private:
	vector<int> ticketID; 
	ticketType type;

public:
	//constructor
	Ticket(vector<int> _ticketID, ticketType _type) {
		this->ticketID = _ticketID;
		this->type = _type;
	}

	//setters
	void setTicketID(const vector<int>& _ticketID) {
		this->ticketID = _ticketID;
	}
	void setType(ticketType _type) {
		if (type >= 0 && type <= 3)
			this->type = type;
	}

	//getters
	vector<int> getTicketID() const {
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