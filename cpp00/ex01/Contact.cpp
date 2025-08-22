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

Contact::Contact(){}

Contact::Contact(std::string *contactFields)
{
    for (int i = 0; i < 5; i++) 
	{
        _contactFields[i] = contactFields[i];
    }
}

Contact::~Contact(){}

std::string* Contact::getContact() 
{
    return _contactFields;
}


