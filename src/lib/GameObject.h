//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <cstdint>
#include <glm/glm.hpp>

class GameObject {

public:
    GameObject();
    virtual ~GameObject();
    virtual void update() = 0;
    void setPosition(float x, float y);
    void translate(float dX, float dY);
    const glm::mat4& getTransformMatrix();
private:
    glm::mat4 mMat;
    float x;
    float y;
};


#endif //CLEARN_GAMEOBJECT_H
