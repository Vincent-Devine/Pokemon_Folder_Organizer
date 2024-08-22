#pragma once

#include <string>

namespace Core
{
	std::string GetPokemonLocation(unsigned int id);

	unsigned int GetFolderNum(unsigned int id, unsigned int& idInThisGeneration);
	unsigned int GetPage(unsigned int id);
}