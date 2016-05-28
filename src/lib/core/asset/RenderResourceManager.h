//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef RENDER_RESOURCE_MANAGER_H
#define RENDER_RESOURCE_MANAGER_H

#include "../render/ShaderProgram.h"
#include "../render/Buffer.h"
#include "../render/Drawer.h"
#include "AssetLoader.h"

class RenderResourceManager {
public:
    RenderResourceManager(AssetLoader& assetLoader):assetLoader(assetLoader){}
    virtual ~RenderResourceManager(){}
    virtual ShaderProgram::Pointer createShader(const char* vertexFile, const char* fragmentFile) = 0;
    virtual Buffer::Pointer createBuffer() = 0;
    virtual Drawer::Pointer createDrawer() = 0;
protected:
    AssetLoader& assetLoader;
};


#endif //RENDER_RESOURCE_MANAGER_H
