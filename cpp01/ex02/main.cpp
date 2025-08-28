/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:00:03 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 17:37:31 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define SET_B_BLK	"\033[1;30m"
#define RESET		"\033[0m"

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << SET_B_BLK "Memory address:" RESET << std::endl;
	std::cout << "    of string         :" << &brain << std::endl;
	std::cout << "    held by stringPTR :" << stringPTR << std::endl;
	std::cout << "    held by stringREF :" << &stringREF << std::endl;
	
	std::cout << SET_B_BLK "Value:" RESET << std::endl;
	std::cout << "    of string               :" << brain << std::endl;
	std::cout << "    pointed to by stringPTR :" << *stringPTR << std::endl;
	std::cout << "    pointed to by stringREF :" << stringREF << std::endl;
	
	return (0);
	
}