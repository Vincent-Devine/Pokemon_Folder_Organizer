#include "UI.hpp"

#include <iostream>

namespace UI
{
	void AskPokemonIdOrName()
	{
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Enter pokemon name or id (max gen 5): " << std::endl;
		std::cout << "Enter '" << Utils::EXIT << "' to exit: " << std::endl;
		std::cout << "Input: ";
	}

	void WrongPokemonIdOrName()
	{
		std::cout << "Pokemon id or name is wrong" << std::endl;
	}

	void DisplayPokemonLocation(const unsigned int id, const std::string& name, const Utils::PokemonLocation& pokemonLocation)
	{
		std::string face = "front";
		if (!pokemonLocation.isFront)
			face = "back";

		std::cout << "Pokemon id: " << id << std::endl;
		std::cout << "Pokemon name: " << name << std::endl;
		std::cout << "Pokemon card location: \n"
			"FOLDER |" + std::to_string(pokemonLocation.folder) + "\n"
			"PAGE   |" + std::to_string(pokemonLocation.page) + "\n"
			"FACE   |" + face + "\n"
			"POS    |" + std::to_string(pokemonLocation.position)
			<< std::endl;
	}
}