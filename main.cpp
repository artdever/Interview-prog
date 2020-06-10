#include "TextToCsvConverter.h"

int main() {
	
	TextToCsvConverter t;
	t.convert("input.txt");
	t.printWarnings();
	t.write("output.csv");

	return 0;
}

