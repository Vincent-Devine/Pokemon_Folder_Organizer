#include "Card.hpp"
#include <cctype>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "JsonReader.hpp"

namespace Card
{
	Utils::InputType DefinedInputType(const std::string& input)
	{
		if (std::all_of(input.begin(), input.end(), ::isdigit)) return Utils::InputType::pokedex;
		else if (std::all_of(input.begin(), input.end(), ::isalpha)) return Utils::InputType::name;
		else return Utils::InputType::extension;
	}

	Utils::CardInformation GetCardData(const std::string& input, Utils::InputType type)
	{
		Utils::CardInformation cardInformation;
		cardInformation.pokedexNumber = 0;

		if (type == Utils::InputType::pokedex)
		{
			cardInformation.pokedexNumber = std::stoi(input);
			JsonReader::GetPokemonName(cardInformation.pokedexNumber, cardInformation.frenchName, cardInformation.japaneseName);
		}
		else if (type == Utils::InputType::name)
		{
			std::string frenchName = input;
			Utils::SetFirstLetterCapitalize(frenchName);
			cardInformation.frenchName = frenchName;
			JsonReader::GetPokemonPokedexAndJapaneseName(cardInformation.frenchName, cardInformation.pokedexNumber, cardInformation.japaneseName);
		}
		else if (type == Utils::InputType::extension)
		{
			std::stringstream ss(input);
			std::string extension;
			std::string cardNumber;
			ss >> extension;
			ss >> cardNumber;

			if (extension.empty() || cardNumber.empty()) return cardInformation;

			JsonReader::GetPokemonPokedex(extension, cardNumber, cardInformation.pokedexNumber);
			JsonReader::GetPokemonName(cardInformation.pokedexNumber, cardInformation.frenchName, cardInformation.japaneseName);
		}

		return cardInformation;
	}
}