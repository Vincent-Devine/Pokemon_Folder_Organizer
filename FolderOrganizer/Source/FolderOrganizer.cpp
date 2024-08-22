#include <iostream>

#include "Core/Log.hpp"
#include "Core/Utils.hpp"
#include "Core/Folder.hpp"
#include "Wrapper/JsonReader.hpp"

int main()
{
	Wrapper::JsonReader* jsonReader = Wrapper::JsonReader::Get();
	std::map<unsigned int, std::string> pokedex = jsonReader->GetPokedex("Asset/pokedex.json");

	std::string input = "";
	bool finishUpdate = true;
	while (finishUpdate)
	{
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "Enter pokemon name or id (or 'quit' to exit): " << std::endl;
		std::cout << "input: ";
		std::getline(std::cin, input);

		std::cout << "--" << std::endl;

		int value = 0;
		if (Utils::StringIsInt(input, value)) // ID
		{
			if (value > Utils::MAX_POKEMON_ID)
			{
				std::cout << "Pokemon id is wrong! (max gen 5)" << std::endl;
				continue;
			}

			std::cout << "Pokemon name: " + Utils::SetCapilizeFirstLetter(pokedex[value]) << std::endl;
			std::cout << "Pokemon id: " << value << std::endl;
			std::cout << Core::GetPokemonLocation(value) << std::endl;
		}
		else                                  // NAME
		{
			Utils::SetLowerCase(input);
			if (input == "quit")
			{
				finishUpdate = false;
				continue;
			}

			unsigned int id = Utils::GetKeyByValue(pokedex, input);
			if (id == 0)
			{
				std::cout << "Pokemon name is wrong!" << std::endl;
				continue;
			}
			else
			{
				if (value > Utils::MAX_POKEMON_ID)
				{
					std::cout << "Pokemon id is wrong! (max gen 5)" << std::endl;
					continue;
				}

				std::cout << "Pokemon id: " << id << std::endl;
				std::cout << "Pokemon name: " << Utils::SetCapilizeFirstLetter(pokedex[id]) << std::endl;
				std::cout << Core::GetPokemonLocation(id) << std::endl;
			}
		}
	}
}
