#pragma once

#include <map>
#include <string>

namespace Wrapper
{
	std::map<unsigned int, std::string> GetPokedex(const std::string& fileName);
}