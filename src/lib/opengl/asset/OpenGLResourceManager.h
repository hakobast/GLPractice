//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef OPENGLRESOURCEMANAGER_H
#define OPENGLRESOURCEMANAGER_H

#include "../../core/asset/RenderResourceManager.h"

class OpenGLResourceManager : public RenderResourceManager{
public:
    OpenGLResourceManager(FileLoader& assetLoader, ImageLoader& imageLoader)
		    :RenderResourceManager::RenderResourceManager(assetLoader, imageLoader){}

    virtual ~OpenGLResourceManager();

	virtual Texture::Pointer createTexture(const char* imageFile,
	                                       TextureFilter filter,
	                                       TextureWrapMode wrapMode);

    virtual ShaderProgram::Pointer createShader(const char* vertexFile,
                                                const char* fragmentFile,
                                                std::vector<VertexAttributeLocation> attributes);
    virtual Buffer::Pointer createBuffer();
    virtual Drawer::Pointer createDrawer();
};


#endif //OPENGLRESOURCEMANAGER_H
