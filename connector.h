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
    return db;
}
std::vector<std::string> temp;
std::vector<std::vector<std::string>> temp2;


//Call back function modificed from geeksforgeeks website
static int callback(void* data, int argc, char** argv, char** azColName) {
    //temp.clear();
    int i;
    for (i = 0; i < argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        temp.push_back(argv[i]);
    }
    return 0;
}

//add methods

bool addUser(std::string username, std::string password, std::string type) {

    sqlite3* db = connectDB();
    int ex;
    char* er;
    hash<string> tempHash;
    std::string in = "INSERT INTO USER VALUES('" + username + "', '" + std::to_string(tempHash(password)) + "', '" + type + "');";
    ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        return false;
    }
    /*
    if (type == "IT") {
        in = "INSERT INTO EMPLOYEE VALUES(' " + username + ", 0 );";
        ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);
    }

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        return false;
    }
    */

    sqlite3_close(db); 

    return true;


}

bool addTicket(std::string id, std::string tag, std::string status, std::string fromUser, std::string content) {
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string toUser = "NA";
    std::string timeAlloted = "NA";

    std::string in = "INSERT INTO TICKET VALUES('" + id + "', '" + tag + "', '" + status + "', '" + fromUser + "', '" + toUser + "', '" + timeAlloted + "', '" + content + "');";

    std::cout << in << std::endl;

    ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        sqlite3_close(db); 
        return false;
    }

    sqlite3_close(db);

    return true;
}

bool addTicket(std::string id, std::string tag, std::string status, std::string fromUser, std::string content, std::string toUser, std::string timeAlloted) {
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string in = "INSERT INTO TICKET VALUES('" + id + "', '" + tag + "', '" + status + "', '" + fromUser + "', '" + toUser + "', '" + timeAlloted + "', '" + content + "');";

    std::cout << in << std::endl;

    ex = sqlite3_exec(db, in.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot insert\n";
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);

    return true;
}

//get methods

std::vector<std::string> getUser(std::string username, std::string password) {
    
    temp.clear(); 
    sqlite3* db = connectDB();
    int ex;
    char* er;


    std::string data = "CALLBACK FUNCTION";
    std::string select = "SELECT * FROM USER WHERE USERNAME LIKE '%" + username + "%'";

    ex = sqlite3_exec(db, select.c_str(), callback, (void*)data.c_str(), NULL);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot select " + username << std::endl;
    }
    else {
        //std::cout << "Success\n";
    }

    hash<string> tempHash;
    if (temp[1] == std::to_string(tempHash(password))) {
        return temp;
    }
    std::vector<std::string> failed = { "Failed" };
    return failed;
    //TO DO
}

std::vector<std::string> getTicket(std::string id) {
    temp.clear(); 
    sqlite3* db = connectDB();
    int ex;
    char* er;


    std::string data = "CALLBACK FUNCTION";
    std::string select = "SELECT * FROM TICKET WHERE ID LIKE '%" + id + "%'";

    ex = sqlite3_exec(db, select.c_str(), callback, (void*)data.c_str(), NULL);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot select " + id << std::endl;
    }
    else { 
        //std::cout << "Success\n"; 
    }

    return temp;
    //TO DO
}

static int callbackTickets(void* data, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        temp2.push_back(getTicket(argv[i]));
    }
    return 0;
}

std::vector<std::vector<std::string>> findAllTickets(std::string username) {
    temp.clear();
    temp2.clear();
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string data = "CALLBACK FUNCTION";
    std::string select = "SELECT ID FROM TICKET WHERE FROMUSER LIKE '%" + username + "%'";

    ex = sqlite3_exec(db, select.c_str(), callbackTickets, (void*)data.c_str(), NULL);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot select Tickets with " + username << std::endl;
    }
    else {
        //std::cout << "Success\n";
    }
    return temp2; 

}

std::vector<std::vector<std::string>> getUnassignedTickets() {

    temp.clear();
    temp2.clear();

    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string data = "CALLBACK FUNCTION";
    std::string select = "SELECT ID FROM TICKET WHERE STATUS LIKE '%UNDER REVIEW%'";

    ex = sqlite3_exec(db, select.c_str(), callbackTickets, (void*)data.c_str(), NULL);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot select Unassigend TIckets" << std::endl;
    }
    else {
        //std::cout << "Success\n";
    }

    return temp2;

}

std::vector<std::vector<std::string>> getEmployeeTickets(std::string username) {

    temp.clear(); 
    temp2.clear(); 

    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string data = "CALLBACK FUNCTION";
    std::string select = "SELECT ID FROM TICKET WHERE TOUSER LIKE '%" + username + "%'";

    ex = sqlite3_exec(db, select.c_str(), callbackTickets, (void*)data.c_str(), NULL);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot select Tickets with " + username << std::endl;
    }
    else {
        //std::cout << "Success\n";
    }
    return temp2;
}

std::vector<std::string> getCalendar(std::string username) {
    std::vector<std::string> test = { "FALSE" };
    return test;
    //TO DO
}

//update methods

bool updatePassword(std::string username, std::string oldPass, std::string newPass) {
    std::vector<std::string> log = getUser(username, oldPass);

    if (log[0] == "Failed") {
        return false;
    }
    else {

        sqlite3* db = connectDB();
        int ex;
        char* er;

        hash<string> tempHash;
        std::string insert = std::to_string(tempHash(newPass));
        std::string upd = "UPDATE USER SET PASSWORD = '" + insert + "' WHERE USERNAME = '" + username + "';";
        ex = sqlite3_exec(db, upd.c_str(), NULL, 0, &er);

        if (ex != SQLITE_OK) {
            std::cout << "Error: Cannot change password\n";
            return false;
        }
        else {
            return true;
        }
    }

    return false;
    //TO DO
}

bool updateTicket(std::string id, std::string tag, std::string status, std::string fromUser, std::string toUser, std::string time, std::string content) {

    sqlite3* db = connectDB();
    int ex;
    char* er;
;
    std::string upd = "UPDATE TICKET SET TAG = '" + tag + 
                                 "', SET STATUS = '" + status +
                                 "', SET FROMUSER = '" + fromUser + 
                                 "', SET TOUSER = '" + toUser + 
                                 "', SET TIMEALLOTED = '" + time +
                                 "', SET CONTENT = '" + content +
                                 "WHERE ID = '" + id + "';";
   
    ex = sqlite3_exec(db, upd.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "Error: Cannot change password\n";
        return false;
    }
    else {
        return true;
    }

    return false;
    //TO DO
}

bool updateCalandar(std::string username, std::string id) {
    return false;
    //TO DO
}

//delete methods

//TO DO

void init() {
    sqlite3* db = connectDB();
    int ex;
    char* er;

    std::string tableUsers = "CREATE TABLE USER(" \
        "USERNAME    TEXT  PRIMARY KEY  NOT NULL, " \
        "PASSWORD    TEXT               NOT NULL, " \
        "TYPE        TEXT               NOT NULL );";

    /*
    std::string tableEmployees = "CREATE TABLE EMPLOYEE(" \
        "USERNAME TEXT PRIMARY KEY NOT NULL, " \
        "NUMTICKS INT NOT NULL, " \
        "TICKET1 TEXT, " \
        "TICKET2 TEXT, " \
        "TICKET3 TEXT, " \
        "TICKET4 TEXT, " \
        "TICKET5 TEXT, " \
        "TICKET6 TEXT, " \
        "TICKET7 TEXT);";

    */
    std::string tableTickets = "CREATE TABLE TICKET(" \
        "ID TEXT PRIMARY KEY NOT NULL, " \
        "TAG TEXT NOT NULL, " \
        "STATUS TEXT NOT NULL, " \
        "FROMUSER TEXT NOT NULL, " \
        "TOUSER TEXT NOT NULL, " \
        "TIMEALLOTED TEXT NOT NULL, " \
        "CONTENT TEXT NOT NULL );";


    ex = sqlite3_exec(db, tableUsers.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create user table\n";
        sqlite3_close(db);
        return;
    }

    /*
    ex = sqlite3_exec(db, tableEmployees.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create employee table\n";
        sqlite3_close(db);
        return;
    }
    */


    ex = sqlite3_exec(db, tableTickets.c_str(), NULL, 0, &er);

    if (ex != SQLITE_OK) {
        std::cout << "ERROR: Failed to create ticket table\n";
        sqlite3_close(db);
        return;
    }

    //std::cout << "SUCCESS: Created all tables";
    sqlite3_close(db);

    //adding dummy data

    //Generic Users
    addUser("User1", "GP1", "Generic");
    addUser("User2", "GP2", "Gemeric");
    addUser("User3", "GP3", "Gemeric");
    addUser("User4", "GP4", "Gemeric");
    addUser("User5", "GP5", "Gemeric");

    //IT staff
    addUser("It1", "ITP1", "IT");
    addUser("It2", "ITP2", "IT");
    addUser("It3", "ITP3", "IT");

    //Unassigned Tickets
    addTicket("1", "Hardware", "Under Review", "User1", "My computer wont turn on");
    addTicket("2", "Hardware", "Under Review", "User2", "I broke my monitor screen");
    addTicket("3", "Software", "Under Review", "User3", "How to insert textbox in word");
    addTicket("4", "Account", "Under Review", "User4", "I have been hacked, ignore future tickets");
    addTicket("5", "Account", "Under Review", "User4", "I require a million dollars or I will leak all data in the company");

    //Assigned Tickets
    addTicket("6", "Account", "In Progress", "User1", "Changing password", "It1", "0.5");
    addTicket("7", "Software", "In Progress", "User1", "BlueScreen of death", "It1", "3");
    addTicket("8", "Software", "In Progress", "User2", "Why dont we use AI instead", "It2", "1");


}

#endif
