#pragma once
class Texture
{
public:
	Texture(const char* file_path, unsigned int color);
	~Texture();

	void bind() const;
	void unBind() const;
	void activate() const;
	static void setFlipVerticallyOnLoad(bool value=true);
	unsigned int getNumber() const;
private:
	unsigned int id;
	unsigned int number;
	static unsigned int count;
	unsigned int color;
};

