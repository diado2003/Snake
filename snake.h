#ifndef OOP_SNAKE_H
#define OOP_SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    Snake();
    void move();
    void grow();
    bool checkCollision(sf::Vector2f position) const;
    void render(sf::RenderWindow& window);
    float getTileSize() const;
    void setDirection(sf::Vector2f newDirection);
    sf::Vector2f getPosition() const;
    friend std::ostream& operator<<(std::ostream& os, const Snake& snake);



private:

    sf::Clock moveClock;  // Timer for controlling movement speed
    float moveInterval = 0.1f;
    float moveAccumulator = 0.0f;

    std::vector<sf::RectangleShape> body;
    float tileSize = 20.0f;
    sf::Vector2f direction;
};

#endif // OOP_SNAKE_H
