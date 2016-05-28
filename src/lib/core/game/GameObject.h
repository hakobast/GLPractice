//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <glm/glm.hpp>
#include "../mat/Vector2.h"

class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    virtual void update() = 0;
    void setPosition(const Vector2& position);
    void setRotation(float angle);
    void translate(const Vector2& deltaPosition);
    void rotate(float deltaAngle);
    const glm::mat4& getTransformMatrix();
private:
    glm::mat4 mMat_;
    Vector2 position_;
    float angle_;
};


#endif //CLEARN_GAMEOBJECT_H
