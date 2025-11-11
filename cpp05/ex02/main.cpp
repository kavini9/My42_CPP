/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:27:05 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/10 18:36:36 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

#define SET_B_BLK	"\033[1;30m"
#define SET_YLW		"\033[33m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main()
{
	ShrubberyCreationForm someGreen("Desert_outpost");
	RobotomyRequestForm roboMate("Jolly_Jumper");
	PresidentialPardonForm noMercy("Daltons");
	ShrubberyCreationForm totalFail("TooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooLooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooongTargetName");
	AForm* form1 = &someGreen;
	AForm* form2 = &roboMate;
	AForm *form3 = &noMercy;
	AForm *form4 = &totalFail;
	Bureaucrat bureau1("Eustace Bureau", 3);
	Bureaucrat bureau2("Cletus Copperfield", 15);
	Bureaucrat bureau3("Abigail Inkwood", 30);
	Bureaucrat bureau4("Sam Stringer", 50);
	Bureaucrat bureau5("Hank Ledger", 100);
	Bureaucrat bureau6("Rusty Penman", 140);
	Bureaucrat bureau7("Dottie Stamp", 147);
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: Bureaucrat satisfies execute_grade but form is not signed yet." RESET  << std::endl;
		try {
			std::cout << "form: " << *form1 << std::endl;
			std::cout << "bureaucrat: " << bureau5 << std::endl;
			bureau5.executeForm(*form1);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: Bureaucrat does not satisfy sign_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form1 << std::endl;
			std::cout << "bureaucrat: " << bureau7 << std::endl;
			bureau7.signForm(*form1);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: Bureaucrat satisfies sign_grade but not execute_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form1 << std::endl;
			std::cout << "bureaucrat: " << bureau6 << std::endl;
			bureau6.signForm(*form1);
			bureau6.executeForm(*form1);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: The form is already signed." RESET  << std::endl;
		try {
			std::cout << "form: " << *form1 << std::endl;
			std::cout << "bureaucrat: " << bureau5 << std::endl;
			bureau6.signForm(*form1);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: File creation fails." RESET  << std::endl;
		try {
			std::cout << "form: " << *form4 << std::endl;
			std::cout << "bureaucrat: " << bureau5 << std::endl;
			bureau6.signForm(*form4);
			bureau5.executeForm(*form4);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "ShrubberyCreationForm: Bureaucrat executes form successfully." RESET  << std::endl;
		try {
			std::cout << "form: " << *form1 << std::endl;
			std::cout << "bureaucrat: " << bureau5 << std::endl;
			bureau5.executeForm(*form1);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "RobotomyRequestForm: Bureaucrat satisfies execute_grade but form is not signed yet." RESET  << std::endl;
		try {
			std::cout << "form: " << *form2 << std::endl;
			std::cout << "bureaucrat: " << bureau3 << std::endl;
			bureau3.executeForm(*form2);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "RobotomyRequestForm: Bureaucrat does not satisfy sign_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form2 << std::endl;
			std::cout << "bureaucrat: " << bureau5 << std::endl;
			bureau5.signForm(*form2);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "RobotomyRequestForm: Bureaucrat satisfies sign_grade but not execute_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form2 << std::endl;
			std::cout << "bureaucrat: " << bureau4 << std::endl;
			bureau4.signForm(*form2);
			bureau4.executeForm(*form2);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "RobotomyRequestForm: Bureaucrat executes form successfully. Loop 10 times to see 50\% success rate" RESET  << std::endl;
		try {
			std::cout << "form: " << *form2 << std::endl;
			std::cout << "bureaucrat: " << bureau3 << std::endl;
			bureau3.executeForm(*form2);
			for(int i = 0; i < 10; i++) {
				bureau3.executeForm(*form2);
				usleep(1000000);
			}
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "PresidentialPardonForm: Bureaucrat satisfies execute_grade but form is not signed yet." RESET  << std::endl;
		try {
			std::cout << "form: " << *form3 << std::endl;
			std::cout << "bureaucrat: " << bureau1 << std::endl;
			bureau1.executeForm(*form3);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "PresidentialPardonForm: Bureaucrat does not satisfy sign_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form3 << std::endl;
			std::cout << "bureaucrat: " << bureau3 << std::endl;
			bureau3.signForm(*form3);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "PresidentialPardonForm: Bureaucrat satisfies sign_grade but not execute_grade." RESET  << std::endl;
		try {
			std::cout << "form: " << *form3 << std::endl;
			std::cout << "bureaucrat: " << bureau2 << std::endl;
			bureau2.signForm(*form3);
			bureau2.executeForm(*form3);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "PresidentialPardonForm: Bureaucrat executes form successfully." RESET  << std::endl;
		try {
			std::cout << "form: " << *form3 << std::endl;
			std::cout << "bureaucrat: " << bureau1 << std::endl;
			bureau1.executeForm(*form3);
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
}