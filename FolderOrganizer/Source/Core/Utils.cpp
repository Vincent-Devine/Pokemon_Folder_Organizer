#include "Utils.hpp"

#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "Log.hpp"

namespace Utils
{
	bool StringIsInt(const std::string& input, int& value)
	{
		std::stringstream ss(input);
		int number = 0;

		if (ss >> number)
		{
			if (ss.eof())
			{
				value = number;
				return true; // INT
			}
			else
			{
				return false; // STRING
			}
		}
		return false; // STRING
	}

	unsigned int GetKeyByValue(const std::map<unsigned int, std::string>& map, const std::string& value)
	{
		for (const std::pair<unsigned int, std::string> pair : map)
		{
			if (pair.second == value)
				return pair.first;
		}
		return 0;
	}

	void SetLowerCase(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
			{
				return std::tolower(c);
			});
	}

	std::string SetCapilizeFirstLetter(const std::string& str)
	{
		if (str.empty())
			return str;

		std::string res = str;
		res[0] = toupper(res[0]);
		return res;
	}
}