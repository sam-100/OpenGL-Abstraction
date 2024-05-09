#include "VertexLayout.h"


VertexLayout::VertexLayout()
{
	stride = 0;
}

VertexLayout::~VertexLayout()
{

}

unsigned int VertexLayout::getAttributeCount() const
{
	return attributeList.size();
}
const Attribute& VertexLayout::getAttribute(unsigned int index) const
{
	return attributeList[index];
}
void VertexLayout::addAttribute(std::string name, const GLsizei size) 
{
	attributeList.push_back(Attribute(size, (void*)getStride()));
	stride += size;
}
GLsizei VertexLayout::getStride() const
{
	return stride*sizeof(float);
}

Attribute::Attribute(GLint size, GLvoid* pointer)
{
	this->size = size;
	this->pointer = pointer;
}
