#include "PCH.hpp"
#include "scenes/BaseScene.hpp"
#include "shapes/RectangleShape.hpp"

BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
}

std::shared_ptr<Layer> BaseScene::AddLayer(const std::string& layerName, uint8 layerIndex)
{
	auto& layer = std::make_shared<Layer>(layerName);
	m_v_Layers.insert(m_v_Layers.begin() + layerIndex, std::make_pair(layerIndex, layer));

	SortLayers();
	return layer;
}
std::shared_ptr<Layer> BaseScene::GetLayerWithName(const std::string& layerName)
{
	for (const auto& item : m_v_Layers)
	{
		if (item.second->GetName() == layerName)
			return item.second;
	}

	return nullptr;
}
void BaseScene::SortLayers()
{
	uint8 counter = 0;
	for (auto& item : m_v_Layers)
	{
		item.first = counter;
		counter++;
	}
}