#include "IndexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

IndexBuffer::IndexBuffer()
{
	glGenBuffers(1, &id);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &id);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void IndexBuffer::unBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void IndexBuffer::setData(const unsigned int* vertices, const size_t count) const
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, vertices, GL_STATIC_DRAW);
}