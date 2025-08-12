/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:20 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/12 20:55:38 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string _first_name;
    	std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
        
    public:
		Contact(void);
        Contact(std::string first_name, std::string last_name,
            std::string nick_name, std::string _hone_number,
            std::string darkest_secret);
		~Contact(void);

        void    get_contact();
        bool    set_contact();
};

#endif