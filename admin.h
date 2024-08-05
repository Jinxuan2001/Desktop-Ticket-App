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
    Admin(std::string u, std::string p) {
        setUsernamePassword(u, p);
    }

    void addEmployee(std::string u, std::string p) {
        staffList.push_back(Employee(u, p));
    }

    void printStaff() {
        for (int i = 0; i < staffList.size(); i++) {
            staffList[i].test();
        }
    }

    void assignTime(Ticket ticket) {
        float time;
        ticket.printTicket();
        cout << "Allotted time:";
        cin >> time;
        ticket.setTimeAllotted(time);
    }

};
#endif