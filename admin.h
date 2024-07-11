#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "employee.h"
#include <vector>

class Admin : public User {
    private:
        std::vector<Employee> staffList;

    public:
        Admin(){
            setUsernamePassword("ADMIN", "ADMIN"); //MUST CHANGE LATER
        };

        void addEmployee(std::string u, std::string p){
            staffList.push_back(Employee(u,p));
        };

        void printStaff(){
            for(int i = 0; i < staffList.size(); i++){
                staffList[i].test();
            }
        };
};

#endif