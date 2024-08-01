#ifndef SFML_TICKET_DISPLAY_H
#define SFML_TICKET_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "ticket.h"

void displayTicketInfo(sf::RenderWindow& window, const sf::Font& font, const Ticket& ticket, float yOffset);

#endif // SFML_TICKET_DISPLAY_H
