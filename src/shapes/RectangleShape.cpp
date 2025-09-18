#include "PCH.hpp"
#include "shapes/RectangleShape.hpp"

RectangleShape::RectangleShape(const std::string& objectName, const glm::vec2& size) : 
	Object2D(objectName, VertexBuffer2DInfo{4, RectangleVertexData, GL_DYNAMIC_DRAW }, GL_TRIANGLE_STRIP)
{
	this->m_Size = size;
	this->m_factor = glm::vec2(1.f);

	SetSize(m_Size);
}
RectangleShape::~RectangleShape()
{

}
void RectangleShape::SetSize(const glm::vec2& newSize)
{
	this->m_Size = newSize;
	Transform2D::SetScale(m_Size * m_factor);
}
void RectangleShape::SetScale(const glm::vec2& factor)
{
	this->m_factor = factor;
	Transform2D::SetScale(m_Size * m_factor);
}
