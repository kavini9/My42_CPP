/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:20 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/13 21:49:47 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string m_contactFields[5];
        // std::string m_firstName;
    	// std::string m_lastName;
		// std::string m_nickName;
		// std::string m_phoneNumber;
		// std::string m_darkestSecret;
        
    public:
		Contact(void);
        Contact(std::string *contactFields);
		~Contact(void);

        void    getContact();
        bool    setContact();
};

#endif