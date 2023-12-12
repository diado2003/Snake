//
// Created by diana on 11/4/2023.
//

#ifndef OOP_APPLE_H
#define OOP_APPLE_H
#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void spawn();
    sf::Vector2f getPosition() const;
    void render(sf::RenderWindow& window);
    friend std::ostream& operator<<(std::ostream& os, const Food& food);
    ~Food();




private:
    sf::RectangleShape foodItem;
    const float tileSize = 20.0f;
    sf::Vector2f position;
};

#endif // FOOD_H


#endif //OOP_APPLE_H
