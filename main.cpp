#include "sfml_app.h"
#include "user.h"
#include "employee.h"
#include "ticket.h"
#include <vector>

#include "helper.h"
#include "connector.h"
#include "tests.h"

int main() {
    std::vector<User> users;
    std::vector<Employee> staffs;
    std::vector<Ticket> tickets;
    //SFMLApp app(users,staffs,tickets);
    //app.run();

    //testCalendar();


    std::vector<std::string> test; 
    std::string username = "It1";
    std::string password = "ITP1";
    test = loginhelper(username, password);

    for (int i = 0; i < test.size(); i++) {
        std::cout << test[i] << std::endl;
    }

    if (test[0] == "Failed") {
        //login fail
    }
    else if (test[2] == "IT") {
        
        Employee temp = employeeType(username, password);
        //Testing stuff
        std::vector<Ticket> tickets = temp.getUnassigned();

        for (int i = 0; i < tickets.size(); i++) {
            tickets[i].printTicket();
        }

        temp.getCalendar().printCalendar();


        //Add sfml stuff


    }
    else if (test[2] == "ADMIN") {
        //ADMIN STUFF
    }
    else {
        Generic temp = genericType(username, password);

        std::vector<Ticket> tempV = temp.retrieveTickets();

        for (int j = 0; j < tempV.size(); j++) {
            tempV[j].printTicket(); 
        }
        //add sfml stuff
    }



    return 0;
}
