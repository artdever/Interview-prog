#include "TextToCsvConverter.h"
#include "Tokenize.h"

void TextToCsvConverter::convert(std::string input)
{
	std::string line;
	std::ifstream myfile(input, std::ios::out);

	if (myfile.is_open())
	{
			while (getline(myfile, line)) {
				tokenizer.tokenize(line);
			}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}

void TextToCsvConverter::write(std::string output)
{
	std::ofstream newfile(output);
	
	for (unsigned int i = 0; i < tokenizer.getRows().size(); ++i) {
		for (unsigned int j = 0; j < tokenizer.getRows()[i].getRowValues().size(); ++j)
		newfile << tokenizer.getRows()[i].getRowValues()[j] << ";";
		newfile << "\n";
	}
	
	newfile.close();
}

void TextToCsvConverter::convertAndWrite(std::string input, std::string output)
{
	
}

void TextToCsvConverter::printWarnings()
{
	for (unsigned int i = 0; i < tokenizer.getRows().size(); ++i)
		for (unsigned int j = 0; j < tokenizer.getRows()[i].getWarnings().size(); ++j)
			std::cout << tokenizer.getRows()[i].getWarnings()[j].warning;
}
