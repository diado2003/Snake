#include "game.h"
#include <iostream>
Game::Game() : window(sf::VideoMode(800, 800), "Snake Game") {
    window.setFramerateLimit(60); // Set a frame rate limit for smooth rendering

    inMenu = true;

    font.loadFromFile("ARIBLK.TTF");

    startButton.setSize(sf::Vector2f(200.0f, 50.0f));
    startButton.setPosition(300.0f, 250.0f);
    startButton.setFillColor(sf::Color::Green);

    exitButton.setSize(sf::Vector2f(200.0f, 50.0f));
    exitButton.setPosition(300.0f, 350.0f);
    exitButton.setFillColor(sf::Color::Red);

    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(20);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(330.0f, 260.0f);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(370.0f, 360.0f);

}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game Information:\n";
    os << "Snake Information: " << game.snake << "\n";
    os << "Food Information: " << game.food << "\n";
    return os;
}

void Game::run() {
    while (window.isOpen()) {
        if (inMenu) {
            handleMenuInput();
            drawMenu();
        } else {
            update();
            render();
        }
    }
}
void Game::handleMenuInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    inMenu = false;
                }
                else if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    window.close();
                }
            }
        }
    }
}

void Game::drawMenu() {
    window.clear();

    window.draw(startButton);
    window.draw(exitButton);
    window.draw(startText);
    window.draw(exitText);

    window.display();
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    // Handle user input for snake movement.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        snake.setDirection(sf::Vector2f(0, -snake.getTileSize()));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        snake.setDirection(sf::Vector2f(0, snake.getTileSize()));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        snake.setDirection(sf::Vector2f(-snake.getTileSize(), 0));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        snake.setDirection(sf::Vector2f(snake.getTileSize(), 0));
    }
}

void Game::update() {

    // Check for collision with food.
    if (snake.checkCollision(food.getPosition())) {
        food.spawn();
        snake.grow();
    }

    // Check for collision with walls or itself (game over condition).

    // Move the snake.
        snake.move();

    std::cout << "Snake position: (" << snake.getPosition().x << ", " << snake.getPosition().y << ")\n";

}

void Game::render() {
    // Clear the window.
    window.clear();

    // Render the snake and food.
    snake.render(window);
    food.render(window);

    // Display the contents of the window.
    window.display();
}
