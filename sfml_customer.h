/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#ifndef SFML_CUSTOMER_H
#define SFML_CUSTOMER_H

#include <SFML/Graphics.hpp>
#include "user.h"
#include "ticket.h"
#include <vector>
#include <string>

class SFMLCustomer {
public:
    SFMLCustomer(std::vector<Ticket>& tickets);

    void runCustomer();

private:
    enum class ViewState { TicketList, TicketCreation };

    sf::RenderWindow window;
    sf::Font font;

    // Ticket list view elements
    sf::RectangleShape createTicketButton;
    sf::Text createTicketButtonText;

    // Ticket creation panel elements
    sf::Text tagLabel;
    sf::Text contentLabel;
    sf::Text tagInput;
    sf::Text contentInput;
    sf::RectangleShape tagRect;
    sf::RectangleShape contentRect;
    sf::RectangleShape submitButton;
    sf::Text submitButtonText;
    sf::RectangleShape ticketPanelBackground;

    sf::RectangleShape logOutButton;
    sf::Text logOutButtonText;

    std::vector<Ticket>& tickets;

    ViewState viewState;
    bool isTagActive;
    bool isContentActive;
    bool showCursor;
    std::string tag;
    std::string content;
    sf::Clock cursorClock;

    void processEvents();
    void update();
    void render();
    void renderTicketList();
    void renderTicketCreation();
    void handleMouseClick(sf::Vector2i position);
    void handleUserInput(sf::Event::KeyEvent keyEvent, bool isPressed);
    void handleTextEntered(sf::Event::TextEvent textEvent);
    void createTicket();

    sf::Text timeAllottedLabel;
    sf::Text timeAllottedInput;
    sf::RectangleShape timeAllottedRect;
    bool isTimeAllottedActive;
    std::string timeAllotted;

};

#endif // SFML_CUSTOMER_H
