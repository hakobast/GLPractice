//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "../../Game.h"
#include "Sprite.h"

const float g_vertex_buffer_data[] = {
		-1.0f,  -1.0f,  0.0f,
		 1.0f,  -1.0f,  0.0f,
		 1.0f,   1.0f,  0.0f,

		-1.0f,  -1.0f,  0.0f,
		 1.0f,   1.0f,  0.0f,
		-1.0f,   1.0f,  0.0f,
};

const float g_vertex_texcoord_buffer_data[] = {
		0.0f,  0.0f,
		1.0f,  0.0f,
		1.0f,  1.0f,

		0.0f,  0.0f,
		1.0f,  1.0f,
		0.0f,  1.0f,
};

Sprite::Sprite(const char* imageFile){
	auto texture = Resources::createTexture(imageFile);

	auto shader = Resources::createShader("res/shaders/sprite_shader.vert", "res/shaders/sprite_shader.frag", {
		VertexAttributeLocation(0, "in_Position"),
		VertexAttributeLocation(1, "in_TexCoord"),
	});

	shader->bind();
	shader->setInt("un_texture", 0);
	shader->setColor("un_color", color_);
	shader->unbind();

	auto vPositionBuffer = Resources::createBuffer();
	vPositionBuffer->bind();
	vPositionBuffer->setData(sizeof(g_vertex_buffer_data), g_vertex_buffer_data);
	vPositionBuffer->unbind();

	auto vTexCoordBuffer = Resources::createBuffer();
	vTexCoordBuffer->bind();
	vTexCoordBuffer->setData(sizeof(g_vertex_texcoord_buffer_data), g_vertex_texcoord_buffer_data);
	vTexCoordBuffer->unbind();

	auto drawer = Resources::createDrawer();
	drawer->addAttribute(0, 3, AttributeFormat::FLOAT, 0, vPositionBuffer);
	drawer->addAttribute(1, 2, AttributeFormat::FLOAT, 0, vTexCoordBuffer);

	this->texture_ = texture;
	this->shader_ = shader;
	this->drawer_ = drawer;
}

void Sprite::draw(glm::mat4& pMat, glm::mat4& vMat){
	texture_->bind();
	shader_->bind();

	shader_->setMat4x4("un_mvpMat", glm::value_ptr(pMat * vMat * getTransformMatrix()));
	drawer_->draw(DrawingType::TRIANGLE, 0, 6);

	shader_->unbind();
	texture_->unbind();
}

void Sprite::setColor(const Color& color) {
	this->color_.setR(color.getR());
	this->color_.setG(color.getG());
	this->color_.setB(color.getB());
	this->color_.setA(color.getA());

	shader_->bind();
	shader_->setColor("un_color", color_);
	shader_->unbind();
}

Color Sprite::getColor() {
	return Color(this->color_);
}