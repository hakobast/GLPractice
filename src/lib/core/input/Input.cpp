//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#include "Input.h"
#include "../game/Engine.h"

bool Input::isKeyDown(Key key) {
    return Engine::getInstance().getInputManager().isKeyDown(key);
}