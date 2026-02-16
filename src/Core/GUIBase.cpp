#include "PCH.hpp"
#include "Core/GUIBase.hpp"

CC::GUIBase::~GUIBase()
{

}

void CC::GUIBase::LoadGUIFromFile(const std::string& filePath)
{
	m_GUI.loadWidgetsFromFile(filePath);
}
