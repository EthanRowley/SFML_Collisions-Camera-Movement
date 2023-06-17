#pragma once
#include "SFML/Graphics.hpp"


class Platform{

public:
    Platform();


    sf::RectangleShape body;

    void update();
};