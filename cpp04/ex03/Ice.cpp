/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:40 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/12 23:35:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {LOG("Ice: Default constructor called");}

Ice::Ice(const Ice& other) : AMateria(other) {LOG("Ice: Copy constructor called");}

Ice&	Ice::operator=(const Ice& other) {
	LOG("Ice: Copy assignment operator called");
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {LOG("Ice: Destructor called");}

AMateria* Ice::clone() const {
	LOG("Ice: clone called");
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	LOG("Ice: use called");
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}