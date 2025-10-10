#ifndef DEBUG_HPP
#define DEBUG_HPP

#define CLR_GREY   "\033[90m"
#define CLR_PINK   "\033[38;2;255;150;150m"
#define CLR_RESET  "\033[0m"

#include <iostream>

#ifdef DEBUG
# define DBG(msg) std::cout << CLR_PINK << msg << CLR_RESET << std::endl
#else
# define DBG(msg) ((void)0)
#endif

#endif