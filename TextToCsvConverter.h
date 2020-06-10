#pragma once
#include <fstream>
#include "IConverter.h"
#include "Tokenize.h"

class TextToCsvConverter : public Converter
{
public:
	void convert(std::string input);
	void write(std::string output);
	void convertAndWrite(std::string input, std::string output);
	void printWarnings();
private:
	Tokenize tokenizer;
};

