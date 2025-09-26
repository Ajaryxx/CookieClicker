#pragma once
#include "utility/GameValueDefines.hpp"
#include "shapes/Object2D.hpp"

class RectangleShape : public Object2D
{
public:
	RectangleShape(const std::string& objectName, const glm::vec2& size = glm::vec2(0.f));
	~RectangleShape();

	inline glm::vec2 GetSize() const
	{
		return m_Size;
	}

	void SetSize(const glm::vec2& newSize);
	virtual glm::vec2 GetScale() const override
	{
		return m_factor;
	}
	void SetScale(const glm::vec2& factor) override;
private:

	glm::vec2 m_Size;
	glm::vec2 m_factor;

};