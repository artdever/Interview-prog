#pragma once
#include <fstream>
#include "IConverter.h"
#include "Tokenize.h"

class TextToCsvConverter : public IConverter
{
public:
	TextToCsvConverter(std::string inputPath, std::string outputPath);
	void convert(std::string input, bool printwarnings = false);
	void write(std::string output);
	void convertAndWrite(std::string input, std::string output, bool printwarnings = false);
private:
	Tokenize tokenizer;
	std::string inputPath;
	std::string outputPath;

	void printWarnings();
};

