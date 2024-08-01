#include "sfml_ticketDisplay.h"
#include "ticket.h"
#include <vector>

void displayTicketInfo(sf::RenderWindow& window, const sf::Font& font, const Ticket& ticket, float yOffset) {
    sf::RectangleShape ticketBackground(sf::Vector2f(700, 150));
    ticketBackground.setFillColor(sf::Color(173, 216, 230)); // Light blue
    ticketBackground.setPosition(50, yOffset);

    sf::Text ticketID("ID: " + ticket.getID(), font, 20);
    ticketID.setFillColor(sf::Color::Black);
    ticketID.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 10);

    sf::Text ticketTag("Tag: " + ticket.getTag(), font, 20);
    ticketTag.setFillColor(sf::Color::Black);
    ticketTag.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 40);

    sf::Text ticketDate("Date: " + ticket.getDate(), font, 20);
    ticketDate.setFillColor(sf::Color::Black);
    ticketDate.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 70);

    sf::Text ticketITStaff("IT Staff: " + ticket.getITStaff(), font, 20);
    ticketITStaff.setFillColor(sf::Color::Black);
    ticketITStaff.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 100);

    sf::Text ticketContent("Content: " + ticket.getContent(), font, 20);
    ticketContent.setFillColor(sf::Color::Black);
    ticketContent.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 130);

    window.draw(ticketBackground);
    window.draw(ticketID);
    window.draw(ticketTag);
    window.draw(ticketDate);
    window.draw(ticketITStaff);
    window.draw(ticketContent);
}
