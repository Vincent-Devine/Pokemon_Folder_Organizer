#pragma once
#include <string>

namespace Utils
{
	struct CardInformation
	{
		std::string frenchName;
		std::string japaneseName;
		unsigned int pokedexNumber;
	};

	struct BinderInformation
	{
		unsigned int binder;
		unsigned int page;
		unsigned int position;
		bool isFront;
	};

	enum InputType
	{
		name,		// pokemon name
		pokedex,	// pokemon pokedex number
		extension	// pokemon card extension number
	};

	const unsigned int GEN_1 = 151;
	const unsigned int GEN_2 = 100;
	const unsigned int GEN_3 = 135;
	const unsigned int GEN_4 = 107;
	const unsigned int GEN_5 = 156;

	const unsigned int CARDS_PER_BINDER = 360;
	const unsigned int PAGE_PER_BINDER = 20;
	const unsigned int CARDS_PER_PAGE = 18;
	const unsigned int CARDS_PER_FACE = 9;

	const unsigned int GEN_1_BINDER = 153;
	const unsigned int GEN_2_BINDER = 108;
	const unsigned int GEN_3_BINDER = 144; // 135
	const unsigned int GEN_4_BINDER = 108;
	const unsigned int GEN_5_BINDER = 162;

	void SetLowerCase(std::string& str);
	void SetFirstLetterCapitalize(std::string& str);
}