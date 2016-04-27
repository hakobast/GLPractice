//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "GameObject.h"

GameObject::GameObject(){
}

GameObject::~GameObject() {
}

void GameObject::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    mMat[3][0] = x;
    mMat[3][1] = y;
}

void GameObject::translate(float dX, float dY){
    setPosition(x+dX, y+dY);
}

const glm::mat4& GameObject::getTransformMatrix() {
    return mMat;
}