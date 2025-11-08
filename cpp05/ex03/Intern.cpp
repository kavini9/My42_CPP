/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:28:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/18 22:28:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called" << std::endl;
    (void) other;
	// *this = other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: Copy assignment operator called" << std::endl;
	// if (this != &other)
	// 	*this = other;
    (void) other;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern: Destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	std::string formType[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int arrLen = sizeof(formType) / sizeof(*formType);
    int formId;
	for(formId = 0 ; formId < arrLen ; formId++) {
		if(!formType[formId].compare(formName)) {
			std::cout << SET_GRN "Intern creates form " << formType[formId] << RESET << std::endl;
            break;
        }
    }
	switch (formId) {
		case 0:
			return new ShrubberyCreationForm(formTarget);
		case 1:
			return new RobotomyRequestForm(formTarget);
		case 2:
			return new PresidentialPardonForm(formTarget);
		default:
			std::cout << SET_RED "Intern couldn't create the form. Invalid name." RESET << std::endl;
		 	return nullptr;
	}
}

