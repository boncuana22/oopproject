#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "EventLocation.h"
#include "Ticket.h"

using namespace std;

int main()
{
	Event e1("CSM Bucuresti - Rapid Bucuresti", "29.01.2023", "20:30");
	Event e2("Corona Brasov - SCM Craiova", "29.01.2023", "19:30");
	e1.setTypeString("handball_game");
	e2.setTypeString("basketball_game");
	cout << e1;
	cout << e2;

	// example of using static member
	Event::setTotalEvents(2);
	cout << endl << "Total Events: " << Event::getTotalEvents() << endl;

	// example of using constant member
	EventLocation location;
	cout << endl << "Max Allowed Seats: " << location.getMaxAllowedSeats() << endl;

	// example of creating a Ticket object with specific ticket IDs
	Ticket myTicket;
	myTicket.addID(10);
	myTicket.setTypeString("VIP");
	cout << endl << myTicket << endl;

	EventLocation userLocation;
	cin >> userLocation;
	cout << endl << "User-specified EventLocation Information: " << userLocation << endl;


	return 0;
}