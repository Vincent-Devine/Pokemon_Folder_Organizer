#pragma once

#include <string>
#include <map>

class FolderOrganizer
{
	// Methods
public:
	void Start();
	void Update();
	void Delete();

private:
	bool CheckGoodPokemon(const unsigned int id);

	// Members
private:
	std::map<unsigned int, std::string> m_pokedex;
};