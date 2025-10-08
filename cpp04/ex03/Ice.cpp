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

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice&	Ice::operator=(const Ice& other) {
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target)  {
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}