/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:40 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/06 18:36:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define SET_RED		"\033[31m"
#define SET_GRN		"\033[32m"
#define RESET		"\033[0m"

#include "Form.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string   _name;
		int                 _grade;
	
	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		~Bureaucrat();

		const std::string& getName() const;
		int		getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureau);

#endif
