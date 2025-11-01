/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:20 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 22:01:50 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const char* drilling_noise= R"(
*VRRRRRRRRRRRRRRRRRR....
.....BRRRRRRRRRTTTTTT!
........VRRRT-VRRRRT-VRRRRT...
tch! tch! whirrrrrrrr......*
)";

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5) , _target(target) {
	std::cout << "PresidentialPardonForm: Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5), _target(other._target) {
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;   
}

const std::string& PresidentialPardonForm::getTarget() const {return (_target);}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);//I hpe in this function "this" works fine.
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}