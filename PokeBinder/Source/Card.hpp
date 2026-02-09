#pragma once
#include "Utils.hpp"

namespace Card
{
	Utils::InputType DefinedInputType(const std::string& input);
	Utils::CardInformation GetCardData(const std::string& input, Utils::InputType type);
}