#include "Row.h"

std::vector<std::string> Row::getRowValues()
{
	return val;
}

std::vector<Warning> Row::getWarnings()
{
	return wornings;
}

void Row::addRowValue(std::string s)
{
	val.push_back(s);
}

void Row::addWarning(Warning w)
{
	wornings.push_back(w);
}
