/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:54 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
		~ShrubberyCreationForm();

		const std::string& getTarget() const;
		
		void execute(const Bureaucrat& executor) const override;
		class FileOpenFailException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

#endif