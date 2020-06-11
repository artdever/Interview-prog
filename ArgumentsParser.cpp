#include "ArgumentsParser.h"

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
	parseArgs(argc, argv);
}

void ArgumentsParser::parseArgs(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Please input file directory" << std::endl;
		std::cin >> inputPath;
		std::cout << "Please input output file directory" << std::endl;
		std::cin >> outputPath;
	}
	else if (argc == 2)
	{
		std::cout << "Please input output file directory" << std::endl;
		inputPath = argv[1];
		std::cin >> outputPath;
	}
	else if (argc == 3)
	{
		inputPath = argv[1];
		outputPath = argv[2];
	}
}

std::string ArgumentsParser::getInputPath() const
{
	return inputPath;
}

std::string ArgumentsParser::getOutputPath() const
{
	return outputPath;
}
