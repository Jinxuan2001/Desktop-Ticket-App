#ifndef CALENDAR_H
#define CALENDAR_H

#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include <chrono>
#include <iostream>
#include <vector>

#include "ticket.h"
#include "day.h"

class Calendar {
    private:
        std::vector<std::vector<Day>> weeklyList;
        int workWeekSize;
    public:
        Calendar(){
            workWeekSize = 5;
        };

        bool addWeek(Ticket ticket){
            Day tempday = Day();
            bool inserted = tempday.insertTicket(ticket);
            if(inserted){
                std::vector<Day> temp = {tempday};
                weeklyList.push_back(temp);
                return true;
            }
            else{return false;}
        }

        bool addDay(Ticket ticket){
            Day tempday = Day();
            bool inserted = tempday.insertTicket(ticket);
            if(inserted && weeklyList[weeklyList.size()-1].size() < 5){
                weeklyList[weeklyList.size()-1].push_back(tempday);
                return true;
            }
            else{return false;}
        }

        bool addTicket(Ticket ticket){
            //Initializing calendar if it is empty
            if(weeklyList.size() == 0){
                addWeek(ticket);
                return true;
            }
            else{
                //iterates through weeks
                bool inserted = false;
                for(int i = 0; i < weeklyList.size(); i++){
                    //if week is empty, adds 
                    if(weeklyList[i].size() == 0){
                        addDay(ticket);
                        return true;
                    }
                    
                    for(int j = 0; j < weeklyList[i].size(); j++){
                        inserted = weeklyList[i][j].insertTicket(ticket);
                        if(inserted){
                            return true;
                        }
                    }
                    if(!inserted && weeklyList[i].size() < workWeekSize){
                        inserted = addDay(ticket);
                        return true;
                    }
                }
                if(!inserted){
                    inserted = addWeek(ticket);
                }
                return inserted;
            }
        }

        void printCalendar(){
            for(int i = 0; i < weeklyList.size(); i++){
                std::cout << "Week " + to_string(i+1) << std::endl;
                for(int j = 0; j < weeklyList[i].size(); j++){
                    std::cout << "Day " + to_string(j+1) << std::endl;
                    weeklyList[i][j].printDay();
                }
            }
        }
};

#endif