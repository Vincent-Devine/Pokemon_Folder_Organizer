#include <iostream>
#include <windows.h>
#include "OMLogger/Logger.hpp"
#include "Display.hpp"
#include "Utils.hpp"
#include "Card.hpp"
#include "Binder.hpp"
#include "UnitTest.hpp"

void GetInput(std::string& input)
{
	std::getline(std::cin, input);
	Utils::SetLowerCase(input);
}

bool CheckExit(const std::string& str)
{
	return str == "exit";
}

bool ValideInput(const std::string& str)
{
	return !str.empty();
}

bool CheckCard(const Utils::CardInformation& cardInformation)
{
	if(cardInformation.pokedexNumber == 0
	|| cardInformation.pokedexNumber > Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4 + Utils::GEN_5)
		return false;
	return true;
}

int main()
{
	std::string input = "";
	Utils::CardInformation cardInformation;

	SetConsoleOutputCP(CP_UTF8); // set console into UTF8 for pokemon japanese name
	OM::Logger::Logger::GetInstance()->SetDisplaySettings(OM::Logger::DisplayVerbosity); // config OMLogger display settings

	// Test::UnitTest();

	while (true)
	{
		Display::ClearConsole();
		Display::DisplayTitle();
		Display::AskPokemon();
		GetInput(input);
		if (CheckExit(input)) return 0;
		if (!ValideInput(input)) continue;

		cardInformation = Card::GetCardData(input, Card::DefinedInputType(input));
		if (CheckCard(cardInformation))
		{
			Display::DisplayCardInformation(cardInformation);
			Display::DisplayBinderInformation(Binder::GetBinderInformation(cardInformation.pokedexNumber));
		}
		else
		{
			Display::DisplayWrongPokemon();
		}


		Display::DisplayAskAgain();
		GetInput(input);
		if (CheckExit(input)) return 0;
	}

	return 0;
}