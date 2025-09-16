#pragma once
#include "shapes/Transform2D.hpp"
#include "shapes/Drawable.hpp"
#include "utility/GameValueDefines.hpp"


class VertexBuffer2D;
class Shader;


/*Base class for every object in a scene*/
/*NOTE: VertexData will be copied, you can delete YOUR vertexBuffer after creation*/
class GameObject2D : public Transform2D, public Drawable
{
public:
	GameObject2D(const std::string& objectName, 
		const VertexBuffer2DInfo& vbInfo,
		GLenum drawMode,
		const Transformation2D& transformation = Transformation2D{glm::vec2(0.f), 0.f, glm::vec2(1.f)});
	~GameObject2D();
	

	

private:

	virtual void draw() override;

private:

	std::string m_ObjectName;

	std::unique_ptr<VertexBuffer2D> m_vertexBuffer;
	std::unique_ptr<Shader> m_shader;

	Vertex2D* m_VertexData = nullptr;
	GLenum m_drawMode;

	VertexBuffer2DInfo m_vbInfo;
};