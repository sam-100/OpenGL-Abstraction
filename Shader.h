#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char* vertex_shader_path, const char* fragment_shader_path);
	~Shader();
	void use() const;
	void setInt(const char* name, int value) const;
	void setFloat(const char* name, float value) const;
	void setVec4(const char* name, const glm::vec4 &value) const;
	void setMat4(const char* name, const glm::mat4 &value) const; 

private:
	unsigned int id;
	int checkCompileErrors(unsigned int vertex_shader, unsigned int fragment_shader) const;
	int checkLinkErrors() const;
};

