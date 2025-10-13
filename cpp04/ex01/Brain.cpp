/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:38:09 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/13 20:59:28 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea_" + std::to_string(i + 1);
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain: Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this); 
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
}

void Brain::setIdea(int idx, std::string idea) {
	if (idx >= 0 && idx < 100)
		_ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
	return ((idx >= 0 && idx < 100) ? _ideas[idx] : "");
}