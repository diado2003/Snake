#include "game.h"
#include <iostream>
Game::Game() : window(sf::VideoMode(800, 800), "Snake Game") {
    window.setFramerateLimit(60); // Set a frame rate limit for smooth rendering

}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game Information:\n";
    os << "Snake Information: " << game.snake << "\n";
    os << "Food Information: " << game.food << "\n";
    return os;
}

void Game::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
    }
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
