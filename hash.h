#ifndef DESKTOP_TICKET_APP_HASH_H
#define DESKTOP_TICKET_APP_HASH_H

#include "ticket.h"
#include <string>
#include <ctime>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

class Hash {
private:
    string ID;
    unordered_map<string, Ticket> tickets;
public:

    //store and hash tickets
    std::string generateTicketID(Ticket ticket) {
        string username = ticket.getFromUser();
        float timeSubmitted = ticket.getTimeSubmitted();

        // Hash the username
        std::hash<std::string> hasher;
        size_t hashedUsername = hasher(username);

        // Combine the hashed username and timestamp
        std::string ticketID = std::to_string(hashedUsername) + to_string(timeSubmitted);
        return ticketID;
    }

    void storeTicket(Ticket ticket) {
        tickets[ticket.getID()] = ticket;
    }

    Ticket findTicket(string ID) {
        if (tickets.find(ID) != tickets.end()) {
            return tickets[ID];
        }
        else {
            cout << "Ticket ID cannot be found" << endl;
        }
    }

    void printTickets() {
        auto iter = tickets.begin();
        for (; iter != tickets.end(); iter++) {
            iter->second.printTicket();
        }
    }
};

#endif //DESKTOP_TICKET_APP_HASH_H
