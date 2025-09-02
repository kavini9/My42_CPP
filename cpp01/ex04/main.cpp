#include "replace.h"

void searchReplace(std::ifstream& inFile, std::ofstream& outFile, std::string& search, std::string& replace)
{
	std::string	line;
	while (std::getline(inFile, line))
	{
		if (!inFile.eof())
			line += "\n";
		size_t	pos = 0;
		while ((pos = line.find(search, pos)) != std::string::npos)
		{
			line.erase(pos, search.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		outFile << line;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout	<< SET_RED "Error: Invalid number of arguments.\n"
			<< "Usage: ./sed_is_for_losers <filename> <search_str> <repalce_str>" RESET << std::endl;
			return (0);
	}
	std::string fname = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	if (!search.length())
	{
		std::cout << SET_RED "Error: Empty search string." RESET << std::endl;
		return (1);
	}
	std::ifstream inFile(fname);
	if (!inFile) {
		std::cout << SET_RED "Error: " << fname << ": Could not open file." << RESET << std::endl;
		return 1;
	}
	if (inFile.peek() == std::ifstream::traits_type::eof()) 
	{
		std::cout << SET_RED "Error: " << fname << ": Empty file." << RESET << std::endl;;
		inFile.close();
		return 1;
	}
	std::ofstream outFile(fname + ".replace");
	if (!outFile) {
		std::cout << SET_RED "Error: " << fname + ".replace" << ": Could not create file."  << RESET << std::endl;
		inFile.close();
		return 1;
	}
	searchReplace(inFile, outFile ,search, replace);
	inFile.close();
	outFile.close();
	return (0);
}