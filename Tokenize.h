#pragma once
#include "Row.h"
#include <iostream>

class Tokenize : public Row
{
public:
	std::vector<Row> tokenize(std::string line);
	std::vector<Row> getRows();
private:
	std::vector<Row> rows;
};

