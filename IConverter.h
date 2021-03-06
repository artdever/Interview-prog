#pragma once
#include <string>

class IConverter
{
public:
	virtual void convert(std::string input, bool printWarning) = 0;
	virtual void write(std::string output) = 0;
	virtual void convertAndWrite(std::string input, std::string output, bool printWarning) = 0;
};