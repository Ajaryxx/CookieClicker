#pragma once
#include "utility/GameValueDefines.hpp"

class VertexBuffer2D
{
public:
	VertexBuffer2D(uint8 numVerts, void* data, GLenum usage);

	~VertexBuffer2D();

	void bind();
	void unbind();

	void UpdateData(const VertexBuffer2DInfo& newInfo);
private:
	GLuint m_bufferID;
	GLuint m_vao;
};