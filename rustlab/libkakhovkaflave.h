#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

void error(string msg)
{
	throw runtime_error(msg);
}