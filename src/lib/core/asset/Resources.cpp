//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "Resources.h"
#include "../game/Engine.h"
#include "../render/VertexAttributeLocation.h"

Texture::Pointer Resources::createTexture(const char* imageFile,
                                      TextureFilter filter,
                                      TextureWrapMode wrapMode){

    return Engine::getInstance().getRenderResourceManager().createTexture(imageFile, filter, wrapMode);
}

ShaderProgram::Pointer Resources::createShader(const char* vertexFile,
                                               const char* fragmentFile,
                                               std::vector<VertexAttributeLocation> attributes){

    return Engine::getInstance().getRenderResourceManager().createShader(vertexFile, fragmentFile, attributes);
}

Buffer::Pointer Resources::createBuffer(){
    return Engine::getInstance().getRenderResourceManager().createBuffer();
}

Drawer::Pointer Resources::createDrawer(){
    return Engine::getInstance().getRenderResourceManager().createDrawer();
}