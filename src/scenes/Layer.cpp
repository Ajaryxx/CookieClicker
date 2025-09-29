#include "PCH.hpp"
#include "scenes/Layer.hpp"
#include "shapes/Object2D.hpp"

Layer::Layer(const std::string& layerName)
{
	this->m_LayerName = layerName;
}
Layer::~Layer()
{

}
std::shared_ptr<Object2D> Layer::GetObject(const std::string& objectName)
{
	for (const auto& item : m_v_Objects)
	{
		if (item.get()->GetName() == objectName)
			return item;
	}

	spdlog::warn("Couldnt find object from Layer: {} Object: {}", m_LayerName, objectName);
	return nullptr;
	
}
void Layer::RemoveObject(const std::string& objectName)
{
	for (auto it = m_v_Objects.begin(); it != m_v_Objects.end(); it++)
	{
		if (it->get()->GetName() == objectName)
		{
			m_v_Objects.erase(it);
			return;
		}
	}
	spdlog::warn("Couldnt remove object from Layer {}; Object:", m_LayerName, objectName);
}
