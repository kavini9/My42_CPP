/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:28:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/18 22:28:16 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern1;
	Intern intern2(intern1);
	Intern intern3;
	Intern intern4;
	intern4 = intern3;
	
	AForm* form1 = intern1.makeForm("ShrubberyCreationForm", "Desert_outpost");
	std::cout << "form1: " << *form1 << std::endl;
	AForm* form2 = intern1.makeForm("RobotomyRequestForm", "Jolly_Jumper");
	std::cout << "form2: " << *form2 << std::endl;
	AForm* form3 = intern1.makeForm("PresidentialPardonForm", "Daltons");
	std::cout << "form3: " << *form3 << std::endl;
	AForm* form4 = intern1.makeForm("ShrubototialCrequedonForm", "Qwerty");
	std::cout << "form4: " << form4 << std::endl;
}