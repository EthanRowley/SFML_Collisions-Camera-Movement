#include "SFML/Graphics.hpp"
#include "headers/Player.hpp"
#include "headers/Platform.hpp"
#include <iostream>

int main(){

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Jumping Demo");
    window.setFramerateLimit(60);
    Platform* platform = new Platform();
    Player* player = new Player(platform);
    sf::Vector2f camera(0.f, 0.f);


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyReleased && sf::Event::KeyReleased == sf::Keyboard::Space){
                std::cout << "space released" << std::endl;
            }

        }

        // Update 
        player->update();
        platform->update();
        camera = (player->body.getPosition() - sf::Vector2f(1280/2, 720/2));

        // update entity positions relative to camera
        player->body.setPosition(player->body.getPosition() - camera);
        platform->body.setPosition(platform->body.getPosition() - camera);

        // Draw
        window.clear(sf::Color::White); // clear window
        

        window.draw(player->body); 
        window.draw(platform->body);

        // draw displays
        window.display();

    }
    
    return 0;
}