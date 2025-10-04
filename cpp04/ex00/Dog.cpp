/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/04 21:33:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: Default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type= other._type;
	return (*this); 
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}