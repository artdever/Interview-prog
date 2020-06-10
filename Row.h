#pragma once
#include "IRow.h"

class Row : public IRow
{
public:
	std::vector<std::string> getRowValues();
	std::vector<Warning> getWarnings();
	void addRowValue(std::string);
	void addWarning(Warning);
private:
	std::vector<std::string> val;
	std::vector<Warning> wornings;
};

