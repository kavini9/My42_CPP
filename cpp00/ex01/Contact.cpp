/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:13 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/12 21:04:25 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nick_name = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name,
            std::string nick_name, std::string phone_number,
            std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nick_name = nick_name;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

Contact::~Contact(){}


