#pragma once
#include "VertexLayout.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void bind() const;
	void unBind() const;
	void setLayout(const VertexLayout& layout) const;
private:
	unsigned int id;
};

