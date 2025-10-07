/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/07 19:58:42 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: Default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog: Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type= other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this); 
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const {return (_brain);}