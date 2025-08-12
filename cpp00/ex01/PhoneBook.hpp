/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:01:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/12 21:09:34 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

//#include <iostream>
#include <string>

class PhoneBook
{
    private: 
        Contact _contacts[8];
        int     _head;
    
    public:
		PhoneBook();
		~PhoneBook();
        
        void    save_contact();
        void    view_list();
        void    view_contact();
};

#endif