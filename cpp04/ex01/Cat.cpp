/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:28 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/13 21:53:06 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat: Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type= other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this); 
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meaw Meaw" << std::endl;
}

Brain* Cat::getBrain() const {return (_brain);}