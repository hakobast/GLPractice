//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef OPENGLRESOURCEMANAGER_H
#define OPENGLRESOURCEMANAGER_H

#include "../../core/asset/RenderResourceManager.h"

class OpenGLResourceManager : public RenderResourceManager{
public:
    OpenGLResourceManager(AssetLoader& assetLoader):RenderResourceManager::RenderResourceManager(assetLoader){}
    virtual ~OpenGLResourceManager();
    virtual ShaderProgram::Pointer createShader(const char* vertexFile, const char* fragmentFile);
    virtual Buffer::Pointer createBuffer();
    virtual Drawer::Pointer createDrawer();
};


#endif //OPENGLRESOURCEMANAGER_H
