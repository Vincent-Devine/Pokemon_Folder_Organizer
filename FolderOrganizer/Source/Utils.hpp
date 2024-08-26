#pragma once

#include <string>
#include <map>

namespace Utils
{
	struct PokemonLocation
	{
		unsigned int folder;
		unsigned int page;
		bool isFront;
		unsigned int position;
	};

	const int CARD_BY_BINDER = 360;
	const unsigned int CARD_PER_PAGE = 18;
	const unsigned int CARD_PER_FACE = 9;
	const unsigned int MAX_POKEMON_ID = 649;
	const std::string EXIT = "exit";

	bool StringIsInt(const std::string& input, unsigned int& value);
	unsigned int GetKeyByValue(const std::map<unsigned int, std::string>& map, const std::string& value);
	void SetLowerCase(std::string& str);
	std::string SetCapilizeFirstLetter(const std::string& str);
}