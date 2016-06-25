//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_COLOR32_H
#define CLEARN_COLOR32_H

#include "Color.h"

class Color32 {
public:
    Color32(): r_(0), g_(0), b_(0), a_(0){};
    Color32(int r, int g, int b, int a): r_(r), g_(g), b_(b), a_(a){};

    void setR(int r_);
    void setG(int g_);
    void setB(int b_);
    void setA(int a_);
	int getR() const;
	int getG() const;
	int getB() const;
	int getA() const;

	operator Color ();
private:
    int r_;
	int g_;
	int b_;
	int a_;
};


#endif //CLEARN_COLOR32_H
