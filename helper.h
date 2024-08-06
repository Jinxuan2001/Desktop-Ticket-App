#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>


#include "ticket.h"
#include "calendar.h"
#include "user.h"
#include "generic.h"
#include "admin.h"
#include "employee.h"
#include "connector.h"

std::vector<Ticket> getUnassignedTicketsHelper() {

	std::vector<Ticket> unassigned;
	std::vector <std::vector<std::string>> r = getUnassignedTickets();

	for (int i = 0; i < r.size(); i++) {

		Ticket tempT = Ticket(
			r[i][0], //id
			r[i][6], //content
			r[i][1], //tag
			r[i][5], //time
			r[i][2], //status
			r[i][3], //user
			r[i][4]); //staff

		unassigned.push_back(tempT);
	}

	return unassigned;
}

std::vector<std::string> loginhelper(std::string username, std::string password) {
	std::vector<std::string> temp = getUser(username, password);
	return temp;
}

Employee employeeType(std::string username, std::string password) {
	Employee tempIT = Employee(username, password); 
	tempIT.setUnassigned(getUnassignedTicketsHelper()); 
	std::cout << "PASSED\n";

	std::vector<std::vector<std::string>> fillC1 = getEmployeeTickets(tempIT.getUsername()); 
	std::vector<Ticket> fillC2; 

	for (int i = 0; i < fillC1.size(); i++) { 

		Ticket tempT = Ticket(fillC1[i][0], //id 
			fillC1[i][6], //content 
			fillC1[i][1], //tag 
			fillC1[i][5], //time 
			fillC1[i][2], //status 
			fillC1[i][3], //user 
			fillC1[i][4]); //staff 

		fillC2.push_back(tempT); 
	}

	for (int j = 0; j < fillC2.size(); j++) { 
		tempIT.addTicket(fillC2[j]); 
	}
	return tempIT;

}

Generic genericType(std::string username, std::string password) {
	Generic temp = Generic(username, password);
	std::vector<std::vector<std::string>> tickets = findAllTickets(username); 
	std::vector<Ticket> outTickets; 

	std::cout << tickets.size() << std::endl;

	for (int i = 0; i < tickets.size(); i++) { 

		Ticket tempT = Ticket(tickets[i][0], //id 
			tickets[i][6], //content 
			tickets[i][1], //tag 
			tickets[i][5], //time 
			tickets[i][2], //status 
			tickets[i][3], //user 
			tickets[i][4]); //staff 

		outTickets.push_back(tempT); 
	}

	temp.setTickets(outTickets); 

	return temp;
}

bool addTicketHelper(Ticket t) {
	return addTicket(t.getID(), t.getTag(), t.getStatus(), t.getFromUser(), t.getContent());
}

bool setTicket(Ticket t, std::string time, std::string username) {
	float temptime = stof(time); //IN MINUTES
	temptime = temptime / 60;

	return updateTicket(t.getID(), t.getTag(), t.getStatus(), t.getFromUser(), username, std::to_string(temptime), t.getContent());

}

#endif
