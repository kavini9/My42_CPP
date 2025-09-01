#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cout	<< SET_RED "Error: Invalid number of arguments.\n"
					<< "Usage: ./harlFilter <level>\n"
					<< "Level options: DEBUG, INFO, WARNING, ERROR" RESET
					<< std::endl;
		return (1);
	}
	Harl	harl;

	harl.complain(argv[1]);;
	return (0);
}