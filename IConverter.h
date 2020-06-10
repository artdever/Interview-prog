#pragma once
#include <string>

class Converter {
public:
	virtual void convert(std::string input) = 0;
	virtual void write(std::string output) = 0;
	virtual void convertAndWrite(std::string input, std::string output) = 0;
};