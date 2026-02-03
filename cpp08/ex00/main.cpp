/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:24:53 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/03 22:13:13 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

#define SET_B_BLK	"\033[1;30m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main() {
	try {
		std::vector<int> intVec{12, 23, 34, 45, 56, 67};
		std::deque<int> intDeq{1, 0, 2, 9, 3};
		std::list<int> intLst{125, 45, -11, 99};
		//write the tests
	} 
	catch (const std::exception& e) {
		std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
	}
}