/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/14 23:11:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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