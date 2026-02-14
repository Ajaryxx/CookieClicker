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

		inline const std::vector<LayerSpecification>& GetLayers() { return m_vecLayers; }
		const Layer& GetLayer(const std::string& LayerName) const;

	//protected:
		void PushLayer(const std::string& LayerName, uint8 zOrder);
		void EraseLayer(const std::string& LayerName);
	private:
		void SortLayersByZOrder();

	private:
		std::vector<LayerSpecification> m_vecLayers;

	};
}
