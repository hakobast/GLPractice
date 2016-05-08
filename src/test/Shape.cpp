//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "Shape.h"
#include "../lib/OpenGLShaderProgram.h"
#include "../lib/OpenGLBuffer.h"
#include "../lib/OpenGLDrawer.h"
#include "../lib/WinAssetLoader.h"
#include <glm/gtc/type_ptr.hpp>

void printGLError(){
    GLenum error = glGetError();
    switch(error){
        case GL_INVALID_ENUM:{
            printf("GL_INVALID_ENUM\n");
            break;
        }
        case GL_INVALID_VALUE:{
            printf("GL_INVALID_VALUE\n");
            break;
        }
        case GL_INVALID_OPERATION:{
            printf("GL_INVALID_OPERATION\n");
            break;
        }
        case GL_INVALID_FRAMEBUFFER_OPERATION:{
            printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
            break;
        }
        case GL_OUT_OF_MEMORY:{
            printf("GL_OUT_OF_MEMORY\n");
            break;
        }
        default:{
            printf("Unknown\n");
        }
    }
}

Shape::Shape(){
    float g_vertex_buffer_data[] = {
            -1.0f,  -1.0f,  0.0f,
             1.0f,  -1.0f,  0.0f,
             0.0f,   1.0f,  0.0f,
    };

    float g_vertex_color_buffer_data[] = {
            1.0f, 0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f, 1.0f
    };

    WinAssetLoader assetLoader;
    AssetFile vertexAsset = assetLoader.loadAsset("res/shaders/shader.vert");
    AssetFile fragmentAsset = assetLoader.loadAsset("res/shaders/shader.frag");


    auto shader = std::make_shared<OpenGLShaderProgram>();
    shader->loadShaderFromString(GL_VERTEX_SHADER, (char*)vertexAsset.data, (int)vertexAsset.length);
    shader->loadShaderFromString(GL_FRAGMENT_SHADER, (char*)fragmentAsset.data, (int)fragmentAsset.length);
    shader->createAndLinkProgram();

    uint32_t vPos = shader->getAttributeLocation("vPosition");
    uint32_t vColor = shader->getAttributeLocation("vColor");

    auto vPositionBuffer = std::make_shared<OpenGLBuffer>();
    vPositionBuffer->bind();
    vPositionBuffer->setData(sizeof(g_vertex_buffer_data), g_vertex_buffer_data);
    vPositionBuffer->unbind();

    auto vColorBuffer = std::make_shared<OpenGLBuffer>();
    vColorBuffer->bind();
    vColorBuffer->setData(sizeof(g_vertex_color_buffer_data), g_vertex_color_buffer_data);
    vColorBuffer->unbind();

    auto drawer = std::make_shared<OpenGLDrawer>();
    drawer->addAttribute(vPos, 3, AttributeFormat::FLOAT, 0, vPositionBuffer);
    drawer->addAttribute(vColor, 4, AttributeFormat::FLOAT, 0, vColorBuffer);

    assetLoader.releaseAsset(&vertexAsset);
    assetLoader.releaseAsset(&fragmentAsset);

    this->shader_ = shader;
    this->drawer_ = drawer;
}

Shape::~Shape(){
}

void Shape::draw(glm::mat4& pMat, glm::mat4& vMat){

    shader_->bind();
    shader_->setMat4x4("mvpMat", glm::value_ptr(pMat * vMat * getTransformMatrix()));

    drawer_->draw(DrawingType::TRIANGLE, 0, 3);

    shader_->unbind();
}

void Shape::update(){
    printf("Shape::update\n");
}