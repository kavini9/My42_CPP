/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:53:41 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/12 23:35:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {LOG("AMateria: Default constructor called");}

AMateria::AMateria(const std::string& type) : _type(type) {LOG("AMateria: Parameterized constructor called");}

AMateria::AMateria(const AMateria& other) : _type(other._type) {LOG("AMateria: Copy constructor called");}

AMateria&  AMateria::operator=(const AMateria&) {
    LOG("AMateria: Copy assignment operator called");
    return (*this);
}

AMateria::~AMateria() {LOG("AMateria: Destructor called");}

const std::string& AMateria::getType() const {
    LOG("AMateria: getType called");
    return (_type);}

void AMateria::use(ICharacter& target) {
    LOG("AMateria: use called");
    (void) target;
}