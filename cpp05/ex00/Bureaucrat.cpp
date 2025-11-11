/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:36 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/11 18:09:19 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName() const {return (_name);}
int	Bureaucrat::getGrade() const {return (_grade);}

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Bureaucrat::grade_too_high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Bureaucrat::grade_too_low";
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureau) {
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (os);
}
