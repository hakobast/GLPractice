//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_OPENGLTEXTURE_H
#define CLEARN_OPENGLTEXTURE_H

#include "../../core/render/Texture.h"
#include "../OpenGL.h"
#include "../utils/OpenGLUtils.h"

class OpenGLTexture : public Texture{
public:
	OpenGLTexture(int width, int height, TextureFormat format);
	OpenGLTexture(int width, int height, TextureFormat format, TextureFilter filter, TextureWrapMode wrapMode);
	virtual ~OpenGLTexture();
	virtual void setData(const unsigned char* data);
	virtual void bind();
	virtual void unbind();
private:
	bool pixelSet = false;
	GLuint textureId_ = 0;
	GLenum toGL(TextureFormat format);
	GLenum toGL(TextureFilter filter);
	GLenum toGL(TextureWrapMode wrapMode);
};


#endif //CLEARN_OPENGLTEXTURE_H
