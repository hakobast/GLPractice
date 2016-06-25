//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "OpenGLDrawer.h"

OpenGLDrawer::OpenGLDrawer() {

}

OpenGLDrawer::~OpenGLDrawer(){
    printf("~OpenGLDrawer\n");
}

void OpenGLDrawer::draw(DrawingType type, uint32_t startIndex, uint32_t count){

    for(auto& att : attributes){
        glEnableVertexAttribArray(att.index);
        att.buffer->bind();
        glVertexAttribPointer(att.index, att.size, toGL(att.format), GL_FALSE, att.stride, 0);
    }

    glDrawArrays(toGL(type), startIndex, count);

    for(auto& att : attributes){
        glDisableVertexAttribArray(att.index);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLenum OpenGLDrawer::toGL(AttributeFormat format){
    switch(format){
        case AttributeFormat::FLOAT:{
            return GL_FLOAT;
        }
        case AttributeFormat::INT:{
            return GL_INT;
        }
        default:{
            return 0;
        }
    }
}

GLenum OpenGLDrawer::toGL(DrawingType drawingType){
    switch(drawingType){
        case DrawingType::TRIANGLE:{
            return GL_TRIANGLES;
        }
        case DrawingType::QUAD:{
            return GL_QUADS;
        }
        default:{
            return 0;
        }
    }
}