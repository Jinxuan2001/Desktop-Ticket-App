#ifndef DAY_H
#define DAY_H

#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include <chrono>
#include <iostream>
#include <vector>

#include "ticket.h"

class Day {
    private:
        int startTime;
        int endTime;
        std::vector<Ticket> ticketList;
        float totalTime;


    public:
        Day(){
            this->startTime = 9; //9 am
            this->endTime = 17; // 5 pm
            this->totalTime = 0;
        }
        Day(int s, int e, int t){
            this->startTime = s;
            this->endTime = e;
            this->totalTime = t;
        }

        bool insertTicket(Ticket ticket){
            //Create function to get ticket from ticket ID (database layer)
            
            if(ticket.getTimeAlloted() <= ((endTime - startTime) - totalTime)){
                ticketList.push_back(ticket);
                totalTime += ticket.getTimeAlloted();
                return true;
            }
            else{
                return false;
            }
        }

        float getAssignedTime(Ticket ticket){
            float tempTime = startTime;
            for(int i = 0; i < ticketList.size(); i++){
                if(ticket.getID() == ticketList[i].getID()){
                    return tempTime;
                }
                else{
                    tempTime += ticketList[i].getTimeAlloted();
                }
            }
        }

        void printDay(){
            float tempTime = startTime;
            for(int i = 0; i < ticketList.size(); i++){
                std::cout << "Start time: " + to_string(tempTime) << std::endl;
                ticketList[i].printTicket();
                tempTime += ticketList[i].getTimeAlloted();
            }
        }

};

#endif