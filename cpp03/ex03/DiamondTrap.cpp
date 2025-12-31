/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:28:54 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 20:03:15 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	_hitPoints = FragTrap::getStatHitPoints();
	_energyPoints = ScavTrap::getStatEnergyPoints();
	_attackDamage = FragTrap::getStatAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	std::cout << "DiamondTrap: Parameterized constructor called" << std::endl;
	_hitPoints = FragTrap::getStatHitPoints();
	_energyPoints = ScavTrap::getStatEnergyPoints();
	_attackDamage = FragTrap::getStatAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this); 
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am DiamondTrap " << _name << " and my ancestor is ClapTrap " << ClapTrap::_name << std::endl;
}