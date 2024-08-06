/*
 * Desktop Ticket Application - an IT support management solution
 * Developed by Ticket Masters
 *
 * Team Members:
 * - Ethan Youmans
 * - Garrett McClay
 * - Jinxuan Liu
 *
 * This application is designed to manage IT support tickets, allowing customers to submit tickets and IT staff to manage and assign them.
 * The project utilizes the Simple and Fast Multimedia Library (SFML) for rendering the graphical user interface.
 *
 * Multimedia Library: SFML (https://www.sfml-dev.org/)
 *
 * Last update: August 6th, 2024
 */



#include "sfml_app.h"
#include "user.h"
#include "employee.h"
#include "ticket.h"
#include <vector>

#include "helper.h"
#include "connector.h"
#include "tests.h"

int main() {
    
    SFMLApp app();
    app().run();

    //testCalendar();

    return 0;
}
