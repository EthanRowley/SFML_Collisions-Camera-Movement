#include "headers/Player.hpp"
#include <iostream>


Player::Player(Platform* plt){
    this->body.setSize(sf::Vector2f(100.f,100.f));
    this->body.setPosition(sf::Vector2f(200.f, 200.f));
    this->body.setFillColor(sf::Color::Blue);
    this->platform = plt;
}

void Player::update(){

    sf::Vector2f acceleration;

   

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        acceleration.x += this->deltaVel;    
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        acceleration.x -= this->deltaVel;    
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        acceleration.y -= gravityVel + 2.f;
    }


    if (this->isColliding() == false){
        if (this->jumping == false){
            acceleration.y += this->gravityVel;    
        }
    } else {
        this->velocity.y = 0;
    }
    // if (platform->body.getPosition().y <= 410 + 48){
    //     this->velocity.y = 0;
    // }


    this->velocity += acceleration;

    this->velocity = 0.95f * this->velocity;

    sf::Vector2f newPosition(this->body.getPosition().x + this->velocity.x,this->body.getPosition().y + this->velocity.y);
    this->body.setPosition(newPosition);

}


bool Player::isColliding(){

    sf::Vector2f newPos = this->body.getPosition() + this->velocity;
    sf::Vector2f b2Pos = this->platform->body.getPosition();

    if (newPos.x < b2Pos.x + 1280 &&
        newPos.x + 100 > b2Pos.x &&
        newPos.y < b2Pos.y + 20 &&
        100 + newPos.y > b2Pos.y){
            return true;
        } else {
            return false;
        }
}