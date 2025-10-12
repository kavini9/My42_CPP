/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:51 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/12 23:35:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {LOG("MateriaSource: Default constructor called");}

MateriaSource::MateriaSource(const MateriaSource& other) {
	LOG("MateriaSource: Copy constructor called");
    for (int i = 0; i < 4; i++)
	{
		if (_bluePrints[i])
			_bluePrints[i] = other._bluePrints[i] -> clone();
		else 
			_bluePrints[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	LOG("MateriaSource: Copy assignment operator called");
	if (this != &other) {
		for (int i = 0; i < 4; i++)
		{
			delete _bluePrints[i];
			_bluePrints[i] = nullptr;
			if (other._bluePrints[i]) 
				_bluePrints[i] = other._bluePrints[i] -> clone();
		}
	}
	return (*this); 
}

MateriaSource::~MateriaSource() {
	LOG("MateriaSource: Destructor called");
	for (int i = 0; i < 4; i++)
		delete _bluePrints[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	LOG("MateriaSource: learnMateria called");
    if (!m) {return;}
	for (int i = 0; i < 4; i++) {
        if (!_bluePrints[i])
		{
            _bluePrints[i] = m;//-> clone();
			return;
		}
    }
	delete m;//TODO: see if this is reasonable to add here
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	LOG("MateriaSource: createMateria called");
	for (int i = 0; i < 4; i++) {
		if (_bluePrints[i] && _bluePrints[i] -> getType() == type)
			return (_bluePrints[i] -> clone());
	}
	return nullptr; 
}