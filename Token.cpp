#include "Token.h"

Token::Token(std::string line, unsigned int row):line(line),row(row){
	write();
}

void Token::write()
{
	int column = 0;
	while (!line.empty()) {
		unsigned int pos = line.find('\t');
		column += pos;
		
		if (pos == 0) {
			std::cout << "There is an error in the  " << row << " row " << column <<" column"  ;
			std::abort();
		}
		
		std::string s = line.substr(0, pos);
		if(pos != std::string::npos)
			line.erase(pos,1);
		line.erase(0,pos);
		vec.push_back(s);
	}
}

char* Token::read()
{
	return nullptr;
}

std::string Token::get_word(const unsigned int i)
{
	return vec[i];
}

unsigned int Token::size()
{
	return vec.size();
}
