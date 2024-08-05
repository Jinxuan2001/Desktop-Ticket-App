// TicketMastersApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tests.h"
#include "connector.h"
#include <vector>
#include <string>

int main()
{
    //testTicket();
    connectDB();
    std::vector<std::string> test;

    /* 
    
    //addUser("Username2", "Password2","Generic");
    test = getUser("Username2", "NewPassword2");
    
    for (int i = 0; i < test.size(); i++) {
        std::cout << test[i] << std::endl;
    }

    */

    addTicket("1", "TestTag", "TestStatus", "Username2", "This is a test");

    /*
    
     test = getTicket("1");

    for (int i = 0; i < test.size(); i++) {
        std::cout << test[i] << std::endl;
    }

    
    */



    //init();
}