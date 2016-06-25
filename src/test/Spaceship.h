//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_SPACESHIP_H
#define CLEARN_SPACESHIP_H

#include "../lib/Game.h"

class Spaceship : public Sprite{
public:
	Spaceship(const char* imageFile) : Sprite(imageFile){};
	virtual void update();
};


#endif //CLEARN_SPACESHIP_H
