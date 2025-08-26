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
#include <csignal>
#include <cstdio>

int g_sig = false;

void sigHandler(int sig)
{
	g_sig = sig;
	std::cerr << SET_RED "\nInterrupt signal received. Exiting phonebook!" RESET << std::endl;
	std::fclose(stdin);
}

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::signal(SIGINT, sigHandler);
	std::signal(SIGQUIT, sigHandler);
	std::cout << SET_B_YLW "Welcome to the Crappy Awesome Phonebook!" RESET << std::endl;
	while(true)
	{
		std::cout << "Enter command [" SET_B_BLK "ADD, SEARCH, EXIT" RESET "]: ";
		std::getline(std::cin, command);
		if (std::cin.bad())
			return (1);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << SET_B_YLW "Exiting phonebook!" RESET << std::endl;
			break;
		}
		else if (std::cin.good() && !g_sig)
			std::cerr << SET_RED "Invalid command!" RESET << std::endl;
		if (std::cin.eof() || g_sig)
		{
			if (!g_sig)
				std::cerr << SET_RED "\nInput stream closed. Exiting phonebook!" RESET << std::endl;
			return(1 | g_sig);
		}
	}
	return (0);
}