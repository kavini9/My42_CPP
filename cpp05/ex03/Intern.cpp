/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:28:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/11 18:25:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called" << std::endl;
    (void) other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: Copy assignment operator called" << std::endl;
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
		if(!formType[formId].compare(formName)) 
            break;
    }
	AForm* form =nullptr;
	switch (formId) {
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << SET_RED "Intern couldn't create the form. Invalid name." RESET << std::endl;
		 	return form;
	}
	std::cout << SET_GRN "Intern creates form " << formType[formId] << RESET << std::endl;
	return form;
}

// throw std::bad_alloc();

