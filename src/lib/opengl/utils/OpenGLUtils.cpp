//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "../OpenGL.h"
#include "OpenGLUtils.h"

std::string OpenGLUtils::getGLError(){
    GLenum error = glGetError();
    switch(error){
        case GL_INVALID_ENUM:{
            return "GL_INVALID_ENUM\n";
        }
        case GL_INVALID_VALUE:{
            return "GL_INVALID_VALUE\n";
        }
        case GL_INVALID_OPERATION:{
            return "GL_INVALID_OPERATION\n";
        }
        case GL_INVALID_FRAMEBUFFER_OPERATION:{
            return "GL_INVALID_FRAMEBUFFER_OPERATION\n";
        }
        case GL_OUT_OF_MEMORY:{
            return "GL_OUT_OF_MEMORY\n";
        }
        default:{
            return "";
        }
    }
}