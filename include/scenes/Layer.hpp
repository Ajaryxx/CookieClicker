#pragma once
#include "shapes/Drawable.hpp"

class Object2D;

class Layer
{
public:
	Layer(const std::string& layerName);
	~Layer();
	
	template<typename T>
	std::shared_ptr<T> AddObject(const std::string& objectName);

	void RemoveObject(const std::string& objectName);
	std::shared_ptr<Object2D> GetObject(const std::string& objectName);

	inline const std::vector<std::shared_ptr<Object2D>>& GetLayerObjects() const
	{
		return m_v_Objects;
	}

	inline std::string GetName() const
	{
		return m_LayerName;
	}
private:

	std::vector<std::shared_ptr<Object2D>> m_v_Objects;

	std::string m_LayerName;

};

template<typename T>
std::shared_ptr<T> Layer::AddObject(const std::string& objectName)
{
	static_assert(std::is_base_of<Object2D, T>::value, "T does not derrive from Object2D");

	auto& obj = std::make_shared<T>(objectName);
	m_v_Objects.push_back(obj);


	return obj;
}