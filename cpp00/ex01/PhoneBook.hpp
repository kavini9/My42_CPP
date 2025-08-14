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

//#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact m_contacts[8];
		int		m_nextUp;
	
	public:
		PhoneBook();
		~PhoneBook();
	
		void	addContact();
		void	searchContact();
};

#endif