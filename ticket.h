#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

class Ticket {
private:
    string ticketID; //automatically assigned ticket ID number
    string content; //description of problem described by generic user
    string tag; //tag for the type of problem
    float timeSubmitted; //time the user submitted the project
    float timeAllotted; //number of minutes/hours needed to finish ticket, set by employee
    string status; //current ticket status (under review, in progress, complete, etc)
    //create chat object

    string fromUser; //user who submitted the ticket
    string assignedEmployee; //employee who is assigned to it

public:
    Ticket() {
        this->ticketID = "ID";
        this->content = "";
        this->tag = "";
        this->timeSubmitted = 0;
        this->timeAllotted = 0;
        this->status = "Under Review";
        this->fromUser = "";
        this->assignedEmployee = "temp";
    }
    Ticket(string c, string t, string u) {
        this->ticketID = "ID";
        this->content = c;
        this->tag = t;
        this->timeSubmitted = 0;
        this->timeAllotted = 0;
        this->status = "Under Review";
        this->fromUser = u;
        this->assignedEmployee = "UNDECIDED";
    };
    Ticket(string id, string c, string tag, string time, string s, string user, string staff) {
        this->ticketID = id;
        this->content = c;
        this->tag = time;
        this->timeSubmitted = 0;
        this->timeAllotted = std::stof(time);
        this->status = s;
        this->fromUser = user;
        this->assignedEmployee = staff;
    };

    //Set Methods
    void setID(string ID) {
        ticketID = ID;
    };
    void setContent(string c) {
        content = c;
    };
    void setTag(string t) {
        tag = t;
    };
    void setTimeSubmitted(float timeS) {
        timeSubmitted = timeS;
    };
    void setTimeAllotted(float timeA) {
        timeAllotted = timeA;
    };
    void setStatus(string s) {
        status = s;
    };
    void setFromUser(string u) {
        fromUser = u;
    };

    //Get Methods
    string getContent() {
        return content;
    };
    string getTag() {
        return tag;
    };
    float getTimeSubmitted() {
        return timeSubmitted;
    };
    float getTimeAlloted() {
        return timeAllotted;
    };
    string getStatus() {
        return status;
    };
    string getFromUser() {
        return fromUser;
    };
    string getAssignedEmployee() {
        return assignedEmployee;
    };
    string getID() {
        return ticketID;
    };

    //Other
    void printTicket() {
        cout << "ID: " << ticketID << endl;
        cout << "Tag: " << tag << endl;
        cout << "Status: " << status << endl;
        cout << "From User: " << fromUser << endl;
        cout << "Content: " << content << endl;
        cout << endl;
    };

};

#endif