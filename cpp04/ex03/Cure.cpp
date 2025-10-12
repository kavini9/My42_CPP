/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:30 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/12 23:35:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {LOG("Cure: Default constructor called");}

Cure::Cure(const Cure& other) : AMateria(other) {LOG("Cure: Copy constructor called");}

Cure&	Cure::operator=(const Cure& other) {
	LOG("Cure: Copy assignment operator called");
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {LOG("Cure: Destructor called");}

AMateria* Cure::clone() const {
	LOG("Cure: Clone called");
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	LOG("Cure: Use called");
	std::cout <<  "* heals " << target.getName() << "'s wounds *" << std::endl;
}
