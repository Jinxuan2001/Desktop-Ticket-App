#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
    private:
        std::string username;
        std::string password; //TO DO: PASSWORD SECURITY
    public:
        User(){
            this->username = "UNKNOWN";
            this->password = "UNKNOWN";
        };
        User(std::string u, std::string p){
            this->username = u;
            this->password = p;
        };
        User(std::vector<std::string> u) {
            this->username = u[0];
            this->password = u[1];
        }
        bool login(std::string input){
            //TO DO: USER AUTHENTICATION
            return true; //CHANGE
        };
        void setUsernamePassword(std::string u, std::string p){
            this->username = u;
            this->password = p;
        };
        std::string getUsername(){
            return this->username;
        };
        void test(){
            std::cout << "Username: " + username << std::endl;
            std::cout << "Password: " + password << std::endl;
            std::cout << endl;
        };
};

#endif