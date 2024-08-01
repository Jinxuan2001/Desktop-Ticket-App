#include "sfml_itStaff.h"
#include <SFML/Graphics.hpp>

void displayNewTicket(sf::RenderWindow& window, const sf::Font& font, const Ticket& ticket) {
    sf::RectangleShape ticketBackground(sf::Vector2f(760, 240));
    ticketBackground.setFillColor(sf::Color(173, 216, 230)); // Light blue
    ticketBackground.setPosition(20, 20);

    sf::Text ticketTitle("New Ticket Information", font, 30);
    ticketTitle.setFillColor(sf::Color::Black);
    ticketTitle.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 10);

    sf::Text ticketID("ID: " + ticket.getID(), font, 20);
    ticketID.setFillColor(sf::Color::Black);
    ticketID.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 50);

    sf::Text ticketTag("Tag: " + ticket.getTag(), font, 20);
    ticketTag.setFillColor(sf::Color::Black);
    ticketTag.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 80);

    sf::Text ticketDate("Date: " + std::to_string(ticket.getTimeSubmitted()), font, 20); // Convert time_t to string
    ticketDate.setFillColor(sf::Color::Black);
    ticketDate.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 110);

    sf::Text ticketFromUser("From: " + ticket.getFromUser(), font, 20);
    ticketFromUser.setFillColor(sf::Color::Black);
    ticketFromUser.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 140);

    sf::Text ticketContent("Content: " + ticket.getContent(), font, 20);
    ticketContent.setFillColor(sf::Color::Black);
    ticketContent.setPosition(ticketBackground.getPosition().x + 10, ticketBackground.getPosition().y + 170);

    window.draw(ticketBackground);
    window.draw(ticketTitle);
    window.draw(ticketID);
    window.draw(ticketTag);
    window.draw(ticketDate);
    window.draw(ticketFromUser);
    window.draw(ticketContent);
}
