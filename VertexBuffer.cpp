#include "VertexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &id);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}
void VertexBuffer::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::setData(const float* vertices, const size_t count) const
{
	glBufferData(GL_ARRAY_BUFFER, count, vertices, GL_STATIC_DRAW);
}