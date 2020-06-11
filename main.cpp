#include "TextToCsvConverter.h"

int main()
{	
	TextToCsvConverter t;
	t.convert("input.txt", true);
	t.write("output.csv");

	return 0;
}

