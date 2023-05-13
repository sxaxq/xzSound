#pragma once

#include <vector>
#include <fstream>

namespace SapperGame
{
	enum DisplayMode
	{
		Show,
		NoShow
	};

	void DrawMap(std::vector<std::string>& map, DisplayMode dm);
	void LoadMap(std::ifstream file, std::vector<std::string>& loadVector);
	void PrintXY(std::vector<std::string>& map, int x, int y);
	bool IsMine(std::vector<std::string>& map, int stepX, int stepY);
}