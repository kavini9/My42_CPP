/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 21:31:13 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool	_signStatus;
		const int	_gradeToSign;
		const int	_gradeToExecute;

	public:
		AForm() = delete;
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other) = delete;
		~AForm();

		const std::string& getName() const;
		int	getSignStatus() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;
		
		void beSigned(const Bureaucrat& bureau);
		void checkExecutability(const Bureaucrat& executor) const;
        virtual void execute(const Bureaucrat& executor) const = 0;
		
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
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
