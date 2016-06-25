//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#include "OpenGLResourceManager.h"
#include "../render/OpenGLShaderProgram.h"
#include "../render/OpenGLBuffer.h"
#include "../render/OpenGLDrawer.h"
#include "../render/OpenGLTexture.h"

OpenGLResourceManager::~OpenGLResourceManager(){
    printf("~OpenGLResourceManager\n");
}

Texture::Pointer OpenGLResourceManager::createTexture(const char* imageFile,
                                       TextureFilter filter,
                                       TextureWrapMode wrapMode){

    ImageInfo info = imageLoader.loadImage(imageFile);
    if(info.success()){
        auto texture = std::make_shared<OpenGLTexture>(info.width, info.height, filter, wrapMode);
        texture->setData(info.data);

        imageLoader.freeImage(info);

        return texture;
    }

    return NULL;
}

ShaderProgram::Pointer OpenGLResourceManager::createShader(const char* vertexFile,
    const char* fragmentFile, std::vector<VertexAttributeLocation> attributes
){
    AssetFile vertexAsset = assetLoader.loadAsset(vertexFile);
    AssetFile fragmentAsset = assetLoader.loadAsset(fragmentFile);

    auto shader = std::make_shared<OpenGLShaderProgram>();
    shader->loadShaderFromString(GL_VERTEX_SHADER, (char*)vertexAsset.data, (int)vertexAsset.length);
    shader->loadShaderFromString(GL_FRAGMENT_SHADER, (char*)fragmentAsset.data, (int)fragmentAsset.length);
    shader->createProgram();
    for(VertexAttributeLocation& attribute : attributes){
        shader->bindAttribute(attribute.getName(), attribute.getIndex());
    }
    shader->linkProgram();

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