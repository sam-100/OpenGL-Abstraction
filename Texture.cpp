#include "Texture.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


unsigned int Texture::count = 0;

Texture::Texture(const char* file_path, unsigned int color)
{
	glGenTextures(1, &id);
	number = count;
	count++;
	this->color = color;

	// LOAD THE TEXTURE 
	unsigned char* data;
	int width, height, nrChannels;
	bind();

	const char* file_name = file_path;

	data = stbi_load(file_name, &width, &height, &nrChannels, 0);
	if (data)
	{	
		
		glTexImage2D(GL_TEXTURE_2D, 0, color, width, height, 0, color, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture!" << std::endl;
	}
	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}


void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, id) ;
}
void Texture::unBind() const
{
	glBindBuffer(GL_TEXTURE_2D, 0);
}

void Texture::activate() const
{
	glActiveTexture(GL_TEXTURE0 + number);
}


void Texture::setFlipVerticallyOnLoad(bool value)
{
	stbi_set_flip_vertically_on_load(value);
}

unsigned int Texture::getNumber() const
{
	return number;
}