//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "Color.h"

float Color::getR() const {
    return this->r_;
}

void Color::setR(float r) {
    this->r_ = r;
}

float Color::getG() const {
    return this->g_;
}

void Color::setG(float g) {
    this->g_ = g;
}

float Color::getB() const {
    return this->b_;
}

void Color::setB(float b) {
    this->b_ = b;
}

float Color::getA() const {
    return this->a_;
}

void Color::setA(float a) {
    this->a_ = a;
}
