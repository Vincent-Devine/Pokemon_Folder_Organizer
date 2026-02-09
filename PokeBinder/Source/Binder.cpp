#include "Binder.hpp"

namespace Binder
{
	const unsigned int GetOffset(const unsigned int pokedex)
	{
		if (pokedex == 494) return Utils::GEN_1_BINDER + Utils::GEN_2_BINDER + Utils::GEN_3_BINDER + Utils::GEN_4_BINDER + Utils::GEN_5; // Victini
		if (pokedex > Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4) return pokedex - 1 + (Utils::GEN_1_BINDER - Utils::GEN_1) + (Utils::GEN_2_BINDER - Utils::GEN_2) + (Utils::GEN_3_BINDER  - Utils::GEN_3) + (Utils::GEN_4_BINDER - Utils::GEN_4); // - 1 for Victini
		else if (pokedex > Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3) return pokedex + (Utils::GEN_1_BINDER - Utils::GEN_1) + (Utils::GEN_2_BINDER - Utils::GEN_2) + (Utils::GEN_3_BINDER - Utils::GEN_3);
		else if (pokedex > Utils::GEN_1 + Utils::GEN_2) return pokedex + (Utils::GEN_1_BINDER - Utils::GEN_1) + (Utils::GEN_2_BINDER - Utils::GEN_2);
		else if (pokedex > Utils::GEN_1) return pokedex + (Utils::GEN_1_BINDER - Utils::GEN_1);
		else return pokedex;
	}

	const unsigned int GetBinder(unsigned int& position)
	{
		if (position <= Utils::CARDS_PER_BINDER)
			return 1;
		position -= Utils::CARDS_PER_BINDER;
		return 2;
	}

	const unsigned int GetPage(unsigned int& position)
	{
		if (position == Utils::CARDS_PER_BINDER || position % Utils::CARDS_PER_PAGE == 0)
		{
			const unsigned int page = position / Utils::CARDS_PER_PAGE;
			position = Utils::CARDS_PER_PAGE;
			return page;
		}

		const unsigned int page = position / Utils::CARDS_PER_PAGE;
		position -= Utils::CARDS_PER_PAGE * page;
		return page + 1;
	}

	const bool GetIsFront(unsigned int& position)
	{
		if (position > Utils::CARDS_PER_FACE)
		{
			position -= Utils::CARDS_PER_FACE;
			return false;
		}
		return true;
	}

	const Utils::BinderInformation GetBinderInformation(const unsigned int pokedex)
	{
		Utils::BinderInformation binderInformation;
		unsigned int position = GetOffset(pokedex);
		binderInformation.binder = GetBinder(position);
		binderInformation.page = GetPage(position);
		binderInformation.isFront = GetIsFront(position);
		binderInformation.position = position;
		return binderInformation;
	}
}