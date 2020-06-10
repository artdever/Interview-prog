#include "Tokenize.h"

std::vector<Row> Tokenize::tokenize(std::string line)
{
	unsigned int row = rows.size();
	int column = 0;
	unsigned int pos = 0;
	Row r;
	while (!line.empty()) {
		pos = line.find('\t');
		++column;

		if (pos == 0 && row == 0) {
			std::cout << "ERROR: There is an error in the  " << row + 1 << " row " << column + 1 << " column" << std::endl;
			std::abort();
		}
		else if (pos == 0) {
			std::string s;
			s += "WARNING: There is not argument in  ";
			s += std::to_string(row + 1);
			s += " row ";
			s += std::to_string(column);
			s += " column\n";
			r.addWarning(Warning(s));
		}

		std::string s = line.substr(0, pos);
		r.addRowValue(s);
		if (pos != std::string::npos && !line.empty())
			s = line.substr(pos, 1);
		if (pos != std::string::npos)
			line.erase(pos, 1);
		line.erase(0, pos);

		if (line.empty() && s == "\t") {
			std::string s;
			s += "WARNING: There is not argument in  ";
			s += std::to_string(row + 1);
			s += " row ";
			s += std::to_string(column);
			s += " column\n";
			r.addWarning(Warning(s));
		}
	}

	rows.push_back(r);
	if (!rows[0].getRowValues().empty() && row != 0 && rows[0].getRowValues().size() < r.getRowValues().size()) {
		std::string s;
		s += "WARNING: The number of arguments is large in ";
		s += std::to_string(row + 1);
		s += " row\n";
		Row rr;
		rr.addWarning(Warning(s));
		for (unsigned int i = 0; i < rows[0].getRowValues().size(); ++i)
			rr.addRowValue("\t");
		rows.pop_back();
		rows.push_back(rr);
	}
	return std::vector<Row>();
}

std::vector<Row> Tokenize::getRows()
{
	return rows;
}