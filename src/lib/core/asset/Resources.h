//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef RESOURCES_H
#define RESOURCES_H

#include "../render/ShaderProgram.h"
#include "../render/Buffer.h"
#include "../render/Drawer.h"

class Resources {
public:
    static ShaderProgram::Pointer createShader(const char* vertexFile, const char* fragmentFile);
    static Buffer::Pointer createBuffer();
    static Drawer::Pointer createDrawer();
};


#endif //RESOURCES_H
