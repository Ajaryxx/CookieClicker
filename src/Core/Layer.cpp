#include "PCH.hpp"
#include "Core/Layer.hpp"
#include "Core/Application.hpp"

CC::Layer::~Layer()
{
	CCLOG("{} Destroyed!", m_LayerName.c_str());
}

void CC::Layer::PushDrawable(sf::Drawable* drawable)
{
	m_vecDrawables.push_back(drawable);
}

void CC::Layer::EraseDrawable(sf::Drawable* drawable)
{
	auto find = std::find(m_vecDrawables.begin(), m_vecDrawables.end(), drawable);
	if (find != m_vecDrawables.end())
	{
		m_vecDrawables.erase(find);
	}
}
