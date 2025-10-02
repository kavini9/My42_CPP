/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:48 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/29 21:01:19 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
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

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else 
		std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)  {
	if (_hitPoints) {
		std::cout << "ClapTrap " << _name << " takes ";
		std::cout << ((amount > _hitPoints) ? _hitPoints : amount); 
		std::cout << " points of damage!" << std::endl;
		_hitPoints = ((amount > _hitPoints) ? 0 : (_hitPoints - amount));
	} else
		std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap " << _name << " repairs, gaining ";
		std::cout << (((UINT_MAX - amount) < _hitPoints) ? (UINT_MAX - _hitPoints) : amount);
		std::cout << " hit points!" << std::endl;	
		_hitPoints = (((UINT_MAX - amount) < _hitPoints) ? UINT_MAX : (_hitPoints + amount)) ;
		_energyPoints--;
	} else
		std::cout << "ClapTrap " << _name << " cannot repair!" << std::endl;
}

std::string	ClapTrap::getName() const {return (_name);}
unsigned int	ClapTrap::getHitPoints() const {return (_hitPoints);}
unsigned int	ClapTrap::getEnergyPoints() const {return (_energyPoints);}
unsigned int	ClapTrap::getAttackDamage() const {return (_attackDamage);}