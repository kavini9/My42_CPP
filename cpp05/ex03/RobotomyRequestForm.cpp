/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:43 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/10 18:45:35 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const char* drilling_noise= R"(*VRRRRRRRRRRRRRRRRRR....
.....BRRRRRRRRRTTTTTT!
........VRRRT-VRRRRT-VRRRRT...
tch! tch! whirrrrrrrr......*)";

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45) , _target(target) {
	std::cout << "RobotomyRequestForm: Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _target(other._target) {
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;   
}

const std::string& RobotomyRequestForm::getTarget() const {return (_target);}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);
	std::cout << drilling_noise << std::endl;
	std::srand(time(NULL));
	if (rand()%100 %2 == 0)
		std::cout << SET_GRN << _target << " has been robotomized successfully." RESET << std::endl;
	else
		std::cout << SET_RED << _target << " robotomy failed." RESET << std::endl;
}