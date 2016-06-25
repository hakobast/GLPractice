//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "Shape.h"
#include "../lib/Game.h"

Shape::Shape(){

    float g_vertex_buffer_data[] = {
            -1.0f,  -1.0f,  0.0f,
             1.0f,  -1.0f,  0.0f,
             1.0f,  1.0f,  0.0f,

            -1.0f,  -1.0f,  0.0f,
             1.0f,  1.0f,  0.0f,
            -1.0f,   1.0f,  0.0f,
    };

    float g_vertex_texcoord_buffer_data[] = {
            0.0f,  0.0f,
            1.0f,  0.0f,
            1.0f,   1.0f,

            0.0f,  0.0f,
            1.0f,   1.0f,
            0.0f,   1.0f,
    };

    float g_vertex_color_buffer_data[] = {
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,

            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
    };

    auto texture = Resources::createTexture("res/textures/spaceship2.png");

    auto shader = Resources::createShader("res/shaders/shader.vert", "res/shaders/shader.frag", {
        VertexAttributeLocation(0, "in_Position"),
        VertexAttributeLocation(1, "in_TexCoord"),
        VertexAttributeLocation(2, "in_Color")
    });

    shader->bind();
    shader->setInt("un_texture", 0);
    shader->setColor("un_color", Color32(255, 255, 255, 255));
    shader->unbind();

    auto vPositionBuffer = Resources::createBuffer();
    vPositionBuffer->bind();
    vPositionBuffer->setData(sizeof(g_vertex_buffer_data), g_vertex_buffer_data);
    vPositionBuffer->unbind();

    auto vTexCoordBuffer = Resources::createBuffer();
    vTexCoordBuffer->bind();
    vTexCoordBuffer->setData(sizeof(g_vertex_texcoord_buffer_data), g_vertex_texcoord_buffer_data);
    vTexCoordBuffer->unbind();

    auto vColorBuffer = Resources::createBuffer();
    vColorBuffer->bind();
    vColorBuffer->setData(sizeof(g_vertex_color_buffer_data), g_vertex_color_buffer_data);
    vColorBuffer->unbind();

    auto drawer = Resources::createDrawer();
    drawer->addAttribute(0, 3, AttributeFormat::FLOAT, 0, vPositionBuffer);
    drawer->addAttribute(1, 2, AttributeFormat::FLOAT, 0, vTexCoordBuffer);
    drawer->addAttribute(2, 4, AttributeFormat::FLOAT, 0, vColorBuffer);

    this->texture_ = texture;
    this->shader_ = shader;
    this->drawer_ = drawer;
}

void Shape::draw(glm::mat4& pMat, glm::mat4& vMat){
    texture_->bind();
    shader_->bind();

    shader_->setMat4x4("un_mvpMat", glm::value_ptr(pMat * vMat * getTransformMatrix()));
    drawer_->draw(DrawingType::TRIANGLE, 0, 6);

    shader_->unbind();
    texture_->unbind();
}

void Shape::update(){

    if(Input::isKeyDown(Input::Key::Up)){
        translate(Vector2(0.0f, 0.1f));
    }
    if(Input::isKeyDown(Input::Key::Down)){
        translate(Vector2(0.0f, -0.1f));
    }
    if(Input::isKeyDown(Input::Key::Right)){
        translate(Vector2(0.1f, 0.0f));
    }
    if(Input::isKeyDown(Input::Key::Left)){
        translate(Vector2(-0.1f, 0.0f));
    }

    if(Input::isKeyDown(Input::Key::D)){
        rotate(-0.1f);
    }

    if(Input::isKeyDown(Input::Key::A)){
        rotate(0.1f);
    }
}