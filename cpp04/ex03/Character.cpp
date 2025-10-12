/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/12 23:35:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {LOG("Character: Default constructor called");}

Character::Character(std::string name) : _name(name) {LOG("Character: Parameterized constructor called");}

Character::Character(const Character& other) : _name(other._name) {
	LOG("Character: Copy constructor called");
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i])
			_slot[i] = other._slot[i] -> clone();
	}
}

Character&	Character::operator=(const Character& other) {
	LOG("Character: Copy assignment operator called");
	if (this != &other) {
		_name= other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _slot[i];
			_slot[i] = nullptr;
			if (other._slot[i]) 
				_slot[i] = other._slot[i] -> clone();
		}
	}
	return (*this); 
}

Character::~Character() {
	LOG("Character: Destructor called");
	for (int i = 0; i < 4; i++)
		delete _slot[i];
}

const std::string& Character::getName() const {
	LOG("Character: getName called");
	return (_name);
}

void Character::equip(AMateria* m) {
	LOG("Character: equip called");
	for (int i = 0; i < 4; i++)
	{
		if (!_slot[i])
		{
			_slot[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	LOG("Character: unequip called");
	if (idx >= 0 && idx < 4)
		_slot[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	LOG("Character: use called");
	if (idx >= 0 && idx < 4 && _slot[idx])
		_slot[idx] -> use(target);	
}