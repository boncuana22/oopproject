#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "EventLocation.h"
#include "Ticket.h"
#include "IdGenerator.h"

using namespace std;

void menu(int option, Event e1, Event e2, Event e3)
{
	switch (option)
	{
	case 1:
	{
		cout << endl << "\nThe events are: " << endl;
		cout << endl;
		cout << endl << "-----------------------------------";
		cout << e1;
		cout << endl << "-----------------------------------";
		cout << e2;
		cout << endl << "-----------------------------------";
		cout << e3;
		cout << endl << "-----------------------------------";
		break;
	}
	case 2:
	{
		cout << endl << "Here are the events: ";
		menu(1, e1, e2, e3);

		cout << endl << "Choose for which event you what to buy a ticket: ";
		cout << endl << "Write the number 1 -> 3\n" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Row: ";
			int r;
			cin >> r;
			cout << "Seat: ";
			int s;
			cin >> s;
			Ticket t1(e1, 0, r, s);
			t1.serialize();

			cout << "\nTicket created! ";
			cout << endl << "-----------------------------------" << endl;
			cout << t1;
			cout << endl << "-----------------------------------" << endl;
			cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;

			break;

		}
		case 2:
		{
			cout << "Row: ";
			int r;
			cin >> r;
			cout << "Seat: ";
			int s;
			cin >> s;
			Ticket t2(e2, 0, r, s);
			t2.serialize();

			cout << "\nTicket created! ";
			cout << endl << "-----------------------------------" << endl;
			cout << t2;
			cout << endl << "-----------------------------------" << endl;
			cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;
			break;
		}
		case 3:
		{

			cout << "Row: ";
			int r;
			cin >> r;
			cout << "Seat: ";
			int s;
			cin >> s;
			Ticket t3(e3, 0, r, s);
			t3.serialize();

			cout << "\nTicket created! ";
			cout << endl << "-----------------------------------" << endl;
			cout << t3;
			cout << endl << "-----------------------------------" << endl;
			cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;
			break;
		}
		default:
			cout << endl << "\nChoose a valid event number!";
			menu(2, e1, e2, e3);
			break;
		}



		break;
	}
	case 3:
	{

		cout << "\nValidate the ticket : " << endl;
		cout << "\nWrite the id of the ticket: " << endl;
		int i;
		cin >> i;
		if (Ticket::validate(i) == 0)
			cout << "\nThe ticket is valid" << endl;
		else
			cout << "\nThe ticket is not valid" << endl;

		break;

	}
	case 4:
	{
		cout << endl << "Close";
		break;

	}
	default:
	{
		cout << endl << "Choose a valid option: \n" << endl;
		cin >> option;
		menu(option, e1, e2, e3);
		break;
	}
	}

};

int main()
{

	Event handball("CSM Bucuresti - Rapid Bucuresti", "29.01.2023", "16:30");
	Event basketball("Corona Brasov - SCM Craiova", "29.01.2023", "19:30");
	Event football("FCSB - Rapid Bucuresti", "29.01.2023", "20:30");
	handball.setTypeString("handball_game");
	basketball.setTypeString("basketball_game");
	football.setTypeString("football_game");

	cout << endl << "-----------------------------------";
	cout << endl << "            TICKETING APP          ";
	cout << endl << "-----------------------------------";
	cout << endl << "| Welcome to my ticketing app! |\n";
	cout << endl << "Choose from the following options: \n";
	int option = 0;
	while (option != 4) {
		cout << endl << "|   1`  See the list of events   |\n";
		cout << endl << "|   2`  Buy a ticket             |\n";
		cout << endl << "|   3`  Validate a ticket        |\n";
		cout << endl << "|   4`  Close the application    |\n";
		cout << endl;
		cout << "Your option = ";
		cin >> option;
		menu(option, handball, basketball, football);
	}

	return 0;
}

/*  //from phase 1
	//example of using static member
	Event::setTotalEvents(2);
	cout << endl << "Total Events: " << Event::getTotalEvents() << endl;

	// example of using constant member
	EventLocation location;
	cout << endl << "Max Allowed Seats: " << location.getMaxAllowedSeats() << endl;

	EventLocation userLocation;
	cin >> userLocation;
	cout << endl << "User-specified EventLocation Information: " << userLocation << endl;*/