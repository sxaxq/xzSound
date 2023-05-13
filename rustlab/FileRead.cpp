#include "FileRead.h"

using namespace std;

namespace FileRead
{
	ostream& os = cout;
	istream& is = cin;

	ifstream& GetFile(string name)
	{
		ifstream& file = *(new ifstream(name));
		return file;
	}

	shared_ptr<vector<string>> ReadFile(ifstream& file)
	{
		shared_ptr<vector<string>> readLines = std::make_shared<vector<string>>();

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				readLines->push_back(line);
			}
		}

		file.close();
		delete& file;
		return readLines;
	}

	void OutputFile(std::shared_ptr<std::vector<std::string>> out)
	{
		for (size_t i = 0; i < out->size(); i++)
		{
			os << i + 1 << ": " << out->at(i) << endl;
		}
	}
}