#pragma once
#include <fstream>
#include "IConverter.h"
#include "Tokenize.h"

class TextToCsvConverter : public Converter
{
public:
	TextToCsvConverter();
	void convert(std::string input, bool printwarnings = false);
	void write(std::string output);
	void convertAndWrite(std::string input, std::string output, bool printwarnings = false);
private:
	Tokenize tokenizer;
	
	void printWarnings();
};

