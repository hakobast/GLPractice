//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Window.hpp>
#include "Engine.h"
#include "../asset/win/WinFileLoader.h"
#include "../asset/soil/SoilImageLoader.h"
#include "../../opengl/asset/OpenGLResourceManager.h"
#include "../input/sfml/SFMLInputManager.h"
#include "../../opengl/OpenGL.h"

#include "../../../test/Shape.h"

bool processEvents(sf::Window& window);
Engine* Engine::instance_ = NULL;

Engine& Engine::getInstance() {
    return *instance_;
}

Engine::Engine(){
    instance_ = this;
}

Engine::~Engine(){
    delete inputManager_;
    delete assetLoader_;
    delete imageLoader_;
    delete renderResourceManager_;
}

InputManager& Engine::getInputManager(){
    return *inputManager_;
}

WindowManager& Engine::getWindowManager(){
    return *windowManager_;
}

FileLoader& Engine::getAssetLoader(){
    return *assetLoader_;
}

RenderResourceManager& Engine::getRenderResourceManager(){
    return *renderResourceManager_;
}

void Engine::run() {
    initSystems();
    gameLoop();
}

void Engine::initSystems() {
    inputManager_ = new SFMLInputManager;
    assetLoader_ = new WinFileLoader;
    imageLoader_ = new SoilImageLoader;
    renderResourceManager_ = new OpenGLResourceManager(*assetLoader_, *imageLoader_);
}

void Engine::gameLoop() {
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

    Shape shape;

    shape.setPosition(Vector2(0.0f, 0.0f));

    bool running = true;
    while(running){
        running = processEvents(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shape.update();
        shape.draw(pMat, vMat);

        window.display();
    }
}

bool processEvents(sf::Window& window) {
    bool running = true;
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            running = false;
        } else if (event.type == sf::Event::KeyPressed) {
            float step = 1.0f;
            switch (event.key.code) {
                case sf::Keyboard::Escape: {
                    running = false;
                    break;
                }
                default: {
                    break;
                }
            }
        } else if (event.type == sf::Event::Resized) {
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }

    return running;
}