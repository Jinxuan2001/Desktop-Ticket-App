#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"
#include "ticket.h"
#include "calendar.h"

class Employee : public User{
    private:
        Calendar personalCalendar = Calendar();

    public:
        Employee();
        Employee(std::string u, std::string p){
            setUsernamePassword(u,p);
        };

        Employee(std::vector<std::string> u) {
            setUsernamePassword(u[0], u[1]);
        }

        bool addTicket(Ticket ticket){
            personalCalendar.addTicket(ticket);
            return true;
        };

        void test(){
            personalCalendar.printCalendar();
        }
};

#endif