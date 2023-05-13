#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

namespace FileRead
{
	extern std::ostream& os;
	extern std::istream& is;
	
	std::ifstream& GetFile(std::string fname);
	std::shared_ptr<std::vector<std::string>> ReadFile(std::ifstream& file);
	void OutputFile(std::shared_ptr<std::vector<std::string>> out);
}