//#include <iostream>
#include <fstream>
//#include <string>
//#include <vector>

//#include "Token.h"
#include "txt_to_csv.h"

//void write(const Token* const&);

void txt_to_csv(const char* input, const char* out) {
	std::string line;
	std::ifstream myfile("input.txt", std::ios::out);

	if (myfile.is_open())
	{
		getline(myfile, line);
		if (!line.empty()) {
			Token* t;// = new Token(line);
			std::ofstream newfile("out.csv");
			//newfile.open();
			unsigned int row = 0;
			do {
				t = new Token(line,row);
				for(int i = 0; i < t->size(); ++i)
					newfile << t->get_word(i)<<";";
				newfile << "\n";
			//	write(t);
				//write in file csv
				++row;
				//std::cout << line << '\n';
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

void read_file(const char* input_file_name, const char* output_file_name)
{
	
}
