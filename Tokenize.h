#pragma once
#include "Row.h"
#include <iostream>

class Tokenize
{
public:
	void tokenize(std::string line);
	const std::vector<Row>& getRows();
private:
	std::vector<Row> rows;
};

