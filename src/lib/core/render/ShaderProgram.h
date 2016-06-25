//
// Created by Hakob Astvatsatryan on 4/27/16.
//

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>
#include "../utils/SmartPointer.h"
#include "../mat/Color.h"
#include "../mat/Color32.h"

class ShaderProgram : public SmartPointer<ShaderProgram>{
public:
    virtual ~ShaderProgram(){};
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void setMat4x4(const std::string& name, const float* value) = 0;
    virtual void setInt(const std::string& name, int value) = 0;
    virtual void setFloat(const std::string& name, float value) = 0;
    virtual void setColor(const std::string& name, const Color& color) = 0;
};


#endif //SHADERPROGRAM_H
