/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#include "sfml_itStaff.h"
#include <iostream>

SFMLItStaff::SFMLItStaff(std::vector<Ticket>& tickets, Employee staff)
    : window(sf::VideoMode(800, 600), "IT Staff Window"),
    tickets(tickets),
    staff(staff) {
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

    assignTicketButton.setSize(sf::Vector2f(150, 30));
    assignTicketButton.setFillColor(sf::Color::White);
    assignTicketButton.setPosition(10, 550);

    assignTicketButtonText.setFont(font);
    assignTicketButtonText.setString("Assign New Ticket");
    assignTicketButtonText.setCharacterSize(20);
    assignTicketButtonText.setFillColor(sf::Color::Black);
    assignTicketButtonText.setPosition(20, 555);

    closeButton.setSize(sf::Vector2f(100, 30));
    closeButton.setFillColor(sf::Color::White);
    closeButton.setPosition(650, 550);

    closeButtonText.setFont(font);
    closeButtonText.setString("Close");
    closeButtonText.setCharacterSize(20);
    closeButtonText.setFillColor(sf::Color::Black);
    closeButtonText.setPosition(670, 555);

    assignPanel.setSize(sf::Vector2f(300, 200));
    assignPanel.setFillColor(sf::Color(100, 100, 100));
    assignPanel.setPosition(250, 200);

    workTimeText.setFont(font);
    workTimeText.setCharacterSize(20);
    workTimeText.setFillColor(sf::Color::White);
    workTimeText.setPosition(270, 220);

    assignPanelButton.setSize(sf::Vector2f(100, 30));
    assignPanelButton.setFillColor(sf::Color::White);
    assignPanelButton.setPosition(270, 320);

    assignPanelButtonText.setFont(font);
    assignPanelButtonText.setString("Assign");
    assignPanelButtonText.setCharacterSize(20);
    assignPanelButtonText.setFillColor(sf::Color::Black);
    assignPanelButtonText.setPosition(290, 325);

    closePanelButton.setSize(sf::Vector2f(100, 30));
    closePanelButton.setFillColor(sf::Color::White);
    closePanelButton.setPosition(370, 320);

    closePanelButtonText.setFont(font);
    closePanelButtonText.setString("Close");
    closePanelButtonText.setCharacterSize(20);
    closePanelButtonText.setFillColor(sf::Color::Black);
    closePanelButtonText.setPosition(390, 325);
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
    if (showAssignTicketPage) {
        renderTicketList();
        window.draw(closeButton);
        window.draw(closeButtonText);
        if (showAssignPanel) {
            window.draw(assignPanel);
            window.draw(workTimeText);
            window.draw(assignPanelButton);
            window.draw(assignPanelButtonText);
            window.draw(closePanelButton);
            window.draw(closePanelButtonText);
        }
    }
    else {
        renderCalendar();
        window.draw(logOutButton);
        window.draw(logOutButtonText);
        window.draw(assignTicketButton);
        window.draw(assignTicketButtonText);
    }
    window.display();
}



void SFMLItStaff::renderTicketList() {
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

        sf::RectangleShape assignButton(sf::Vector2f(100, 30));
        assignButton.setFillColor(sf::Color::White);
        assignButton.setPosition(650, 110 + index * 110);

        sf::Text assignButtonText;
        assignButtonText.setFont(font);
        assignButtonText.setCharacterSize(20);
        assignButtonText.setFillColor(sf::Color::Black);
        assignButtonText.setPosition(660, 115 + index * 110);
        assignButtonText.setString("Assign");

        window.draw(ticketBackground);
        window.draw(ticketText);
        window.draw(assignButton);
        window.draw(assignButtonText);
    }
}


void SFMLItStaff::switchToAssignTicketPage() {
    showAssignTicketPage = true;
}
void SFMLItStaff::switchToCalendarPage() {
    showAssignTicketPage = false;
}

void SFMLItStaff::setupCalendar() {
    personalCalendar = staff.getCalendar();
}

void SFMLItStaff::renderCalendar() {
    float yOffset = 10.0f;
    auto weeks = personalCalendar.getWeeklyList();
    std::vector<sf::Color> dayColors = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta, sf::Color::White };

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

        int dayColorIndex = 0;
        for (auto dayIt = weekIt->begin(); dayIt != weekIt->end(); ++dayIt, ++dayColorIndex) {
            // Draw background for day
            sf::RectangleShape dayBackground(sf::Vector2f(window.getSize().x - 40, 200));
            dayBackground.setFillColor(dayColors[dayColorIndex % dayColors.size()]);
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
    else if (assignTicketButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
        switchToAssignTicketPage();
    }
    else if (closeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
        switchToCalendarPage();
    }
    else if (assignPanelButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
        showAssignPanel = true;
    }
    else if (closePanelButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
        showAssignPanel = false;
    }
    else {
        int index = 0;
        for (auto it = tickets.begin(); it != tickets.end(); ++it, ++index) {
            sf::RectangleShape assignButton(sf::Vector2f(100, 30));
            assignButton.setPosition(650, 110 + index * 110);
            if (assignButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(position))) {
                showAssignPanel = true;
                tempT = *it;

                setTicket(tempT, workTimeInput, staff.getUsername());

                break;
            }
        }
    }
}

