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

PhoneBook::PhoneBook()
{
	m_nextUp = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::addContact()
{
	std::string	inputs[5];
	std::string	fieldNames[] = {
		"first name",
		"last name",
		"nick name",
		"phone number",
		"darkest secret"
	};
	for (int i = 0; i < 5; ++i)
	{
		int attempt = 0;
		while (attempt < 3)
		{
			
		}
	}
}