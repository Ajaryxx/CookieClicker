#pragma once
#include "Utilities.hpp"

namespace CC
{
	class Layer
	{
	public:
		Layer(const std::string& LayerName) : m_LayerName(LayerName) { }
		~Layer();


		void PushDrawable(sf::Drawable* drawable);
		void EraseDrawable(sf::Drawable* drawable);

		inline std::string GetLayerName() const { return m_LayerName; }
		inline const std::vector<sf::Drawable*>& GetDrawables() const { return m_vecDrawables; }
	private:

		std::vector<sf::Drawable*> m_vecDrawables;
		std::string m_LayerName;
	};
}
