/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:37:24 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 22:10:03 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) 
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}