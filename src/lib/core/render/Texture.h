//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_TEXTURE_H
#define CLEARN_TEXTURE_H

#include "../utils/SmartPointer.h"

enum class TextureFormat{
	L = 1,
	LA = 2,
	RGB = 3,
	RGBA = 4,
};

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
	Texture(int width, int height, TextureFormat format, TextureFilter filter, TextureWrapMode wrapMode)
			: width_(width), height_(height), format_(format), filter_(filter), wrapMode_(wrapMode){};

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

	TextureFormat getFormat() const {
		return this->format_;
	}

	TextureFilter getFilter() const {
		return this->filter_;
	}

	TextureWrapMode getWrapMode() const {
		return this->wrapMode_;
	}

private:
	int width_;
	int height_;
	TextureFormat  format_;
	TextureFilter  filter_;
	TextureWrapMode  wrapMode_;
};


#endif //CLEARN_TEXTURE_H
