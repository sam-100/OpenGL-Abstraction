#pragma once
class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void bind() const;
	void unBind() const;
	void setData(const float* vertices, const size_t count) const;

private:
	unsigned int id;
};

