/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:28:12 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 21:40:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    _type = type;
}

Weapon::~Weapon() {}

const std::string&  Weapon::getType() {
    return (_type);
}

void    Weapon::setType(std::string& newtype) {
    _type = newtype;
}

