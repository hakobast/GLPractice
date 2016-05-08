//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Buffer.h"
#include "OpenGL.h"

class OpenGLBuffer : public Buffer{
public:
    OpenGLBuffer();
    virtual ~OpenGLBuffer();
    virtual void setData(uint32_t size, const void* data);
    virtual void setDataOffset(uint32_t offset, uint32_t size, const void* data);
    virtual void bind();
    virtual void unbind();
private:
    GLuint id_ = 0;
};



#endif //OPENGLBUFFER_H
