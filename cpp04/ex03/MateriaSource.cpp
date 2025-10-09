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

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) {
    	for (int i = 0; i < 4; i++)
	{
		if (_template[i])
			_template[i] = other._template[i] -> clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
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
	for (int i = 0; i < 4; i++)
		delete _template[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {return;}
	for (int i = 0; i < 4; i++) {
        if (!_template[i])
            _template[i] = m -> clone();
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_template[i] && _template[i] -> getType() == type)
			return _template[i] -> clone();
	}
	return nullptr; 
}