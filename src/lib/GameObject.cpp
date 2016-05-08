//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "GameObject.h"

GameObject::GameObject(){
}

GameObject::~GameObject() {
}

void GameObject::setPosition(float x, float y){
    this->x_ = x;
    this->y_ = y;
    mMat_[3][0] = x;
    mMat_[3][1] = y;
}

void GameObject::translate(float dX, float dY){
    setPosition(x_+dX, y_+dY);
}

const glm::mat4& GameObject::getTransformMatrix() {
    return mMat_;
}