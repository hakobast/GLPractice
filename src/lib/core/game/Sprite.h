//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_SPRITE_H
#define CLEARN_SPRITE_H


#include "Drawable.h"
#include "../render/ShaderProgram.h"
#include "../render/Drawer.h"
#include "../render/Texture.h"

class Sprite : public Drawable{
public:
	Sprite(const char* imageFile);
	void draw(glm::mat4& pMat, glm::mat4& vMat) final ;
	virtual void update(){};
	void setColor(const Color& color);
	Color getColor();
private:
	Color color_{1.0f, 1.0f, 1.0f, 1.0f};
	ShaderProgram::Pointer shader_ = 0;
	Drawer::Pointer drawer_ = 0;
	Texture::Pointer texture_ = 0;
};


#endif //CLEARN_SPRITE_H
