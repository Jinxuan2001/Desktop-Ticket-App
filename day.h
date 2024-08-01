#ifndef DAY_H
#define DAY_H

#include "ticket.h"
#include <vector>
#include <iostream>

class Day {
private:
    int startTime;
    int endTime;
    std::vector<Ticket> ticketList;
    float totalTime;

public:
    Day() : startTime(9), endTime(17), totalTime(0) {}

    bool insertTicket(const Ticket& ticket) {
        if (ticket.getTimeAllotted() <= (endTime - startTime - totalTime)) {
            ticketList.push_back(ticket);
            totalTime += ticket.getTimeAllotted();
            return true;
        }
        return false;
    }

    void printDay() const {
        float tempTime = startTime;
        for (const auto& ticket : ticketList) {
            std::cout << "Start time: " << tempTime << std::endl;
            ticket.printTicket();
            tempTime += ticket.getTimeAllotted();
        }
    }
};

#endif
