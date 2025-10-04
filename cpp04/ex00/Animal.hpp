/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:27:32 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/04 21:30:48 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(const Animal& other);
		Animal&   operator=(const Animal& other);
		virtual ~Animal();
		
		virtual void makeSound() const;

		std::string  getType() const;
};

#endif