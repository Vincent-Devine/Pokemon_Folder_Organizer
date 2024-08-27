#pragma once

#include <string>
#include <map>


namespace Test
{
	bool Test(std::map<unsigned int, std::string> pokedex);

	namespace Unit
	{
		bool CheckUnitTest();
	}
}