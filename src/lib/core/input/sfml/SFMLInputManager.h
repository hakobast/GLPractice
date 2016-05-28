//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#ifndef CLEARN_SFMLINPUTMANAGER_H
#define CLEARN_SFMLINPUTMANAGER_H

#include "../InputManager.h"

class SFMLInputManager : public InputManager{
public:
    SFMLInputManager();
    virtual ~SFMLInputManager();
    virtual bool isKeyDown(Key key);
};


#endif //CLEARN_SFMLINPUTMANAGER_H
