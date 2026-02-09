#include "JsonReader.hpp"
#include <fstream>
#include <string>
#include "OMLogger/Logger.hpp"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

namespace JsonReader
{
	bool GetPokemonPokedex(const std::string& extension, const std::string& number, unsigned int& pokedex)
	{
		std::ifstream file("Asset/" + extension + ".json");
		if (!file.is_open())
		{
			OM_LOG_WARNING("Extension name not supported");
			return false;
		}

		json data;
		file >> data;

		for (const auto& [key, value] : data.items())
		{
			for (const auto& pokemon : value)
			{
				if (pokemon["card_number"] == number)
				{
					pokedex = pokemon["pokedex_id"];
					return true;
				}
			}
		}
		return false;
	}

	bool GetPokemonPokedexAndJapaneseName(const std::string& name, unsigned int& pokedex, std::string& japaneseName)
	{
		std::ifstream file("Asset/pokedex.json");
		OM_ASSERTION(file.is_open(), "could not open file!");

		json data;
		file >> data;

		for (const auto& [key, value] : data.items())
		{
			for (const auto& pokemon : value)
			{
				if (pokemon["name_fr"] == name)
				{
					pokedex = pokemon["pokedex_id"];
					japaneseName = pokemon["name_jp"];
					return true;
				}
			}
		}
		return false;
	}

	bool GetPokemonName(const unsigned int pokedex, std::string& frenchName, std::string& japaneseName)
	{
		std::ifstream file("Asset/pokedex.json");
		OM_ASSERTION(file.is_open(), "could not open file!");

		json data;
		file >> data;

		for (const auto& pokemon : data[GetPokemonGen(pokedex)])
		{
			if (pokemon["pokedex_id"] == pokedex)
			{
				frenchName = pokemon["name_fr"];
				japaneseName = pokemon["name_jp"];
				return true;
			}
		}
		return false;
	}

	const std::string GetPokemonGen(const unsigned int pokedex)
	{
		if		(pokedex > Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4) return "gen5";
		else if (pokedex > Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3) return "gen4";
		else if (pokedex > Utils::GEN_1 + Utils::GEN_2) return "gen3";
		else if (pokedex > Utils::GEN_1) return "gen2";
		else return "gen1";
	}
}