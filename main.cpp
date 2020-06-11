#include "ArgumentsParser.h"
#include "TextToCsvConverter.h"
#include "IConverter.h"

int main(int argc, char** argv)
{	
	ArgumentsParser argsParser(argc, argv);
	IConverter* converter = new TextToCsvConverter(argsParser.getInputPath(), argsParser.getOutputPath());
	converter->convert("input.txt", true);
	converter->write("output.csv");

	return 0;
}

