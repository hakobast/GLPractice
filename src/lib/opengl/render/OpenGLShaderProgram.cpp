//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include "OpenGLShaderProgram.h"

OpenGLShaderProgram::OpenGLShaderProgram() {
	shaders_[VERTEX_SHADER] = 0;
	shaders_[FRAGMENT_SHADER] = 0;
}

OpenGLShaderProgram::~OpenGLShaderProgram() {
	glDeleteProgram(program_);
	program_ = 0;

	printf("~OpenGLShaderProgram\n");
}

void OpenGLShaderProgram::loadShaderFromString(GLenum shader_type, const char* source, int length) {
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, &length);
	glCompileShader(shader);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		
		if (infoLogLength > 0) {
			GLchar* infoLog = new GLchar[infoLogLength];
			glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
			printf("Shader compilation log: %s\n", infoLog);

			delete[] infoLog;
		} else {
            printf("Shader compilation error\n");
		}

		glDeleteShader(shader);
		return;
	}

	if (shader_type == GL_VERTEX_SHADER) {
		shaders_[VERTEX_SHADER] = shader;
	}
	else if (shader_type == GL_FRAGMENT_SHADER) {
		shaders_[FRAGMENT_SHADER] = shader;
	}
}

void OpenGLShaderProgram::createAndLinkProgram() {
	program_ = glCreateProgram();

	if (shaders_[VERTEX_SHADER] != 0)
		glAttachShader(program_, shaders_[VERTEX_SHADER]);
	if (shaders_[FRAGMENT_SHADER] != 0)
		glAttachShader(program_, shaders_[FRAGMENT_SHADER]);

	glLinkProgram(program_);

	GLint status;
	glGetProgramiv(program_, GL_LINK_STATUS, &status);

	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 1) {
			GLchar* infoLog = new GLchar[infoLogLength];
			glGetProgramInfoLog(program_, infoLogLength, NULL, infoLog);
            printf("Program linking log: %s\n", infoLog);

			delete[] infoLog;
		} else {
            printf("Program linking error\n");
		}

		glDeleteProgram(program_);
	}

	glDeleteShader(shaders_[VERTEX_SHADER]);
	glDeleteShader(shaders_[FRAGMENT_SHADER]);
}

GLuint OpenGLShaderProgram::getProgram() const {
    return program_;
}

void OpenGLShaderProgram::bind() {
    glUseProgram(program_);
}

void OpenGLShaderProgram::unbind() {
    glUseProgram(0);
}

GLint OpenGLShaderProgram::getUniformLocation(const std::string& name) {
	GLint location;
	auto it = uniforms_.find(name);
	if(it != uniforms_.end()){
		location = it->second;
	}else{
		location = glGetUniformLocation(program_, name.c_str());
		uniforms_[name] = location;
	}

	return location;
}

GLint OpenGLShaderProgram::getAttributeLocation(const std::string& name){
	GLint location;
	auto it = attributes_.find(name);
	if(it != attributes_.end()){
		location = it->second;
	}else{
		location = glGetAttribLocation(program_, name.c_str());
		attributes_[name] = location;
	}

	return location;
}

void OpenGLShaderProgram::setAttribute(const std::string& name, uint32_t index){
	glBindAttribLocation(program_, index, name.c_str());
}

void OpenGLShaderProgram::setMat4x4(const std::string& name, const float* value){
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, value);
}
