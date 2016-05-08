//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "OpenGLBuffer.h"

OpenGLBuffer::OpenGLBuffer() {
    glGenBuffers(1, &id_);
}

OpenGLBuffer::~OpenGLBuffer() {
    glDeleteBuffers(1, &id_);
    printf("~OpenGLBuffer\n");
}

void OpenGLBuffer::setData(uint32_t size, const void* data){
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void OpenGLBuffer::setDataOffset(uint32_t offset, uint32_t size, const void* data){
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void OpenGLBuffer::bind(){
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void OpenGLBuffer::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
