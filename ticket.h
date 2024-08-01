#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

class Ticket {
private:
    std::string id;
    std::string content;
    std::string tag;
    std::string fromUser;
    std::time_t timeSubmitted;
    float timeAllotted;

public:
    Ticket() : id("UNKNOWN"), content(""), tag(""), fromUser(""), timeSubmitted(0), timeAllotted(0) {}
    Ticket(std::string c, std::string t, std::string u)
        : content(c), tag(t), fromUser(u), timeSubmitted(std::time(nullptr)), timeAllotted(0) {}

    std::string getID() const { return id; }
    void setID(const std::string& newID) { id = newID; }

    std::string getTag() const { return tag; }
    std::string getDate() const { return formatTime(timeSubmitted); }
    std::string getITStaff() const { return fromUser; }

    std::string getContent() const { return content; }
    void setContent(const std::string& newContent) { content = newContent; }

    std::string getFromUser() const { return fromUser; }
    std::time_t getTimeSubmitted() const { return timeSubmitted; }
    float getTimeAllotted() const { return timeAllotted; }
    void setTimeAllotted(float t) { timeAllotted = t; }
    void setTimeSubmitted(std::time_t t) { timeSubmitted = t; }

    void printTicket() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Content: " << content << std::endl;
        std::cout << "Tag: " << tag << std::endl;
        std::cout << "From: " << fromUser << std::endl;
        std::cout << "Time Submitted: " << timeSubmitted << std::endl;
        std::cout << "Time Allotted: " << timeAllotted << std::endl;
    }
};

#endif // TICKET_H
