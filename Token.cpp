#include "Token.h"
#include <stack>

Token::Token(std::string line, unsigned int row, unsigned int size_header):line(line), row(row), size_header(size_header){
	write();
}

void Token::write()
{
	int column = 0;
	unsigned int pos = 0;
	while (!line.empty()) {
		 pos = line.find('\t');
		//column += pos;
		 ++column;

		if (pos == 0 && row == 0) {
			std::cout << "There is an error in the  " << row+1 << " row " << column+1 <<" column" << std::endl;
			std::abort();
		}
		else if (pos == 0) {
			std::cout << "WARNING: There is not argument in  " << row+1 << " row " << column << " column" << std::endl;
		}
		
		std::string s = line.substr(0, pos);
		vec.push_back(s);
		if(pos != std::string::npos && !line.empty())
			s = line.substr(pos, 1);
		if(pos != std::string::npos)
			line.erase(pos,1);
		line.erase(0,pos);

		if(line.empty() && s == "\t")
			std::cout << "WARNING: There is not argument in  " << row+1 << " row " << column + 1 << " column" << std::endl;
	}
	if (row == 0 && vec[vec.size()-1] == "\t") {
		vec.pop_back();
		std::cout << "WARNING: There is not argument in  " << row+1 << " row " << vec.size() << " column" << std::endl;

	}
	if (row != 0 && size_header < vec.size()) {
			std::cout << "WARNING: The number of arguments is large in " << row+1 << " row "  << std::endl;
			vec.clear();
			for (unsigned int i = 0; i < size_header; ++i)
				vec.push_back("\t");
		}
}

std::string Token::get_word(const unsigned int i)
{
	return vec[i];
}

unsigned int Token::size()
{
	return vec.size();
}
