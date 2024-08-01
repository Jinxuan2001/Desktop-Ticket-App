#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"
#include "ticket.h"
#include "calendar.h"
#include <vector>

class Employee : public User {
private:
    Calendar personalCalendar;

public:
    Employee() {}
    Employee(std::string u, std::string p) : User(u, p) {}

    bool addTicket(const Ticket& ticket) {
        personalCalendar.addTicket(ticket);
        return true;
    }

    void test() const {
        personalCalendar.printCalendar();
    }
};

#endif
