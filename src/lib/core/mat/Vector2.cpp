//
// Created by Hakob Astvatsatryan on 5/11/16.
//

#include "Vector2.h"

float Vector2::getX() const{
    return this->x_;
}

float Vector2::getY() const{
    return this->y_;
}

void Vector2::set(float x, float y){
    this->x_ = x;
    this->y_ = y;
}

void Vector2::setX(float x){
    this->x_ = x;
}

void Vector2::setY(float y){
    this->y_ = y;
}