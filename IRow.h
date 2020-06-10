#pragma once
#include <vector>
#include <string>
#include "Warning.h"

class IRow {
public:
	virtual std::vector<std::string> getRowValues() = 0;
	virtual std::vector<Warning> getWarnings() = 0;
};
