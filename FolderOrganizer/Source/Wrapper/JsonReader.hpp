#pragma once

#include <map>
#include <string>

namespace Wrapper
{
	class JsonReader
	{
		// Methods
	public:
		static JsonReader* Get();

		std::map<unsigned int, std::string> GetPokedex(const std::string& fileName);

	private:
		std::string GetValue(const std::string& line, const std::string& key, int decal);

		// Attributes
	private:
		static JsonReader* singleton;
	};
}