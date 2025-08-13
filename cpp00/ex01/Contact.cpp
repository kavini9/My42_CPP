/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:13 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/13 21:51:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	// m_firstName = "";
	// m_lastName = "";
	// m_nickName = "";
	// m_phoneNumber = "";
	// m_darkestSecret = "";
}

Contact::Contact(std::string *contactFields)
{
	m_contactFields[0] = contactFields[0];
	m_contactFields[1] = contactFields[1];
	m_contactFields[2] = contactFields[2];
	m_contactFields[3] = contactFields[3];
	m_contactFields[4] = contactFields[4];
	// m_firstName = firstName;
	// m_lastName = lastName;
	// m_nickName = nickName;
	// m_phoneNumber = phoneNumber;
	// m_darkestSecret = darkestSecret;
}

Contact::~Contact(){}


