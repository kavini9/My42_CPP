/* ************************************************************************** */
/*_____________           */
/*_____________    :::      ::::::::   */
/*   PhoneBook.cpp_____________            :+:      :+:    :+:   */
/*_____________+:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*_____________         +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:23 by wweerasi          #+#    #+#_____________*/
/*   Updated: 2025/08/22 21:25:45 by wweerasi         ###   ########.fr       */
/*_____________           */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string PhoneBook::_fieldNames[5] = {
    "First Name",
    "Last Name",
    "Nick Name",
    "Phone Number",
    "Darkest Secret"
};

PhoneBook::PhoneBook()
{
	_nextID = 0;
	_phonebookFull = false;
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
			std::cout << "Enter " << std::left << std::setw(14) << _fieldNames[i] << std::right << ": ";
			if (!std::getline(std::cin, inputs[i]))
			{
				std::cerr << SET_RED "\nInput stream closed. Add contact cancelled. Returning back to main menu!" RESET << std::endl;
				std::cin.clear();
				//std::cin.ignore(INT_MAX, '\n');//<climits>
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//<limits>
				return;
			}
			attempt++;
			if (!inputs[i].empty())
				break;
			else if (attempt == 3)
			{
				std::cerr << SET_RED "Failed to add contact. Returning back to main menu!" RESET << std::endl;
				return;
			}
			std::cout << SET_RED << _fieldNames[i] << " cannot be empty. " << (3 - attempt) << " more attempt(s) left." RESET << std::endl;
		}
	}
	_contacts[_nextID] = Contact(inputs);
	++_nextID;
	_phonebookFull = _phonebookFull || (_nextID == 8);
	_nextID = _nextID % 8;
	std::cout << SET_GRN "Add contact sucessful!" RESET << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string	searchID;
	std::string	*fullContact;

	if (!_phonebookFull && !_nextID)
	{
		std::cout << SET_RED "Phonebook empty!" RESET << std::endl;
		return ;
	}
	std::cout << " __________ __________ __________ __________ " << std::endl;
	std::cout << "|" SET_YLW "_____________Phonebook Summary_____________" RESET "|" << std::endl;
	std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
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
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "\nEnter index for full contact details:";
	if (!std::getline(std::cin, searchID))
	{
		std::cerr << SET_RED "\nInput stream closed. Search contact cancelled. Returning back to main menu!" RESET << std::endl;
		std::cin.clear();
		//std::cin.ignore(INT_MAX, '\n');//<climits>
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//<limits>
		return;
	}
	if (searchID.length() == 1 && std::isdigit(searchID[0]))
	{
		int id = searchID[0] - '0' - 1;
		if ((!_phonebookFull && id >= _nextID) || id > 8 || id < 0)//check ths condition
			std::cerr << SET_RED "Search index out of range. Returning back to main menu!" RESET << std::endl;
		else
		{
			fullContact = _contacts[id].getContact();
			for (int i = 0; i < 5; i++)
				std::cout << std::left << std::setw(20) << _fieldNames[i] << std::right << ": " << fullContact[i] << std::endl;
		}
	}
	else
		std::cerr << SET_RED "Invalid input. Returning back to main menu!" RESET << std::endl;
}
