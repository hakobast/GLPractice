//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_TEXTURE_H
#define CLEARN_TEXTURE_H

#include "../utils/SmartPointer.h"

enum class TextureFilter{
	LINEAR,
	NEAREST,
};

enum class TextureWrapMode{
	CLAMP_TO_EDGE,
	MIRRORED_REPEAT,
	REPEAT,
};

class Texture : public SmartPointer<Texture>{
public:
	Texture(int width, int height, TextureFilter filter, TextureWrapMode wrapMode)
			: width_(width), height_(height), filter_(filter), wrapMode_(wrapMode){};

	virtual ~Texture(){}
	virtual void setData(const unsigned char* data) = 0;
	virtual void bind() = 0;
	virtual void unbind() = 0;

	int getWidth() const {
		return this->width_;
	};

	int getHeight() const{
		return this->height_;
	};

	TextureFilter getFilter() const {
		return this->filter_;
	}

	TextureWrapMode getWrapMode() const {
		return this->wrapMode_;
	}

private:
	int width_;
	int height_;
	TextureFilter  filter_;
	TextureWrapMode  wrapMode_;
};


#endif //CLEARN_TEXTURE_H
