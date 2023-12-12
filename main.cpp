//
// Created by diana on 11/21/2023.
//
#include "game.h"
#include<iostream>

int main() {
    Game game;
    game.run();
    // Create an original Food object
    Food originalFood;
    originalFood.spawn();

    Food copiedFood(originalFood);
    std::cout << "Original Food Position: (" << originalFood.getPosition().x << ", " << originalFood.getPosition().y << ")\n";
    std::cout << "Copied Food Position: (" << copiedFood.getPosition().x << ", " << copiedFood.getPosition().y << ")\n";

    return 0;
}