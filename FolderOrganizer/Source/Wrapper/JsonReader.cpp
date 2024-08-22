#include "JsonReader.hpp"

#include <fstream>
#include <iostream>

#include "../Core/Log.hpp"
#include "../Core/Utils.hpp"

namespace Wrapper
{
	JsonReader* JsonReader::singleton = nullptr;

	JsonReader* JsonReader::Get()
	{
		if (!singleton)
			singleton = new JsonReader;
		return singleton;
	}

	std::map<unsigned int, std::string> JsonReader::GetPokedex(const std::string& fileName)
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

			// French name
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

		LOG("pokedex finish to read", LogLevel::Validation);

		return pokedex;
	}

	std::string JsonReader::GetValue(const std::string& line, const std::string& key, int decal)
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
}