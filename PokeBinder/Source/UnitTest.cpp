#include "UnitTest.hpp"
#include "Utils.hpp"
#include "Binder.hpp"
#include "OMLogger/Logger.hpp"

namespace Test
{
	void BinderInformation()
	{
		unsigned int expectedBinder = 1;
		unsigned int expectedPage = 1;
		unsigned int expectedPosition = 1;
		bool expectedIsFront = true;

		Utils::BinderInformation bi;
		for (int pokedex = 1; pokedex < Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4 + Utils::GEN_5 + 2; pokedex++) // +2 for Victini
		{
			if (pokedex == Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4 + 1)
			{
				pokedex++;
				expectedPosition--;
			}

			bi = Binder::GetBinderInformation(pokedex);
			OM_ASSERTION(expectedBinder == bi.binder, "wrong binder for " + std::to_string(pokedex));
			OM_ASSERTION(expectedPage == bi.page, "wrong page for " + std::to_string(pokedex));
			OM_ASSERTION(expectedPosition == bi.position, "wrong position for " + std::to_string(pokedex));
			OM_ASSERTION(expectedIsFront == bi.isFront, "wrong isFront for " + std::to_string(pokedex));

			if (pokedex == Utils::GEN_1)
				expectedPosition += Utils::GEN_1_BINDER - Utils::GEN_1 + 1; // Offset gen 1
			else if (pokedex == Utils::GEN_1 + Utils::GEN_2)
				expectedPosition += Utils::GEN_2_BINDER - Utils::GEN_2 + 1; // Offset gen 2
			else if (pokedex == Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3)
				expectedPosition += Utils::GEN_3_BINDER - Utils::GEN_3 + 1; // Offset gen 3
			else if (pokedex == Utils::GEN_1 + Utils::GEN_2 + Utils::GEN_3 + Utils::GEN_4)
				expectedPosition += Utils::GEN_4_BINDER - Utils::GEN_4 + 2; // Offset gen 4
			else
				expectedPosition++;

			if (expectedPosition > Utils::CARDS_PER_FACE)
			{
				unsigned int nb = (int)(expectedPosition / Utils::CARDS_PER_FACE);
				expectedPosition -= Utils::CARDS_PER_FACE * nb;
				for (int i = 0; i < nb; i++)
				{
					expectedIsFront = !expectedIsFront;
					if (expectedIsFront)
						expectedPage++;
				}

				if (expectedPage > Utils::PAGE_PER_BINDER)
				{
					expectedPage -= Utils::PAGE_PER_BINDER;
					expectedBinder++;
				}
			}
		}
	}

	void UnitTest()
	{
		BinderInformation();
	}
}