#include<iostream>
#include<string>
using namespace std;


class EventLocation {
private:
	string name;
	int maxSeats;

public:
	//constructor
	EventLocation(string _name, int _maxSeats){
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

class Ticket {
private:
	int ticketID;
	string type;
public:
	//constructor
	Ticket(int _ticketID, string _type) {
		ticketID = _ticketID;
		type = _type;
	}

	//setters
	void setTicketID(int _ticketID) {
		ticketID = _ticketID;
	}
	void setType(string _type) {
		type = _type;
	}

	//getters
	int getTicketID() {
		return ticketID;
	}
	string getType() {
		return type;
	}

};

int main()
{
		

	
	return 0;
}