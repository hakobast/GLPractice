//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#include "SFMLInputManager.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdio>

SFMLInputManager::SFMLInputManager(){

}

SFMLInputManager::~SFMLInputManager() {
    printf("~SFMLInputManager\n");
}

bool SFMLInputManager::isKeyDown(Key key) {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key));
}