#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <vector>
#include "user.h"
#include "ticket.h"
#include "calendar.h"

class Employee : public User {
private:
    std::vector<Ticket> unassigned;
    std::string username;
    std::string password; //TO DO: PASSWORD SECURITY
    Calendar personalCalendar = Calendar();


public:
    Employee() {
        this->username = "UNKNOWN";
        this->password = "UNKNOWN";
    };
    Employee(std::string u, std::string p) {
        this->username = u;
        this->password = p;
    };
    bool login(std::string input) {// PASSWORD CHECK
        return input == password;
    };
    void setUsernamePassword(std::string u, std::string p) {
        this->username = u;
        this->password = p;
    };
    std::string getUsername() {
        return this->username;
    };
    bool addTicket(Ticket ticket) {
        personalCalendar.addTicket(ticket);
        return true;
    };
    void test() {
        std::cout << "Username: " + username << std::endl;
        std::cout << "Password: " + password << std::endl;
        std::cout << std::endl;
        personalCalendar.printCalendar();
    };
    std::vector<Ticket> getUnassigned() {
        return unassigned;
    }

    Calendar getCalendar() {
        return personalCalendar;
    }

    void setUnassigned(std::vector<Ticket> tickets){
        unassigned = tickets;
    }
};

#endif
