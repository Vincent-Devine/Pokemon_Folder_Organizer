#include "Display.hpp"
#include <iostream>


namespace Display
{
	void ClearConsole()
	{
		system("cls");
	}

	void DisplayTitle()
	{
		std::cout << "  _____      _        ____  _           _            " << std::endl;
		std::cout << " |  __ \\    | |      |  _ \\(_)         | |           " << std::endl;
		std::cout << " | |__) |__ | | _____| |_) |_ _ __   __| | ___ _ __  "<< std::endl;
		std::cout << " |  ___/ _ \\| |/ / _ \\  _ <| | '_ \\ / _` |/ _ \\ '__| " << std::endl;
		std::cout << " | |  | (_) |   <  __/ |_) | | | | | (_| |  __/ |    " << std::endl;
		std::cout << " |_|   \\___/|_|\\_\\___|____/|_|_| |_|\\__,_|\\___|_|    " << std::endl;
		std::cout << std::endl;
	}

	void AskPokemon()
	{
		std::cout << "Enter pokemon name (ex: nemtwo), pokedex number (ex: 150) or the extension number of the card (ex: sv2a 183)." << std::endl;
		std::cout << "Or type 'exit' to quit the application." << std::endl;
	}

	void DisplayWrongPokemon()
	{
		std::cout << std::endl;
		std::cout << "Pokemon name, pokedex number or extension number of the card is not recognize." << std::endl;
		std::cout << "Please, check the input and retry." << std::endl;
	}

	void DisplayCardInformation(Utils::CardInformation cardInformation)
	{
		std::cout << std::endl;
		std::cout << "Pokemon name (fr): " << cardInformation.frenchName << std::endl;
		std::cout << "Pokemon name (jp): " << cardInformation.japaneseName << std::endl;
		std::cout << "Pokemon pokedex number: " << cardInformation.pokedexNumber << std::endl;
	}

	const std::string DisplayPosition(const unsigned int position, const unsigned int row)
	{
		if (row == 0) return " BINDER";

		switch (position)
		{
		case 1:
			if (row == 1) return " |x| | |";
			if (row == 2) return " | | | |";
			if (row == 3) return " | | | |";
			break;

		case 2:
			if (row == 1) return " | |x| |";
			if (row == 2) return " | | | |";
			if (row == 3) return " | | | |";
			break;

		case 3:
			if (row == 1) return " | | |x|";
			if (row == 2) return " | | | |";
			if (row == 3) return " | | | |";
			break;

		case 4:
			if (row == 1) return " | | | |";
			if (row == 2) return " |x| | |";
			if (row == 3) return " | | | |";
			break;

		case 5:
			if (row == 1) return " | | | |";
			if (row == 2) return " | |x| |";
			if (row == 3) return " | | | |";
			break;

		case 6:
			if (row == 1) return " | | | |";
			if (row == 2) return " | | |x|";
			if (row == 3) return " | | | |";
			break;

		case 7:
			if (row == 1) return " | | | |";
			if (row == 2) return " | | | |";
			if (row == 3) return " |x| | |";
			break;

		case 8:
			if (row == 1) return " | | | |";
			if (row == 2) return " | | | |";
			if (row == 3) return " | |x| |";
			break;

		case 9:
			if (row == 1) return " | | | |";
			if (row == 2) return " | | | |";
			if (row == 3) return " | | |x|";
			break;

		default:
			break;
		}
	}

	void DisplayBinderInformation(Utils::BinderInformation BinderInformation)
	{
		std::string isFront = "front";
		if (!BinderInformation.isFront)
			isFront = "back ";

		std::cout << std::endl;
		std::cout << "Binder   |: " << BinderInformation.binder << "      " << DisplayPosition(BinderInformation.position, 0) << std::endl;
		if (BinderInformation.page > 9) std::cout << "Page     |: " << BinderInformation.page << "     " << DisplayPosition(BinderInformation.position, 1) << std::endl;
		else std::cout << "Page     |: " << BinderInformation.page << "      " << DisplayPosition(BinderInformation.position, 1) << std::endl;
		std::cout << "Face     |: " << isFront << " " << " " << DisplayPosition(BinderInformation.position, 2) << std::endl;
		std::cout << "Position |: " << BinderInformation.position << "      " << DisplayPosition(BinderInformation.position, 3) << std::endl;
	}

	void DisplayAskAgain()
	{
		std::cout << std::endl;
		std::cout << "Click on 'Enter' button for new pokemon card" << std::endl;
		std::cout << "Or type 'exit' to quit the application." << std::endl;
	}
}