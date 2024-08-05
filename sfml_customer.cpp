#include "sfml_customer.h"
#include "hash.h"
#include <sstream>
#include <iterator>

SFMLCustomer::SFMLCustomer(std::vector<Ticket>& tickets, User& user)
    : window(sf::VideoMode(800, 600), "Customer Window"), tickets(tickets), user(user),
    viewState(ViewState::TicketList), isTagActive(false), isContentActive(false), showCursor(true) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }

    // Initialize UI elements for ticket creation panel
    tagLabel.setFont(font);
    tagLabel.setString("Tag:");
    tagLabel.setCharacterSize(20);
    tagLabel.setFillColor(sf::Color::White);
    tagLabel.setPosition(200, 200);

    contentLabel.setFont(font);
    contentLabel.setString("Content:");
    contentLabel.setCharacterSize(20);
    contentLabel.setFillColor(sf::Color::White);
    contentLabel.setPosition(200, 250);

    tagInput.setFont(font);
    tagInput.setCharacterSize(20);
    tagInput.setFillColor(sf::Color::Black);
    tagInput.setPosition(300, 200);

    contentInput.setFont(font);
    contentInput.setCharacterSize(20);
    contentInput.setFillColor(sf::Color::Black);
    contentInput.setPosition(300, 250);

    tagRect.setSize(sf::Vector2f(200, 30));
    tagRect.setFillColor(sf::Color::White);
    tagRect.setPosition(300, 200);

    contentRect.setSize(sf::Vector2f(200, 30));
    contentRect.setFillColor(sf::Color::White);
    contentRect.setPosition(300, 250);

    submitButton.setSize(sf::Vector2f(100, 30));
    submitButton.setFillColor(sf::Color::White);
    submitButton.setPosition(350, 450);

    submitButtonText.setFont(font);
    submitButtonText.setString("Submit");
    submitButtonText.setCharacterSize(20);
    submitButtonText.setFillColor(sf::Color::Black);
    submitButtonText.setPosition(370, 450);

    ticketPanelBackground.setSize(sf::Vector2f(600, 400));
    ticketPanelBackground.setFillColor(sf::Color(50, 50, 50));
    ticketPanelBackground.setPosition(100, 100);

    // Initialize UI elements for ticket list view
    createTicketButton.setSize(sf::Vector2f(180, 40));
    createTicketButton.setFillColor(sf::Color::White);
    createTicketButton.setPosition(20, 520);

    createTicketButtonText.setFont(font);
    createTicketButtonText.setString("Create New Ticket");
    createTicketButtonText.setCharacterSize(20);
    createTicketButtonText.setFillColor(sf::Color::Black);
    createTicketButtonText.setPosition(25, 525);

    // Initialize Log Out button
    logOutButton.setSize(sf::Vector2f(100, 40));
    logOutButton.setFillColor(sf::Color::White);
    logOutButton.setPosition(670, 520);

    logOutButtonText.setFont(font);
    logOutButtonText.setString("Log Out");
    logOutButtonText.setCharacterSize(20);
    logOutButtonText.setFillColor(sf::Color::Black);
    logOutButtonText.setPosition(675, 525);

    timeAllottedLabel.setFont(font);
    timeAllottedLabel.setString("Time Allotted:");
    timeAllottedLabel.setCharacterSize(20);
    timeAllottedLabel.setFillColor(sf::Color::White);
    timeAllottedLabel.setPosition(200, 400);

    timeAllottedInput.setFont(font);
    timeAllottedInput.setCharacterSize(20);
    timeAllottedInput.setFillColor(sf::Color::Black);
    timeAllottedInput.setPosition(350, 400);

    timeAllottedRect.setSize(sf::Vector2f(200, 30));
    timeAllottedRect.setFillColor(sf::Color::White);
    timeAllottedRect.setPosition(350, 400);

    isTimeAllottedActive = false;
}

void SFMLCustomer::runCustomer() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void SFMLCustomer::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            handleUserInput(event.key, true);
            break;
        case sf::Event::TextEntered:
            handleTextEntered(event.text);
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseClick(sf::Mouse::getPosition(window));
            break;
        default:
            break;
        }
    }
}

void SFMLCustomer::update() {
    if (cursorClock.getElapsedTime().asSeconds() >= 0.5f) {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    if (isTagActive) {
        tagInput.setString(tag + (showCursor ? "|" : ""));
    }
    else {
        tagInput.setString(tag);
    }

    if (isContentActive) {
        contentInput.setString(content + (showCursor ? "|" : ""));
    }
    else {
        contentInput.setString(content);
    }

    if (isTimeAllottedActive) {
        timeAllottedInput.setString(timeAllotted + (showCursor ? "|" : ""));
    }
    else {
        timeAllottedInput.setString(timeAllotted);
    }
}

void SFMLCustomer::render() {
    window.clear(sf::Color::Black);
    if (viewState == ViewState::TicketList) {
        renderTicketList();
    }
    else if (viewState == ViewState::TicketCreation) {
        renderTicketCreation();
    }
    window.display();
}

void SFMLCustomer::renderTicketList() {
    int index = 0;
    for (auto it = tickets.begin(); it != tickets.end(); ++it, ++index) {
        sf::RectangleShape ticketBackground(sf::Vector2f(700, 100));
        ticketBackground.setFillColor(sf::Color(100, 100, 100));
        ticketBackground.setPosition(50, 100 + index * 110);

        sf::Text ticketText;
        ticketText.setFont(font);
        ticketText.setCharacterSize(20);
        ticketText.setFillColor(sf::Color::White);
        ticketText.setPosition(60, 110 + index * 110);

        std::stringstream ss;
        ss << "ID: " << it->getID() << " | Tag: " << it->getTag()
            << "\nContent: " << it->getContent()
            << "\nStatus: " << it->getStatus()
            << " | From User: " << it->getFromUser();
        ticketText.setString(ss.str());

        window.draw(ticketBackground);
        window.draw(ticketText);
    }

    window.draw(createTicketButton);
    window.draw(createTicketButtonText);
    window.draw(logOutButton);
    window.draw(logOutButtonText);
}




void SFMLCustomer::renderTicketCreation() {
    window.draw(ticketPanelBackground);
    window.draw(tagLabel);
    window.draw(contentLabel);
    window.draw(tagRect);
    window.draw(contentRect);
    window.draw(tagInput);
    window.draw(contentInput);
    window.draw(timeAllottedLabel);
    window.draw(timeAllottedRect);
    window.draw(timeAllottedInput);
    window.draw(submitButton);
    window.draw(submitButtonText);
}

void SFMLCustomer::handleMouseClick(sf::Vector2i position) {
    if (viewState == ViewState::TicketList) {
        if (createTicketButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            viewState = ViewState::TicketCreation;
        }
        else if (logOutButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            window.close();
            return;
        }
    }
    else if (viewState == ViewState::TicketCreation) {
        if (tagRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isTagActive = true;
            isContentActive = false;
            isTimeAllottedActive = false;
        }
        else if (contentRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isTagActive = false;
            isContentActive = true;
            isTimeAllottedActive = false;
        }
        else if (timeAllottedRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            isTagActive = false;
            isContentActive = false;
            isTimeAllottedActive = true;
        }
        else if (submitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
            createTicket();
            viewState = ViewState::TicketList;
        }
        else {
            isTagActive = false;
            isContentActive = false;
            isTimeAllottedActive = false;
        }
    }
}


void SFMLCustomer::handleUserInput(sf::Event::KeyEvent keyEvent, bool isPressed) {
    // Handle key events if needed, current function to satisfy declaration
}

void SFMLCustomer::handleTextEntered(sf::Event::TextEvent textEvent) {
    if (isTagActive) {
        if (textEvent.unicode == '\b' && !tag.empty()) {
            tag.pop_back();
        }
        else if (textEvent.unicode < 128 && textEvent.unicode != '\b') {
            tag += static_cast<char>(textEvent.unicode);
        }
    }
    else if (isContentActive) {
        if (textEvent.unicode == '\b' && !content.empty()) {
            content.pop_back();
        }
        else if (textEvent.unicode < 128 && textEvent.unicode != '\b') {
            content += static_cast<char>(textEvent.unicode);
        }
    }
    else if (isTimeAllottedActive) {
        if (textEvent.unicode == '\b' && !timeAllotted.empty()) {
            timeAllotted.pop_back();
        }
        else if (textEvent.unicode < 128 && textEvent.unicode != '\b' && std::isdigit(static_cast<char>(textEvent.unicode))) {
            timeAllotted += static_cast<char>(textEvent.unicode);
        }
    }
}

void SFMLCustomer::createTicket() {
    if (!tag.empty() && !content.empty() && !timeAllotted.empty()) {
        Ticket newTicket(content, tag, user.getUsername());
        newTicket.setTimeAllotted(std::stof(timeAllotted));
        Hash hash;
        std::string ticketID = hash.generateTicketID(newTicket);
        newTicket.setID(ticketID);
        tickets.push_back(newTicket);
    }
}