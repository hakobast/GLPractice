//
// Created by Hakob Astvatsatryan on 5/11/16.
//

#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2 {
public:
    Vector2(): x_(0), y_(0){};
    Vector2(float x, float y): x_(x), y_(y){};
    float getX() const;
    float getY() const;
    void set(float x, float y);
    void setX(float x);
    void setY(float y);
private:
    float x_;
    float y_;
};


#endif //VECTOR2_H