//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "Color32.h"

int Color32::getR() const {
    return this->r_;
}

void Color32::setR(int r) {
    this->r_ = r;
}

int Color32::getG() const {
    return this->g_;
}

void Color32::setG(int g) {
    this->g_ = g;
}

int Color32::getB() const {
    return this->b_;
}

void Color32::setB(int b) {
    this->b_ = b;
}

int Color32::getA() const {
    return this->a_;
}

void Color32::setA(int a) {
    this->a_ = a;
}

Color32::operator Color(){
    float r = this->r_/255.0f;
    float g = this->g_/255.0f;
    float b = this->b_/255.0f;
    float a = this->a_/255.0f;

    r = r < 0.0f ? 0.0f : (r > 1.0f ? 1.0f : r);
    g = g < 0.0f ? 0.0f : (g > 1.0f ? 1.0f : g);
    b = b < 0.0f ? 0.0f : (b > 1.0f ? 1.0f : b);
    a = a < 0.0f ? 0.0f : (a > 1.0f ? 1.0f : a);

    return Color(r, g, b, a);
}