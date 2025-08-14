/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:13 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/14 23:08:44 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::Contact(std::string *contactFields)
{
	m_contactFields[0] = contactFields[0];
	m_contactFields[1] = contactFields[1];
	m_contactFields[2] = contactFields[2];
	m_contactFields[3] = contactFields[3];
	m_contactFields[4] = contactFields[4];
}

Contact::~Contact(){}


