#pragma once
#include "Core/GUIBase.hpp"

namespace CC::Game
{
	class CCMainGUI : public CC::GUIBase
	{
	public:
		CCMainGUI(sf::RenderWindow& window) : GUIBase(window) { CCLOG("CCMainGUI Initialized Successfully!"); }
		~CCMainGUI();
		virtual void Start() override;
		virtual void Destroy() override;

	};
}