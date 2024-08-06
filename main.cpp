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
