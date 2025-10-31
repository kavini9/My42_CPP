/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:53 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/31 21:04:13 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form::Form() : _signStatus(false), _gradeToSign(1), _gradeToExecute(1) {
//     std::cout << "Form: Default constructor called" << std::endl;
// }

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form: Parameterized constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name),_signStatus(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form: Copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form: Destructor called" << std::endl;
}

const std::string& Form::getName() const {return (_name);}
int	Form::getSignStatus() const {return (_signStatus);}
int	Form::getGradeToSign() const {return (_gradeToSign);}
int Form::getGradeToExecute() const {return (_gradeToExecute);}

void Form::beSigned(const Bureaucrat& bureau) {
	if (_gradeToSign > bureau.getGrade())
		throw GradeTooLowException();
	else if (_signStatus == true)
		throw AlreadySignedException();
	_signStatus = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Form::grade_too_high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Form::grade_too_low";
}

const char* Form::AlreadySignedException::what() const noexcept {
	return "Form::already_signed";
}

std::ostream	&operator<<(std::ostream& os, const Form& form) {
	os << "Form, "<< form.getName() 
	<< " [grade_to_sign: " << form.getGradeToSign() 
	<< ", grade_to_execute: " << form.getGradeToExecute()
	<< ", sign_status: " << form.getSignStatus() << "]";
	return (os);
}