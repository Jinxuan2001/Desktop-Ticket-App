/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#ifndef SFML_APP_H
#define SFML_APP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "employee.h"
#include "user.h"
#include "ticket.h"

class SFMLApp {
public:
    SFMLApp();
    void run();

private:
    void processEvents();
    void update();
    void render();

    void handleUserInput(sf::Keyboard::Key key, bool isPressed);
    void handleMouseClick(sf::Vector2i position);
    void handleLogin();
    void showErrorMessage(const std::string& message);

    void renderLoginPanel();
    void renderSignUpPanel();

    enum class AppState { Login, SignUp, Customer, ITStaff, CreateTicket, TicketDisplay };
    AppState state;

    sf::RenderWindow window;
    sf::Font font;

    // Login Panel
    sf::Text loginTitle;
    sf::Text usernameLabel;
    sf::Text passwordLabel;
    sf::Text usernameInput;
    sf::Text passwordInput;
    sf::RectangleShape usernameRect;
    sf::RectangleShape passwordRect;

    sf::RectangleShape loginButton;
    sf::Text loginButtonText;
    sf::RectangleShape signUpButton;
    sf::Text signUpButtonText;

    bool isUsernameActive;
    bool isPasswordActive;
    bool showCursor;
    sf::Clock cursorClock;

    std::string username;
    std::string password;

    // Sign Up Panel
    sf::Text signUpTitle;
    sf::Text signUpUsernameLabel;
    sf::Text signUpPasswordLabel;
    sf::Text signUpUsernameInput;
    sf::Text signUpPasswordInput;
    sf::RectangleShape signUpUsernameRect;
    sf::RectangleShape signUpPasswordRect;

    sf::RectangleShape signUpPanelButton;
    sf::Text signUpPanelButtonText;

    sf::Text signUpStaffIDLabel;
    sf::Text signUpStaffIDInput;
    sf::RectangleShape signUpStaffIDRect;

    // bool isSignUpUsernameActive;
    // bool isSignUpPasswordActive;
    // bool isSignUpStaffIDActive;

    std::string signUpUsername;
    std::string signUpPassword;
    std::string signUpStaffID;

    // Additional UI elements and state variables
};

#endif // SFML_APP_H
