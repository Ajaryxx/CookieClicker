#include "PCH.hpp"
#include "shapes/GameObject2D.hpp"
#include "utility/OpenGLUtilities/VertexBuffer2D.hpp"
#include "utility/OpenGLUtilities/Shader.hpp"
#include "utility/OpenGLUtilities/Camera.hpp"
#include "shaders/Shaders.hpp"

GameObject2D::GameObject2D(const std::string& objectName, const VertexBuffer2DInfo& vbInfo, GLenum drawMode, const Transformation2D& transformation) :
	Transform2D(transformation.position, transformation.rotation, transformation.scale)
{
	this->m_ObjectName = objectName;
	m_vbInfo = vbInfo;
	m_drawMode = drawMode;

	//copy pre defined const Vertex2D* data to the new vertex buffer
	m_VertexData = new Vertex2D[m_vbInfo.numVertecies];
	std::memcpy(m_VertexData, vbInfo.vertexData, sizeof(Vertex2D) * m_vbInfo.numVertecies);

	m_vertexBuffer = std::make_unique<VertexBuffer2D>(vbInfo.numVertecies, m_VertexData, vbInfo.usage);
	m_shader = std::make_unique<Shader>(BasicVertexShader, BasicFragmentShader);;

	SetScale({ 300, 300 });
}
GameObject2D::~GameObject2D()
{
	if (m_VertexData)
	{
		delete[] m_VertexData;
		m_VertexData = nullptr;
	}
}
void GameObject2D::draw()
{
	Camera2D cam(800, 600);
	m_vertexBuffer->bind();
	m_shader->bind();
	int a = glGetUniformLocation(m_shader->GetShaderID(), "u_mvp");
	glUniformMatrix4fv(a, 1, GL_FALSE, glm::value_ptr(cam.GetViewProjetion() * GetModelMatrix()));
	glDrawArrays(m_drawMode, 0, m_vbInfo.numVertecies);
	m_shader->unbind();
	m_vertexBuffer->unbind();
	
}