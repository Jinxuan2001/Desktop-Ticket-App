#include "sfml_app.h"
#include "sfml_ticketCreation.h"
#include "sfml_ticketDisplay.h"
#include "ticket.h"
#include <iomanip>
#include <sstream>

std::string formatTime(std::time_t time) {
    std::tm timeinfo;
    localtime_s(&timeinfo, &time);
    std::stringstream ss;
    ss << std::put_time(&timeinfo, "%Y/%m/%d %H:%M:%S");
    return ss.str();
}

SFMLApp::SFMLApp() : window(sf::VideoMode(800, 600), "Desktop Ticket App"), state(AppState::Login), accountType(""), loggedIn(false) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }
    if (!texture.loadFromFile("background.png")) {
        // Handle error
    }
    background.setTexture(texture);

    username.setFont(font);
    username.setString("Username:");
    username.setCharacterSize(24);
    username.setFillColor(sf::Color::White);
    username.setPosition(200, 200);

    usernameInput.setFont(font);
    usernameInput.setCharacterSize(24);
    usernameInput.setFillColor(sf::Color::White);
    usernameInput.setPosition(350, 200);

    password.setFont(font);
    password.setString("Password:");
    password.setCharacterSize(24);
    password.setFillColor(sf::Color::White);
    password.setPosition(200, 250);

    passwordInput.setFont(font);
    passwordInput.setCharacterSize(24);
    passwordInput.setFillColor(sf::Color::White);
    passwordInput.setPosition(350, 250);

    loginButton.setSize(sf::Vector2f(100, 30));
    loginButton.setFillColor(sf::Color::White);
    loginButton.setOutlineColor(sf::Color::Black);
    loginButton.setOutlineThickness(1);
    loginButton.setPosition(350, 300);

    loginButtonText.setFont(font);
    loginButtonText.setString("Login");
    loginButtonText.setCharacterSize(24);
    loginButtonText.setFillColor(sf::Color::Black);
    loginButtonText.setPosition(360, 300);

    createTicketButton.setSize(sf::Vector2f(150, 50));
    createTicketButton.setFillColor(sf::Color::White);
    createTicketButton.setOutlineColor(sf::Color::Black);
    createTicketButton.setOutlineThickness(1);
    createTicketButton.setPosition(600, 50);

    createTicketButtonText.setFont(font);
    createTicketButtonText.setString("Create Ticket");
    createTicketButtonText.setCharacterSize(24);
    createTicketButtonText.setFillColor(sf::Color::Black);
    createTicketButtonText.setPosition(createTicketButton.getPosition().x + 10, createTicketButton.getPosition().y + 10);
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
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (state == AppState::Login) {
            handleLoginInput(event);
        }
        else if (state == AppState::Customer) {
            handleCustomerInput(event);
        }
        else if (state == AppState::ITStaff) {
            handleITStaffInput(event);
        }
        else if (state == AppState::CreateTicket) {
            handleCreateTicketInput(event);
        }
    }
}

void SFMLApp::update() {
    // Update logic if necessary
}

void SFMLApp::render() {
    window.clear();
    if (state == AppState::Login) {
        renderLoginScreen();
    }
    else if (state == AppState::Customer) {
        renderCustomerScreen();
    }
    else if (state == AppState::ITStaff) {
        renderITStaffScreen();
    }
    else if (state == AppState::CreateTicket) {
        renderCreateTicketScreen();
    }
    window.display();
}

void SFMLApp::renderLoginScreen() {
    window.draw(background);
    window.draw(username);
    window.draw(usernameInput);
    window.draw(password);
    window.draw(passwordInput);
    window.draw(loginButton);
    window.draw(loginButtonText);
}

void SFMLApp::renderCustomerScreen() {
    window.draw(createTicketButton);
    window.draw(createTicketButtonText);
    displayTickets();
}

void SFMLApp::renderITStaffScreen() {
    window.draw(createTicketButton);
    window.draw(createTicketButtonText);
    displayITStaffTickets();
}

void SFMLApp::renderCreateTicketScreen() {
    createTicket();
}

void SFMLApp::handleLoginInput(sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (usernameActive) {
            if (event.text.unicode == '\b' && !usernameStr.empty()) {
                usernameStr.pop_back();
            }
            else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                usernameStr += static_cast<char>(event.text.unicode);
            }
            usernameInput.setString(usernameStr);
        }
        else if (passwordActive) {
            if (event.text.unicode == '\b' && !passwordStr.empty()) {
                passwordStr.pop_back();
            }
            else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                passwordStr += static_cast<char>(event.text.unicode);
            }
            passwordInput.setString(passwordStr);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (username.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            usernameActive = true;
            passwordActive = false;
        }
        else if (password.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            usernameActive = false;
            passwordActive = true;
        }
        else if (loginButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            if (usernameStr == "customer" && passwordStr == "123456") {
                accountType = "customer";
                state = AppState::Customer;
            }
            else if (usernameStr == "bob123" && passwordStr == "123456") {
                accountType = "ITStaff";
                state = AppState::ITStaff;
            }
            else {
                // Handle invalid login
            }
        }
    }
}

void SFMLApp::handleCustomerInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (createTicketButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            state = AppState::CreateTicket;
        }
    }
}

void SFMLApp::handleITStaffInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (createTicketButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            state = AppState::CreateTicket;
        }
    }
}

void SFMLApp::handleCreateTicketInput(sf::Event& event) {
    // Handle create ticket input if necessary
}

void SFMLApp::displayTickets() {
    for (size_t i = 0; i < tickets.size(); ++i) {
        sf::RectangleShape ticketBackground(sf::Vector2f(600, 150));
        ticketBackground.setFillColor(sf::Color(173, 216, 230));
        ticketBackground.setPosition(100, 100 + i * 200);

        sf::Text ticketID("ID: " + tickets[i].getID(), font, 20);
        ticketID.setFillColor(sf::Color::Black);
        ticketID.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 10);

        sf::Text ticketTag("Tag: " + tickets[i].getTag(), font, 20);
        ticketTag.setFillColor(sf::Color::Black);
        ticketTag.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 40);

        sf::Text ticketDate("Date: " + tickets[i].getDate(), font, 20);
        ticketDate.setFillColor(sf::Color::Black);
        ticketDate.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 70);

        sf::Text ticketITStaff("IT Staff: " + tickets[i].getITStaff(), font, 20);
        ticketITStaff.setFillColor(sf::Color::Black);
        ticketITStaff.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 100);

        sf::Text ticketContent("Content: " + tickets[i].getContent(), font, 20);
        ticketContent.setFillColor(sf::Color::Black);
        ticketContent.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 130);

        window.draw(ticketBackground);
        window.draw(ticketID);
        window.draw(ticketTag);
        window.draw(ticketDate);
        window.draw(ticketITStaff);
        window.draw(ticketContent);
    }
}

void SFMLApp::displayITStaffTickets() {
    if (!tickets.empty()) {
        displayTickets();
    }
    else {
        sf::Text noTickets("No tickets available", font, 20);
        noTickets.setFillColor(sf::Color::Black);
        noTickets.setPosition(100, 100);
        window.draw(noTickets);
    }
}

void SFMLApp::createTicket() {
    if (createTicket(window, font, tickets)) {
        state = (accountType == "customer") ? AppState::Customer : AppState::ITStaff;
    }
}
