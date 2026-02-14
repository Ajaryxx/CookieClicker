#include "PCH.hpp"
#include "Core/LayerManager.hpp"
#include "Core/Layer.hpp"

void CC::LayerManager::PushLayer(const std::string& LayerName, uint8 zOrder)
{
	LayerSpecification spec{};
	spec.layer = std::make_unique<Layer>(LayerName);
	spec.zOrder = zOrder;
	m_vecLayers.push_back(std::move(spec));

	SortLayersByZOrder();
}

void CC::LayerManager::EraseLayer(const std::string& LayerName)
{
	auto it = std::find_if(m_vecLayers.begin(), m_vecLayers.end(), [&](const LayerSpecification& spec) { return spec.layer->GetLayerName() == LayerName; });
	if(it != m_vecLayers.end())
	{
		m_vecLayers.erase(it);
	}
}

void CC::LayerManager::SortLayersByZOrder()
{
	std::sort(m_vecLayers.begin(), m_vecLayers.end(), [](const LayerSpecification& a, const LayerSpecification& b) { return a.zOrder < b.zOrder; });
}
