/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:54:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/29 19:33:53 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
    _name = name;
    _weapon = nullptr;
}

HumanB::~HumanB() {}

void	HumanB::attack() const {
    if (_weapon)
        std::cout << _name << "attacks with their" << _weapon -> getType() << std::endl;
    else
        std::cout << _name << "attacks with no weapon" << std::endl;
}