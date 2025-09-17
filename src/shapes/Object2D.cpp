#include "PCH.hpp"
#include "shapes/Object2D.hpp"
#include "utility/OpenGLUtilities/VertexBuffer2D.hpp"
#include "utility/OpenGLUtilities/Shader.hpp"
#include "utility/OpenGLUtilities/Camera.hpp"
#include "shaders/Shaders.hpp"

Object2D::Object2D(const std::string& objectName, const VertexBuffer2DInfo& vbInfo, GLenum drawMode) :
	Transform2D()
{
	this->m_ObjectName = objectName;
	this->m_vbInfo = vbInfo;
	this->m_drawMode = drawMode;

	//copy the pre defined const Vertex2D* data to the new Vertex2D buffer
	this->m_VertexData = new Vertex2D[m_vbInfo.numVertecies];
	Vertex2D* newDataAddress = (Vertex2D*)std::memcpy(m_VertexData, vbInfo.vertexData, sizeof(Vertex2D) * m_vbInfo.numVertecies);
	this->m_vbInfo.vertexData = newDataAddress;

	this->m_vertexBuffer = std::make_unique<VertexBuffer2D>(vbInfo.numVertecies, m_VertexData, vbInfo.usage);
	this->m_shader = std::make_unique<Shader>(BasicVertexShader, BasicFragmentShader);;

}
Object2D::~Object2D()
{
	if (m_VertexData)
	{
		delete[] m_VertexData;
		m_VertexData = nullptr;
	}
}

void Object2D::SetObjectColor(const Color& newColor)
{
	const VertexBuffer2DInfo& vbi = m_vbInfo;

	for(size_t i = 0; i < m_vbInfo.numVertecies; i++)
		m_VertexData[i].color = newColor;

	m_vertexBuffer->UpdateData(vbi);
}

void Object2D::draw()
{
	m_vertexBuffer->bind();
	m_shader->bind();
	int a = glGetUniformLocation(m_shader->GetShaderID(), "u_mvp");
	glUniformMatrix4fv(a, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.f)));
	glDrawArrays(GL_TRIANGLES, 0, 3);
}