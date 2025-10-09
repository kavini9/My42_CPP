/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:53:41 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/09 22:39:34 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria&  AMateria::operator=(const AMateria&) {return (*this);}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const {return (_type);}

void AMateria::use(ICharacter& target) {(void) target;}