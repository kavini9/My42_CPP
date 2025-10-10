/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:30 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/08 22:25:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {DBG("Cure: Default constructor called");}

Cure::Cure(const Cure& other) : AMateria(other) {DBG("Cure: Copy constructor called");}

Cure&	Cure::operator=(const Cure& other) {
	DBG("Cure: Copy assignment operator called");
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {DBG("Cure: Destructor called");}

AMateria* Cure::clone() const {
	DBG("Cure: Clone called");
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	DBG("Cure: Use called");
	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}
