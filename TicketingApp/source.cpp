#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "EventLocation.h"
#include "Ticket.h"

using namespace std;

int main()
{
	Event e1("fcsb-dinamo", "29.01.2023", "20:30");
	e1.setType(handball_game);

	cout << e1.getName();
	cout << endl;
	cout << e1.getType();
	cout << e1.getTime();
	cout << endl;

	// example of using static member
	cout << "Total Events: " << Event::getTotalEvents() << endl;

	// example of using constant member
	EventLocation location;
	cout << "Max Allowed Seats: " << location.getMaxAllowedSeats() << endl;

	// example of creating a Ticket object with specific ticket IDs
	vector<int> ticketIDs = { 1001, 1002, 1003 };
	Ticket myTicket(ticketIDs, VIP);

	return 0;
}