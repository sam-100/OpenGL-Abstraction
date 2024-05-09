#include "VertexArray.h"
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &id);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id);
}

void VertexArray::bind() const
{
	glBindVertexArray(id);
}
void VertexArray::unBind() const
{
	glBindVertexArray(0);
}

void VertexArray::setLayout(const VertexLayout& layout) const
{
	bind();
	for (int i = 0; i < layout.getAttributeCount(); i++)
	{
		const Attribute& attribute = layout.getAttribute(i);
		glVertexAttribPointer(i, attribute.size, GL_FLOAT, GL_FALSE, layout.getStride(), attribute.pointer);
		glEnableVertexAttribArray(i);
	}
}