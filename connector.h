#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "sqlite3.h"
#include <string>
#include <iostream>
#include <vector>

sqlite3* connectDB() {
	sqlite3* db;;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("data.db", &db);

    if (rc) {
        std::cout << "Can't open database \n";
        return(0);
    }
    else {
        std::cout << "Opened database successfully\n";
    }
    return db;
}

void init() {
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string tableUsers =     "CREATE TABLE USER(" \
                                 "USERNAME    TEXT  PRIMARY KEY  NOT NULL, " \
                                 "PASSWORD    TEXT               NOT NULL, " \
                                 "TYPE        TEXT               NOT NULL );";

    std::string tableEmployees = "CREATE TABLE EMPLOYEE(" \
                                 "USERNAME TEXT PRIMARY KEY NOT NULL, " \
                                 "NUMTICKS INT              NOT NULL, " \
                                 "TICKET1  TEXT                     , " \
                                 "TICKET2  TEXT                     , " \
                                 "TICKET3  TEXT                     , " \
                                 "TICKET4  TEXT                     , " \
                                 "TICKET5  TEXT                     , " \
                                 "TICKET6  TEXT                     , " \
                                 "TICKET7  TEXT                      );";

    std::string tableTickets =   "CREATE TABLE TICKET(" \
                                 "ID          TEXT PRIMARY KEY NOT NULL, " \
                                 "TAG         TEXT             NOT NULL, " \
                                 "STATUS      TEXT             NOT NULL, " \
                                 "FROMUSER    TEXT             NOT NULL, " \
                                 "TOUSER      TEXT                     , " \
                                 "TIMEALLOTED TEXT                     , " \
                                 "CONTENT     TEXT             NOT NULL );";


    ex = sqlite3_exec(db, tableUsers.c_str(), NULL, 0, &er);
    
    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create user table\n";
        sqlite3_close(db); 
        return;
    }

    ex = sqlite3_exec(db, tableEmployees.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create employee table\n";
        sqlite3_close(db);
        return;
    }

    ex = sqlite3_exec(db, tableTickets.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create employee table\n";
        sqlite3_close(db);
        return;
    }

    std::cout << "SUCCESS: Created all tables";
    sqlite3_close(db);           
}

//add methods

bool addUser(std::string username, std::string password, std::string type) {

    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string in = "INSERT INTO USER('" + username + ", " + password + ", " + type + ");";
    ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);

    if (ex == SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        return false;
    }

    if (type == "IT") {
        in = "INSERT INTO EMPLOYEE(' " + username + ", 0 );";
        ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);
    }

    if (ex == SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        return false;
    }

    sqlite3_close(db); 

    return true;


}

bool addTicket(std::string id, std::string tag, std::string status, std::string fromUser, std::string content) {
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string in = "INSERT INTO TICKET('" + id + ", " + tag + ", " + status + ", " + fromUser + ", NULL, NULL" + ", " + content + ");";
    ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);

    if (ex == SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        return false;
    }

    sqlite3_close(db);

    return true;
}

//refresh methods

std::vector<std::string> refreshUnassignedTickets() {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

std::vector<std::string> refreshUserList() {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

std::vector<std::string> refreshCalandar(std::string username) {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

//get methods

std::vector<std::string> getUser(std::string username, std::string password) {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

std::vector<std::string> getTicket(std::string id) {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

std::vector<std::string> getCalendar(std::string username) {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

//update methods

bool updatePassword(std::string username, std::string oldPass, std::string newPass) {
    return false;
    //TO DO
}

bool updateTicket(std::string id, std::string tag, std::string status, std::string fromUser, std::string content) {
    return false;
    //TO DO
}

bool updateCalandar(std::string username, std::string id) {
    return false;
    //TO DO
}

//delete methods

//TO DO

#endif
