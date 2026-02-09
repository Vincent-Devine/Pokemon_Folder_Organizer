#pragma once
#include "Utils.hpp"

namespace Display
{
	void ClearConsole();
	void DisplayTitle();
	void AskPokemon();
	void DisplayWrongPokemon();
	void DisplayBinderInformation(Utils::BinderInformation BinderInformation);
	void DisplayCardInformation(Utils::CardInformation cardInformation);
	void DisplayAskAgain();
}