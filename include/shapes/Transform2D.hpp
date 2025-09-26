#pragma once

class Transform2D
{
public:
	Transform2D(const glm::vec2& position = glm::vec2(0.f), 
		float rotaion = 0.f, 
		const glm::vec2 scale = glm::vec2(1.f));
	~Transform2D() { };

public:
	//Getter

	inline virtual glm::vec2 GetPosition() const
	{
		return m_Position;
	}
	inline virtual float GetRotaion() const
	{
		return m_Rotation;
	}
	inline virtual glm::vec2 GetScale() const
	{
		return m_Scale;
	}
	inline virtual glm::mat4 GetModelMatrix() const
	{
		return m_ModelMatrix;
	}
	//Setter

	virtual void SetPosition(const glm::vec2& newPosition);
	virtual void SetOffset(const glm::vec2 offset);
	virtual void SetRotation(float newRotation);
	virtual void SetScale(const glm::vec2& newScale);

protected:

	void UpdateModelMatrix();

private:

	glm::vec2 m_Position;
	float m_Rotation;
	glm::vec2 m_Scale;

	glm::mat4 m_ModelMatrix;

};