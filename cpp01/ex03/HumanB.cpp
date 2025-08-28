/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:54:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 22:22:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    _name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack(std::string name, Weapon weapon) {
    std::cout << _name << "attacks with their" << _weapon.getType() << std::endl;
}