/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:17:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 16:20:32 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool	_signStatus;
		const int	_gradeToSign;
		const int	_gradeToExecute;

	public:
		Form() = delete;
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;
		~Form();

		const std::string& getName() const;
		int	getSignStatus() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;
		
		void beSigned(const Bureaucrat& bureau);
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class AlreadySignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif