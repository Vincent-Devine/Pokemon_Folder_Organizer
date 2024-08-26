#include "Test.hpp"

namespace Test
{
	bool Test(std::map<unsigned int, std::string> pokedex)
	{
		return Unit::CheckUnitTest(pokedex);
	}

	namespace Unit
	{
		bool CheckUnitTest(std::map<unsigned int, std::string> pokedex)
		{
			return true;
		}
	}
}