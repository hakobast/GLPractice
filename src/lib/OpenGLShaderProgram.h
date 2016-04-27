//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include "ShaderProgram.h"
#include <SFML/OpenGL.hpp>
#include <unordered_map>

class OpenGLShaderProgram : public ShaderProgram{
public:
	OpenGLShaderProgram();
	virtual ~OpenGLShaderProgram();
	virtual void bind();
	virtual void unbind();
	virtual void setMat4x4(const std::string& name, const float* value);

	void loadShaderFromString(GLenum shader_type, const char* source, int length);
	void createAndLinkProgram();
	GLuint getProgram() const;
	GLint getUniformLocation(const std::string& name);
	GLint getAttributeLocation(const std::string& name);

private:
	enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};
	GLuint program_;
	GLuint shaders_[2];
	std::unordered_map<std::string, GLint> uniforms;
};

#endif