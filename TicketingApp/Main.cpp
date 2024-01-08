#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "EventLocation.h"
#include "Ticket.h"

using namespace std;

void displayMenu() {
	cout << "\n------ Menu ------" << endl;
	cout << "1. Add EventLocation" << endl;
	cout << "2. Add Event" << endl;
	cout << "3. Display EventLocation Details" << endl;
	cout << "4. Display Event Details" << endl;
	cout << "5. Save EventLocation to File" << endl;
	cout << "6. Load EventLocation from File" << endl;
	cout << "7. Generate Random Ticket IDs" << endl;
	cout << "8. Process Event" << endl;
	cout << "9. Exit" << endl;
	cout << "-------------------" << endl;
}


int main(int argc, char* argv[]) {
    // Check if a command-line argument is provided
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Open the file
    ifstream inputFile(argv[1]);

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    // Read and process data from the file
    EventLocation userLocation;
    inputFile >> userLocation;

    // Display information
    cout << "User-specified EventLocation Information: " << userLocation << endl;

    // Close the file
    inputFile.close();
            cout << "Processing completed." << endl;
        }
        else {
            cout << "Error: Unable to open file for reading." << endl;
            return 1;
        }
    }
    else {
        // Console menu mode
        vector<EventLocation> eventLocations;
        vector<Event> events;
        Ticket myTicket;

        int choice;
        do {
            displayMenu();
            cout << "Enter your choice (1-9): ";
            cin >> choice;

            switch (choice) {
            case 1: {
                EventLocation newLocation;
                cin >> newLocation;
                eventLocations.push_back(newLocation);
                break;
            }
            case 2: {
                Event newEvent;
                cin >> newEvent;
                events.push_back(newEvent);
                break;
            }
            case 3: {
                cout << "\n--- Displaying EventLocation Details ---" << endl;
                for (const auto& location : eventLocations) {
                    location.displayDetails();
                }
                break;
            }
            case 4: {
                cout << "\n--- Displaying Event Details ---" << endl;
                for (const auto& event : events) {
                    event.displayDetails();
                }
                break;
            }
            case 5: {
                if (!eventLocations.empty()) {
                    cout << "Enter the index of the EventLocation to save: ";
                    int index;
                    cin >> index;
                    if (index >= 0 && index < eventLocations.size()) {
                        eventLocations[index].saveToFile("eventlocation_data.bin");
                        cout << "EventLocation saved to file." << endl;
                    }
                    else {
                        cout << "Invalid index." << endl;
                    }
                }
                else {
                    cout << "No EventLocation to save." << endl;
                }
                break;
            }
            case 6: {
                EventLocation loadedLocation;
                loadedLocation.loadFromFile("eventlocation_data.bin");
                eventLocations.push_back(loadedLocation);
                cout << "EventLocation loaded from file." << endl;
                break;
            }
            case 7: {
                myTicket.setTicketID(myTicket.generateRandomTicketIDs(5));
                cout << "\n--- Generated Ticket IDs ---" << endl;
                cout << myTicket;
                break;
            }

            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
                break;
            }

        } while (choice != 9);
    }

    return 0;
}

/*int main()
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
}*/