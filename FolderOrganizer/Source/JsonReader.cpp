#include "JsonReader.hpp"

#include <fstream>
#include <iostream>

#include "Log.hpp"
#include "Utils.hpp"

namespace Wrapper
{
	std::string GetValue(const std::string& line, const std::string& key, int decal)
	{
		unsigned int start = line.find(key);
		if (start == std::string::npos)
			return "";

		start = line.find(":", start);
		if (start == std::string::npos)
			return "";

		start += decal;
		unsigned int end = line.find("\"", start + 1);
		return line.substr(start + 1, end - start - 1);
	}

	std::map<unsigned int, std::string> GetPokedex(const std::string& fileName)
	{
		std::ifstream file(fileName);
		if (!file.is_open())
			LOG("Error opening file", LogLevel::Critical);

		std::string line = "";
		std::map<unsigned int, std::string> pokedex;
		unsigned int currentPokemonId = 0;
		std::string currentPokemonName = "";

		while (std::getline(file, line))
		{
			// ID
			if (line.find("\"id\"") != std::string::npos)
				currentPokemonId = std::stoi(GetValue(line, "\"id\"", 1));

			// Name (only french name)
			if (line.find("\"french\"") != std::string::npos)
			{
				currentPokemonName = GetValue(line, "\"french\"", 2);
				Utils::SetLowerCase(currentPokemonName);
			}

			if (currentPokemonId != 0 && !currentPokemonName.empty())
			{
				pokedex.insert(std::make_pair(currentPokemonId, currentPokemonName));
				LOG("Add Pokemon[" + std::to_string(currentPokemonId) + "]:" + currentPokemonName + " to pokedex.", LogLevel::Info);
				currentPokemonId = 0;
				currentPokemonName = "";
			}
		}

		file.close();
		LOG("Pokedex finish to read", LogLevel::Validation);
		return pokedex;
	}
}