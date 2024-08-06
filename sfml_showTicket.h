/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#ifndef SFML_SHOWTICKET_H
#define SFML_SHOWTICKET_H

#include <SFML/Graphics.hpp>
#include "ticket.h"

class SFMLShowTicket {
public:
    SFMLShowTicket(Ticket& ticket);
    void runShowTicket();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text ticketInfo;
    Ticket& ticket;
};

#endif // SFML_SHOWTICKET_H
