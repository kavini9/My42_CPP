/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/13 19:01:15 by wweerasi         ###   ########.fr       */
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
        Contact _contacts[8];
        int     _head;
    
    public:
		PhoneBook();
		~PhoneBook();
        
        void    saveContact();
        void    viewList();
        void    viewContact();
};

#endif