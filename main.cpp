#include "TextToCsvConverter.h"

int main(int argc, char* argv[])
{	
	std::string inputPath;
	std::string outputPath;

	if (argc < 2)
	{
		std::cout << "Please input file directory" << std::endl;
		std::cin >> inputPath;
		std::cout << "Please input output file directory" << std::endl;
		std::cin >> outputPath;
	}
	else if(argc == 2)
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

	TextToCsvConverter t(inputPath, outputPath);
	t.convert("input.txt", true);
	t.write("output.csv");

	return 0;
}

