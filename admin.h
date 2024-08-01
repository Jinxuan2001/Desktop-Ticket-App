#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "employee.h"
#include "ticket.h"
#include <vector>

class Admin : public User {
private:
    std::vector<Employee> staffList;

public:
    Admin() {
        setUsernamePassword("ADMIN", "ADMIN"); //MUST CHANGE LATER
    }

    void addEmployee(const std::string& u, const std::string& p) {
        staffList.push_back(Employee(u, p));
    }

    void printStaff() const {
        for (const auto& staff : staffList) {
            staff.test();
        }
    }

    void assignTime(Ticket& ticket) {
        float time;
        ticket.printTicket();
        std::cout << "Allotted time:";
        std::cin >> time;
        ticket.setTimeAllotted(time);
    }
};

#endif
