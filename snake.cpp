#include "snake.h"

Snake::Snake() {
    // Initialize the snake with a single segment.
    sf::RectangleShape segment(sf::Vector2f(tileSize, tileSize));
    segment.setFillColor(sf::Color::Green);
    body.push_back(segment);

    // Set initial direction.
    direction = sf::Vector2f(0.1, 0);
}

void Snake::move() {
    // Move the snake by adding a new segment in the current direction.
    sf::RectangleShape newSegment(sf::Vector2f(tileSize, tileSize));
    newSegment.setFillColor(sf::Color::Green);

    sf::Vector2f newPosition = body[0].getPosition() + direction;
    newSegment.setPosition(newPosition);

    // Add the new segment to the front of the snake.
    body.insert(body.begin(), newSegment);

    // Remove the last segment to maintain the snake's length.
    if (body.size() > 1) {
        body.pop_back();
    }
}

void Snake::grow() {
    // Add a new segment at the end of the snake.
    sf::RectangleShape newSegment(sf::Vector2f(tileSize, tileSize));
    newSegment.setFillColor(sf::Color::Green);
    newSegment.setPosition(body.back().getPosition());

    body.push_back(newSegment);
}

bool Snake::checkCollision(sf::Vector2f position) const {
    // Check if the given position collides with any part of the snake's body.
    for (const auto& segment : body) {
        if (segment.getPosition() == position) {
            return true;
        }
    }
    return false;
}

void Snake::render(sf::RenderWindow& window) {
    // Render each segment of the snake.
    for (const auto& segment : body) {

        window.draw(segment);
    }
}

float Snake::getTileSize() const {
    return tileSize;
}

void Snake::setDirection(sf::Vector2f newDirection) {
    direction = newDirection;
}

sf::Vector2f Snake::getPosition() const {
    // Return the position of the head of the snake (first segment).
    return body[0].getPosition();
}