#pragma once
#include "shapes/Transform2D.hpp"
#include "shapes/Drawable.hpp"
#include "utility/GameValueDefines.hpp"


class VertexBuffer2D;
class Shader;
class Texture;

/*Base class for every object in a scene*/
/*NOTE: VertexData will be copied, you can delete YOUR vertexBuffer after creation*/
/*You can choose your shader after the creation of this object*/
class Object2D : public Drawable, public Transform2D
{
public:
	Object2D(const std::string& objectName, 
		const VertexBuffer2DInfo& vbInfo,
		GLenum drawMode);
	~Object2D();
	

public:

	//Getter

	inline std::string GetName() const
	{
		return m_ObjectName;
	}

	inline Shader* GetShader() const
	{
		return m_shader.get();
	}
	
	//Setter

	void SetObjectColor(const Color& newColor);

	void SetTexture(std::unique_ptr<Texture> newTexture);

	virtual void draw() const override;

private:


	


	void UpdateBuffer();

private:


	std::string m_ObjectName;

	std::unique_ptr<VertexBuffer2D> m_vertexBuffer;
	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<Texture> m_texture;

	Vertex2D* m_VertexData = nullptr;
	GLenum m_drawMode;

	VertexBuffer2DInfo m_vbInfo;

	uint8 m_objectState = 0;
};