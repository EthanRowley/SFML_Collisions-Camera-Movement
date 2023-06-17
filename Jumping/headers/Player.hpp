#pragma once
#include "SFML/Graphics.hpp"
#include "Platform.hpp"

class Player{

public:
    Player(Platform*);

    void update();
    bool isColliding();

    sf::RectangleShape body;
    sf::Vector2f velocity;
    float deltaVel = 0.3f;
    float gravityVel = 2.f;
    Platform* platform;
    bool jumping = false;



};