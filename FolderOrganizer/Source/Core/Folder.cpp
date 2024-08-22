#include "Folder.hpp"

#include "Utils.hpp"

namespace Core
{
	std::string GetPokemonLocation(unsigned int id)
	{
		unsigned int position = 0;
		unsigned int gen = GetFolderNum(id, position);
		
		unsigned int page = GetPage(position);
		position -= Utils::CARD_PER_PAGE * (page - 1);

		std::string face = "front";
		if (position > Utils::CARD_PER_FACE)
		{
			face = "back";
			position -= Utils::CARD_PER_FACE;
		}

		return "Pokemon card location: \n"
			"FOLDER |" + std::to_string(gen) + "\n"
			"PAGE   |" + std::to_string(page) + "\n"
			"FACE   |" + face + "\n"
			"POS    |" + std::to_string(position);
	}

	unsigned int GetFolderNum(unsigned int id, unsigned int& idInThisGeneration)
	{
		int temp = id;
		if ((temp - Utils::CARD_BY_BINDER) <= 0)
		{
			idInThisGeneration = id;
			return 1;
		}
		else
		{
			idInThisGeneration = id - Utils::CARD_BY_BINDER;
			return 2;
		}
	}

	unsigned int GetPage(unsigned int id)
	{
		return id / Utils::CARD_PER_PAGE + 1;
	}
}