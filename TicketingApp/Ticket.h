#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

enum ticketType { VIP, GoldenCircle, Tribune, Other };

class Ticket {
private:
    vector<int> ticketID;
    ticketType type;

public:
    // default constructor
    Ticket() {
        this->ticketID = {};
        this->type = Other;
    }

    // constructor with parameters
    Ticket(vector<int> _ticketID, ticketType _type) {
        this->ticketID = _ticketID;
        this->type = _type;
    }

    // setters
    void setTicketID(const vector<int>& _ticketID) {
        this->ticketID = _ticketID;
    }
    void setType(ticketType _type) {
        if (type >= 0 && type <= 3)
            this->type = type;
    }
    void setTypeString(string type)
    {
        if (type == "VIP")
            this->type = ticketType::VIP;
        else
            if (type == "GoldenCircle")
                this->type = ticketType::GoldenCircle;
            else
                if (type == "Tribune")
                    this->type = ticketType::Tribune;
                else
                    if (type == "Other")
                        this->type = ticketType::Other;
    }

    // getters
    vector<int> getTicketID() const {
        return ticketID;
    }
    int getType() const {
        return type;
    }
    string getTypeString() const {
        switch (type) {
        case VIP: return "VIP";
        case GoldenCircle: return "GoldenCircle";
        case Tribune: return "Tribune";
        case Other: return "Other";
        default: return "unknown";
        }
    }

    void displayElements() const {
        cout << "Ticket elements:" << endl;
        cout << "ID:";
        for (int i : ticketID) {
            cout << " " << i;
        }
        cout << endl << "Type: " << type;
    }

    // copy constructor
    Ticket(const Ticket& t) {
        this->ticketID = t.ticketID;
        this->type = t.type;
    }

    void addID(int value) {
        ticketID.push_back(value);
    }

    // validate that the ticket IDs are non-negative
    bool isValidTicketIDs(const Ticket& ticket) {
        for (int id : ticket.getTicketID()) {
            if (id < 0) {
                return false;
            }
        }
        return true;
    }

    // calculate the price of a ticket based on its type
    double calculateTicketPrice(const Ticket& ticket) {
        switch (ticket.getType()) {
        case VIP:
            return 50.0;  
        case GoldenCircle:
            return 40.0;  
        case Tribune:
            return 30.0;  
        default:
            return 20.0;  
        }
    }

    //  << and >> operators
    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);
};

// overloading << op
ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "Ticket IDs: ";
    for (int id : ticket.getTicketID()) {
        os << id << " ";
    }
    os << "\nTicket Type: ";
    switch (ticket.getType()) {
    case VIP: os << "VIP"; break;
    case GoldenCircle: os << "Golden Circle"; break;
    case Tribune: os << "Tribune"; break;
    default: os << "Unknown"; break;
    }
    os << "\n";
    return os;
}

// overloading >> op
istream& operator>>(istream& is, Ticket& ticket) {
    vector<int> ids;
    int count;
    cout << "Enter number of Ticket IDs: ";
    is >> count;
    ids.resize(count);

    cout << "Enter Ticket IDs (separated by space): ";
    for (int i = 0; i < count; ++i) {
        is >> ids[i];
    }

    int typeInput;
    cout << "Enter Ticket Type (0 for VIP, 1 for Golden Circle, 2 for Tribune): ";
    is >> typeInput;

    ticket.setTicketID(ids);
    ticket.setType(static_cast<ticketType>(typeInput));

    return is;
}
