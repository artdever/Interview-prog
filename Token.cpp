#include "Token.h"
#include <stack>

Token::Token(std::string line, unsigned int row):line(line),row(row){
	write();
}

void Token::write()
{
	int column = 0;
	unsigned int pos = 0;
	while (!line.empty()) {
		 pos = line.find('\t');
		column += pos;
		
		if (pos == 0 && row == 0) {
			std::cout << "There is an error in the  " << row << " row " << column+1 <<" column" << std::endl;
			std::abort();
		}
		else if (pos == 0) {
			std::cout << "There is not argument in  " << row << " row " << column+1 << " column" << std::endl;
		}
		
		std::string s = line.substr(0, pos);
		vec.push_back(s);
		if(pos != std::string::npos && !line.empty())
			s = line.substr(pos, 1);
		if(pos != std::string::npos)
			line.erase(pos,1);
		line.erase(0,pos);
		if(line.empty() && s == "\t")
			std::cout << "There is not argument in  " << row << " row " << column + 1 << " column" << std::endl;
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
