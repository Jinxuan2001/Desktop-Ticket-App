#ifndef TESTS_H
#define TESTS_H

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

void testCalendar(){
    Employee testEmployee = Employee("Staff 1", "1");
    testEmployee.test();

    //Ticket Content
    std::string content = "Calendar Test Prompt for Individual Ticket";
    std::string tag = "Testing Tag";
    std::string user = "Dumb User";

    //Ticket Creation
    Ticket test1 = Ticket("TestID1",content,tag,user);
    Ticket test2 = Ticket("TestID2",content,tag,user);
    Ticket test3 = Ticket("TestID3",content,tag,user);
    Ticket test4 = Ticket("TestID4",content,tag,user);
    Ticket test5 = Ticket("TestID5",content,tag,user);
    Ticket test6 = Ticket("TestID6",content,tag,user);
    Ticket test7 = Ticket("TestID7",content,tag,user);
    Ticket test8 = Ticket("TestID8",content,tag,user);
    Ticket test9 = Ticket("TestID9",content,tag,user);
    Ticket test10 = Ticket("TestID10",content,tag,user);

    //Change Alloted Time
    test1.setTimeAllotted(5);
    test2.setTimeAllotted(3); //1 day
    test3.setTimeAllotted(7); //day 2
    test4.setTimeAllotted(4); //too long for day 2, move to day 3
    test5.setTimeAllotted(4);
    test6.setTimeAllotted(8);//day 4
    test7.setTimeAllotted(8);//day 5
    test8.setTimeAllotted(4); // week 2 day 1
    test9.setTimeAllotted(4); 
    test10.setTimeAllotted(5); // week 2 day 2

    //Insert into Calendar
    testEmployee.addTicket(test1);
    testEmployee.addTicket(test2);
    testEmployee.addTicket(test3);
    testEmployee.addTicket(test4);
    testEmployee.addTicket(test5);
    testEmployee.addTicket(test6);
    testEmployee.addTicket(test7);
    testEmployee.addTicket(test8);
    testEmployee.addTicket(test9);
    testEmployee.addTicket(test10);

    //print
    testEmployee.test();
}

void runAllTests(){
    testObjects();
    testTicket();
}

#endif