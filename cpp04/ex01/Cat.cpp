/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:28 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 23:21:30 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat: Parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type= other._type;
	return (*this); 
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "*Cat sound*" << std::endl;
}