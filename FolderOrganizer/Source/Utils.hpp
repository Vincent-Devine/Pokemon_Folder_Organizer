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

	const float CARD_BY_BINDER = 360.f;
	const int CARD_PER_PAGE = 18.f;
	const float CARD_PER_FACE = 9.f;
	const float MAX_POKEMON_ID = 649.f;
	const std::string EXIT = "exit";

	bool StringIsInt(const std::string& input, unsigned int& value);
	unsigned int GetKeyByValue(const std::map<unsigned int, std::string>& map, const std::string& value);
	void SetLowerCase(std::string& str);
	std::string SetCapilizeFirstLetter(const std::string& str);
}