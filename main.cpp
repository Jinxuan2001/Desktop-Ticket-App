#include <iostream>
#include <vector>
#include <string>

#include "ticket.h"
#include "user.h"
#include "generic.h"
#include "employee.h"
#include "admin.h"
//#include "tests.h"
#include "hash.h"
#include "sfml_app.h"

int main() {
    std::cout << "Testing" << std::endl;
    // Uncomment to run tests
    //runAllTests();
    //testCalendar();
    //testTicket();

    SFMLApp app;
    app.run();

    return 0;
}
