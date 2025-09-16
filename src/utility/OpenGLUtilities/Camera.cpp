#include "PCH.hpp"
#include "utility/OpenGLUtilities/Camera.hpp"

Camera2D::Camera2D(float right, float bottom)
{
	view = glm::mat4(1.f);
	proj = glm::ortho(0.f, right, bottom, 0.f, -0.1f, 1000.f);
}

Camera2D::~Camera2D()
{
}