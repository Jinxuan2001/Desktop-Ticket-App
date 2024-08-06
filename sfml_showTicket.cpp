/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#include "sfml_showTicket.h"
#include <sstream>

SFMLShowTicket::SFMLShowTicket(Ticket& ticket)
    : window(sf::VideoMode(600, 400), "Ticket Information"), ticket(ticket) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }

    std::stringstream ss;
    ss << "ID: " << ticket.getID() << "\n"
        << "Tag: " << ticket.getTag() << "\n"
        << "Status: " << ticket.getStatus() << "\n"
        << "From User: " << ticket.getFromUser() << "\n"
        << "Content: " << ticket.getContent() << "\n";

    ticketInfo.setFont(font);
    ticketInfo.setString(ss.str());
    ticketInfo.setCharacterSize(20);
    ticketInfo.setFillColor(sf::Color::White);
    ticketInfo.setPosition(50, 50);
}

void SFMLShowTicket::runShowTicket() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void SFMLShowTicket::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void SFMLShowTicket::update() {
    // Update logic if needed
}

void SFMLShowTicket::render() {
    window.clear();
    window.draw(ticketInfo);
    window.display();
}
