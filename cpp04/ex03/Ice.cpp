/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:40 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/08 22:26:02 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {DBG("Ice: Default constructor called");}

Ice::Ice(const Ice& other) : AMateria(other) {DBG("Ice: Copy constructor called");}

Ice&	Ice::operator=(const Ice& other) {
	DBG("Ice: Copy assignment operator called");
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {DBG("Ice: Destructor called");}

AMateria* Ice::clone() const {
	DBG("Ice: clone called");
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	DBG("Ice: use called");
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}