//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_COLOR_H
#define CLEARN_COLOR_H

class Color {
public:
    Color(): r_(0.0f), g_(0.0f), b_(0.0f), a_(0.0f){};
    Color(float r, float g, float b, float a): r_(r), g_(g), b_(b), a_(a){};

    void setR(float r_);
    void setG(float g_);
    void setB(float b_);
    void setA(float a_);
    float getR() const;
    float getG() const;
    float getB() const;
    float getA() const;
private:
    float r_;
    float g_;
    float b_;
    float a_;
};


#endif //CLEARN_COLOR_H
