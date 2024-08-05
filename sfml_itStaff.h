#ifndef SFML_ITSTAFF_H
#define SFML_ITSTAFF_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ticket.h"
#include "employee.h"
#include "calendar.h"
#include "day.h"

class SFMLItStaff {
public:
    SFMLItStaff(std::vector<Ticket>& tickets, Employee& itStaff);
    void runItStaff();

private:
    void processEvents();
    void update();
    void render();
    void setupCalendar();
    void renderCalendar();
    void handleMouseClick(sf::Vector2i position);

    sf::RenderWindow window;
    sf::Font font;
    sf::RectangleShape logOutButton;
    sf::Text logOutButtonText;

    std::vector<Ticket>& tickets;
    Employee& itStaff;
    Calendar personalCalendar;
};

#endif // SFML_ITSTAFF_H
