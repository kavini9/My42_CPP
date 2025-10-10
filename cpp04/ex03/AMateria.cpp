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

AMateria::AMateria() {DBG("AMateria: Default constructor called");}

AMateria::AMateria(const std::string& type) : _type(type) {DBG("AMateria: Parameterized constructor called");}

AMateria::AMateria(const AMateria& other) : _type(other._type) {DBG("AMateria: Copy constructor called");}

AMateria&  AMateria::operator=(const AMateria&) {
    DBG("AMateria: Copy assignment operator called");
    return (*this);
}

AMateria::~AMateria() {DBG("AMateria: Destructor called");}

const std::string& AMateria::getType() const {
    DBG("AMateria: getType called");
    return (_type);}

void AMateria::use(ICharacter& target) {
    DBG("AMateria: use called");
    (void) target;
}