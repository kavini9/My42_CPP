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

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure&	Cure::operator=(const Cure& other) {
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target)  {
	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}
