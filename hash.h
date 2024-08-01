#ifndef HASH_H
#define HASH_H

#include "ticket.h"
#include <string>
#include <unordered_map>
#include <iostream>

class Hash {
private:
    std::unordered_map<std::string, Ticket> tickets;

public:
    std::string generateTicketID(const Ticket& ticket) {
        std::string username = ticket.getFromUser();
        std::time_t timeSubmitted = ticket.getTimeSubmitted();

        // Hash the username
        std::hash<std::string> hasher;
        size_t hashedUsername = hasher(username);

        // Combine the hashed username and timestamp
        std::string ticketID = std::to_string(hashedUsername) + std::to_string(timeSubmitted);
        return ticketID;
    }

    void storeTicket(const Ticket& ticket) {
        tickets[ticket.getID()] = ticket;
    }

    Ticket findTicket(const std::string& ID) {
        if (tickets.find(ID) != tickets.end()) {
            return tickets[ID];
        }
        else {
            std::cerr << "Ticket ID cannot be found" << std::endl;
            return Ticket();
        }
    }

    void printTickets() const {
        for (const auto& pair : tickets) {
            pair.second.printTicket();
        }
    }
};

#endif
