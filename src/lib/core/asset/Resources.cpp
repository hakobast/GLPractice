//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "Resources.h"
#include "../game/Engine.h"

ShaderProgram::Pointer Resources::createShader(const char* vertexFile, const char* fragmentFile){
    return Engine::getInstance().getRenderResourceManager().createShader(vertexFile, fragmentFile);
}

Buffer::Pointer Resources::createBuffer(){
    return Engine::getInstance().getRenderResourceManager().createBuffer();
}

Drawer::Pointer Resources::createDrawer(){
    return Engine::getInstance().getRenderResourceManager().createDrawer();
}