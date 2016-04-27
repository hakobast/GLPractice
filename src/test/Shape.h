//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef SHAPE_H
#define SHAPE_H

#include "../lib/Drawable.h"
#include "../lib/OpenGLShaderProgram.h"

class Shape : public Drawable{
public:
    Shape();
    virtual ~Shape();
    virtual void draw(glm::mat4& pMat, glm::mat4& vMat);
    virtual void update();
private:
    ShaderProgram::Pointer shader;
    GLuint vertexBuffer;
};


#endif //SHAPE_H