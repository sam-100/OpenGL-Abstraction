#pragma once
#include <vector>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Attribute
{
	GLsizei size;
	GLvoid* pointer;

	Attribute(GLint size, GLvoid* pointer);
};
class VertexLayout
{
public:
	VertexLayout();
	~VertexLayout();

	unsigned int getAttributeCount() const;
	const Attribute& getAttribute(unsigned int index) const;
	void addAttribute(std::string name, const GLsizei size);
	GLsizei getStride() const;
private:
	std::vector<Attribute> attributeList;
	GLsizei stride;
};

