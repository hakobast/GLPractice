//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "GameObject.h"
#include "../utils/MathUtils.h"

GameObject::GameObject(){
}

GameObject::~GameObject() {
    printf("~GameObject(%s)\n", this->name_.c_str());
}

void GameObject::setName(const std::string& name){
    this->name_ = name;
}

std::string GameObject::getName() const{
    return this->name_;
}

void GameObject::setPosition(const Vector2& position){
    this->position_ = position;
}

void GameObject::translate(const Vector2& deltaPosition){
    setPosition(Vector2(position_.getX()+deltaPosition.getX(), position_.getY()+deltaPosition.getY()));
}

void GameObject::setRotation(float angle){
    this->angle_ = angle;
}

void GameObject::rotate(float deltaAngle) {
    setRotation(angle_ + deltaAngle);
}

const glm::mat4& GameObject::getTransformMatrix() {

    //identity
    mMat_[0][0] = 1.0f;     mMat_[1][0] = 0.0f;     mMat_[2][0] = 0.0f;
    mMat_[0][1] = 0.0f;     mMat_[1][1] = 1.0f;     mMat_[2][1] = 0.0f;
    mMat_[0][2] = 0.0f;     mMat_[1][2] = 0.0f;     mMat_[2][2] = 1.0f;

    if(angle_ != 0.0f){
        mMat_ = glm::rotate(mMat_, angle_*0.0174533f, glm::vec3(0.0f, 0.0f, 1.0f));
    }

    //transformation
    mMat_[3][0] = position_.getX();
    mMat_[3][1] = position_.getY();
    mMat_[3][2] = 0.0f;

    return mMat_;
}