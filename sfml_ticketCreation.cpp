#include "sfml_ticketCreation.h"
#include "ticket.h"
#include <vector>
#include <SFML/Graphics.hpp>

bool createTicket(sf::RenderWindow& window, const sf::Font& font, std::vector<Ticket>& tickets) {
    std::string newTag = "";
    std::string newDate = "";
    std::string newStaff = "";
    std::string newContent = "";

    sf::RectangleShape formBackground(sf::Vector2f(400, 300));
    formBackground.setFillColor(sf::Color(173, 216, 230)); // Light blue
    formBackground.setPosition(200, 150);

    sf::Text formTitle("Create Ticket", font, 30);
    formTitle.setFillColor(sf::Color::Black);
    formTitle.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 10);

    sf::Text idText("ID: 00000004", font, 20);
    idText.setFillColor(sf::Color::Black);
    idText.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 50);

    sf::Text tagText("Tag:", font, 20);
    tagText.setFillColor(sf::Color::Black);
    tagText.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 90);
    sf::Text tagInput(newTag, font, 20);
    tagInput.setFillColor(sf::Color::Black);
    tagInput.setPosition(formBackground.getPosition().x + 120, formBackground.getPosition().y + 90);
    sf::RectangleShape tagRect(sf::Vector2f(250, 30));
    tagRect.setFillColor(sf::Color::Transparent);
    tagRect.setOutlineColor(sf::Color::Black);
    tagRect.setOutlineThickness(1);
    tagRect.setPosition(tagInput.getPosition().x, tagInput.getPosition().y + 5);

    sf::Text dateText("Date:", font, 20);
    dateText.setFillColor(sf::Color::Black);
    dateText.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 130);
    sf::Text dateInput(newDate, font, 20);
    dateInput.setFillColor(sf::Color::Black);
    dateInput.setPosition(formBackground.getPosition().x + 120, formBackground.getPosition().y + 130);
    sf::RectangleShape dateRect(sf::Vector2f(250, 30));
    dateRect.setFillColor(sf::Color::Transparent);
    dateRect.setOutlineColor(sf::Color::Black);
    dateRect.setOutlineThickness(1);
    dateRect.setPosition(dateInput.getPosition().x, dateInput.getPosition().y + 5);

    sf::Text staffText("IT Staff:", font, 20);
    staffText.setFillColor(sf::Color::Black);
    staffText.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 170);
    sf::Text staffInput(newStaff, font, 20);
    staffInput.setFillColor(sf::Color::Black);
    staffInput.setPosition(formBackground.getPosition().x + 120, formBackground.getPosition().y + 170);
    sf::RectangleShape staffRect(sf::Vector2f(250, 30));
    staffRect.setFillColor(sf::Color::Transparent);
    staffRect.setOutlineColor(sf::Color::Black);
    staffRect.setOutlineThickness(1);
    staffRect.setPosition(staffInput.getPosition().x, staffInput.getPosition().y + 5);

    sf::Text contentText("Content:", font, 20);
    contentText.setFillColor(sf::Color::Black);
    contentText.setPosition(formBackground.getPosition().x + 10, formBackground.getPosition().y + 210);
    sf::Text contentInput(newContent, font, 20);
    contentInput.setFillColor(sf::Color::Black);
    contentInput.setPosition(formBackground.getPosition().x + 120, formBackground.getPosition().y + 210);
    sf::RectangleShape contentRect(sf::Vector2f(250, 30));
    contentRect.setFillColor(sf::Color::Transparent);
    contentRect.setOutlineColor(sf::Color::Black);
    contentRect.setOutlineThickness(1);
    contentRect.setPosition(contentInput.getPosition().x, contentInput.getPosition().y + 5);

    sf::RectangleShape createButton(sf::Vector2f(100, 30));
    createButton.setFillColor(sf::Color::White);
    createButton.setOutlineColor(sf::Color::Black);
    createButton.setOutlineThickness(1);
    createButton.setPosition(formBackground.getPosition().x + 150, formBackground.getPosition().y + 260);

    sf::Text createButtonText("Create", font, 20);
    createButtonText.setFillColor(sf::Color::Black);
    createButtonText.setPosition(createButton.getPosition().x + 10, createButton.getPosition().y + 2);

    bool tagActive = false;
    bool dateActive = false;
    bool staffActive = false;
    bool contentActive = false;
    bool showCursor = true;
    sf::Clock cursorClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (tagActive) {
                    if (event.text.unicode == '\b' && !newTag.empty()) {
                        newTag.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        newTag += static_cast<char>(event.text.unicode);
                    }
                    tagInput.setString(newTag);
                }
                else if (dateActive) {
                    if (event.text.unicode == '\b' && !newDate.empty()) {
                        newDate.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        newDate += static_cast<char>(event.text.unicode);
                    }
                    dateInput.setString(newDate);
                }
                else if (staffActive) {
                    if (event.text.unicode == '\b' && !newStaff.empty()) {
                        newStaff.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        newStaff += static_cast<char>(event.text.unicode);
                    }
                    staffInput.setString(newStaff);
                }
                else if (contentActive) {
                    if (event.text.unicode == '\b' && !newContent.empty()) {
                        newContent.pop_back();
                    }
                    else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                        newContent += static_cast<char>(event.text.unicode);
                    }
                    contentInput.setString(newContent);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (tagRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        tagActive = true;
                        dateActive = false;
                        staffActive = false;
                        contentActive = false;
                    }
                    else if (dateRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        tagActive = false;
                        dateActive = true;
                        staffActive = false;
                        contentActive = false;
                    }
                    else if (staffRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        tagActive = false;
                        dateActive = false;
                        staffActive = true;
                        contentActive = false;
                    }
                    else if (contentRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        tagActive = false;
                        dateActive = false;
                        staffActive = false;
                        contentActive = true;
                    }
                    else if (createButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        tickets.push_back(Ticket(newContent, newTag, newStaff));
                        return true;
                    }
                }
            }
        }

        if (cursorClock.getElapsedTime().asSeconds() >= 0.5f) {
            showCursor = !showCursor;
            cursorClock.restart();
        }

        std::string tagDisplay = newTag + (tagActive && showCursor ? "|" : "");
        std::string dateDisplay = newDate + (dateActive && showCursor ? "|" : "");
        std::string staffDisplay = newStaff + (staffActive && showCursor ? "|" : "");
        std::string contentDisplay = newContent + (contentActive && showCursor ? "|" : "");

        tagInput.setString(tagDisplay);
        dateInput.setString(dateDisplay);
        staffInput.setString(staffDisplay);
        contentInput.setString(contentDisplay);

        window.clear(sf::Color(211, 211, 211));
        window.draw(formBackground);
        window.draw(formTitle);
        window.draw(idText);
        window.draw(tagText);
        window.draw(tagRect);
        window.draw(tagInput);
        window.draw(dateText);
        window.draw(dateRect);
        window.draw(dateInput);
        window.draw(staffText);
        window.draw(staffRect);
        window.draw(staffInput);
        window.draw(contentText);
        window.draw(contentRect);
        window.draw(contentInput);
        window.draw(createButton);
        window.draw(createButtonText);
        window.display();
    }

    return false;
}
