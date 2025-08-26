/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:43 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/26 19:38:10 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << SET_B_YLW "Welcome to the Crappy Awesome Phonebook!" RESET << std::endl;
	while(true)
	{
		std::cout << "Enter command [" SET_B_BLK "ADD, SEARCH, EXIT" RESET "]: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << SET_B_YLW "Exiting phonebook!" RESET << std::endl;
			break;
		}
		else if (std::cin.good())
			std::cout << SET_RED "Invalid command!" RESET << std::endl;
		if (std::cin.eof())
		{
			std::cout << SET_RED "\nInput stream closed. Exiting phonebook!" RESET << std::endl;
			return(1);
		}
	}
	return (0);
}