//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#ifndef CLEARN_INPUT_H
#define CLEARN_INPUT_H

#include "InputManager.h"

class Input {
public:
    typedef InputManager::Key Key;
    static bool isKeyDown(Key key);
};


#endif //CLEARN_INPUT_H
