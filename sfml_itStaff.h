/*
 * The code within this file has been modified from the Tutorials for SFML 2.6.
 * For original tutorials and more information about SFML, visit:
 * https://www.sfml-dev.org/tutorials/2.6/
 */



#ifndef SFML_ITSTAFF_H
#define SFML_ITSTAFF_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ticket.h"
#include "employee.h"
#include "calendar.h"
#include "helper.h"

class SFMLItStaff {
public:
    SFMLItStaff(std::vector<Ticket>& tickets, Employee staff);
    void runItStaff();

private:
    void processEvents();
    void update();
    void render();
    void setupCalendar();
    void renderCalendar();
    void handleMouseClick(sf::Vector2i position);
    void renderTicketList();

    void switchToAssignTicketPage();
    void switchToCalendarPage();


    sf::RenderWindow window;
    sf::Font font;
    sf::RectangleShape logOutButton;
    sf::Text logOutButtonText;
    sf::RectangleShape assignTicketButton;
    sf::Text assignTicketButtonText;

    sf::RectangleShape closeButton;
    sf::Text closeButtonText;


    std::vector<Ticket> tickets;
    Employee& staff;
    Calendar personalCalendar;
    bool showAssignTicketPage = false;

    sf::RectangleShape assignButton;
    sf::Text assignButtonText;
    sf::RectangleShape assignPanel;
    sf::Text workTimeText;
    sf::RectangleShape assignPanelButton;
    sf::Text assignPanelButtonText;
    sf::RectangleShape closePanelButton;
    sf::Text closePanelButtonText;
    bool showAssignPanel = false;
    std::string workTimeInput;
    bool isWorkTimeActive = false;

    Ticket tempT;

};

#endif // SFML_ITSTAFF_H
