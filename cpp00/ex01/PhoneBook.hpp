/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/26 20:14:30 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define SET_GRN		"\033[32m"
#define SET_RED		"\033[31m"
#define SET_YLW		"\033[33m"
#define SET_B_YLW	"\033[1;33m"
#define SET_B_BLK	"\033[1;30m"
#define RESET		"\033[0m"

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact						_contacts[8];
		static const std::string	_fieldNames[5];
		int							_nextID;
		bool						_phonebookFull;
		
	public:
		PhoneBook();
		~PhoneBook();
	
		void	addContact();
		void	searchContact();
};

#endif