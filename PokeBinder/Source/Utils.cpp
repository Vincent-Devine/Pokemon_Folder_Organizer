#include "Utils.hpp"
#include <algorithm>

namespace Utils
{
	void SetLowerCase(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
			{
				return std::tolower(c);
			});
	}

	void SetFirstLetterCapitalize(std::string& str)
	{
		if (str.empty()) return;
		str[0] = toupper(str[0]);
	}
}