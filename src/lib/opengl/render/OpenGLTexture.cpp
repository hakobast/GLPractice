//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture(int width, int height, TextureFilter filter, TextureWrapMode wrapMode)
	: Texture(width, height, filter, wrapMode
) {
	glGenTextures(1, &textureId_);

	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, toGL(getFilter()));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, toGL(getFilter()));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, toGL(getWrapMode()));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, toGL(getWrapMode()));
	unbind();
}

OpenGLTexture::OpenGLTexture(int width, int height)
	: OpenGLTexture(width, height, TextureFilter::LINEAR, TextureWrapMode::CLAMP_TO_EDGE
){}

OpenGLTexture::~OpenGLTexture(){
	bind();
	glDeleteTextures(1, &textureId_);
	unbind();
	textureId_ = 0;

	printf("~OpenGLTexture\n");
}

void OpenGLTexture::setData(const unsigned char* data){
	bind();
	if(!pixelSet){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, getWidth(), getHeight(), 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
		pixelSet = true;
	}else{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, getWidth(), getHeight(), GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	unbind();
}

void OpenGLTexture::bind(){
	glBindTexture(GL_TEXTURE_2D, textureId_);
}

void OpenGLTexture::unbind(){
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLenum OpenGLTexture::toGL(TextureFilter filter){
	switch(filter){
		case TextureFilter::LINEAR: {
			return GL_LINEAR;
		}
		case TextureFilter::NEAREST: {
			return GL_NEAREST;
		}
		default:{
			return GL_NEAREST;
		}
	}
}

GLenum OpenGLTexture::toGL(TextureWrapMode wrapMode){
	switch(wrapMode){
		case TextureWrapMode::CLAMP_TO_EDGE:{
			return GL_CLAMP_TO_EDGE;
		}
		case TextureWrapMode::REPEAT:{
			return GL_REPEAT;
		}
		case TextureWrapMode::MIRRORED_REPEAT:{
			return GL_MIRRORED_REPEAT;
		}
		default:{
			return GL_CLAMP_TO_EDGE;
		}
	}
}
