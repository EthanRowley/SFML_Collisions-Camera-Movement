#include "headers/Box.hpp"
#include <iostream>

Box::Box(sf::Vector2f pos, sf::Color col, int id, Box* b){
    std::cout << "Box created" << std::endl;
    this->body.setSize(sf::Vector2f(100,100));
    this->body.setFillColor(col);
    this->body.setPosition(pos);
    this->id = id;
    this->box2 = b;
}


void Box::BoxMovement(){

    if (this->id == 1){
        // move box 1
        // for the sake of the demo, id 1 is the main player
        // main player checks positions of all other objects

        sf::Vector2f acceleration(0.f,0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            acceleration.y -= this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            acceleration.x -= this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            acceleration.y += this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            acceleration.x += this->dAcceleration;
        }

        this->velocity += acceleration;

        this->velocity = 0.99f * this->velocity;

        sf::Vector2f newPos(this->body.getPosition().x + this->velocity.x, this->body.getPosition().y + this->velocity.y);
        sf::Vector2f b2Pos = this->box2->body.getPosition();

        // check if box is colliding
        if (newPos.x < b2Pos.x + 100 &&
            newPos.x + 100 > b2Pos.x &&
            newPos.y < b2Pos.y + 100 &&
            100 + newPos.y > b2Pos.y){

            std::cout << "Collision Detected" << std::endl;
            this->velocity = sf::Vector2f(0.f, 0.f);
    } 

        this->body.setPosition(this->body.getPosition().x + this->velocity.x, this->body.getPosition().y + this->velocity.y);
        // std::cout << "Blue: " <<this->body.getPosition().x << " : " << this->body.getPosition().y << std::endl;


    } else if (this->id == 2){
        // move box 2
        sf::Vector2f acceleration(0.f,0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            acceleration.y -= this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            acceleration.x -= this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            acceleration.y += this->dAcceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            acceleration.x += this->dAcceleration;
        }

        this->velocity += acceleration;

        this->velocity = 0.99f * this->velocity;

        this->body.setPosition(this->body.getPosition().x + this->velocity.x, this->body.getPosition().y + this->velocity.y);
        // std::cout << "Red: "<< this->body.getPosition().x << " : " << this->body.getPosition().y << std::endl;
    }

}