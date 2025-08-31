#ifndef HARL_HPP
#define HARL_HPP

#define SET_RED		"\033[31m"
#define SET_B_BLK	"\033[1;30m"
#define RESET		"\033[0m"

#include <iostream>
#include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public:
		Harl();
		~Harl();
		
		void complain(std::string level);
};

#endif