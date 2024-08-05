#include "sfml_itStaff.h"
#include <iostream>

SFMLItStaff::SFMLItStaff(std::vector<Ticket>& tickets, Employee& itStaff)
    : window(sf::VideoMode(800, 600), "IT Staff Window"), tickets(tickets), itStaff(itStaff) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    setupCalendar();

    // Initialize UI elements
    logOutButton.setSize(sf::Vector2f(100, 30));
    logOutButton.setFillColor(sf::Color::White);
    logOutButton.setPosition(650, 550);

    logOutButtonText.setFont(font);
    logOutButtonText.setString("Log Out");
    logOutButtonText.setCharacterSize(20);
    logOutButtonText.setFillColor(sf::Color::Black);
    logOutButtonText.setPosition(660, 555);
}

void SFMLItStaff::runItStaff() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void SFMLItStaff::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseClick(sf::Mouse::getPosition(window));
            break;
        default:
            break;
        }
    }
}

void SFMLItStaff::update() {
    // Update logic for the IT Staff window
}

void SFMLItStaff::render() {
    window.clear();
    renderCalendar();
    window.draw(logOutButton);
    window.draw(logOutButtonText);
    window.display();
}

void SFMLItStaff::setupCalendar() {
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        personalCalendar.addTicket(*it);
    }
}

void SFMLItStaff::renderCalendar() {
    float yOffset = 10.0f;
    auto weeks = personalCalendar.getWeeklyList();

    for (auto weekIt = weeks.begin(); weekIt != weeks.end(); ++weekIt) {
        // Draw background for week
        sf::RectangleShape weekBackground(sf::Vector2f(window.getSize().x - 20, 100));
        weekBackground.setFillColor(sf::Color(100, 100, 100));
        weekBackground.setPosition(10, yOffset);
        window.draw(weekBackground);

        std::stringstream weekStream;
        weekStream << "Week " << std::distance(weeks.begin(), weekIt) + 1;

        sf::Text weekText;
        weekText.setFont(font);
        weekText.setCharacterSize(20);
        weekText.setFillColor(sf::Color::White);
        weekText.setPosition(20, yOffset + 10);
        weekText.setString(weekStream.str());
        window.draw(weekText);
        yOffset += 40;

        for (auto dayIt = weekIt->begin(); dayIt != weekIt->end(); ++dayIt) {
            // Draw background for day
            sf::RectangleShape dayBackground(sf::Vector2f(window.getSize().x - 40, 200));
            dayBackground.setFillColor(sf::Color(173, 216, 230)); // Light blue
            dayBackground.setPosition(30, yOffset);
            window.draw(dayBackground);

            std::stringstream dayStream;
            dayStream << "Day " << std::distance(weekIt->begin(), dayIt) + 1;

            sf::Text dayText;
            dayText.setFont(font);
            dayText.setCharacterSize(18);
            dayText.setFillColor(sf::Color::White);
            dayText.setPosition(40, yOffset + 10);
            dayText.setString(dayStream.str());
            window.draw(dayText);
            yOffset += 40;

            float tempTime = dayIt->getStartTime();
            auto tickets = dayIt->getTicketList();
            for (auto ticketIt = tickets.begin(); ticketIt != tickets.end(); ++ticketIt) {
                std::stringstream ticketStream;
                ticketStream << "Start time: " << tempTime << "\nID: " << ticketIt->getID()
                    << "\nTag: " << ticketIt->getTag() << "\nStatus: " << ticketIt->getStatus()
                    << "\nFrom User: " << ticketIt->getFromUser() << "\nContent: " << ticketIt->getContent();

                sf::Text ticketText;
                ticketText.setFont(font);
                ticketText.setCharacterSize(16);
                ticketText.setFillColor(sf::Color::White);
                ticketText.setPosition(50, yOffset + 10);
                ticketText.setString(ticketStream.str());
                window.draw(ticketText);
                yOffset += 110;
                tempTime += ticketIt->getTimeAlloted();
            }
            yOffset += 20;
        }
        yOffset += 20;
    }
}




void SFMLItStaff::handleMouseClick(sf::Vector2i position) {
    if (logOutButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
        window.close();
    }
}
