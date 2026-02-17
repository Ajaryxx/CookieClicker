#pragma once
#include <iostream>

#if defined(_WIN32)
//WINDOWS ONLY
//returns the result which button was pressed
inline int ShowMessageBox(HWND window, LPCSTR message, LPCSTR caption, UINT utype)
{
	return MessageBoxA(window, message, caption, utype);
}
#endif

inline std::string MakePath(std::initializer_list<std::string> list)
{
	std::string path;
	const std::string lastStr = *std::prev(list.end());

	for (const auto& item : list)
	{
		path.append(item);
		if (item != lastStr)
			path.append("\\");
	}

	return path;
}