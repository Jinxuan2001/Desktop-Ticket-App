#ifndef GENERIC_H
#define GENERIC_H

#include "user.h"
#include "ticket.h"
#include <ctime>
#include <vector>

class Generic : public User {
    private:
        std::vector<Ticket> outgoingTickets;
    public:
        Generic(std::string u, std::string p) {
            setUsernamePassword(u,p);
        }

        void createTicket(std::string c, std::string t) {
            string u = getUsername();
            Ticket ticket = Ticket(c, t, u);
            std::time_t now = std::time(nullptr);
            std::stringstream ss;
            ss << now;
            ticket.setTimeSubmitted(now);
            outgoingTickets.push_back(ticket);
        }

        void printTickets() {
            for(int i = 0; i < outgoingTickets.size(); i++){
                outgoingTickets[i].printTicket();
            }
        }

        vector<Ticket> retrieveTickets() {
            return outgoingTickets;
        }
};

#endif
