#include "snake.h"

Snake::Snake() {
    // Initialize the snake with a single segment.
    sf::RectangleShape segment(sf::Vector2f(tileSize, tileSize));
    segment.setFillColor(sf::Color::Green);
    body.push_back(segment);

    // Set initial direction.
    direction = sf::Vector2f(0, 0);
}

std::ostream& operator<<(std::ostream& os, const Snake& snake) {
    os << "Snake Position: (" << snake.getPosition().x << ", " << snake.getPosition().y << ")\n";
    return os;
}

void Snake::move() {
    // Accumulate time since the last movement
    moveAccumulator += moveClock.restart().asSeconds();

    // Move the snake only if enough time has passed since the last movement
    if (moveAccumulator >= moveInterval) {
        // Calculate the new position based on the current direction
        sf::Vector2f newPosition = body[0].getPosition() + direction;

        // Update the position of each segment
        for (std::size_t i = body.size() - 1; i > 0; --i) {
            body[i].setPosition(body[i - 1].getPosition());
        }

        // Update the position of the head (first segment)
        body[0].setPosition(newPosition);

        // Reset the accumulator
        moveAccumulator = 0.0f;
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