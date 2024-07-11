#include <iostream>
#include <vector>
#include <string>

#include "ticket.h"
#include "user.h"
#include "generic.h"
#include "employee.h"
#include "admin.h"

void testObjects(){
    Admin adminAccount = Admin();
    adminAccount.test();
    adminAccount.addEmployee("Employee 1", "1");
    adminAccount.addEmployee("Employee 2", "2");
    adminAccount.addEmployee("Employee 3", "3");
    adminAccount.printStaff();
}

void testTicket(){
    Generic testUser = Generic("User 1","1");
    testUser.test();
    std::string content = "THIS IS A TEST. DO NOT BE ALARMED. THERE IS NO DANGER. BLAH BLAH BLAH";
    std::string tag = "Testing Tag";
    testUser.createTicket(content, tag);
    testUser.printTickets();
}


int main() {
    std::cout << "Testing" << std::endl;

    testObjects();
    testTicket();

    return 0;
}
