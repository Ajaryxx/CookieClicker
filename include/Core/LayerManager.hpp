#pragma once
#include "Utilities.hpp"
#include "Core/Layer.hpp"

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
		virtual ~LayerManager() = default;

		inline const std::vector<LayerSpecification>& GetSceneLayers() const { return m_vecLayers; }
		// Returns a pointer to the layer with the specified name, or nullptr if not found.
		const CC::Layer* GetLayer(const std::string& LayerName) const;

	protected:
		void PushLayer(const std::string& LayerName, uint8 zOrder);
		void EraseLayer(const std::string& LayerName);
	private:
		void SortLayersByZOrder();

	private:
		std::vector<LayerSpecification> m_vecLayers;

	};
}
