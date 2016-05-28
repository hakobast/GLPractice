#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "test/Shape.h"
#include "lib/core/game/Engine.h"


using namespace std;

bool processEvents(sf::Window& window){
    bool running = true;
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            running = false;
        }else if(event.type == sf::Event::KeyPressed){
            float step = 1.0f;
            switch(event.key.code){
                case sf::Keyboard::Escape:{
                    running = false;
                    break;
                }
                default:{
                    break;
                }
            }
        }else if(event.type == sf::Event::Resized){
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }

    return running;
}

int main() {

    Engine engine;

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;

    uint32_t width = 1200;
    uint32_t height = 1000;
    sf::Window window(sf::VideoMode(width, height, 32), "Hello", sf::Style::Resize | sf::Style::Close, settings);

    float ratio = (float)width/height;
    float sizeX = 5.0f;
    float sizeY = 5.0f;

    if(ratio > 0){
        sizeX *= ratio;
    }else{
        sizeY /= ratio;
    }

    glm::mat4 pMat = glm::ortho(-sizeX, sizeX, -sizeY, sizeY, -1.0f, 1.0f);
    glm::mat4 vMat = glm::mat4();

    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

    Shape shape;
    Shape shape2;

    shape.setPosition(Vector2(2.0f, 1.0f));
    shape2.setPosition(Vector2(-2.0f, 1.0f));

    bool running = true;
    while(running){
        running = processEvents(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shape.update();
        shape2.update();
        shape.draw(pMat, vMat);
        shape2.draw(pMat, vMat);

        window.display();
    }

    return 0;
}