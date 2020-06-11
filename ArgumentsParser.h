#pragma once
#include <iostream>
#include <string>

class ArgumentsParser
{
public:
	ArgumentsParser(int argc, char** argv);
	std::string getInputPath() const;
	std::string getOutputPath() const;
private:
	std::string inputPath;
	std::string outputPath;

	void parseArgs(int argc, char** argv);
};

