#pragma once
#include<iostream>
using namespace std;

enum ticketType{VIP, GoldenCircle, Tribune1, Tribune2 };

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
		this->type = _type;
	}

	//getters
	int getTicketID() {
		return ticketID;
	}
	int getType() {
		return type;
	}

};