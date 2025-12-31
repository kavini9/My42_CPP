/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:35:13 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 19:33:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int FragTrap::_statHitPoints = 100;
unsigned int FragTrap::_statEnergyPoints = 100;
unsigned int FragTrap::_statAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap: Default constructor called" << std::endl;
	_hitPoints = _statHitPoints;
	_energyPoints = _statEnergyPoints;
	_attackDamage = _statAttackDamage;
}

FragTrap::FragTrap(std::string name) :  ClapTrap(name) {
	std::cout << "FragTrap: Parameterized constructor called" << std::endl;
	_hitPoints = _statHitPoints;
	_energyPoints = _statEnergyPoints;
	_attackDamage = _statAttackDamage;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this); 
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " throws a hand up for a high five!" << std::endl;
}

unsigned int FragTrap::getStatHitPoints() {return _statHitPoints;}
unsigned int FragTrap::getStatEnergyPoints() {return _statEnergyPoints;}
unsigned int FragTrap::getStatAttackDamage() {return _statAttackDamage;}