//
// Created by Hakob Astvatsatryan on 4/27/16.
//

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>
#include "../../utils/SmartPointer.h"

class ShaderProgram : public SmartPointer<ShaderProgram>{
public:
    virtual ~ShaderProgram(){};
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void setAttribute(const std::string& name, uint32_t index) = 0;
    virtual void setMat4x4(const std::string& name, const float* value) = 0;
};


#endif //SHADERPROGRAM_H
