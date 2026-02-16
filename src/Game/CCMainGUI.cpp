#include "PCH.hpp"
#include "Game/CCMainGUI.hpp"
#include "Core/Application.hpp"

CC::Game::CCMainGUI::~CCMainGUI()
{
	CCLOG("CCMainGUI Destroyed Successfully!");
}

void CC::Game::CCMainGUI::Start()
{
	LoadGUIFromFile("C:\\Users\\joelf\\Documents\\gui-builder\\CookieClicker\\MainGUI.txt");


}

void CC::Game::CCMainGUI::Destroy()
{
}
