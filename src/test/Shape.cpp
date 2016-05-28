//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "Shape.h"
#include "../lib/Game.h"


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

    auto shader = Resources::createShader("res/shaders/shader.vert", "res/shaders/shader.frag");
    shader->setAttribute("vPosition", 0);
    shader->setAttribute("vColor", 1);

/*  uint32_t vPos = shader->getAttributeLocation("vPosition");
    uint32_t vColor = shader->getAttributeLocation("vColor");*/

    auto vPositionBuffer = Resources::createBuffer();
    vPositionBuffer->bind();
    vPositionBuffer->setData(sizeof(g_vertex_buffer_data), g_vertex_buffer_data);
    vPositionBuffer->unbind();

    auto vColorBuffer = Resources::createBuffer();
    vColorBuffer->bind();
    vColorBuffer->setData(sizeof(g_vertex_color_buffer_data), g_vertex_color_buffer_data);
    vColorBuffer->unbind();

    auto drawer = Resources::createDrawer();
    drawer->addAttribute(1, 3, AttributeFormat::FLOAT, 0, vPositionBuffer);
    drawer->addAttribute(0, 4, AttributeFormat::FLOAT, 0, vColorBuffer);

    this->shader_ = shader;
    this->drawer_ = drawer;
}

void Shape::draw(glm::mat4& pMat, glm::mat4& vMat){
    shader_->bind();
    shader_->setMat4x4("mvpMat", glm::value_ptr(pMat * vMat * getTransformMatrix()));

    drawer_->draw(DrawingType::TRIANGLE, 0, 3);

    shader_->unbind();
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