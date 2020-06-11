#include "TextToCsvConverter.h"
#include "Tokenize.h"

TextToCsvConverter::TextToCsvConverter() : tokenizer()
{
}

void TextToCsvConverter::convert(std::string input, bool printWarnings)
{
	std::string line;
	std::string path = __argv[1]; //"./files/input/";
	path += input;
	std::ifstream myFile(path, std::ios::out);

	if (myFile.is_open())
	{
		while (getline(myFile, line)) 
		{
			tokenizer.tokenize(line);
		}
		myFile.close();
	}	else 
	{
		std::cout << "Unable to open file";
	}
	if (printWarnings)
	{
		this->printWarnings();
	}
}

void TextToCsvConverter::write(std::string output)
{
	std::string path = __argv[2]; //"./files/output/";
	path += output;
	std::ofstream newfile(path);
	
	for (std::vector<Row>::const_iterator itrRows = tokenizer.getRows().begin(); itrRows != tokenizer.getRows().end(); ++itrRows)
	{
		for(std::vector<std::string>::const_iterator itrValues = itrRows->getRowValues().begin(); itrValues != itrRows->getRowValues().end(); ++itrValues)
		{
			newfile << *itrValues << ";";
		}
		newfile << "\n";
	}
	newfile.close();
}

void TextToCsvConverter::convertAndWrite(std::string input, std::string output, bool printwarnings)
{
	convert(input);
	write(output);
}

void TextToCsvConverter::printWarnings()
{
	for (unsigned int i = 0; i < tokenizer.getRows().size(); ++i)
	{
		for (unsigned int j = 0; j < tokenizer.getRows()[i].getWarnings().size(); ++j)
		{
			std::cout << tokenizer.getRows()[i].getWarnings()[j].warning;
		}
	}
}
