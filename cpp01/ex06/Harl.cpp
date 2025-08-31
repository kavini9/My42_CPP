
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
			<< " You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
			<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {
	std::string allLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptrFunc[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int levelNum;

	levelNum = -1;
	for (int i = 0; i < 4; i++) 
	{
		if (level == allLevels[i])
		{
			levelNum = i;
			break;
		}	
	}

	switch (levelNum) {
	case 0:
		std::cout << SET_B_BLK "[ " << allLevels[0] << " ]" RESET <<std::endl;
		(this->*ptrFunc[0])();
		std::cout << std::endl;
		[[fallthrough]];
	case 1:
		std::cout << SET_B_BLK "[ " << allLevels[1] << " ]" RESET <<std::endl;
		(this->*ptrFunc[1])();
		std::cout << std::endl;
		[[fallthrough]];
	case 2:
		std::cout << SET_B_BLK "[ " << allLevels[2] << " ]" RESET <<std::endl;
		(this->*ptrFunc[2])();
		std::cout << std::endl;
		[[fallthrough]];
	case 3:
		std::cout << SET_B_BLK "[ " << allLevels[3] << " ]" RESET <<std::endl;
		(this->*ptrFunc[3])();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	
}