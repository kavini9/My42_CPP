/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:47 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 21:04:43 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

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