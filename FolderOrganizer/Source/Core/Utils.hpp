#pragma once

#include <string>
#include <map>
#include <vector>

namespace Utils
{
	const int CARD_BY_BINDER = 360;
	const unsigned int CARD_PER_PAGE = 18;
	const unsigned int CARD_PER_FACE = 9;
	const unsigned int MAX_POKEMON_ID = 649;

	bool StringIsInt(const std::string& input, int& value);
	unsigned int GetKeyByValue(const std::map<unsigned int, std::string>& map, const std::string& value);
	void SetLowerCase(std::string& str);
	std::string SetCapilizeFirstLetter(const std::string& str);
}