/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/09 20:38:25 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {}

Character::Character(std::string name) : _name(name) {}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i])
			_slot[i] = other._slot[i] -> clone();
	}
}

Character&	Character::operator=(const Character& other) {
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
	for (int i = 0; i < 4; i++)
		delete _slot[i];
}

const std::string& Character::getName() const {return (_name);}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (!_slot[i])
			_slot[i] = m;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		_slot[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _slot[idx])
		_slot[idx] -> use(target);	
}