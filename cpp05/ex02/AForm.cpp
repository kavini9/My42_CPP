/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:28 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 19:43:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm: Parameterized constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name),_signStatus(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "AForm: Copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm: Destructor called" << std::endl;
}

const std::string& AForm::getName() const {return (_name);}
int	AForm::getSignStatus() const {return (_signStatus);}
int	AForm::getGradeToSign() const {return (_gradeToSign);}
int AForm::getGradeToExecute() const {return (_gradeToExecute);}

void AForm::beSigned(const Bureaucrat& bureau) {
	if (_gradeToSign > bureau.getGrade())
		throw GradeTooLowException();
	else if (_signStatus == true)
		throw AlreadySignedException();
	_signStatus = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const {
    if (this -> getSignStatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this -> getGradeToExecute())
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "AForm::grade_too_high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "AForm::grade_too_low";
}

const char* AForm::AlreadySignedException::what() const noexcept {
	return "AForm::already_signed";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return "AForm::form_not_signed";
}

std::ostream	&operator<<(std::ostream& os, const AForm& form) {
	os << "Form, "<< form.getName() 
	<< " [grade_to_sign: " << form.getGradeToSign() 
	<< ", grade_to_execute: " << form.getGradeToExecute()
	<< ", sign_status: " << form.getSignStatus() << "]";
	return (os);
}