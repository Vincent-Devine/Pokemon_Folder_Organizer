#pragma once
#include <string>
#include "Utils.hpp"

namespace JsonReader
{
	bool GetPokemonPokedex(const std::string& extension, const std::string& number, unsigned int& pokedex);
	bool GetPokemonPokedexAndJapaneseName(const std::string& name, unsigned int& pokedex, std::string& japaneseName);
	bool GetPokemonName(const unsigned int pokedex, std::string& frenchName, std::string& japaneseName);

	const std::string GetPokemonGen(const unsigned int pokedex);
}