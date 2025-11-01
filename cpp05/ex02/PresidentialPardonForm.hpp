/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/01 21:50:41 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>


class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		~PresidentialPardonForm();

		const std::string& getTarget() const;
		
		void execute(const Bureaucrat& executor) const override;
};

#endif