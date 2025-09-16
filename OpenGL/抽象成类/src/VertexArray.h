#pragma once

#include "VertexBuffer.h"
#include "VErtexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_RenedererID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};