#ifndef DEBUG_HPP
#define DEBUG_HPP

#define CLR_GREY   "\033[38;5;250m"
#define CLR_PINK   "\033[38;2;255;150;150m"
#define CLR_RESET  "\033[0m"

#include <iostream>

#ifdef DEBUG
# define LOG(msg) std::cout << CLR_GREY << msg << CLR_RESET << std::endl
#else
# define LOG(msg) ((void)0)
#endif

#endif