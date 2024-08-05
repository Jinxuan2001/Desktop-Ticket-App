#include "sfml_app.h"
#include "sfml_customer.h"
#include "sfml_itStaff.h"

#include <iostream>
#include <iterator>
#include <vector>


SFMLApp::SFMLApp(std::vector<User>& users, std::vector<Employee>& staffs, std::vector<Ticket>& tickets) 
    : window(sf::VideoMode(800, 600), "Desktop Ticket App"), state(AppState::Login), 
      isUsernameActive(false), isPasswordActive(false), showCursor(true), 
      users(users), staffs(staffs),tickets(tickets) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }
    // Initialize UI elements for login panel
    loginTitle.setFont(font);
    loginTitle.setString("Log In");
    loginTitle.setCharacterSize(30);
    loginTitle.setFillColor(sf::Color::White);
    loginTitle.setPosition(350, 100);

    usernameLabel.setFont(font);
    usernameLabel.setString("Username:");
    usernameLabel.setCharacterSize(20);
    usernameLabel.setFillColor(sf::Color::White);
    usernameLabel.setPosition(200, 200);

    passwordLabel.setFont(font);
    passwordLabel.setString("Password:");
    passwordLabel.setCharacterSize(20);
    passwordLabel.setFillColor(sf::Color::White);
    passwordLabel.setPosition(200, 300);

    usernameInput.setFont(font);
    usernameInput.setCharacterSize(20);
    usernameInput.setFillColor(sf::Color::Black);
    usernameInput.setPosition(350, 200);

    passwordInput.setFont(font);
    passwordInput.setCharacterSize(20);
    passwordInput.setFillColor(sf::Color::Black);
    passwordInput.setPosition(350, 300);

    usernameRect.setSize(sf::Vector2f(200, 30));
    usernameRect.setFillColor(sf::Color::White);
    usernameRect.setPosition(350, 200);

    passwordRect.setSize(sf::Vector2f(200, 30));
    passwordRect.setFillColor(sf::Color::White);
    passwordRect.setPosition(350, 300);

    loginButton.setSize(sf::Vector2f(100, 30));
    loginButton.setFillColor(sf::Color::White);
    loginButton.setPosition(350, 400);

    loginButtonText.setFont(font);
    loginButtonText.setString("Log In");
    loginButtonText.setCharacterSize(20);
    loginButtonText.setFillColor(sf::Color::Black);
    loginButtonText.setPosition(370, 400);

    signUpButton.setSize(sf::Vector2f(100, 30));
    signUpButton.setFillColor(sf::Color::White);
    signUpButton.setPosition(500, 400);

    signUpButtonText.setFont(font);
    signUpButtonText.setString("Sign Up");
    signUpButtonText.setCharacterSize(20);
    signUpButtonText.setFillColor(sf::Color::Black);
    signUpButtonText.setPosition(520, 400);

    // Initialize UI elements for sign-up panel
    signUpTitle.setFont(font);
    signUpTitle.setString("Sign Up");
    signUpTitle.setCharacterSize(30);
    signUpTitle.setFillColor(sf::Color::White);
    signUpTitle.setPosition(350, 100);

    signUpUsernameLabel.setFont(font);
    signUpUsernameLabel.setString("Username:");
    signUpUsernameLabel.setCharacterSize(20);
    signUpUsernameLabel.setFillColor(sf::Color::White);
    signUpUsernameLabel.setPosition(200, 200);

    signUpPasswordLabel.setFont(font);
    signUpPasswordLabel.setString("Password:");
    signUpPasswordLabel.setCharacterSize(20);
    signUpPasswordLabel.setFillColor(sf::Color::White);
    signUpPasswordLabel.setPosition(200, 300);

    signUpUsernameInput.setFont(font);
    signUpUsernameInput.setCharacterSize(20);
    signUpUsernameInput.setFillColor(sf::Color::Black);
    signUpUsernameInput.setPosition(350, 200);

    signUpPasswordInput.setFont(font);
    signUpPasswordInput.setCharacterSize(20);
    signUpPasswordInput.setFillColor(sf::Color::Black);
    signUpPasswordInput.setPosition(350, 300);

    signUpUsernameRect.setSize(sf::Vector2f(200, 30));
    signUpUsernameRect.setFillColor(sf::Color::White);
    signUpUsernameRect.setPosition(350, 200);

    signUpPasswordRect.setSize(sf::Vector2f(200, 30));
    signUpPasswordRect.setFillColor(sf::Color::White);
    signUpPasswordRect.setPosition(350, 300);

    signUpPanelButton.setSize(sf::Vector2f(100, 30));
    signUpPanelButton.setFillColor(sf::Color::White);
    signUpPanelButton.setPosition(350, 400);

    signUpPanelButtonText.setFont(font);
    signUpPanelButtonText.setString("Sign Up");
    signUpPanelButtonText.setCharacterSize(20);
    signUpPanelButtonText.setFillColor(sf::Color::Black);
    signUpPanelButtonText.setPosition(370, 400);

    // Staff ID check
    signUpStaffIDLabel.setFont(font);
    signUpStaffIDLabel.setString("Staff ID (Optional):");
    signUpStaffIDLabel.setCharacterSize(20);
    signUpStaffIDLabel.setFillColor(sf::Color::White);
    signUpStaffIDLabel.setPosition(150, 350);

    signUpStaffIDInput.setFont(font);
    signUpStaffIDInput.setCharacterSize(20);
    signUpStaffIDInput.setFillColor(sf::Color::Black);
    signUpStaffIDInput.setPosition(350, 350);

    signUpStaffIDRect.setSize(sf::Vector2f(200, 30));
    signUpStaffIDRect.setFillColor(sf::Color::White);
    signUpStaffIDRect.setPosition(350, 350);
}

void SFMLApp::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void SFMLApp::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            handleUserInput(event.key.code, true);
            break;
        case sf::Event::TextEntered:
            if (state == AppState::Login) {
                if (isUsernameActive) {
                    if (event.text.unicode == '\b' && !username.empty()) {
                        username.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        username += static_cast<char>(event.text.unicode);
                    }
                    usernameInput.setString(username + (showCursor ? "|" : ""));
                }
                else if (isPasswordActive) {
                    if (event.text.unicode == '\b' && !password.empty()) {
                        password.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        password += static_cast<char>(event.text.unicode);
                    }
                    passwordInput.setString(password + (showCursor ? "|" : ""));
                }
            }
            else if (state == AppState::SignUp) {
                if (isSignUpUsernameActive) {
                    if (event.text.unicode == '\b' && !signUpUsername.empty()) {
                        signUpUsername.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        signUpUsername += static_cast<char>(event.text.unicode);
                    }
                    signUpUsernameInput.setString(signUpUsername + (showCursor ? "|" : ""));
                }
                else if (isSignUpPasswordActive) {
                    if (event.text.unicode == '\b' && !signUpPassword.empty()) {
                        signUpPassword.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        signUpPassword += static_cast<char>(event.text.unicode);
                    }
                    signUpPasswordInput.setString(signUpPassword + (showCursor ? "|" : ""));
                }
                else if (isSignUpStaffIDActive) {
                    if (event.text.unicode == '\b' && !signUpStaffID.empty()) {
                        signUpStaffID.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        signUpStaffID += static_cast<char>(event.text.unicode);
                    }
                    signUpStaffIDInput.setString(signUpStaffID + (showCursor ? "|" : ""));
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseClick(sf::Mouse::getPosition(window));
            break;
        default:
            break;
        }
    }
}

void SFMLApp::update() {
    if (cursorClock.getElapsedTime().asSeconds() >= 0.5f) {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    if (state == AppState::Login) {
        if (isUsernameActive) {
            usernameInput.setString(username + (showCursor ? "|" : ""));
        }
        else {
            usernameInput.setString(username);
        }

        if (isPasswordActive) {
            passwordInput.setString(password + (showCursor ? "|" : ""));
        }
        else {
            passwordInput.setString(password);
        }
    }
    else if (state == AppState::SignUp) {
        if (isSignUpUsernameActive) {
            signUpUsernameInput.setString(signUpUsername + (showCursor ? "|" : ""));
        }
        else {
            signUpUsernameInput.setString(signUpUsername);
        }

        if (isSignUpPasswordActive) {
            signUpPasswordInput.setString(signUpPassword + (showCursor ? "|" : ""));
        }
        else {
            signUpPasswordInput.setString(signUpPassword);
        }
        if (isSignUpStaffIDActive) {
            signUpStaffIDInput.setString(signUpStaffID + (showCursor ? "|" : ""));
        }
        else {
            signUpStaffIDInput.setString(signUpStaffID);
        }
    }
}

void SFMLApp::render() {
    window.clear(sf::Color(128, 128, 128));
    if (state == AppState::Login) {
        renderLoginPanel();
    }
    else if (state == AppState::SignUp) {
        renderSignUpPanel();
    }
    window.display();
}

void SFMLApp::handleUserInput(sf::Keyboard::Key key, bool isPressed) {
    // Handle user input
}

void SFMLApp::handleLogin() {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getUsername() == username) {
            if (it->login(password)) {
                // logged in as Customer
                SFMLCustomer customerWindow(tickets,*it);
                customerWindow.runCustomer();
                return;
            }
            else {
                showErrorMessage("Incorrect password!");
                return;
            }
        }
    }

    for (auto it = staffs.begin(); it != staffs.end(); ++it) {
        if (it->getUsername() == username) {
            if (it->login(password)) {
                // logged in as Customer
                SFMLItStaff itStaffWindow(tickets, *it);
                itStaffWindow.runItStaff();
                return;
            }
            else {
                showErrorMessage("Incorrect password!");
                return;
            }
        }
    }
    showErrorMessage("Username doesn't exist!");
}



void SFMLApp::handleMouseClick(sf::Vector2i position) {
    if (state == AppState::Login) {
        if (usernameRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isUsernameActive = true;
            isPasswordActive = false;
        }
        else if (passwordRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isUsernameActive = false;
            isPasswordActive = true;
        }
        else if (loginButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            handleLogin();
        }
        else if (signUpButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            state = AppState::SignUp;
            isSignUpUsernameActive = false;
            isSignUpPasswordActive = false;
            isSignUpStaffIDActive = false;
            signUpUsername.clear();
            signUpPassword.clear();
            signUpStaffID.clear();
            signUpUsernameInput.setString("");
            signUpPasswordInput.setString("");
            signUpStaffIDInput.setString("");
        }
        else {
            isUsernameActive = false;
            isPasswordActive = false;
        }
    }
    else if (state == AppState::SignUp) {
        if (signUpUsernameRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isSignUpUsernameActive = true;
            isSignUpPasswordActive = false;
            isSignUpStaffIDActive = false;
        }
        else if (signUpPasswordRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isSignUpUsernameActive = false;
            isSignUpPasswordActive = true;
            isSignUpStaffIDActive = false;
        }
        else if (signUpStaffIDRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isSignUpUsernameActive = false;
            isSignUpPasswordActive = false;
            isSignUpStaffIDActive = true;
        }
        else if (signUpPanelButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            if (signUpUsername.empty()) {
                showErrorMessage("Please fill in Username!");
                return;
            }
            else {
                if (signUpPassword.empty()) {
                    showErrorMessage("Please fill in Password!");
                    return;
                }
                else {
                    if (signUpStaffID.empty()) {
                        User newUser;
                        newUser.setUsernamePassword(signUpUsername, signUpPassword);
                        users.push_back(newUser);
                    }
                    else if (signUpStaffID == "ITSTAFF") {
                        Employee newStaff;
                        newStaff.setUsernamePassword(signUpUsername, signUpPassword);
                        staffs.push_back(newStaff);
                    }
                    else {
                        showErrorMessage("Invalid staff ID!");
                        return;
                    }
                }
            }
            state = AppState::Login;
        }
        else {
            isSignUpUsernameActive = false;
            isSignUpPasswordActive = false;
            isSignUpStaffIDActive = false;
        }
    }
}



void SFMLApp::renderLoginPanel() {
    window.draw(loginTitle);
    window.draw(usernameLabel);
    window.draw(passwordLabel);
    window.draw(usernameRect);
    window.draw(passwordRect);
    window.draw(usernameInput);
    window.draw(passwordInput);
    window.draw(loginButton);
    window.draw(loginButtonText);
    window.draw(signUpButton);
    window.draw(signUpButtonText);
}
void SFMLApp::renderSignUpPanel() {
    window.draw(signUpTitle);
    window.draw(signUpUsernameLabel);
    window.draw(signUpPasswordLabel);
    window.draw(signUpUsernameRect);
    window.draw(signUpPasswordRect);
    window.draw(signUpUsernameInput);
    window.draw(signUpPasswordInput);
    window.draw(signUpPanelButton);
    window.draw(signUpPanelButtonText);

    window.draw(signUpStaffIDLabel);
    window.draw(signUpStaffIDRect);
    window.draw(signUpStaffIDInput);
}
void SFMLApp::showErrorMessage(const std::string& message) {
    sf::RectangleShape errorPanel(sf::Vector2f(400, 200));
    errorPanel.setFillColor(sf::Color(255, 0, 0)); // Red color for error
    errorPanel.setPosition(200, 200);

    sf::Text errorMessage;
    errorMessage.setFont(font);
    errorMessage.setString(message);
    errorMessage.setCharacterSize(20);
    errorMessage.setFillColor(sf::Color::White);
    errorMessage.setPosition(220, 250);

    sf::RectangleShape closeButton(sf::Vector2f(100, 30));
    closeButton.setFillColor(sf::Color::White);
    closeButton.setPosition(350, 320);

    sf::Text closeButtonText;
    closeButtonText.setFont(font);
    closeButtonText.setString("Close");
    closeButtonText.setCharacterSize(20);
    closeButtonText.setFillColor(sf::Color::Black);
    closeButtonText.setPosition(375, 320);

    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (closeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    return;
                }
            }
        }

        window.clear();
        window.draw(errorPanel);
        window.draw(errorMessage);
        window.draw(closeButton);
        window.draw(closeButtonText);
        window.display();
    }
}
