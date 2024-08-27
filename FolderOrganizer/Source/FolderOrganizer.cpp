#include "FolderOrganizer.hpp"

#include <iostream>

#include "UI.hpp"
#include "Folder.hpp"
#include "JsonReader.hpp"
#include "Test.hpp"

int main()
{
	FolderOrganizer fo;
	fo.Start();
	fo.Update();
	fo.Delete();
}

void FolderOrganizer::Start()
{
	m_pokedex = Wrapper::GetPokedex("Asset/pokedex.json");
	Test::Test(m_pokedex);
}

void FolderOrganizer::Update()
{
	std::string input = "";
	std::string name = "";
	unsigned int id = 0;
	bool finishUpdate = true;

	while (finishUpdate)
	{
		UI::AskPokemonIdOrName();
		std::getline(std::cin, input);

		if (Utils::StringIsInt(input, id)) // USER GIVE AN ID
		{
			if (!CheckGoodPokemon(id))
			{
				UI::WrongPokemonIdOrName();
				continue;
			}
		}
		else                              // USER GIVE AN NAME
		{
			Utils::SetLowerCase(input);
			if (input == Utils::EXIT)
			{
				finishUpdate = false;
				continue;
			}

			id = Utils::GetKeyByValue(m_pokedex, input);
			if (!CheckGoodPokemon(id))
			{
				UI::WrongPokemonIdOrName();
				continue;
			}
		}

		name = Utils::SetCapilizeFirstLetter(m_pokedex[id]);
		Utils::PokemonLocation pokemonLocation = Core::GetPokemonLocation(id);
		UI::DisplayPokemonLocation(id, name, pokemonLocation);
	}
}

void FolderOrganizer::Delete()
{
	m_pokedex.clear();
}

bool FolderOrganizer::CheckGoodPokemon(const unsigned int id)
{
	if (id > Utils::MAX_POKEMON_ID || id == 0)
		return false;
	return true;
}