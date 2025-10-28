/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:36 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/28 21:46:58 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150) {
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Bureaucrat: Parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

// Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
// 	std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
// 	if (this != &other)
// 		_grade = other._grade;
// 	return (*this);
// }

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called" << std::endl;
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

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception& e) {
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
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