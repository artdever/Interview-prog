#include "ArgumentsParser.h"
#include "TextToCsvConverter.h"

int main(int argc, char** argv)
{	
	ArgumentsParser argsParser(argc, argv);
	TextToCsvConverter t(argsParser.getInputPath(), argsParser.getOutputPath());
	t.convert("input.txt", true);
	t.write("output.csv");

	return 0;
}

