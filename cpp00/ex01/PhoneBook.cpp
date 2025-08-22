/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/15 18:17:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string PhoneBook::_fieldNames[5] = {
    "first name",
    "last name",
    "nick name",
    "phone number",
    "darkest secret"
};

PhoneBook::PhoneBook()
{
	_nextID = 0;
	_phonebookFull = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::addContact()
{
	std::string	inputs[5];
	for (int i = 0; i < 5; ++i)
	{
		int attempt = 0;
		while (attempt < 3)
		{
			std::cout << "Enter " << _fieldNames[i] << ":";
			if (!std::getline(std::cin, inputs[i]))
			{
				std::cerr << "\nInput stream closed. Add contact cancelled. Returning back to main menu!" << std::endl;
				return;
			}
			attempt++;
			if (!inputs[i].empty())
				break;
			std::cout << _fieldNames[i] << " cannot be empty. " << (3 - attempt) << "attempt(s) left." << std::endl;
		}
		if (attempt == 3)
		{
			std::cerr << "Failed to add contact. Returning back to main menu!\n";
			return;
		}
	}
	_contacts[_nextID] = Contact(inputs);
	++_nextID;
	if (!_phonebookFull)
		_phonebookFull = (bool) _nextID / 8;
	_nextID = _nextID % 8;
	std::cout << "Add contact sucessful!" << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string	searchID;
	std::string	*fullContact;

	if (!_phonebookFull && !_nextID)
	{
		std::cout << "Phonebook empty!" << std::endl;
		return ;
	}
	std::cout << " __________ __________ __________ __________ " << std::endl;
	std::cout << "|     index|first name| last name| nick name|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		fullContact = _contacts[i].getContact();
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(10)
			<< (fullContact[j].length() > 10 ? fullContact[j].substr(0, 9) + "." : fullContact[j])
			<< "|";
		}
		std::cout << std::endl;
	}
	std::cout << "\nEnter index to get full contact details:" << std::endl;
	if (!std::getline(std::cin, searchID))
	{
		std::cerr << "\nInput stream closed. Search contact cancelled. Returning back to main menu!" << std::endl;
		return;
	}
	if (searchID.length() == 1 && std::isdigit(searchID[0]))
	{
		int id = searchID[0] - '0' - 1;
		if (!_phonebookFull && id >= _nextID)
			std::cout << "Search index out of range!" << std::endl;
		else
		{
			fullContact = _contacts[id].getContact();
			for (int i = 0; i < 5; i++)
				std::cout << _fieldNames[i] << ": " << fullContact[i] << std::endl;
		}
	}
	else
		std::cout << "Invalid input!" << std::endl;
}