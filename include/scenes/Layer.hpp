#pragma once

class Object2D;

class Layer
{
public:
	Layer(const std::string& layerName);
	~Layer();
	
	template<typename T>
	T* AddObject(const std::string& objectName);

	inline std::string GetName() const
	{
		return m_LayerName;
	}
private:


	std::vector<std::shared_ptr<Object2D>> m_v_Objects;

	std::string m_LayerName;

};
template<typename T>
T* Layer::AddObject(const std::string& objectName)
{
	static_assert(std::is_base_of<Object2D, T>::value, "T does not derrive from Object2D");

	auto& obj = std::make_shared<T>(objectName);
	m_v_Objects.push_back(obj);


	return obj.get();
}