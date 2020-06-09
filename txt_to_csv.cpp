#include <fstream>

#include "txt_to_csv.h"


void txt_to_csv(const char* input, const char* out) {
	std::string line;
	std::ifstream myfile(input, std::ios::out);

	if (myfile.is_open())
	{
		getline(myfile, line);
		if (!line.empty()) {
			Token* t;
			std::ofstream newfile(out);
			unsigned int row = 0;
			
			do {
				t = new Token(line,row);
				for(int i = 0; i < t->size(); ++i)
					newfile << t->get_word(i)<<";";
				newfile << "\n";
				++row;
			} while (getline(myfile, line));
			newfile.close();
			delete t;
		}
		else
			std::cout << "file is empty";
		myfile.close();
	}

	else std::cout << "Unable to open file";
}

