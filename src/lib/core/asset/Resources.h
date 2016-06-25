//
// Created by Hakob Astvatsatryan on 5/9/16.
//

#ifndef RESOURCES_H
#define RESOURCES_H

#include "../render/ShaderProgram.h"
#include "../render/Buffer.h"
#include "../render/Drawer.h"
#include "../render/Texture.h"
#include "../render/VertexAttributeLocation.h"

class Resources {
public:
	static Texture::Pointer createTexture(const char* imageFile,
                                          TextureFilter filter = TextureFilter::LINEAR,
                                          TextureWrapMode wrapMode = TextureWrapMode::CLAMP_TO_EDGE);

    static ShaderProgram::Pointer createShader(const char* vertexFile,
                                               const char* fragmentFile,
                                               std::vector<VertexAttributeLocation> attributes);
    static Buffer::Pointer createBuffer();
    static Drawer::Pointer createDrawer();
};


#endif //RESOURCES_H
