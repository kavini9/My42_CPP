/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:24:53 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/09 22:30:32 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <sstream>
#include "easyfind.hpp"

#define SET_B_BLK	"\033[1;30m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

template <typename T>
std::string stringifyContent(const T& cont) {
    std::ostringstream oss;
    oss << "[ ";
    auto it = cont.begin();
    auto end = cont.end();
    if (it != end) {
        oss << *it;
        ++it;
    }
    for (; it != end; ++it) {
        oss << ", " << *it;
    }
    oss << " ]";
    return oss.str();
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << SET_RED "Error: Missing/Extra argument/s" << std::endl
			<< "Usage: ./easyfind <number>" RESET << std::endl;
		return 1;
	}
	try {
		std::vector<int> intVec{12, 23, 34, 45, 56, 67};
		std::deque<int> intDeq{1, 0, 2, 9, 3};
		std::list<int> intLst{125, 45, -11, 99};
		std::vector<int> emptVec;
		int num = std::stoi(av[1]);
		
		std::cout << SET_B_BLK "Test for Vector" RESET << std::endl;
		std::cout << "Container content: " << stringifyContent(intVec) << std::endl;
		std::cout << "Number " << num << ((easyfind(intVec, num) != intVec.end())? " found" : " not found") 
				<< " in container" << std::endl;
		std::cout << std::endl;
		std::cout << SET_B_BLK "Test for Deque" RESET << std::endl;
		std::cout << "Container content: " << stringifyContent(intDeq) << std::endl;
		std::cout << "Number " << num << ((easyfind(intDeq, num) != intDeq.end())? " found" : " not found") 
				<< " in container" << std::endl;
		std::cout << std::endl;
		std::cout << SET_B_BLK "Test for List" RESET << std::endl;
		std::cout << "Container content: " << stringifyContent(intLst) << std::endl;
		std::cout << "Number " << num << ((easyfind(intLst, num) != intLst.end())? " found" : " not found") 
				<< " in container" << std::endl;
		std::cout << std::endl;
		std::cout << SET_B_BLK "Test for Empty Vector" RESET << std::endl;
		std::cout << "Container content: " << stringifyContent(emptVec) << std::endl;
		std::cout << "Number " << num << ((easyfind(emptVec, num) != emptVec.end())? " found" : " not found") 
				<< " in container" << std::endl;
		std::cout << std::endl;
	} 
	catch (const std::exception& e) {
		std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
	}
}