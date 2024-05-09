#pragma once
class IndexBuffer
{
public:
	IndexBuffer();
	~IndexBuffer();

	void bind() const;
	void unBind() const;
	void setData(const unsigned int* vertices, const size_t count) const;

private:
	unsigned int id;
};

