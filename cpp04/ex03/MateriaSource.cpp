/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:51 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/09 22:47:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {DBG("MateriaSource: Default constructor called");}

MateriaSource::MateriaSource(const MateriaSource& other) {
	DBG("MateriaSource: Copy constructor called");
    for (int i = 0; i < 4; i++)
	{
		if (_template[i])
			_template[i] = other._template[i] -> clone();
		else 
			_template[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	DBG("MateriaSource: Copy assignment operator called");
	if (this != &other) {
		for (int i = 0; i < 4; i++)
		{
			delete _template[i];
			_template[i] = nullptr;
			if (other._template[i]) 
				_template[i] = other._template[i] -> clone();
		}
	}
	return (*this); 
}

MateriaSource::~MateriaSource() {
	DBG("MateriaSource: Destructor called");
	for (int i = 0; i < 4; i++)
		delete _template[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	DBG("MateriaSource: learnMateria called");
    if (!m) {return;}
	for (int i = 0; i < 4; i++) {
        if (!_template[i])
		{
            _template[i] = m -> clone();
			break;
		}
    }
	delete m;//TODO: see if this is reasonable to add here
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	DBG("MateriaSource: createMateria called");
	for (int i = 0; i < 4; i++) {
		if (_template[i] && _template[i] -> getType() == type)
			return _template[i] -> clone();
	}
	return nullptr; 
}