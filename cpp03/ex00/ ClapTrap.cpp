/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ClapTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:48 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/27 22:18:57 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap() {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this); 
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)  {
	if (!_hitPoints) {
		_hitPoints = (amount >= _hitPoints) ? 0 : (_hitPoints - amount);
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
		
		
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap " << _name << " repairs, gaining " << amount << " hit points!" << std::endl;	
		_energyPoints--;
	}
}