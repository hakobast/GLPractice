//
// Created by Hakob Astvatsatryan on 4/27/16.
//

#ifndef CLEARN_DRAWABLE_H
#define CLEARN_DRAWABLE_H

#include "GameObject.h"

class Drawable : public GameObject{
public:
    Drawable();
    virtual ~Drawable();
    virtual void draw(glm::mat4& pMat, glm::mat4& vMat) = 0;
};


#endif //CLEARN_DRAWABLE_H
