#pragma once

class Camera2D
{
public:
	Camera2D(float right, float bottom);
	~Camera2D();

	inline glm::mat4 GetViewProjetion() const
	{
		return proj * view;
	}
private:
	glm::mat4 proj;
	glm::mat4 view;

};