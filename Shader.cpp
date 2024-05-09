#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertex_shader_path, const char* fragment_shader_path)
{
	/* 1. Take the file input into a string */
	// open the files 
	std::ifstream vertex_file, fragment_file;
	// enable error handling 
	vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream vertex_stream, fragment_stream;
	std::string vertex_str, fragment_str;
	try
	{
		// open the files
		vertex_file.open(vertex_shader_path);
		fragment_file.open(fragment_shader_path);
	
		// copy content into a string-stream
		vertex_stream << vertex_file.rdbuf();
		fragment_stream << fragment_file.rdbuf();

		// copy it from string-stream into strings
		vertex_str = vertex_stream.str();
		fragment_str = fragment_stream.str();

		// close file handlers 
		vertex_file.close();
		fragment_file.close();

	}
	catch (std::ios_base::failure& e)
	{
		std::cout << "C++ File Error: "<<e.what() << std::endl;
	}

	// convert into c strings
	const char* vertex_src = vertex_str.c_str();
	const char* fragment_src = fragment_str.c_str();

	/* 2. Create the shaders and copy the source codes into them */
	// create shader objects
	unsigned int vertex_shader, fragment_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	// copy source code
	glShaderSource(vertex_shader, 1, &vertex_src, 0);
	glShaderSource(fragment_shader, 1, &fragment_src, 0);


	/* 3. Compile, Link and prepare the shader program */

	// compile shaders
	glCompileShader(vertex_shader);
	glCompileShader(fragment_shader);

	// check for compile errors
	checkCompileErrors(vertex_shader, fragment_shader);

	// link shaders 
	id = glCreateProgram();
	glAttachShader(id, vertex_shader);
	glAttachShader(id, fragment_shader);
	glLinkProgram(id);

	// check for linking errors
	checkLinkErrors();
	
	// delete shaders
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	
}


Shader::~Shader()
{
	glDeleteProgram(id);
}


void Shader::use() const
{
	glUseProgram(id);
}


void Shader::setInt(const char* name, int value) const
{
	glUniform1i(glGetUniformLocation(id, name), value);
}


void Shader::setFloat(const char* name, float value) const
{
	glUniform1f(glGetUniformLocation(id, name), value);
}


void Shader::setVec4(const char* name, const glm::vec4& value) const
{
	glUniform4f(glGetUniformLocation(id, name), value.x, value.y, value.z, value.w);
}

void Shader::setMat4(const char* name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, glm::value_ptr(value));
}


int Shader::checkCompileErrors( unsigned int vertex_shader, unsigned int fragment_shader) const
{
	int success;
	char infoLog[512];
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, 0, infoLog);
		std::cout << "Compile error for Vertex Shader" << std::endl;
		std::cout << "Error: " << infoLog << std::endl;
		return success;
	}
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, 0, infoLog);
		std::cout << "Compile error for Fragment Shader" << std::endl;
		std::cout << "Error: " << infoLog << std::endl;
		return success;
	}
	return 0;
}

int Shader::checkLinkErrors() const
{
	int success;
	char infoLog[512];
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(id, 512, 0, infoLog);
		std::cout << "Linking error" << std::endl;
		std::cout << "Error: " << infoLog << std::endl;
		return success;
	}
	return 0;
}