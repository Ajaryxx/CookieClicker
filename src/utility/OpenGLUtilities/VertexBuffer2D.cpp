#include "PCH.hpp"
#include "utility/OpenGLUtilities/VertexBuffer2D.hpp"

VertexBuffer2D::VertexBuffer2D(uint8 numVerts, void* data, GLenum usage)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(Vertex2D), data, usage);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(struct Vertex2D, position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(struct Vertex2D, texCoords));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(struct Vertex2D, color));

	unbind();
	
}
VertexBuffer2D::~VertexBuffer2D()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_bufferID);
}
void VertexBuffer2D::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	glBindVertexArray(m_vao);
}
void VertexBuffer2D::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexBuffer2D::UpdateData(const VertexBuffer2DInfo& newInfo)
{
	bind();

	void* addressLoc = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	std::memcpy(addressLoc, newInfo.vertexData, sizeof(Vertex2D) * newInfo.numVertecies);

	glUnmapBuffer(GL_ARRAY_BUFFER);

	unbind();
}