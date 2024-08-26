#pragma once

#include "Utils.hpp"

namespace UI
{
	void AskPokemonIdOrName();
	void WrongPokemonIdOrName();
	void DisplayPokemonLocation(const unsigned int id, const std::string& name, const Utils::PokemonLocation& pokemonLocation);
}