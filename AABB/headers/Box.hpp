#pragma once
#include <SFML/Graphics.hpp>

class Box{

public:
    Box(sf::Vector2f, sf::Color, int, Box* b);

    void BoxMovement();

    sf::RectangleShape body;
    int id;
    const float dAcceleration = 0.3f;
    sf::Vector2f velocity;
    Box* box2;
};