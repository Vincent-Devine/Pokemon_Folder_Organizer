#include "Test.hpp"

#include "Log_System/Log.hpp"
#include "Folder.hpp"

namespace Test
{
	bool Test(std::map<unsigned int, std::string> pokedex)
	{
		bool allTest = true;
		if (!Unit::CheckUnitTest())
			allTest = false;

		if (allTest)
		{
			LOG_INFO("Test passed!");
		}
		else
		{
			LOG_INFO("Test failed!");
		}
		return allTest;
	}

	namespace Unit
	{
		bool CheckFolder(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.folder <= 0)
			{
				LOG_WARNING("Wrong folder info! Folder given: " + std::to_string(pl.folder) + ", Pokemon id : " + std::to_string(id));
				return false;
			}
			return true;
		}

		bool CheckPage(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.page <= 0 || pl.page > (Utils::CARD_BY_BINDER / Utils::CARD_PER_PAGE))
			{
				LOG_WARNING("Wrong page info! Page given: " + std::to_string(pl.page) + ", Pokemon id : " + std::to_string(id));
				return false;
			}
			return true;
		}

		bool CheckPosition(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.position <= 0 || pl.position > Utils::CARD_PER_FACE)
			{
				LOG_WARNING("Wrong position info! Position given: " + std::to_string(pl.position) + ", Pokemon id : " + std::to_string(id));
				return false;
			}
			return true;
		}

		bool CheckUnitTest()
		{
			bool unitTest = true;
			for (unsigned int i = 1; i < Utils::MAX_POKEMON_ID + 1; i++)
			{
				Utils::PokemonLocation pl = Core::GetPokemonLocation(i);
				if (!CheckFolder(pl, i) || !CheckPage(pl, i) || !CheckPosition(pl, i))
					unitTest = false;
			}

			if (unitTest)
			{
				LOG_INFO("Unit test passed!");
			}
			else
			{
				LOG_INFO("Unit test failed!");
			}

			return unitTest;
		}
	}
}