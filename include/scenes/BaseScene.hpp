#pragma once
#include "scenes/Layer.hpp"
#include "utility/GameValueDefines.hpp"


class Layer;


class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	

	virtual void Start() {};
	virtual void Update(float deltaTime) {};



	std::shared_ptr<Layer> AddLayer(const std::string& layerName, uint8 layerIndex);
	std::shared_ptr<Layer> GetLayerWithName(const std::string& layerName);

	inline const std::vector<std::pair<uint8, std::shared_ptr<Layer>>>& GetSceneLayers() const
	{
		return m_v_Layers;
	}

private:
	void SortLayers();

private:
	std::vector<std::pair<uint8, std::shared_ptr<Layer>>> m_v_Layers;
	

};