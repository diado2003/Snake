//
// Created by diana on 11/6/2023.
//
#include "apple.h"
#include <cstdlib>
#include <ctime>

Food::Food() {
    // Initialize the food item.
    foodItem.setSize(sf::Vector2f(tileSize, tileSize));
    foodItem.setFillColor(sf::Color::Red);

    // Seed for random number generation.
    std::srand(std::time(0));

    // Initial spawn of the food item.
    spawn();
}

std::ostream& operator<<(std::ostream& os, const Food& food) {
    os << "Apple Position: (" << food.getPosition().x << ", " << food.getPosition().y << ")\n";
    return os;
}
Food::~Food() {


}

Food& Food::operator=(const Food& other) {
    if (this != &other) {  // Avoid self-assignment
        foodItem.setSize(other.foodItem.getSize());
        foodItem.setFillColor(other.foodItem.getFillColor());
        position = other.position;
    }
    return *this;
}

Food::Food(const Food& other) {
    foodItem.setSize(other.foodItem.getSize());
    foodItem.setFillColor(other.foodItem.getFillColor());
    position = other.position;
}

void Food::spawn() {
    // Generate random positions for the food item.
    float x = (std::rand() % 20) * tileSize;  // Assuming a 20x20 grid.
    float y = (std::rand() % 20) * tileSize;

    position = sf::Vector2f(x, y);
    foodItem.setPosition(position);
}

sf::Vector2f Food::getPosition() const {
    return position;
}

void Food::render(sf::RenderWindow& window) {
    // Render the food item.
    window.draw(foodItem);
}
