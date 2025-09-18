#include "PCH.hpp"
#include "shapes/Object2D.hpp"
#include "utility/OpenGLUtilities/VertexBuffer2D.hpp"
#include "utility/OpenGLUtilities/Shader.hpp"
#include "utility/OpenGLUtilities/Texture.hpp"
#include "utility/OpenGLUtilities/Camera.hpp"
#include "shaders/Shaders.hpp"

Object2D::Object2D(const std::string& objectName, const VertexBuffer2DInfo& vbInfo, GLenum drawMode) :
	Transform2D()
{
	this->m_ObjectName = objectName;
	this->m_vbInfo = vbInfo;
	this->m_drawMode = drawMode;
	this->m_texture = nullptr;
	this->m_objectState |= ObjectState::NONE_STATE;

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

void Object2D::SetTexture(std::unique_ptr<Texture> newTexture)
{
	const int unifUseTex = m_shader->GetUniformLocation("u_useTexture");
	const int unifSampler = m_shader->GetUniformLocation("u_sampler");

	if (!newTexture)
	{
		m_texture = nullptr;
		m_objectState &= ~ObjectState::USE_TEXTURE;
		glUniform1i(unifUseTex, 0);
		
		return;
	}


	m_texture = std::move(newTexture);
	m_objectState |= ObjectState::USE_TEXTURE;
	m_shader->bind();

	glUniform1i(unifSampler, 0);
	glUniform1i(unifUseTex, 1);

	m_shader->bind();
}

void Object2D::draw()
{

	if (m_objectState & ObjectState::INVISIBLE)
		return;

	m_vertexBuffer->bind();
	m_shader->bind();

	if (m_objectState & ObjectState::USE_TEXTURE)
		m_texture->bind();

	Camera2D cam(800, 600);
	int a = glGetUniformLocation(m_shader->GetShaderID(), "u_mvp");
	glUniformMatrix4fv(a, 1, GL_FALSE, glm::value_ptr(cam.GetViewProjetion() * GetModelMatrix()));
	glDrawArrays(m_drawMode, 0, m_vbInfo.numVertecies);

	if (m_objectState & ObjectState::USE_TEXTURE)
		m_texture->unbind();

	m_shader->unbind();
	m_vertexBuffer->unbind();
}