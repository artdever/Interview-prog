#pragma once
#include <vector>
#include <string>

#include <iostream>
class Token
{
public:
	explicit Token(std::string line, unsigned int row);
	void write();
	char* read();
	std::string get_word(const unsigned int i);
	unsigned int size();

private:
	unsigned int row;
	std::string line;
	std::vector<std::string> vec;
};

