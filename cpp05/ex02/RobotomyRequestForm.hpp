/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:47 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/10 18:41:24 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define SET_RED		"\033[31m"
#define SET_GRN		"\033[32m"
#define RESET		"\033[0m"

#include "AForm.hpp"
#include <string>
#include <iostream>


class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	
	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
		~RobotomyRequestForm();

		const std::string& getTarget() const;
		
		void execute(const Bureaucrat& executor) const override;
};

#endif