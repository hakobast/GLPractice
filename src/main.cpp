#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "test/Shape.h"


using namespace std;

bool processEvents(sf::Window& window, Shape& shape){
    bool running = true;
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            running = false;
        }else if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Escape:{
                    running = false;
                    break;
                }
                case sf::Keyboard::Right:{
                    shape.translate(1.0f, 0.0f);
                    break;
                }
                case sf::Keyboard::Left:{
                    shape.translate(-1.0f, 0.0f);
                    break;
                }
                case sf::Keyboard::Up:{
                    shape.translate(0.0f, 1.0f);
                    break;
                }
                case sf::Keyboard::Down:{
                    shape.translate(0.0f, -1.0f);
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

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;

    uint32_t width = 1200;
    uint32_t height = 1000;
    sf::Window window(sf::VideoMode(width, height, 32), "Hello SFML", sf::Style::Resize | sf::Style::Close, settings);

    float ratio = (float)width/height;
    float sizeX = 5;
    float sizeY = 5;

    if(ratio > 0){
        sizeX *= ratio;
    }else{
        sizeY /= ratio;
    }

    glm::mat4 pMat = glm::ortho(-sizeX, sizeX, -sizeY, sizeY, 0.0f, 100.0f);
    glm::mat4 vMat = glm::mat4();

    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

    Shape shape;

    shape.setPosition(0, 3);

    bool running = true;
    while(running){
        running = processEvents(window, shape);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shape.draw(pMat, vMat);

        window.display();
    }

    return 0;
}