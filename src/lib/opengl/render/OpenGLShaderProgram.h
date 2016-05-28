//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include "../../core/render/ShaderProgram.h"
#include "../OpenGL.h"
#include <unordered_map>

class OpenGLShaderProgram : public ShaderProgram{
public:
	OpenGLShaderProgram();
	virtual ~OpenGLShaderProgram();
	virtual void bind();
	virtual void unbind();
	virtual void setAttribute(const std::string& name, uint32_t index);
	virtual void setMat4x4(const std::string& name, const float* value);

	void loadShaderFromString(GLenum shader_type, const char* source, int length);
	void createAndLinkProgram();
	GLuint getProgram() const;
	GLint getUniformLocation(const std::string& name);
	GLint getAttributeLocation(const std::string& name);

private:
	enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};
	GLuint program_ = 0;
	GLuint shaders_[2] = {0};
	std::unordered_map<std::string, GLint> uniforms_;
	std::unordered_map<std::string, GLint> attributes_;
};

#endif