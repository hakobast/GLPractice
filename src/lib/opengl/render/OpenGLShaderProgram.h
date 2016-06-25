//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include <unordered_map>

#include "../../core/render/ShaderProgram.h"
#include "../../core/render/VertexAttributeLocation.h"
#include "../OpenGL.h"

class OpenGLShaderProgram : public ShaderProgram{
public:
	OpenGLShaderProgram();
	virtual ~OpenGLShaderProgram();
	virtual void bind();
	virtual void unbind();
	virtual void setMat4x4(const std::string& name, const float* value);
	virtual void setInt(const std::string& name, int value);
	virtual void setFloat(const std::string& name, float value);
	virtual void setColor(const std::string& name, const Color& color);

	void loadShaderFromString(GLenum shader_type, const char* source, int length);
	void createProgram();
	void linkProgram();
	void bindAttribute(const std::string &name, uint32_t index);
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