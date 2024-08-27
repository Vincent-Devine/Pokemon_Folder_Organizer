#include "Test.hpp"

#include "Folder.hpp"
#include "Log.hpp"

namespace Test
{
	bool Test(std::map<unsigned int, std::string> pokedex)
	{
		bool allTest = true;
		if (!Unit::CheckUnitTest())
			allTest = false;

		if (allTest)
		{
			LOG("Test passed!", LogLevel::Info);
		}
		else
		{
			LOG("Test failed!", LogLevel::Warning);
		}
		return allTest;
	}

	namespace Unit
	{
		bool CheckFolder(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.folder <= 0)
			{
				LOG("Wrong folder info! Folder given: " + std::to_string(pl.folder) + ", Pokemon id : " + std::to_string(id), LogLevel::Warning);
				return false;
			}
			return true;
		}

		bool CheckPage(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.page <= 0 || pl.page > (Utils::CARD_BY_BINDER / Utils::CARD_PER_PAGE))
			{
				LOG("Wrong page info! Page given: " + std::to_string(pl.page) + ", Pokemon id : " + std::to_string(id), LogLevel::Warning);
				return false;
			}
			return true;
		}

		bool CheckPosition(const Utils::PokemonLocation& pl, const unsigned int id)
		{
			if (pl.position <= 0 || pl.position > Utils::CARD_PER_FACE)
			{
				LOG("Wrong position info! Position given: " + std::to_string(pl.position) + ", Pokemon id : " + std::to_string(id), LogLevel::Warning);
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
				LOG("Unit test passed!", LogLevel::Info);
			}
			else
			{
				LOG("Unit test failed!", LogLevel::Warning);
			}

			return unitTest;
		}
	}
}