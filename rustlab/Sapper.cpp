#include "Sapper.h"
#include <iostream>
#include <string>

using namespace std;

namespace SapperGame
{
	void DrawMap(vector<string>& map, DisplayMode dm = Show)
	{
		cout << "   ";
		for (size_t j = 0; j <= 8; j++)
		{
			cout << j << " ";
		}

		cout << endl;

		for (size_t i = 0; i < map.size(); i++)
		{
			cout << i << "|";
			string line = map[i];

			for (size_t j = 0; j < line.size(); j++)
			{
				if (dm == Show && isdigit(line[j]))
				{
					cout << '.';
					continue;
				}
				cout << line[j];
			}

			cout << endl;
		}
	}

	void LoadMap(ifstream file, vector<string>& loadVector)
	{
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				loadVector.push_back(line);
			}
		}
	}

	void PrintXY(vector<string>& map, int x, int y)
	{
		if (x >= map.size())
		{
			cout << "not find its cells " << endl;
			return;
		}
		map[x][y] = '*';
		cout << "print done" << endl;
	}

	bool IsMine(std::vector<std::string>& map, int stepX, int stepY)
	{
		if (stepX >= map.size())
		{
			cout << "not find its cells " << endl;
			return false;
		}

		if (isdigit(map[stepX][stepY]))
		{
			cout << "You lose" << endl;
			DrawMap(map, NoShow);
			return true;
		}
		return false;
	}
}