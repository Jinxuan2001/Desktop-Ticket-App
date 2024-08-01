#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"
#include "ticket.h"
#include <vector>
#include <iostream>

class Calendar {
private:
    std::vector<std::vector<Day>> weeklyList;
    int workWeekSize;

public:
    Calendar() : workWeekSize(5) {}

    bool addWeek(const Ticket& ticket) {
        Day tempday;
        if (tempday.insertTicket(ticket)) {
            weeklyList.push_back({ tempday });
            return true;
        }
        return false;
    }

    bool addDay(const Ticket& ticket) {
        Day tempday;
        if (tempday.insertTicket(ticket) && weeklyList.back().size() < workWeekSize) {
            weeklyList.back().push_back(tempday);
            return true;
        }
        return false;
    }

    bool addTicket(const Ticket& ticket) {
        if (weeklyList.empty()) {
            return addWeek(ticket);
        }
        else {
            for (auto& week : weeklyList) {
                for (auto& day : week) {
                    if (day.insertTicket(ticket)) {
                        return true;
                    }
                }
                if (week.size() < workWeekSize) {
                    return addDay(ticket);
                }
            }
            return addWeek(ticket);
        }
    }

    void printCalendar() const {
        for (size_t i = 0; i < weeklyList.size(); ++i) {
            std::cout << "Week " << (i + 1) << std::endl;
            for (size_t j = 0; j < weeklyList[i].size(); ++j) {
                std::cout << "Day " << (j + 1) << std::endl;
                weeklyList[i][j].printDay();
            }
        }
    }
};

#endif
