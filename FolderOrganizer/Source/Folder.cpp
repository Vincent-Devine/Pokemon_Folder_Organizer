#include "Folder.hpp"

#include <cmath>

#include "Log_System/Log.hpp"

#include "Utils.hpp"

namespace Core
{
	const unsigned int GetFolder(unsigned int& position)
	{
		unsigned int blinderNeeded = static_cast<unsigned int>(std::ceil(Utils::MAX_POKEMON_ID / Utils::CARD_BY_BINDER));

		for (unsigned int i = 1; i < blinderNeeded + 1; i++)
		{
			if (position <= Utils::CARD_BY_BINDER * i)
				return i;

			position -= Utils::CARD_BY_BINDER;
		}

		LOG_WARNING("Wrong id given");
		return 0;
	}

	const unsigned int GetPage(unsigned int& position)
	{
		if (position == Utils::CARD_BY_BINDER || position % Utils::CARD_PER_PAGE == 0)
		{
			const unsigned int page = position / Utils::CARD_PER_PAGE;
			position = Utils::CARD_PER_PAGE;
			return page;
		}

		const unsigned int page = position / Utils::CARD_PER_PAGE;
		position -= Utils::CARD_PER_PAGE * page;
		return page + 1; // User start count at 1
	}

	const bool GetIsFront(unsigned int& position)
	{
		bool isFront = true;
		if (position > Utils::CARD_PER_FACE)
		{
			isFront = false;
			position -= Utils::CARD_PER_FACE;
		}

		return isFront;
	}

	Utils::PokemonLocation GetPokemonLocation(const unsigned int id)
	{
		unsigned int position = id;
		
		const unsigned int folder = GetFolder(position);
		const unsigned int page = GetPage(position);
		const bool isFront = GetIsFront(position);

		return Utils::PokemonLocation(
			folder,
			page, 
			isFront,
			position
		);
	}
}