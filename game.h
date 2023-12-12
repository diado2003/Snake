#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include "snake.h"
#include "apple.h"

class Game {
public:
    Game();
    void run();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    sf::RenderWindow window;
    Snake snake;
    Food food;
    bool inMenu;
    sf::Font font;
    sf::RectangleShape startButton;
    sf::RectangleShape exitButton;
    sf::Text startText;
    sf::Text exitText;

    void processInput();
    void update();
    void render();
    void drawMenu();
    void handleMenuInput();
};

#endif // OOP_GAME_H
