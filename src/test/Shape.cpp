//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "Shape.h"
#include <glm/gtc/type_ptr.hpp>
#include "../lib/WinAssetLoader.h"

Shape::Shape(){

    // creating vertex and fragment shaders
    const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };

    WinAssetLoader assetLoader;
    AssetFile vertexAsset = assetLoader.loadAsset("res/shaders/shader.vert");
    AssetFile fragmentAsset = assetLoader.loadAsset("res/shaders/shader.frag");


    auto shaderProgram = std::make_shared<OpenGLShaderProgram>();
    shaderProgram->loadShaderFromString(GL_VERTEX_SHADER, (char*)vertexAsset.data, (int)vertexAsset.length);
    shaderProgram->loadShaderFromString(GL_FRAGMENT_SHADER, (char*)fragmentAsset.data, (int)fragmentAsset.length);
    shaderProgram->createAndLinkProgram();

    // creating vertex buffer
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    assetLoader.releaseAsset(&vertexAsset);
    assetLoader.releaseAsset(&fragmentAsset);

    this->shader = shaderProgram;
}

Shape::~Shape(){
    glDeleteBuffers(1, &vertexBuffer);
}

void Shape::draw(glm::mat4& pMat, glm::mat4& vMat){

    shader->bind();
    shader->setMat4x4("mvpMat", glm::value_ptr(pMat * vMat * getTransformMatrix()));

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    shader->unbind();
}

void Shape::update(){
    printf("Shape::update\n");
}