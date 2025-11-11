/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:28:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/11 18:14:06 by wweerasi         ###   ########.fr       */
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

	AForm* form1 = nullptr;
	AForm* form2 = nullptr;
	AForm* form3 = nullptr;
	AForm* form4 = nullptr;
		
	try {
	std::cout << std::endl;
	form1 = intern1.makeForm("ShrubberyCreationForm", "Desert_outpost");
	form1 && std::cout << "form1: " << *form1 << std::endl;
	std::cout << std::endl;
	form2 = intern1.makeForm("RobotomyRequestForm", "Jolly_Jumper");
	form2 && std::cout << "form2: " << *form2 << std::endl;
	std::cout << std::endl;
	form3 = intern1.makeForm("PresidentialPardonForm", "Daltons");
	form3 && std::cout << "form3: " << *form3 << std::endl;
	std::cout << std::endl;
	form4 = intern1.makeForm("ShrubototialCrequedonForm", "Qwerty");
	form4 && std::cout << "form4: " << *form4 << std::endl;
	std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
	}
	if (form1) delete form1;
	if (form2) delete form2;
	if (form3) delete form3;
	if (form4) delete form4;
}