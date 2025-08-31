#define SET_B_BLK	"\033[1;30m"
#define RESET		"\033[0m"
#include "Harl.hpp"

int main (void)
{
	Harl harl;

	std::cout << SET_B_BLK "[DEBUG]: " RESET;
	harl.complain("DEBUG");
	std::cout << SET_B_BLK "[INFO]: " RESET;
	harl.complain("INFO");
	std::cout << SET_B_BLK "[WARNING]: " RESET;
	harl.complain("WARNING");
	std::cout << SET_B_BLK "[ERROR]: " RESET;
	harl.complain("ERROR");
	std::cout << SET_B_BLK "[INVALID]: " RESET;
	harl.complain("ALARM");
	std::cout << SET_B_BLK "[INVALID]: " RESET;
	harl.complain("");
	std::cout << SET_B_BLK "[INVALID]: " RESET;
	harl.complain("    ");

	return (0);
}