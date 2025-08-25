/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:43 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/22 22:23:10 by wweerasi         ###   ########.fr       */
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
		// if (!std::getline(std::cin, command))//maybe we can add this to the end of the line and catch eof from add and serch too
		// {
		// 	std::cerr << SET_RED "\nInput stream closed. Exiting phonebook!" RESET << std::endl;
		// 	break;
		// }
		if (command == "ADD")//make sure you check for the eof inside this
			phoneBook.addContact();
		else if (command == "SEARCH")//make sure you check for the eof inside this
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << SET_B_YLW "Exiting phonebook!" RESET << std::endl;
			break;
		}
		else if (std::cin.good())
			std::cerr << SET_RED "Invalid command!" RESET << std::endl;
		if (std::cin.eof())
		{
			std::cerr << SET_RED "\nInput stream closed. Exiting phonebook!" RESET << std::endl;
			break;
		}
	}
	return (0);
}