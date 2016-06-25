//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef RENDER_RESOURCE_MANAGER_H
#define RENDER_RESOURCE_MANAGER_H

#include "FileLoader.h"
#include "ImageLoader.h"

#include "../render/ShaderProgram.h"
#include "../render/Buffer.h"
#include "../render/Drawer.h"
#include "../render/Texture.h"
#include "../render/VertexAttributeLocation.h"

class RenderResourceManager {
public:
    RenderResourceManager(FileLoader& assetLoader, ImageLoader& imageLoader)
		    :assetLoader(assetLoader), imageLoader(imageLoader){}

    virtual ~RenderResourceManager(){}

	virtual Texture::Pointer createTexture(const char* imageFile,
	                                       TextureFilter filter,
	                                       TextureWrapMode wrapMode) = 0;

    virtual ShaderProgram::Pointer createShader(const char* vertexFile,
                                                const char* fragmentFile,
                                                std::vector<VertexAttributeLocation> attributes) = 0;

    virtual Buffer::Pointer createBuffer() = 0;
    virtual Drawer::Pointer createDrawer() = 0;
protected:
    FileLoader& assetLoader;
    ImageLoader& imageLoader;
};


#endif //RENDER_RESOURCE_MANAGER_H
