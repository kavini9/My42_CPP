/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:43 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/14 23:14:25 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;
	
	std::cout << "\033[33mWelcome to the Crappy Awesome Phonebook!\033[0m\n";
	while(1)
	{
		std::cout << "Enter command [ADD, SEARCH, EXIT]: ";
		if (!std::getline(std::cin, command))//maybe we can add this to the end of the line and catch eof from add and serch too
		{
			std::cout << "\nEOF reached. Exiting phonebook...\n";
			break;
		}
		else if (command == "ADD")//make sure you check for the eof inside this
			phoneBook.addContact();
		else if (command == "SERACH")//make sure you check for the eof inside this
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "\nExiting phonebook!\n";
			break;
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}