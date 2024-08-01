#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
private:
    std::string username;
    std::string password; //TO DO: PASSWORD SECURITY
public:
    User() : username("UNKNOWN"), password("UNKNOWN") {}
    User(std::string u, std::string p) : username(u), password(p) {}

    bool login(std::string input) {
        //TO DO: USER AUTHENTICATION
        return true; //CHANGE
    }

    void setUsernamePassword(std::string u, std::string p) {
        this->username = u;
        this->password = p;
    }

    std::string getUsername() const {
        return this->username;
    }

    void test() const {
        std::cout << "Username: " + username << std::endl;
        std::cout << "Password: " + password << std::endl;
        std::cout << std::endl;
    }
};

#endif
