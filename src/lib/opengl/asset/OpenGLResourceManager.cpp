//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "OpenGLResourceManager.h"
#include "../OpenGL.h"
#include "../render/OpenGLShaderProgram.h"
#include "../render/OpenGLBuffer.h"
#include "../render/OpenGLDrawer.h"

OpenGLResourceManager::~OpenGLResourceManager(){
    printf("~OpenGLResourceManager\n");
}

ShaderProgram::Pointer OpenGLResourceManager::createShader(const char* vertexFile, const char* fragmentFile){

    AssetFile vertexAsset = assetLoader.loadAsset(vertexFile);
    AssetFile fragmentAsset = assetLoader.loadAsset(fragmentFile);

    auto shader = std::make_shared<OpenGLShaderProgram>();
    shader->loadShaderFromString(GL_VERTEX_SHADER, (char*)vertexAsset.data, (int)vertexAsset.length);
    shader->loadShaderFromString(GL_FRAGMENT_SHADER, (char*)fragmentAsset.data, (int)fragmentAsset.length);
    shader->createAndLinkProgram();

    assetLoader.releaseAsset(&vertexAsset);
    assetLoader.releaseAsset(&fragmentAsset);

    return shader;
}

Buffer::Pointer OpenGLResourceManager::createBuffer(){
    return std::make_shared<OpenGLBuffer>();
}

Drawer::Pointer OpenGLResourceManager::createDrawer(){
    return std::make_shared<OpenGLDrawer>();
}