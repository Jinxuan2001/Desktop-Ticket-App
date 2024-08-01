#ifndef SFML_APP_H
#define SFML_APP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ticket.h"

enum class AppState { Login, Customer, ITStaff, CreateTicket };

class SFMLApp {
public:
    SFMLApp();
    void run();

private:
    void processEvents();
    void update();
    void render();

    void renderLoginScreen();
    void renderCustomerScreen();
    void renderITStaffScreen();
    void renderCreateTicketScreen();

    void handleLoginInput(sf::Event& event);
    void handleCustomerInput(sf::Event& event);
    void handleITStaffInput(sf::Event& event);
    void handleCreateTicketInput(sf::Event& event);

    void displayTickets();
    void displayITStaffTickets();
    void createTicket();

    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite background;
    sf::Font font;

    sf::Text username;
    sf::Text password;
    sf::Text usernameInput;
    sf::Text passwordInput;
    sf::RectangleShape loginButton;
    sf::Text loginButtonText;

    sf::RectangleShape createTicketButton;
    sf::Text createTicketButtonText;

    std::vector<Ticket> tickets;

    AppState state;
    std::string accountType;
    bool loggedIn;
    bool usernameActive = false;
    bool passwordActive = false;
    std::string usernameStr;
    std::string passwordStr;
};

std::string formatTime(std::time_t time);

#endif // SFML_APP_H
