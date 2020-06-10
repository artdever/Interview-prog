#pragma once
#include <vector>
#include <string>

#include <iostream>
class Token
{
public:
	explicit Token(std::string line, unsigned int row, unsigned int size_header = 0);
	void write();
	std::string get_word(const unsigned int i);
	unsigned int size();

private:
	unsigned int row;
	unsigned int size_header;
	std::string line;
	std::vector<std::string> vec;
};

