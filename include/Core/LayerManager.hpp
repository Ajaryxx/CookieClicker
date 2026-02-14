#pragma once
#include "BaseValues.hpp"

namespace CC
{
	class Layer;

	struct LayerSpecification
	{
		uint8 zOrder;
		std::unique_ptr<Layer> layer;
	};


	class LayerManager
	{
	public:
		LayerManager() = default;
		~LayerManager() = default;


	//protected:
		void PushLayer(const std::string& LayerName, uint8 zOrder);
		void EraseLayer(const std::string& LayerName);
	private:
		void SortLayersByZOrder();

	private:
		std::vector<LayerSpecification> m_vecLayers;

	};
}
