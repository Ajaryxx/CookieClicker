#pragma once
#include <iostream>

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