#include "headers/Platform.hpp"
#include <iostream>

Platform::Platform(){

    this->body.setFillColor(sf::Color::Black);
    this->body.setPosition(sf::Vector2f(0.f, 600.f));
    this->body.setSize(sf::Vector2f(1280.f, 20.f));

}

void Platform::update(){

}