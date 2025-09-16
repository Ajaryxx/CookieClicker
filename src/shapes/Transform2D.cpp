#include "PCH.hpp"
#include "shapes/Transform2D.hpp"

Transform2D::Transform2D(const glm::vec2& position, float rotaion, const glm::vec2 scale)
{
	this->m_Position = position;
	this->m_Rotation = glm::radians(rotaion);
	this->m_Scale = scale;
	this->m_ModelMatrix = glm::mat4(1.f);

	UpdateModelMatrix();

}
void Transform2D::SetPosition(const glm::vec2& newPosition)
{
	this->m_Position = newPosition;
	UpdateModelMatrix();
}

void Transform2D::SetOffset(const glm::vec2 offset)
{
	this->m_Position += offset;
	UpdateModelMatrix();
}

void Transform2D::SetRotation(float newRotation)
{
	this->m_Rotation = glm::radians(newRotation);
	UpdateModelMatrix();
}

void Transform2D::SetScale(const glm::vec2& newScale)
{
	this->m_Scale = newScale;
	UpdateModelMatrix();
}

void Transform2D::UpdateModelMatrix()
{
	m_ModelMatrix = glm::mat4(1.f);

	m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(m_Position, 0.f));
	m_ModelMatrix = glm::rotate(m_ModelMatrix, m_Rotation, glm::vec3(0.f, 0.f, 1.f));
	m_ModelMatrix = glm::scale(m_ModelMatrix, glm::vec3(m_Scale, 1.f));
}
