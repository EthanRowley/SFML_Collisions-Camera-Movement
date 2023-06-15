#include <SFML/Graphics.hpp>
#include "headers/Box.hpp"
#include <iostream>

int main(){

    sf::RenderWindow window(sf::VideoMode(500,500), "AABB Collisions");
    sf::Vector2f camera(0.f,0.f); // initialise camera position
    window.setFramerateLimit(60);
    // Create Boxes
    Box* b2 = new Box(sf::Vector2f(100,40), sf::Color::Red, 2,NULL);
    Box* b1 = new Box(sf::Vector2f(20,20), sf::Color::Blue, 1,b2);




    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        b1->BoxMovement();
        b2->BoxMovement();

        // Move camera based on player movement - centers the player in the camera
        camera = (b1->body.getPosition() + sf::Vector2f(50.f, 50.f)) - sf::Vector2f(500/2, 500/2);
        // std::cout << "Camera: " << camera.x << " : " << camera.y << std::endl;

        // redrawn objects relative to the camera
        b1->body.setPosition(b1->body.getPosition() - camera);
        b2->body.setPosition(b2->body.getPosition() - camera);

        window.clear(sf::Color::White);
        window.draw(b1->body);
        window.draw(b2->body);
        window.display();

    }

    return 0;
}